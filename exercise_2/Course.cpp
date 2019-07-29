//
// Created by cdd on 16.07.19.
//

#include "Course.h"
#include <string>
#include <sstream>


Course::Course(const int &id,const std::string &name,const int &teacherId):_id(id),_name{name},_teacherId{teacherId} {
}
int Course::getId() const {
    return _id;
}

std::string Course::getFormatted() const {
    std::ostringstream  formatedData;
    formatedData << _id << _name << _teacherId;
    return formatedData.str();
}
