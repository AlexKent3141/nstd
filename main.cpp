#include "serialisable_enum.h"

#include <string>
#include <iostream>

using namespace nstd;

struct Fish;

template <>
std::vector<serialisable_enum<Fish>::value> serialisable_enum<Fish>::str_values_ =
  std::vector<serialisable_enum<Fish>::value>();

struct Fish : public serialisable_enum<Fish>
{
  static inline Fish::value Minnow = Fish::value("minnow");
  static inline Fish::value Shark = Fish::value("shark");
};

int main()
{
  std::cout << Fish::Minnow.to_string() << std::endl;

  Fish::value shark = Fish::Shark;
  std::cout << shark.to_string() << std::endl;

  Fish::value minnow = Fish::from_string("minnow");
  std::cout << minnow.to_string() << std::endl;

  return 0;
}
