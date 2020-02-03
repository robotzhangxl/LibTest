// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 LIBTEST2_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// LIBTEST_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#pragma once
#ifdef LIBTEST_EXPORTS
#define LIBTEST_API __declspec(dllexport)
#else
#define LIBTEST_API __declspec(dllimport)
#endif



// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" LIBTEST_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" LIBTEST_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" LIBTEST_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" LIBTEST_API unsigned fibonacci_index();
extern "C" LIBTEST_API int add(int a, int b);


typedef struct _NRC_RobotDHConfig
{
    double L1; ///<L1杆长
    double L2; ///<L2杆长
    double L3; ///<L3杆长
    double L4; ///<L4杆长
    double L5; ///<L5杆长
    double L6; ///<L6杆长
    double L7; ///<L7杆长
    double theta; ///<5轴方向，仅对六轴机器人有效，参数可选：0、90
    double CoupleCoe12; ///<1/2轴耦合比
    double CoupleCoe23; ///<2/3轴耦合比
    double CoupleCoe32; ///<3/2轴耦合比
    double CoupleCoe34; ///<3/4轴耦合比
    double CoupleCoe45; ///<4/5轴耦合比
    double CoupleCoe46; ///<4/6轴耦合比
    double CoupleCoe56; ///<5/6轴耦合比
}NRC_RobotDHConfig;

typedef struct _NRC_Robot
{
    int id;
    char name[10];
    NRC_RobotDHConfig dhConfig;

}NRC_Robot;

extern "C" LIBTEST_API NRC_Robot* createRobot(char name[10]);

extern "C" LIBTEST_API NRC_RobotDHConfig createRobotConfig(double L1,double L2,double CoupleCoe12);

extern "C" LIBTEST_API int move();

extern "C" LIBTEST_API int setRobotConfig(NRC_Robot* robot,NRC_RobotDHConfig config);