//
// Created by wikto on 04.06.2024.
//

#ifndef TEXT_GAME_BSO_PLAYER_H
#define TEXT_GAME_BSO_PLAYER_H


#include <string>
#include <map>
class Player{
public:
    std::string name;
    int health;
    int xp;
    std::string inventory[10];  // An array of strings for the player's inventory
    int inventoryCount = 0;
    std::map<std::string, int> skills;
    Player(std::string name, int health, int xp){
        this->name = name;
        this->health = health;
        this->xp = xp;
    }


    void showInventory() const {
        std::cout << name << "'s Inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item << std::endl;
        }
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
    void buyItem(const std::string& item, int requirements){
        if (requirements<= xp){
            addItem(item);
        }
        else{
            std::cout<<"Level too low"<<std::endl;
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
