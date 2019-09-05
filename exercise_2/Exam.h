//
// Created by cdd on 16.07.19.
//

#ifndef EXERCISE_2_EXAM_H
#define EXERCISE_2_EXAM_H

#include "IRecord.h"
#include <string>


class Exam : public IRecord {

private:
    int _id;
    int _courseId;
    int _studentId;
    int _result;
public:
    Exam(const int &id,const int &courseId,const int &studentId,const int &result);
    int getId() const override ;
    std::string getFormatted() const override ;

};
#endif //EXERCISE_2_EXAM_H
