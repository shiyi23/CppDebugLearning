#include "Student.h"

Student::Student(){};
Student::~Student(){};

Student::Student(std::string name, int age) {
    this->name = name;
    this->age = age;
};

std::string Student::getName() {
    return this->name;
}

int Student::getAge() {
    return this->age;
}












