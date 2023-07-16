//
// Created by cofon on 16/07/2023.
//

#ifndef LISTASPESA_PRODUCTS_H
#define LISTASPESA_PRODUCTS_H

#include <string>

class Products{
private:
    std::string name;
    int quantity;
public:
    Products(const std::string& name, int quantity) : name(name), quantity(quantity){}

    const std::string &getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Products::quantity = quantity;
    }

};
#endif //LISTASPESA_PRODUCTS_H
