#include <iostream>
#include <chrono>
#include <fmt/format.h>

int main()
{

    try
    {
        auto now = std::chrono::system_clock::now();
        auto zone = std::chrono::zoned_time(std::chrono::current_zone(), now);

        const auto formatado = std::format("{:%H:%M:%S}", zone);
        fmt::print("Horário: {}\n", formatado);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
