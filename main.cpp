#include "Student.h"
// #include "Teacher.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Student stu("ZhangSan", 12);
    // Teacher tea("LiMing", 45);
    std::cout << "student's name: " << stu.getName() << ",student's age: " 
    << stu.getAge() << std::endl;
    // std::cout << "teacher's name: " << tea.getName() << ",teacher's age:" << tea.getAge() << std::endl;
    return 0;
}


