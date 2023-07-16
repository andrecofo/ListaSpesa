//
// Created by cofon on 16/07/2023.
//

#ifndef LISTASPESA_LIST_H
#define LISTASPESA_LIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Subject.h"
#include "Products.h"

class List : public Subject{
private:
    std::string name;
    std::vector<Products> products;
    std::vector<Observer*> observers;
public:
    List(std::string name) : name(name){}

    void addProduct(std::string name, int quantity){
        for(auto p : products){
            if(p.getName() == name){
                p.setQuantity(p.getQuantity()+quantity);
                notify();
            }
        }
        Products newProduct(name, quantity);
        products.push_back(newProduct);
        notify();
    }

    void removeProduct(std::string name, int quantity){
        for(auto pr=products.begin(); pr!=products.end(); pr++){
            if(pr->getName()==name){
                products.erase(pr);
                notify();
                break;
            }
        }
    }

    void updateQuantity(std::string name, int quantity){
        for(auto p : products){
            if(p.getName() == name){
                p.setQuantity(p.getQuantity()+quantity);
                if(p.getQuantity()<0)
                    p.setQuantity(0);
                notify();
            }
        }
    }

    void display(){
        std::cout<<"Lista della spesa" << std::endl;
        for(auto p : products){
            std::cout<<"Prodotto: "<<p.getName()<<" | Quantità: "<<p.getQuantity()<<std::endl;
        }
    }

    virtual void attach(Observer* obs) override{
        observers.push_back(obs);
    }

    virtual void detach(Observer* obs) override{
        for(auto o=observers.begin(); o!=observers.end(); o++) {
            if(*o==obs) {
                observers.erase(o);
                break;
            }
        }
    }


    void notify() override{
        for(auto o : observers)
            o->update();
    }

};
#endif //LISTASPESA_LIST_H
