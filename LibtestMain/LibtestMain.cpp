// LibtestMain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../LibTest/LibTest.h"


void test()
{
    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
    " Fibonacci sequence values fit in an " <<
    "unsigned 64-bit integer." << std::endl; 
}

int main()
{
    std::cout << "Hello World!\n";
    //test();
    createRobotConfig(1, 2, 3);
}
