//
// Created by cdd on 22.07.19.
//

#ifndef EXERCISE_2_IRECORD_H
#define EXERCISE_2_IRECORD_H
#include <string>

class IRecord
{
public:
    virtual int getId() const  = 0;
    virtual std::string getFormatted() const = 0;
    virtual ~IRecord() = default;
};
#endif //EXERCISE_2_IRECORD_H
