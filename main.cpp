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
#if __GNUC__ > 11
            auto zone = std::chrono::zoned_time(std::chrono::current_zone(), now);

            const auto formatado = std::format("{:%H:%M:%S}", zone);
            fmt::print("\rHorário: {}", formatado);
#else
            auto time = std::chrono::system_clock::to_time_t(now);
            auto local_time = *std::localtime(&time);

            fmt::print("\rHorário: {:02d}:{:02d}:{:02d}",
                       local_time.tm_hour,
                       local_time.tm_min,
                       local_time.tm_sec);
#endif
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
