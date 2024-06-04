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

    Dragon(const std::string& dragonType, const std::string& ability)
            : type(dragonType), specialAbility(ability) {}

    void attack() const {
        std::cout << "The " << type << " dragon have " << specialAbility << " ability. Wow that's insane!" << std::endl;
    }
};


#endif //TEXT_GAME_BSO_DRAGON_H
