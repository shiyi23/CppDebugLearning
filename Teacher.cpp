#include "Teacher.h"

Teacher::Teacher(){};
Teacher::~Teacher(){};

Teacher::Teacher(std::string name, int age){
    this->name = name;
    this->age = age;
};

std::string Teacher::getName() {
    return this->name;
};

int Teacher::getAge() {
    return this->age;
};