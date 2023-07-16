//
// Created by cofon on 16/07/2023.
//

#ifndef LISTASPESA_SUBJECT_H
#define LISTASPESA_SUBJECT_H

#include "Observer.h"

class Subject{
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    virtual void notify() = 0;
};
#endif //LISTASPESA_SUBJECT_H
