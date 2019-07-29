//
// Created by cdd on 16.07.19.
//

#include "Exam.h"
#include <sstream>


Exam::Exam(const int &id,const int &courseId,const int &studentId,const int &result):_id(id),_courseId{courseId},_studentId{studentId},_result{result} {
}
int Exam::getId() const {
    return _id;
}

std::string Exam::getFormatted() const {
    std::ostringstream  formatedData;
    formatedData << _id  << _courseId  << _studentId  << _result;
    return formatedData.str();
}
