//
// Created by cdd on 16.07.19.
//

#include "Teacher.h"
#include <sstream>
#include <string>


Teacher::Teacher(const int &id,std::string &name):_id(id),_name(name) {
}
int Teacher::getId() const {
    return _id;
}
std::string  Teacher::getName() const {
    return _name;
}
std::string Teacher::getFormatted() const {
    std::ostringstream  formatedData;
    formatedData << _id << _name;
    return formatedData.str();
}