#ifndef __SERIALISABLE_ENUM_INCLUDED__
#define __SERIALISABLE_ENUM_INCLUDED__ 

#include <stdexcept>
#include <string>
#include <vector>

namespace nstd
{

template <typename EnumType>
struct serialisable_enum
{
public:
  class value
  {
  public:
    value() = delete;
    value(std::string&&);
    value(std::string&&, int);

    // Explicit conversions.
    explicit value(int);
    inline explicit operator int() const { return id_; }

    inline std::string to_string() const { return repr_; }

  private:
    using enum_type = serialisable_enum<EnumType>;
    int id_ = 0;
    std::string repr_;
  };

  static serialisable_enum<EnumType>::value from_string(const std::string&);

private:
  static std::vector<serialisable_enum<EnumType>::value> str_values_;
};

template <typename EnumType>
serialisable_enum<EnumType>::value::value(
  std::string&& repr)
:
  repr_(repr)
{
  // Infer the id of this element by looking at the latest element.
  if (!enum_type::str_values_.empty())
  {
    id_ = enum_type::str_values_.back().id_ + 1;
  }

  enum_type::str_values_.push_back(*this);
}

template <typename EnumType>
serialisable_enum<EnumType>::value::value(
  std::string&& repr, int id)
:
  repr_(repr), id_(id)
{
  enum_type::str_values_.push_back(*this);
}

template <typename EnumType>
serialisable_enum<EnumType>::value::value(
  int id)
:
  repr_(std::string{}), id_(id)
{
  for (const auto& val : enum_type::str_values_)
  {
    if (val.id_ == id)
    {
      repr_ = val.repr_;
    }
  }

  if (repr_ == std::string{})
  {
    throw std::exception();
  }
}

template <typename EnumType>
typename serialisable_enum<EnumType>::value
  serialisable_enum<EnumType>::from_string(
    const std::string& repr)
{
  for (const auto& val : serialisable_enum<EnumType>::str_values_)
  {
    if (val.to_string() == repr)
    {
      return val;
    }
  }

  throw std::exception();
}

} // namespace nstd

#endif // __SERIALISABLE_ENUM_INCLUDED__
