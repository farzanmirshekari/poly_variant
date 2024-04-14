#ifndef poly_variant_h_INCLUDED
#define poly_variant_h_INCLUDED

#include <variant>

template <typename Base, typename... Derived>
class poly_variant
{
public:
    poly_variant() = default;

    template <typename T>
    poly_variant(const T& value) : data(value) {}

    Base* operator->()
    {
        return std::visit([](auto& value) -> Base* { return &value; }, data);
    }
    
private:
    std::variant<Derived...> data;
};

#endif