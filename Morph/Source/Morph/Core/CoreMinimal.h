#pragma once

#include <stdint.h>
#include <string>
#include <memory>

typedef uint8_t	    uint8;
typedef uint16_t    uint16;
typedef uint32_t    uint32;
typedef uint64_t    uint64;

typedef int8_t	    int8;
typedef int16_t     int16;
typedef int32_t     int32;
typedef int64_t     int64;

template<typename Ty>
using Ref = std::shared_ptr<Ty>;
template<typename Ty>
using CreateRef = std::make_shared<Ty>;

template<typename Ty>
using Scope = std::unique_ptr;
template<typename Ty>
using CreateScope = std::make_unique<Ty>;

using String = std::string;
