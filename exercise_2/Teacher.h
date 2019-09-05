//
// Created by cdd on 16.07.19.
//

#ifndef EXERCISE_2_TEACHER_H
#define EXERCISE_2_TEACHER_H

#include <string>
#include "IRecord.h"
#include "IPerson.h"

class Teacher : public IRecord, public IPerson{
private:
    int _id;
    std::string _name;
public:
    Teacher(const int &id,std::string &_name);
    int getId() const override ;
    std::string getName() const override ;
    std::string getFormatted() const override ;
};



#endif //EXERCISE_2_TEACHER_H
