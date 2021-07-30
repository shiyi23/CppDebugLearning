//Student.h
#include <string>

class Student
{
private:
    /* data */
    std::string name;
    int age;
public:
    Student(/* args */);
    Student(std::string name, int age);
    std::string getName();
    int getAge();
    ~Student();
};
