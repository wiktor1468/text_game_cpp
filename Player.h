//
// Created by wikto on 04.06.2024.
//

#ifndef TEXT_GAME_BSO_PLAYER_H
#define TEXT_GAME_BSO_PLAYER_H


#include <string>
#include <map>
#include <algorithm> // for std::find
class Player{
public:
    std::string name;
    float health;
    int xp;
    std::string inventory[10];  // An array of strings for the player's inventory
    int inventoryCount = 0;
    int gold;
    std::map<std::string, int> skills;
    Player(const std::string name, float health, int xp, int gold){
        this->name = name;
        this->health = health;
        this->xp = xp;
        this->gold = gold;

    }


    void showInventory() const {
        std::cout << name << "'s Inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item << std::endl;
        }
    }
    void showGold() const{
        std::cout << "You have "<<gold<<"gold"<<std::endl;
    }

    void showSkills() const {
        std::cout << name << "'s Skills:" << std::endl;
        for (const auto& skill : skills) {
            std::cout << "- " << skill.first << ": Level " << skill.second << std::endl;
        }
    }
    //inventory validation
    bool checkIfFull() const {
        return inventoryCount >= 10;
    }

    void addItem(const std::string& item) {
        if (!checkIfFull()) {
            inventory[inventoryCount] = item;
            inventoryCount++;
            std::cout << item << " has been added to your inventory." << std::endl;
        } else {
            std::cout << "Inventory is full! Cannot add " << item << "." << std::endl;
        }
    }
    void buyItem(const std::string& item, int requiredXP, int price){
        if (requiredXP<= xp  && price <=gold){
            addItem(item);
        }
        else{
            std::cout<<"Level too low"<<std::endl;
        }

    }


    void sellItem(const std::string& item) {
        //return the index of found value or __last if value hasn't been found
        auto possibleItem = std::find(std::begin(inventory), std::end(inventory), item);
        if (possibleItem != std::end(inventory)) {
            std::cout << "Item found in inventory." << std::endl;
            // removing item from array
            *possibleItem = "";
            std::cout << "Item sold and removed from inventory." << std::endl;
        } else {
            std::cout << "Item not found in inventory." << std::endl;
        }
    }

    void damageTaken(int damage){
        if(health-damage<1){
            std::cout <<  "You died. That's very sad, goodbye" << std::endl;
            exit(0);
        }
        else{
            health-=damage;
        }
    }

    void showHealth()
    {
        std::cout<<"Your health: "<< health <<std::endl;
    }
};


#endif //TEXT_GAME_BSO_PLAYER_H
