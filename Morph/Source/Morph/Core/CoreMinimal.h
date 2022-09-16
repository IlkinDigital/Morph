#pragma once

#include <iostream>
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


#define MORPH_LOG(message) std::cout << message << '\n'
#define MORPH_TRACE(message) MORPH_LOG("[TRACE]: " << message)
#define MORPH_INFO(message) MORPH_LOG("[INFO]: " << message)
#define MORPH_ERROR(message) MORPH_LOG("[ERROR]: " << message)
#define MORPH_FATAL(message) MORPH_LOG("[FATAL]: " << message)


#ifdef MORPH_CONFIG_DEBUG
	#define MORPH_ASSERT(expr, message) if (!expr) { MORPH_ERROR(message); __debugbreak(); }
#else
	#define MORPH_ASSERT(expr, message)
#endif
