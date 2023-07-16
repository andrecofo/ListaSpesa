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
public:
    const std::string &getName() const {
        return name;
    }

    const std::vector<Products> &getProducts() const {
        return products;
    }

    const std::unordered_map<Observer *, std::unordered_map<std::string, int>> &getSharedLists() const {
        return sharedLists;
    }

private:
    std::vector<Products> products;
    std::unordered_map<Observer*,std::unordered_map<std::string,int>> sharedLists;
public:
    List(std::string name) : name(name){}

    void addProduct(const std::string& product, int quantity){
        for(auto p : products){
            if(p.getName() == product){
                p.setQuantity(p.getQuantity()+quantity);
                notify();
            }
        }
        Products newProduct(product, quantity);
        products.push_back(newProduct);
        notify();
    }

    void removeProduct(const std::string& product){
        for(auto pr=products.begin(); pr!=products.end(); pr++){
            if(pr->getName() == product){
                products.erase(pr);
                notify();
                break;
            }
        }
    }

    void updateQuantity(const std::string& product, int quantity){
        for(auto p : products){
            if(p.getName() == product){
                p.setQuantity(p.getQuantity()+quantity);
                if(p.getQuantity()<0)
                    p.setQuantity(0);
                notify();
            }
        }
    }

    void display(){
        std::cout<<"Lista della spesa" << std::endl;
        for(const auto& p : products){
            std::cout<<"Prodotto: "<<p.getName()<<" | Quantità: "<<p.getQuantity()<<std::endl;
        }
    }

    virtual void attach(Observer* obs) override{
        sharedLists[obs] = createItemsToBuyMap();
    }

    virtual void detach(Observer* obs) override{
        sharedLists.erase(obs);
    }

    void notify() override{
        for(auto [observers, productsToBuy] : sharedLists){
            productsToBuy.clear();
            productsToBuy=createItemsToBuyMap();
            observers->update(productsToBuy);
        }
    }

    std::unordered_map<std::string, int> createItemsToBuyMap() {
        std::unordered_map<std::string, int> productsToBuy;

        for(const auto& p : products){
            if(p.getQuantity() > 0){
                productsToBuy[p.getName()]=p.getQuantity();
            }
        }
        return productsToBuy;
    }

};
#endif //LISTASPESA_LIST_H
