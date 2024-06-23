//
// Created by wikto on 04.06.2024.
//

#ifndef TEXT_GAME_BSO_DRAGON_H
#define TEXT_GAME_BSO_DRAGON_H


#include <string>
#include <iostream>
class Dragon {
public:
    std::string type;
    std::string specialAbility;
    float powerMultiplier;
    int dragonHealth;

    Dragon(const std::string& dragonType, const std::string& ability, float multiplier, int health)
            : type(dragonType), specialAbility(ability), powerMultiplier(multiplier), dragonHealth(health) {}

    void attack() const {
        std::cout << "The " << type << " dragon have " << specialAbility << " ability. Wow that's insane!" << std::endl;
    }

    void showHealth(){
        std::cout<<"WOW Remain health: "<<dragonHealth<<"\n"<<std::endl;
    }

    bool checkIfDragonAlive(){
        //if alive return true
        return dragonHealth>0;
    }
    void takeDamage(int damage){
        dragonHealth -=damage;
        if(!checkIfDragonAlive())
            printf("Dragon died, nice");
        else {
            printf("Try harder\n");
            std::cout<<"Remain health: "<<dragonHealth<<"\n"<<std::endl;
            printf("");

        }

    }
};


#endif //TEXT_GAME_BSO_DRAGON_H
