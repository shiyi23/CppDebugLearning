#include "Student.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Student stu("ZhangSan", 12);
    std::cout << "student's name: " << stu.getName() << ", student's age: " 
    << stu.getAge() << std::endl;
    return 0;
}


