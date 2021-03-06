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

#include <vulkan/vulkan.h>

// The define adds the definitions to this unit to be compiled.
#define VK_VALUE_SERIALIZATION_CONFIG_MAIN
#include "vk_value_serialization.hpp"

// The define adds the definitions to this unit to be compiled.
#define VK_EQUALITY_CHECK_CONFIG_MAIN
#include "vk_equality_checks.hpp"

// The define adds the definitions to this unit to be compiled.
#define VK_ERROR_CODE_CONFIG_MAIN
#include "vk_error_code.hpp"

// The define adds the definitions to this unit to be compiled.
#define VK_STRUCT_CLEANUP_CONFIG_MAIN
#include "vk_struct_cleanup.hpp"