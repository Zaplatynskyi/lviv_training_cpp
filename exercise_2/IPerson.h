//
// Created by cdd on 22.07.19.
//

#ifndef EXERCISE_2_IPERSON_H
#define EXERCISE_2_IPERSON_H
#include <string>

class IPerson
{
public:
    virtual std::string getName() const = 0;
    virtual ~IPerson() = default;
};
#endif //EXERCISE_2_IPERSON_H
