#ifndef __INCLUDED_675A3F04598211E6AA6EA088B4D1658C
#define __INCLUDED_675A3F04598211E6AA6EA088B4D1658C

#include "RRawPointer.h"
#include <WString.h>
#include <Printable.h>

class RFlashString
{
private:
  typedef class __FlashStringHelper ValueType;

public:
  RFlashString();
  RFlashString(const ValueType *flashStr);
  ~RFlashString();

  ValueType *
  data()
  {
    return mStr.data();
  }

  bool
  isNull()
  {
    return mStr.isNull();
  }

  operator ValueType*()
  {
      return data();
  }

  /// Support if(flashStr) style
  operator bool()
  {
    return mStr;
  }

private:
  RRawPointer<ValueType> mStr;
};

#endif // __INCLUDED_675A3F04598211E6AA6EA088B4D1658C