#include <iostream>
#include <chrono>
#include <date/date.h>
#include <date/tz.h>

int main()
{

    try
    {
        auto now = std::chrono::system_clock::now();
        auto zone = date::locate_zone("America/Sao_Paulo");
        auto zoned_time = date::make_zoned(zone, now);
        auto local_time = zoned_time.get_local_time();
        std::cout << date::format("%T", zoned_time) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
