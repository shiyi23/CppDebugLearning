//Teacher.h
#include <string>

class Teacher
{
private:
    /* data */
    std::string name;
    int age;
public:
    Teacher(/* args */);
    Teacher(std::string name, int age);
    std::string getName();
    int getAge();
    ~Teacher();
};