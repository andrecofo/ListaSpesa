//
// Created by cofon on 16/07/2023.
//

#ifndef LISTASPESA_OBSERVER_H
#define LISTASPESA_OBSERVER_H

#include <unordered_map>
#include <string>

class Observer{
public:
    virtual void update(const std::unordered_map<std::string, int>&itemsToBuy) = 0;
};
#endif //LISTASPESA_OBSERVER_H
