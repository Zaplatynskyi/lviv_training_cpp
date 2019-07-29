//
// Created by cdd on 16.07.19.
//
#include "Student.h"
#include <sstream>
#include <string>

Student::Student(const int &id,std::string &name):_id(id),_name(name) {
}
int Student::getId() const {
    return _id;
}
std::string  Student::getName() const {
    return _name;
}
std::string Student::getFormatted() const {
    std::ostringstream  formatedData;
    formatedData << _id << _name;
    return formatedData.str();
}