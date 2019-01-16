//
// Created by koncord on 09.01.19.
//

#pragma once

#include <cstdint>
#include <variant>
#include <vector>

typedef std::variant<uint8_t,
                     int8_t,
                     uint16_t,
                     int16_t,
                     uint32_t,
                     int32_t,
                     uint64_t,
                     int64_t,
                     const char *,
                     void *,
                     float,
                     double,
                     bool> TArgVariant;
typedef std::vector<TArgVariant> TArgsStore;

