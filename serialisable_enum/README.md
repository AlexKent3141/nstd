# Serialisable Enum
The `serialisable_enum` header file contains my attempt at a strongly-typed enum which has a built-in ability to be serialised and de-serialised.

The main drawback of this new class is the way it has to be initialised. You need to explicitly provide a template specialisation of the values cache for each new enum type. This downside has been partly negated by introducing macros which streamline this process.

Setting aside initialisation, this new enum type is close to being a drop-in replacement for standard `enum class`. The main difference is that values in the enum have a different type to the enum itself: the enum type is more like a factory for creating its values. This means that you end up passing around `enum::value` types.

If you want to see this in action take a look at `example.cpp` which also shows a comparison of enum initialisation with & without macros.
