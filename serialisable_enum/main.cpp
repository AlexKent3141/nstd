#include "serialisable_enum.h"

#include <iostream>
#include <string>

#include <cassert>

/* Equivalent non-macro code
struct Fish;

// Need to explicitly provide a specialisation of the values cache
//  for the new enum type.
template <>
std::vector<nstd::serialisable_enum<Fish>::value>
  nstd::serialisable_enum<Fish>::str_values_ =
    std::vector<nstd::serialisable_enum<Fish>::value>();

struct Fish : public nstd::serialisable_enum<Fish>
{
  static inline Fish::value Minnow = Fish::value("minnow", 0);
  static inline Fish::value Shark = Fish::value("shark");
  static inline Fish::value Dolphin = Fish::value("dolphin", 10);
  static inline Fish::value Barracuda = Fish::value("barracuda", 1);
  static inline Fish::value Tuna = Fish::value("tuna");
};
*/

SERIALISABLE_ENUM(Fish)
  SERIALISABLE_ENUM_VALUE_ID(Fish, Minnow, minnow, 0)
  SERIALISABLE_ENUM_VALUE(Fish, Shark, shark)
  SERIALISABLE_ENUM_VALUE_ID(Fish, Dolphin, dolphin, 10)
  SERIALISABLE_ENUM_VALUE_ID(Fish, Barracuda, barracuda, 1)
  SERIALISABLE_ENUM_VALUE(Fish, Tuna, tuna)
SERIALISABLE_ENUM_END

std::ostream& operator<<(std::ostream& os, const Fish::value& fish)
{
  os << fish.to_string();
  return os;
}

int main()
{
  std::cout << Fish::Minnow << std::endl;

  Fish::value shark = Fish::Shark;
  std::cout << shark << std::endl;

  Fish::value minnow = Fish::from_string("minnow");
  std::cout << minnow << std::endl;

  int tuna = static_cast<int>(Fish::Tuna);
  std::cout << tuna << std::endl;

  Fish::value dolphin = Fish::value(10);
  std::cout << dolphin << std::endl;

  assert(dolphin == Fish::Dolphin);

  return 0;
}
