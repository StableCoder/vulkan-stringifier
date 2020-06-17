/*
    Copyright (C) 2020 George Cave - gcave@stablecoder.ca

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

const char *includesStr = R"HEADER(
#include <algorithm>
#include <cctype>
#include <cstring>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <tuple>

namespace {

)HEADER";

const char *commonFunctionsStr = R"COMMON(
/**
 * @brief Removes a vendor tag from the end of the given string view
 * @param view String view to remove the vendor tag from
 * @return A string_view without the vendor tag, if it was suffixed
 */
std::string_view removeVendorTag(std::string_view view) {
    for (std::size_t i = 0; i < vendorTagCount; ++i) {
        std::size_t vendorSize = strlen(vendorTags[i]);
        if (strncmp(view.data() + view.size() - vendorSize, vendorTags[i], vendorSize) == 0) {
            view = view.substr(0, view.size() - strlen(vendorTags[i]));
            break;
        }
    }

    return view;
}

/**
 * @brief Strips '_BIT' from the end of a string, if there
 */
std::string_view stripBit(std::string_view view) {
    if (view.size() > strlen("_BIT")) {
        if (view.substr(view.size() - strlen("_BIT")) == "_BIT") {
            return view.substr(0, view.size() - strlen("_BIT"));
        }
    }

    return view;
}

/**
 * @brief Returns the start->end pointer range for valid value sets for the given typename
 * @param enumType Vulkan enum typename
 * @return Pointer range, or nullopt if type not found
 *
 * First tries the original typename, then tries the typename with any vendor strings removed.
 * If the 'Flags' variant of a type is passed in, it is automatically converted to 'FlagBits'.
 */
std::optional<std::tuple<const EnumValueSet *, const EnumValueSet *>> getValueSets(
    std::string_view enumType) {
    // Check for a conversion from Flags -> FlagBits
    std::string testStr;
    if (enumType.rfind("Flags") != std::string::npos) {
        testStr = enumType;
        auto it = testStr.rfind("Flags");
        testStr = testStr.replace(it, strlen("Flags"), "FlagBits");
        enumType = testStr;
    }

    // Try the original name
    for (std::size_t i = 0; i < enumTypesCount; ++i) {
        if (enumType == std::string_view{enumTypes[i].name}) {
            return std::make_tuple(valueSets[i], valueSets[i] + enumTypes[i].count);
        }
    }

    // Try a vendor-stripped name
    enumType = removeVendorTag(enumType);
    for (std::size_t i = 0; i < enumTypesCount; ++i) {
        if (enumType == std::string_view{enumTypes[i].name}) {
            return std::make_tuple(valueSets[i], valueSets[i] + enumTypes[i].count);
        }
    }

    return std::nullopt;
}

/**
 * @brief Takes a given string and formats it for use with parsing
 * @param str The string to format
 * @return Formatted string
 *
 * First, any non alphanumeric characters are trimmed from both ends of the string.
 * After than, any spaces are replaced with underscores, and finally all the characters are
 * capitalized. This will generate the string closest to the original ones found in the XML spec.
 */
std::string formatString(std::string str) {
    // Trim left
    std::size_t cutOffset = 0;
    for (auto c : str) {
        if (::isalnum(c))
            break;
        else
            ++cutOffset;
    }
    str = str.substr(cutOffset);

    // Trim right
    cutOffset = 0;
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (::isalnum(str[i]))
            cutOffset = i + 1;
    }
    str = str.substr(0, cutOffset);

    std::replace(str.begin(), str.end(), ' ', '_');
    std::for_each(str.begin(), str.end(), [](char &c) { c = ::toupper(c); });

    return str;
}

/**
 * @brief Converts a Vulkan Flag typename into the prefix that is used for it's enums
 * @param typeName Name of the type to generate the Vk enum prefix for
 * @return Generated prefix string
 *
 * Any capitalized letters except for the first has an underscore inserted before it, an underscore
 * is added to the end, and all characters are converted to upper case.
 *
 * It also removed the 'Flags' or 'FlagBits' suffixes.
 */
std::string processEnumPrefix(std::string_view typeName) {
    // Flag Bits
    std::size_t flagBitsSize = strlen("FlagBits");
    if (typeName.size() > flagBitsSize) {
        if (strncmp(typeName.data() + typeName.size() - flagBitsSize, "FlagBits", flagBitsSize) ==
            0) {
            typeName = typeName.substr(0, typeName.size() - strlen("FlagBits"));
        }
    }
    // Flags
    std::size_t flagsSize = strlen("Flags");
    if (typeName.size() > flagsSize) {
        if (strncmp(typeName.data() + typeName.size() - flagsSize, "Flags", flagsSize) == 0) {
            typeName = typeName.substr(0, typeName.size() - strlen("Flags"));
        }
    }

    std::string retStr;
    for (auto it = typeName.begin(); it != typeName.end(); ++it) {
        if (it == typeName.begin()) {
            retStr += ::toupper(*it);
        } else if (::isupper(*it)) {
            retStr += '_';
            retStr += *it;
        } else {
            retStr += toupper(*it);
        }
    }
    retStr += '_';

    return retStr;
}

/**
 * @brief Returns the value for the given type/value
 * @param enumType Vulkan enum typename
 * @param enumPrefix The normal prefix for the enum's values
 * @param enumName Name of the enum value to find
 * @return The associated value, or zero if not found otherwise.
 */
std::optional<uint32_t> findValue(std::string_view enumType,
                                  std::string_view enumPrefix,
                                  std::string_view enumName) {
    // Figure out which ValueSet the enum given corresponds to
    auto range = getValueSets(enumType);
    if (!range.has_value())
        return std::nullopt;
    auto [start, end] = range.value();

    // Remove the vendor tag suffix if it's there
    enumName = removeVendorTag(enumName);
    if (enumName[enumName.size() - 1] == '_')
        enumName = enumName.substr(0, enumName.size() - 1);

    // Remove the '_BIT' if its there
    enumName = stripBit(enumName);

    // With the given sets/count, iterate until we find the value
    while (start != end) {
        if (enumName == std::string_view{start->name}) {
            return start->value;
        }

        std::string prefixedName{enumPrefix.begin(), enumPrefix.end()};
        prefixedName += start->name;
        if (enumName == prefixedName) {
            return start->value;
        }

        ++start;
    }

    return std::nullopt;
}

} // namespace

namespace vkEnum {

uint32_t vulkanHeaderVersion() {
    return generatedVulkanVersion;
}

std::optional<uint32_t> parseEnum(std::string_view enumType, std::string value) {
    // If empty, just return 0
    if (value.empty())
        return 0;

    auto prefix = processEnumPrefix(removeVendorTag(enumType));
    value = formatString(value);

    return findValue(enumType, prefix, value);
}

std::optional<uint32_t> parseBitmask(std::string_view enumType, std::string value) {
    auto prefix = processEnumPrefix(removeVendorTag(enumType));
    uint32_t retVal = 0;

    auto startCh = value.begin();
    auto endCh = startCh;
    for (; endCh != value.end(); ++endCh) {
        if (*endCh == '|') {
            std::string token(startCh, endCh);
            token = formatString(token);

            auto val = findValue(enumType, prefix, token);
            if (!val.has_value())
                return std::nullopt;
            retVal |= val.value();

            startCh = endCh + 1;
        }
    }
    if (startCh != endCh) {
        std::string token(startCh, endCh);
        token = formatString(token);

        auto val = findValue(enumType, prefix, token);
        if (!val.has_value())
            return std::nullopt;
        retVal |= val.value();
    }

    return retVal;
}

std::optional<std::string> stringifyEnum(std::string_view enumType, uint32_t enumValue) {
    auto range = getValueSets(enumType);
    if (!range.has_value())
        return std::nullopt;
    auto [start, end] = range.value();

    while (start != end) {
        if (start->value == enumValue) {
            return start->name;
        }

        ++start;
    }

    // If there was a value and we couldn't find it, then that's an error alright. If it was zero,
    // then it was probably just an empty enum set anyways
    if (enumValue == 0) {
        return "";
    }

    return std::nullopt;
}

std::optional<std::string> stringifyBitmask(std::string_view enumType, uint32_t enumValue) {
    auto range = getValueSets(enumType);
    if (!range.has_value())
        return std::nullopt;
    auto [end, start] = range.value();
    --end;
    --start;

    std::string retStr;

    while (start != end && enumValue != 0) {
        if ((start->value & enumValue) == start->value) {
            // Found a compatible bit mask, add it
            if (!retStr.empty()) {
                retStr += " | ";
            }
            retStr += start->name;
            enumValue = enumValue ^ start->value;
        }

        --start;
    }

    if (!retStr.empty()) {
        return retStr;
    }

    return std::nullopt;
}

} // namespace vkEnum
)COMMON";

const char *helpStr = R"HELP(
This program builds a source/header file for use in C++17 or newer. It lists
contains all Vulkan enum types/flags/values of the indicated Vulkan header spec
version, and can convert to/from strings representing those values. 

Supports both plain enums and the bitmasks.

When converting values to strings, where possible a shorter version of the
enum string is used, where the verbose type prefix is removed:
    VK_IMAGE_LAYOUT_GENERAL => GENERAL
    VK_CULL_MODE_FRONT_BIT | VK_CULL_MODE_BACK_BIT => FRONT | BACK

When converting from strings into values, either the short OR full string can
be used where strings are case insensitive, and underscores can be replaced
with spaces, and addition whitespace can be added to either side of the first/
last alphanumeric character, as these are trimmed off.

For example, all of the following convert to VK_IMAGE_LAYOUT_GENERAL:
`vk imAGE_LayOut GenerAL`, `VK_IMAGE_LAYOUT_GENERAL`,`GENERAL`, `   General `

Also, to assist with forward and backwards compatability, all the vendor tags
are stripped from the typenames and values, since they can be removed in later
versions leading to incompatability issues. For example, the flag for 
VkToolPurposeFlagBitsEXT, `VK_TOOL_PURPOSE_VALIDATION_BIT_EXT`, can will
be stringified as `VALIDATION_BIT`, and can be read similarly, with the above
rules applicable for de-stringifying.

Program Arguments:
    -h, --help  : Help Blurb
    -i, --input : Input vk.xml file to parse. These can be found from the 
                    KhronosGroup, often at this repo:
                    https://github.com/KhronosGroup/Vulkan-Docs
    -d, --dir   : Output directory
    -o, --out   : Output file name (Default: `vk_value_stringifier.cpp`)
)HELP";