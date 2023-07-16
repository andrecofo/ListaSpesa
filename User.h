//
// Created by cofon on 16/07/2023.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include <string>
#include <vector>
#include "Observer.h"
#include "Products.h"
#include "List.h"

class User : public Observer{
private:
    std::string name;
    std::vector<List*> lists;
    std::unordered_map<std::string, int> productsToBuy;
public:
    User(const std::string& name) : name(name){}

    void createList(const std::string& listName){
        List* newList=new List(listName);
        lists.push_back(newList);
        newList->attach(this);
    }

    void addProductToList(const std::string& listName, const std::string productName, int quantity = 1){
        for(const auto& l : lists){
            if(l->getName()==listName){
                l->addProduct(productName, quantity);
                break;
            }
        }
    }

    void removeProductFromList(const std::string& listName, const std::string productName){
        for(const auto& l : lists){
            if(l->getName()==listName){
                l->removeProduct(productName);
                break;
            }
        }
    }

    void update(const std::unordered_map<std::string,int>& productsToBuyUpdated) override{
        this->productsToBuy=productsToBuyUpdated;

        std::cout<<"Prodotti da acquistare:"<<std::endl;
        for(const auto& p : productsToBuy){
            std::cout<<"Prodotto: "<<p.first<<"| Quantità: "<<p.second<<std::endl;
        }
    }
};
#endif //LISTASPESA_USER_H
