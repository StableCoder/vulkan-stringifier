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

/*
    This file was auto-generated by the Vulkan mini-libs utility can be found at
    https://github.com/stablecoder/vulkan-mini-libs.git
    or
    https://git.stabletec.com/utilities/vulkan-mini-libs.git

    Check for an updated version anytime, or state concerns/bugs.
*/

#ifndef VK_VALUE_SERIALIZATION_HPP
#define VK_VALUE_SERIALIZATION_HPP

/*  USAGE:
    To use, include this header where the declarations for the boolean checks are required.

    On *ONE* compilation unit, include the definition of `#define VK_VALUE_SERIALIZATION_CONFIG_MAIN`
    so that the definitions are compiled somewhere following the one definition rule.
*/

#include <vulkan/vulkan.h>

// Delegate to header specific to the local Vulkan header version
#if VK_HEADER_VERSION == 159
    #include "detail_value_serialization/vk_value_serialization_v159.hpp"
#endif
#if VK_HEADER_VERSION == 158
    #include "detail_value_serialization/vk_value_serialization_v158.hpp"
#endif
#if VK_HEADER_VERSION == 157
    #include "detail_value_serialization/vk_value_serialization_v157.hpp"
#endif
#if VK_HEADER_VERSION == 156
    #include "detail_value_serialization/vk_value_serialization_v156.hpp"
#endif
#if VK_HEADER_VERSION == 155
    #include "detail_value_serialization/vk_value_serialization_v155.hpp"
#endif
#if VK_HEADER_VERSION == 154
    #include "detail_value_serialization/vk_value_serialization_v154.hpp"
#endif
#if VK_HEADER_VERSION == 153
    #include "detail_value_serialization/vk_value_serialization_v153.hpp"
#endif
#if VK_HEADER_VERSION == 152
    #include "detail_value_serialization/vk_value_serialization_v152.hpp"
#endif
#if VK_HEADER_VERSION == 151
    #include "detail_value_serialization/vk_value_serialization_v151.hpp"
#endif
#if VK_HEADER_VERSION == 150
    #include "detail_value_serialization/vk_value_serialization_v150.hpp"
#endif
#if VK_HEADER_VERSION == 149
    #include "detail_value_serialization/vk_value_serialization_v149.hpp"
#endif
#if VK_HEADER_VERSION == 148
    #include "detail_value_serialization/vk_value_serialization_v148.hpp"
#endif
#if VK_HEADER_VERSION == 147
    #include "detail_value_serialization/vk_value_serialization_v147.hpp"
#endif
#if VK_HEADER_VERSION == 146
    #include "detail_value_serialization/vk_value_serialization_v146.hpp"
#endif
#if VK_HEADER_VERSION == 145
    #include "detail_value_serialization/vk_value_serialization_v145.hpp"
#endif
#if VK_HEADER_VERSION == 144
    #include "detail_value_serialization/vk_value_serialization_v144.hpp"
#endif
#if VK_HEADER_VERSION == 143
    #include "detail_value_serialization/vk_value_serialization_v143.hpp"
#endif
#if VK_HEADER_VERSION == 142
    #include "detail_value_serialization/vk_value_serialization_v142.hpp"
#endif
#if VK_HEADER_VERSION == 141
    #include "detail_value_serialization/vk_value_serialization_v141.hpp"
#endif
#if VK_HEADER_VERSION == 140
    #include "detail_value_serialization/vk_value_serialization_v140.hpp"
#endif
#if VK_HEADER_VERSION == 139
    #include "detail_value_serialization/vk_value_serialization_v139.hpp"
#endif
#if VK_HEADER_VERSION == 138
    #include "detail_value_serialization/vk_value_serialization_v138.hpp"
#endif
#if VK_HEADER_VERSION == 137
    #include "detail_value_serialization/vk_value_serialization_v137.hpp"
#endif
#if VK_HEADER_VERSION == 136
    #include "detail_value_serialization/vk_value_serialization_v136.hpp"
#endif
#if VK_HEADER_VERSION == 135
    #include "detail_value_serialization/vk_value_serialization_v135.hpp"
#endif
#if VK_HEADER_VERSION == 134
    #include "detail_value_serialization/vk_value_serialization_v134.hpp"
#endif
#if VK_HEADER_VERSION == 133
    #include "detail_value_serialization/vk_value_serialization_v133.hpp"
#endif
#if VK_HEADER_VERSION == 132
    #include "detail_value_serialization/vk_value_serialization_v132.hpp"
#endif
#if VK_HEADER_VERSION == 131
    #include "detail_value_serialization/vk_value_serialization_v131.hpp"
#endif
#if VK_HEADER_VERSION == 130
    #include "detail_value_serialization/vk_value_serialization_v130.hpp"
#endif
#if VK_HEADER_VERSION == 129
    #include "detail_value_serialization/vk_value_serialization_v129.hpp"
#endif
#if VK_HEADER_VERSION == 128
    #include "detail_value_serialization/vk_value_serialization_v128.hpp"
#endif
#if VK_HEADER_VERSION == 127
    #include "detail_value_serialization/vk_value_serialization_v127.hpp"
#endif
#if VK_HEADER_VERSION == 126
    #include "detail_value_serialization/vk_value_serialization_v126.hpp"
#endif
#if VK_HEADER_VERSION == 125
    #include "detail_value_serialization/vk_value_serialization_v125.hpp"
#endif
#if VK_HEADER_VERSION == 124
    #include "detail_value_serialization/vk_value_serialization_v124.hpp"
#endif
#if VK_HEADER_VERSION == 123
    #include "detail_value_serialization/vk_value_serialization_v123.hpp"
#endif
#if VK_HEADER_VERSION == 122
    #include "detail_value_serialization/vk_value_serialization_v122.hpp"
#endif
#if VK_HEADER_VERSION == 121
    #include "detail_value_serialization/vk_value_serialization_v121.hpp"
#endif
#if VK_HEADER_VERSION == 120
    #include "detail_value_serialization/vk_value_serialization_v120.hpp"
#endif
#if VK_HEADER_VERSION == 119
    #include "detail_value_serialization/vk_value_serialization_v119.hpp"
#endif
#if VK_HEADER_VERSION == 118
    #include "detail_value_serialization/vk_value_serialization_v118.hpp"
#endif
#if VK_HEADER_VERSION == 117
    #include "detail_value_serialization/vk_value_serialization_v117.hpp"
#endif
#if VK_HEADER_VERSION == 116
    #include "detail_value_serialization/vk_value_serialization_v116.hpp"
#endif
#if VK_HEADER_VERSION == 115
    #include "detail_value_serialization/vk_value_serialization_v115.hpp"
#endif
#if VK_HEADER_VERSION == 114
    #include "detail_value_serialization/vk_value_serialization_v114.hpp"
#endif
#if VK_HEADER_VERSION == 113
    #include "detail_value_serialization/vk_value_serialization_v113.hpp"
#endif
#if VK_HEADER_VERSION == 112
    #include "detail_value_serialization/vk_value_serialization_v112.hpp"
#endif
#if VK_HEADER_VERSION == 111
    #include "detail_value_serialization/vk_value_serialization_v111.hpp"
#endif
#if VK_HEADER_VERSION == 110
    #include "detail_value_serialization/vk_value_serialization_v110.hpp"
#endif
#if VK_HEADER_VERSION == 109
    #include "detail_value_serialization/vk_value_serialization_v109.hpp"
#endif
#if VK_HEADER_VERSION == 108
    #include "detail_value_serialization/vk_value_serialization_v108.hpp"
#endif
#if VK_HEADER_VERSION == 107
    #include "detail_value_serialization/vk_value_serialization_v107.hpp"
#endif
#if VK_HEADER_VERSION == 106
    #include "detail_value_serialization/vk_value_serialization_v106.hpp"
#endif
#if VK_HEADER_VERSION == 105
    #include "detail_value_serialization/vk_value_serialization_v105.hpp"
#endif
#if VK_HEADER_VERSION == 104
    #include "detail_value_serialization/vk_value_serialization_v104.hpp"
#endif
#if VK_HEADER_VERSION == 103
    #include "detail_value_serialization/vk_value_serialization_v103.hpp"
#endif
#if VK_HEADER_VERSION == 102
    #include "detail_value_serialization/vk_value_serialization_v102.hpp"
#endif
#if VK_HEADER_VERSION == 101
    #include "detail_value_serialization/vk_value_serialization_v101.hpp"
#endif
#if VK_HEADER_VERSION == 100
    #include "detail_value_serialization/vk_value_serialization_v100.hpp"
#endif
#if VK_HEADER_VERSION == 99
    #include "detail_value_serialization/vk_value_serialization_v99.hpp"
#endif
#if VK_HEADER_VERSION == 98
    #include "detail_value_serialization/vk_value_serialization_v98.hpp"
#endif
#if VK_HEADER_VERSION == 97
    #include "detail_value_serialization/vk_value_serialization_v97.hpp"
#endif
#if VK_HEADER_VERSION == 96
    #include "detail_value_serialization/vk_value_serialization_v96.hpp"
#endif
#if VK_HEADER_VERSION == 95
    #include "detail_value_serialization/vk_value_serialization_v95.hpp"
#endif
#if VK_HEADER_VERSION == 94
    #include "detail_value_serialization/vk_value_serialization_v94.hpp"
#endif
#if VK_HEADER_VERSION == 93
    #include "detail_value_serialization/vk_value_serialization_v93.hpp"
#endif
#if VK_HEADER_VERSION == 92
    #include "detail_value_serialization/vk_value_serialization_v92.hpp"
#endif
#if VK_HEADER_VERSION == 91
    #include "detail_value_serialization/vk_value_serialization_v91.hpp"
#endif
#if VK_HEADER_VERSION == 90
    #include "detail_value_serialization/vk_value_serialization_v90.hpp"
#endif
#if VK_HEADER_VERSION == 89
    #include "detail_value_serialization/vk_value_serialization_v89.hpp"
#endif
#if VK_HEADER_VERSION == 88
    #include "detail_value_serialization/vk_value_serialization_v88.hpp"
#endif
#if VK_HEADER_VERSION == 87
    #include "detail_value_serialization/vk_value_serialization_v87.hpp"
#endif
#if VK_HEADER_VERSION == 86
    #include "detail_value_serialization/vk_value_serialization_v86.hpp"
#endif
#if VK_HEADER_VERSION == 85
    #include "detail_value_serialization/vk_value_serialization_v85.hpp"
#endif
#if VK_HEADER_VERSION == 84
    #include "detail_value_serialization/vk_value_serialization_v84.hpp"
#endif
#if VK_HEADER_VERSION == 83
    #include "detail_value_serialization/vk_value_serialization_v83.hpp"
#endif
#if VK_HEADER_VERSION == 82
    #include "detail_value_serialization/vk_value_serialization_v82.hpp"
#endif
#if VK_HEADER_VERSION == 81
    #include "detail_value_serialization/vk_value_serialization_v81.hpp"
#endif
#if VK_HEADER_VERSION == 80
    #include "detail_value_serialization/vk_value_serialization_v80.hpp"
#endif
#if VK_HEADER_VERSION == 79
    #include "detail_value_serialization/vk_value_serialization_v79.hpp"
#endif
#if VK_HEADER_VERSION == 78
    #include "detail_value_serialization/vk_value_serialization_v78.hpp"
#endif
#if VK_HEADER_VERSION == 77
    #include "detail_value_serialization/vk_value_serialization_v77.hpp"
#endif
#if VK_HEADER_VERSION == 76
    #include "detail_value_serialization/vk_value_serialization_v76.hpp"
#endif
#if VK_HEADER_VERSION == 75
    #include "detail_value_serialization/vk_value_serialization_v75.hpp"
#endif
#if VK_HEADER_VERSION == 74
    #include "detail_value_serialization/vk_value_serialization_v74.hpp"
#endif
#if VK_HEADER_VERSION == 73
    #include "detail_value_serialization/vk_value_serialization_v73.hpp"
#endif
#if VK_HEADER_VERSION == 72
    #include "detail_value_serialization/vk_value_serialization_v72.hpp"
#endif

#endif // VK_VALUE_SERIALIZATION_HPP
