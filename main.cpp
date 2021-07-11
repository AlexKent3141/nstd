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
  static inline Fish::value Minnow = Fish::value("minnow", 0);
  static inline Fish::value Shark = Fish::value("shark");
  static inline Fish::value Dolphin = Fish::value("dolphin", 10);
  static inline Fish::value Barracuda = Fish::value("barracuda", 1);
  static inline Fish::value Tuna = Fish::value("tuna");
};

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

  return 0;
}
