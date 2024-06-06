#include <iostream> // Include the I/O stream library for input and output
#include "Player.h"
#include "Dragon.h"
#include "random"

int exploreStage=0;
void interactWithNPC(const std::string& npcName, Player* player) {
    std::cout << npcName << ": Hello, " << player->name << "! I've heard about your bravery." << std::endl;
    std::cout << npcName << ": Would you like a special tool to help in your fight against the dragons?" << std::endl;
    std::cout << "1. Yes\n2. No" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << npcName << ": Here, take this Dragon Slayer's Axe. It will help you in battles." << std::endl;
        player->addItem("Dragon Slayer's Axe");
        player->inventoryCount++;
    } else {
        std::cout << npcName << ": Very well. Stay safe out there!" << std::endl;
    }
    exploreStage++;
}

void rescueMission(Player* player) {
    std::cout << "You have been called to rescue civilians trapped in a burning building!" << std::endl;
    std::cout << "You can use your tools to help them." << std::endl;
    std::cout << "1. Use water hose\n2. Use fire extinguisher\n3. Use axe to clear debris" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "You use the water hose to douse the flames and create a path for the civilians to escape." << std::endl;
        player->xp += 10;
        std::cout << "Experience gained: 10" << std::endl;
    } else if (choice == 2) {
        std::cout << "You use the fire extinguisher to control the fire around the civilians, helping them to escape safely." << std::endl;
        player->xp += 10;
        std::cout << "Experience gained: 10" << std::endl;
    } else if (choice == 3) {
        std::cout << "You use the axe to clear debris and create an escape route for the civilians." << std::endl;
        player->xp += 10;
        std::cout << "Experience gained: 10" << std::endl;
    } else {
        std::cout << "Invalid choice, you lost valuable time!" << std::endl;
        player->health -= 10;
        std::cout << "Health lost: 10" << std::endl;
    }
    exploreStage++;
}

void exploreLocation(const std::string& location, Player* player) {
    std::cout << "Exploring " << location << "..." << std::endl;
    if (location == "Moonlight Markets") {
        std::cout << "You see a variety of vendors selling mystical items." << std::endl;
        interactWithNPC("Merchant", player);
        std::cout << "Someone is selling some refreshing beer. Wanna taste?"<<std::endl;
        std::cout << "1. Yes\n2. No" << std::endl;
        int nestedChoice;
        std::cin >> nestedChoice;
        if (nestedChoice == 2) {
            std::cout << "Remaining silent, " << player->name << " decide not to drink some beer, so nothing happens." << std::endl;
        } else if (nestedChoice == 1) {

            std::cout << "Singing along, a merfolk surfaces and gifts " << player->name << " new element to inventory" << std::endl;
            player->addItem("quality beer");
            player->skills["Firefighting"] += 1;

        }

    } else if (location == "Grand Library") {
        std::cout << "You find ancient texts about dragons and firefighting techniques." << std::endl;
        player->skills["Firefighting"] += 1;
        std::cout << "Your firefighting skills have improved!" << std::endl;
    } else if (location == "Shimmering Lake") {
        std::cout << player->name << " arrives at Shimmering Lake. It is one of the most beautiful lakes that " << player->name << " has seen. They hear a mysterious melody from the water. They can either: " << std::endl;
        std::cout << "1. Stay quiet and listen\n2. Sing along with the melody" << std::endl;
        int nestedChoice;
        std::cin >> nestedChoice;
        if (nestedChoice == 1) {
            std::cout << "Remaining silent, " << player->name << " hears whispers of the merfolk below, but nothing happens." << std::endl;
        } else if (nestedChoice == 2) {
            std::cout << "Singing along, a merfolk surfaces and gifts " << player->name << " a special blue parrot as a token of appreciation for their voice." << std::endl;
            player->addItem("Blue parrot:D");
        }
    }
    exploreStage++;
}


void fightDragon(Player* player) {

    //array of Dragons to choose random Dragon to fight innteraction
    Dragon dragons[]={
            Dragon("Fire", "Flame Burst"),
            Dragon("Bad","Unwanted thoughts"),
            Dragon("Sus","none:p")
    };
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,3); // distribution in range [1, 3]


    Dragon RandomDragon = dragons[dist6(rng)];
    std::cout << "A wild " << RandomDragon.type << " dragon appears!" << std::endl;
    RandomDragon.attack();
    std::cout << "You can either:" << std::endl;
    std::cout << "1. Use water hose\n"
                 "2. Use Dragon Slayer's Axe\n"
                 "3. Use fire extinguisher\n"
                 "4. Use Water pump"
              << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "You use the water hose to weaken the dragon's flames." << std::endl;
        player->xp += 20;
        std::cout << "Experience gained: 20" << std::endl;
    } else if (choice == 2) {
        std::cout << "You use the Dragon Slayer's Axe to strike at the dragon. It's very effective!" << std::endl;
        player->xp += 30;
        std::cout << "Experience gained: 30" << std::endl;
    } else if (choice == 3) {
        std::cout << "You use the fire extinguisher to douse the dragon's flames. It's moderately effective." << std::endl;
        player->xp += 10;
        std::cout << "Experience gained: 10" << std::endl;
    } else if (choice==4 && player->xp >20){
        std::cout << "You use the water pump to avoid  dragon's flames. It's pretty dope." << std::endl;
        player->xp += 40;
        std::cout << "Experience gained: 40" << std::endl;

    }
    else if (choice==4 && player->xp <=20)
    {
        std::cout << "You  can't use the water pump to avoid  dragon's flames. It's sad but your exp is too low." << std::endl;
        fightDragon(player);
    }
    else {
        std::cout << "Invalid choice, the dragon attacks you!" << std::endl;
        player->health -= 20;
        std::cout << "Health lost: -20" << std::endl;
        player->damageTaken(20);
    }
    exploreStage++;
}


//finall boss

//battleWithBoss

void battleWithBoss(Player* player, bool isSecondRound = false) {
    if (isSecondRound) {
        std::cout << "The big boss wants a second run!" << std::endl;
    } else {
        Dragon FinallDragon("Boss", "all");
        std::cout << "An ultimately wild " << FinallDragon.type << " dragon appears! Wow, he is so strong" << std::endl;
        FinallDragon.attack();

        player->damageTaken(20);
        std::cout << "He is so strong that you lose health just by looking at him" << std::endl;
        std::cout << "Health lost: -20" << std::endl;
    }

    std::cout << "You can either:" << std::endl;
    std::cout << "1. Use water hose\n"
              << "2. Use Dragon Slayer's Axe\n"
              << "3. Use fire extinguisher\n"
              << "4. Use Water pump\n"
              << "5. Use power of friendship" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "You use the water hose to weaken the dragon's flames." << std::endl;
            player->xp += 50;
            std::cout << "Experience gained: 50" << std::endl;
            break;
        case 2:
            std::cout << "You use the Dragon Slayer's Axe to strike at the dragon. It's very effective!" << std::endl;
            player->xp += 30;
            std::cout << "Experience gained: 30" << std::endl;
            break;
        case 3:
            std::cout << "You use the fire extinguisher to douse the dragon's flames. It's moderately effective." << std::endl;
            player->xp += 10;
            std::cout << "Experience gained: 10" << std::endl;
            break;
        case 4:
            std::cout << "You use the water pump to avoid the dragon's flames. It's pretty dope." << std::endl;
            player->xp += 80;
            std::cout << "Experience gained: 80" << std::endl;
            break;
        case 5:
            std::cout << "Tricky move, nice" << std::endl;
            std::cout << "Experience gained: 0 :DD" << std::endl;
            break;
        default:
            std::cout << "Invalid choice, the dragon attacks you!" << std::endl;
            player->damageTaken(20);
            std::cout << "Health lost: -20" << std::endl;
            if (player->health <= 0) {
                std::cout << "You died. That's very sad, goodbye" << std::endl;
                exit(0); // End the game
            }
            break;
    }
}

void finallFight(Player* player) {
    battleWithBoss(player);
    std::cout << "The first round was tough. However, the developer of this game planned a second round for you (you're welcome)" << std::endl;
    battleWithBoss(player, true);
    std::cout << "Nice, you have won" << std::endl;
}

void checkEndings(Player* player) {
    bool hasBeer = false;
    for (const auto &item: player->inventory) {
        if (item == "quality beer") {
            hasBeer = true;
            break;
        }
    }

    if (hasBeer) {
        std::cout << "Ending 3: You celebrated your victory with a quality beer! Which is a pretty great ending." << std::endl;
        std::cout << "You enjoy a moment of peace, knowing that your adventures have come to an end." << std::endl;
    } else if (player->xp >= 50) {
        std::cout << "Ending 1: You have become a legendary dragon slayer! Everybody loves you." << std::endl;
        std::cout << "Your skills and experience are great, and you are revered as a hero." << std::endl;
    } else {
        std::cout << "Ending 2: You have survived the great dragon fight." << std::endl;
        std::cout << "Though your journey was tough, you have much to learn and many more adventures ahead." << std::endl;
    }
}

void suspiciousQuest(Player* player) {
    std::cout << "You have encountered a Suspicious Quest! Prepare to fight the great dragon." << std::endl;
    exploreStage++;

    finallFight(player); // Complete fight
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "\n"<<std::endl;
    checkEndings(player); // Check and display the appropriate ending

    std::cout << "Written and directed by Wiktor Labno (I'm looking for an internship, please consider me)" << std::endl;
    exit(0);
}



// Main function, the starting point of the program
int main()
{
    std::string playerName;
    std::cout << "Welcome to the Dragon Realm!" << std::endl;
    std::cout << "Enter player name: ";
    std::cin >> playerName;

    Player* player = new Player(playerName, 100, 0);
    player->skills["Firefighting"] = 1;

    bool exploring = true;

    while (exploring) {
        std::cout << "--------------------------------------------------------" << std::endl;
        player->showHealth();
        std::cout << "Where will " << player->name << " go next?" << std::endl;
        std::cout << "1. Moonlight Markets\n2. Grand Library\n3. Shimmering Lake\n4. Fight a dragon\n5. Rescue mission\n6. Show inventory\n7. Show skills\n8. Exit" << std::endl;

        //If player gain some xp and will take party in at least three exercises,
        // the finall boss fight will occur as a possibility
        if (exploreStage > 3) {
            std::cout << "9. Suspicious quest" << std::endl;
        }

        std::cout << "Please enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                if (choice == 1) exploreLocation("Moonlight Markets", player);
                else if (choice == 2) exploreLocation("Grand Library", player);
                else if (choice == 3) exploreLocation("Shimmering Lake", player);
                break;
            case 4:
                fightDragon(player);
                break;
            case 5:
                rescueMission(player);
                break;
            case 6:
                player->showInventory();
                break;
            case 7:
                player->showSkills();
                break;
            case 8:
                exploring = false;
                break;
            case 9:
                if (exploreStage > 3) {
                    suspiciousQuest(player);
                } else {
                    std::cout << "You did not enter a valid choice." << std::endl;
                }
                break;
            default:
                std::cout << "You did not enter a valid choice." << std::endl;
        }
    }

    delete player;
    return 0;
}