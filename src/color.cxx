#include "color.hxx"

std::ostream &pi::rtm::operator <<(std::ostream &os, color_t const &c)
{
    return os << static_cast<int>(std::round(255.0 * c.r)) << ' '
              << static_cast<int>(std::round(255.0 * c.g)) << ' '
              << static_cast<int>(std::round(255.0 * c.b));
}
