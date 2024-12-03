#include <iostream>
#include <chrono>
#include <fmt/format.h>
#include <thread>

int main()
{

    try
    {
        while (true)
        {
            auto now = std::chrono::system_clock::now();
            auto zone = std::chrono::zoned_time(std::chrono::current_zone(), now);

            const auto formatado = std::format("{:%H:%M:%S}", zone);
            fmt::print("\rHorário: {}", formatado);
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
