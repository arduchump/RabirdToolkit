#ifndef __INCLUDED_C140043A425411E6A04700F1F38F93EF
#define __INCLUDED_C140043A425411E6A04700F1F38F93EF

#include <Arduino.h>

#undef abs
#undef max
#undef min

#include <stddef.h>
#include <stdint.h>

// Include all FreeRTOS stuffs
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

namespace Rt
{
template <class T>
struct RTypeSignTraits;

template <>
struct RTypeSignTraits<char>
{
  typedef signed char   Signed;
  typedef unsigned char Unsigned;
};

template <>
struct RTypeSignTraits<unsigned char>
{
  typedef signed char   Signed;
  typedef unsigned char Unsigned;
};

template <>
struct RTypeSignTraits<short>
{
  typedef signed short   Signed;
  typedef unsigned short Unsigned;
};

template <>
struct RTypeSignTraits<unsigned short>
{
  typedef signed short   Signed;
  typedef unsigned short Unsigned;
};

template <>
struct RTypeSignTraits<int>
{
  typedef signed int   Signed;
  typedef unsigned int Unsigned;
};

template <>
struct RTypeSignTraits<unsigned int>
{
  typedef signed int   Signed;
  typedef unsigned int Unsigned;
};

template <>
struct RTypeSignTraits<long>
{
  typedef signed long   Signed;
  typedef unsigned long Unsigned;
};

template <>
struct RTypeSignTraits<unsigned long>
{
  typedef signed long   Signed;
  typedef unsigned long Unsigned;
};

template <>
struct RTypeSignTraits<long long>
{
  typedef signed long long   Signed;
  typedef unsigned long long Unsigned;
};

template <>
struct RTypeSignTraits<unsigned long long>
{
  typedef signed long long   Signed;
  typedef unsigned long long Unsigned;
};

template <typename T>
struct RArraySize;

template <typename T, size_t N>
struct RArraySize<T(&)[N]>
{
  enum { Value = N };
};
}

typedef Rt::RTypeSignTraits<size_t>::Signed    rsize;
typedef Rt::RTypeSignTraits<uintptr_t>::Signed rnumber;
/**
 * A number type use for limited reference counter.
 *
 * It's designed for fewer memory size and signed type.
 */
typedef BaseType_t   rcount;
typedef signed char  rbool;
typedef unsigned int ruint;

/**
 * @brief Time related counter
 *
 * Just like seconds, milliseconds, microseconds, nanoseconds or ticks.
 */
typedef TickType_t rtime;

/**
 * Flash char type (Rabird Flash Char). An alias of __FlashStringHelper.
 *
 * String be stored in flash not in memory.
 */
typedef class __FlashStringHelper rfchar;

template <class Type>
inline
uintptr_t
rShortenPtr(const Type *longPtr)
{
  return static_cast<uintptr_t>(reinterpret_cast<int>(const_cast<Type *>(longPtr)));
}

template <class PtrType>
inline
PtrType
rLengthenPtr(uintptr_t shortPtr)
{
  return reinterpret_cast<PtrType>(static_cast<int>((shortPtr)));
}

template <class T>
inline
typename Rt::RTypeSignTraits<T>::Signed
rSignedCast(const T &value)
{
  return static_cast<typename Rt::RTypeSignTraits<T>::Signed>(value);
}

template <class T>
inline
typename Rt::RTypeSignTraits<T>::Unsigned
rUnsignedCast(const T &value)
{
  return static_cast<typename Rt::RTypeSignTraits<T>::Unsigned>(value);
}

/**
 * Calculate how much elements in the array
 *
 * @param array Target array variant to calculate
 */
#define R_SIZE_OF_ARRAY(array) (Rt::RArraySize<decltype((array))>::Value)

/**
 * Offset specific ptr to nBytes
 */
#define R_PTR_OFFSET(ptr, nBytes) \
  ((decltype(ptr))(((char *)(ptr)) + (nBytes)))

/**
 * Calculate how much bytes between ptrBegin and ptrEnd
 */
#define R_OFFSET_BETWEEN_PTRS(ptrBegin, ptrEnd) \
  ((char *)(ptrEnd) - (char *)(ptrBegin))

/**
 * Get the member offset of a struct
 */
#define R_OFFSET_OF(structName, member) (size_t)&(((structName *)0)->member)

/**
 * Disable copy constructor and assign operations.
 *
 */
#define R_DISABLE_COPY(aclass) \
  aclass(const aclass &); \
  aclass & \
  operator =(const aclass &);

#define R_MAKE_VERSION(major, minor, micro) \
  (((major) << 24) | ((minor) << 16) | ((micro) << 0))

#define _R_MAKE_VERSION_TEXT0(major, minor, \
                              micro) #major "."#minor "."#micro
#define _R_MAKE_VERSION_TEXT1(major, minor, \
                              micro) _R_MAKE_VERSION_TEXT0(major, \
                                                           minor, \
                                                           micro)
#define R_MAKE_VERSION_TEXT(major, minor, micro) \
  _R_MAKE_VERSION_TEXT1(major, minro, micro)

#endif // __INCLUDED_C140043A425411E6A04700F1F38F93EF
