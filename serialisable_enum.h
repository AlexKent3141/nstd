#include <string>
#include <vector>
#include <stdexcept>

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

    value(std::string&& repr) : repr_(repr)
    {
      serialisable_enum<EnumType>::str_values_.push_back(*this);
    }

    std::string to_string() const
    {
      return repr_;
    }

  private:
    std::string repr_;
  };

  static serialisable_enum<EnumType>::value from_string(
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

private:
  static std::vector<serialisable_enum<EnumType>::value> str_values_;
};

}
