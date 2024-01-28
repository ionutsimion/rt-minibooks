#include <iostream>

#include "color.hxx"

int main()
{
    auto static constexpr image_width = 512UL;
    auto static constexpr image_height = 512UL;

    std::cout << "P3\n" << image_width * 3UL << ' ' << image_height << "\n255\n";

    using pi::rtm::color_t;
    for (auto row = 0UL, progress = 101UL; row < image_height; ++row)
    {
        if (auto const new_progress = static_cast<int>(100.0 * (row + 1.0) / image_height); new_progress != progress)
            std::clog << "\rRendering: " << (progress = new_progress) << "%..." << std::flush;

        for (auto column = 0UL; column < image_width; ++column)
            std::cout << color_t((column + 1.0) / image_width, (row + 1.0) / image_height, 0) << '\n';
        for (auto column = 0UL; column < image_width; ++column)
            std::cout << color_t((column + 1.0) / image_width, 0, (row + 1.0) / image_height) << '\n';
        for (auto column = 0UL; column < image_width; ++column)
            std::cout << color_t(0, (column + 1.0) / image_width, (row + 1.0) / image_height) << '\n';
    }
    std::clog << "\rDone!             \n";
}
