#include "String.h"
#include <iostream>

int main()
{
    String Test;
    std::cin >> Test;
    std::cout << Test << "\n";
    String Test_time("God");
    std::cout << Test_time << "\n";
    String Test_help(Test);
    std::cout << Test_help << "\n";
    Test = Test_time;
    std::cout << Test << "\n";
    if (Test == Test_help)
    {
        std::cout << "true" << "\n";
    }
    else
    {
        std::cout << "false" << "\n";
    }
    if (Test == Test_time)
    {
        std::cout << "true" << "\n";
    }
    else
    {
        std::cout << "false" << "\n";
    }
    std::cout << Test.Size() << "\n";
    std::cout << Test.Find(Test_help) << "\n";
    std::cout << Test.Find(Test_time) << "\n";
    Test.Change('d', 't');
    std::cout << Test << "\n";
    std::cout << Test[2] << "\n";
    return 0;
}
