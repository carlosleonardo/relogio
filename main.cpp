#include <iostream>
#include <chrono>

int main()
{

    try
    {
        auto now = std::chrono::system_clock::now();
        auto zone = std::chrono::zoned_time(std::chrono::current_zone(), now);

        std::cout << std::format("{:%H:%M:%S}", zone) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
