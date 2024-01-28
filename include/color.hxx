#ifndef COLOR_HXX
#define COLOR_HXX

#include <iostream>

namespace pi::rtm
{
    struct color_t
    {
        double r{};
        double g{};
        double b{};
        double a{ 1.0 };
    };

    auto operator <<(std::ostream &, color_t const &) -> std::ostream &;
} // namespace pi::rtm

#endif //COLOR_HXX
