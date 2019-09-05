//
// Created by cdd on 16.07.19.
//

#ifndef EXERCISE_2_COURSE_H
#define EXERCISE_2_COURSE_H
#include "IRecord.h"
#include <string>



class Course : public IRecord {

private:
    int _id;
    std::string _name;
    int _teacherId;
public:
    Course(const int &id,const std::string  &_name,const int &_teacherId);
    int getId() const override ;
    std::string getFormatted() const override ;

};
#endif //EXERCISE_2_COURSE_H
