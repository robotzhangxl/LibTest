// LibTest2.cpp : 定义 DLL 的导出函数。
//

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "LibTest.h"

#include  <stdio.h>
#include <pybind11/pybind11.h>

#include <iostream>

namespace py = pybind11;
// DLL internal state variables:
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
void fibonacci_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // see special case when initialized

}

// Produce the next value in the sequence.
// Returns true on success, false on overflow.
bool fibonacci_next()
{
    // check to see if we'd overflow result or position
    if ((ULLONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }

    // Special case when index == 0, just return b value
    if (index_ > 0)
    {
        // otherwise, calculate next sequence value
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
    return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
    return index_;
}

int add(int i, int j) {
    return i + j;

}
NRC_RobotDHConfig config;
int createRobotConfig(double L1, double L2, double L3)
{
    //NRC_RobotDHConfig config;

    config.L1 = L1;
    config.L2 = L2;
   config.L3 = L3;
    std::cout << config.L1 << config.L2 << config.L3 << std::endl;
    std::cout << "createRobotConfig\n";
    printf("Create\n");
   // return config;
    return 0;
}

PYBIND11_MODULE(libtest, m) {
    m.doc() = "pybind11 libpytest plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
}