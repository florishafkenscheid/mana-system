#include <algorithm>
#include <mutex>
#include "itemmanager.h"
#include "utils.h"
#include "material.h"
#include "regen.h"
#include "display.h"
#include "input.h"
#include "filemanager.h"

Armor getItem(std::string& name, std::vector<Armor> armorList) {
    for (Armor& armor : armorList) {
        if (armor.getName() == name) {
            return armor;
        }
    }
    throw std::runtime_error("This item does not exist");
}

Player getPlayer(std::string& name, std::vector<Player> playerList) {
    for (Player& player : playerList) {
        if (player.getName() == name) {
            return player;
        }
    }
    throw std::runtime_error("This player does not exist");
}

void displayArmorList(std::vector<Armor>& armorList) {
    if (armorList.empty()) {
        std::cout << "No armor available.\n";
        return;
    }
    std::cout << "List of armor:\n";
    for (Armor& armor : armorList) {
        std::cout << trim_copy(armor.getName()) << "\n";
    }
    std::cout << "\n";
    system("read");
}

void displayPlayerList(const std::vector<Player>& playerList) {
    if (playerList.empty()) {
        std::cout << "No players available.\n";
        return;
    }
    std::cout << "\nList of players:\n";
    for (const Player& player : playerList) {
        std::cout << player.getName() << "\n";
    }
    std::cout << "\n";
    system("read");
}

void addArmorToPlayer(std::vector<Player>& playerList, std::vector<Armor>& armorList) {
    if (playerList.empty() || armorList.empty()) {
        std::cout << "No players or armor available.\n";
        system("read");
        return;
    }
    std::cout << "Who do you want to add it to?\n";
    std::string playerName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, playerName);
    playerName = trim_copy(playerName);

    std::cout << "\nWhat do you want to add?\n";
    std::string itemName;
    std::getline(std::cin, itemName);
    itemName = trim_copy(itemName);

    for (Player& player : playerList) {
        if (player.getName() == playerName) {
            for (Armor& armor : armorList) {
                std::string armorName = trim_copy(armor.getName());
                if (armorName == itemName) {
                    std::array<Armor, 4> newArmor = player.getArmor();
                    int slot = armor.getSlot();
                    newArmor[slot] = armor;
                    player.setArmor(newArmor);
                    std::cout << "\nArmor added to player.\n\n";
                    system("read");
                    return;
                }
            }
        }
    }
}

void displayArmorForPlayer(std::vector<Player>& playerList, std::vector<Armor>& armorList) {
    if (playerList.empty() || armorList.empty()) {
        std::cout << "No players or armor available.\n";
        system("read");
        return;
    }
    std::string playerName;

    std::cout << "Who's armor do you want to view?\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, playerName);
    playerName = trim_copy(playerName);

    for (Player& player : playerList) {
        if (player.getName() == playerName) {
            std::array<Armor, 4> playerArmor = player.getArmor();
            for (Armor armor : playerArmor) {
                std::cout << armor.getName() << "\n";
            }
            system("read");
            return;
        }
    }
    std::cout << "This player does not exist.\n";
    system("read");
}

void createNewPlayer(std::vector<Player>& playerList) {
    std::string username;
    std::cout << "Choose a username\n";
    std::cin >> username;

    auto it = std::find_if(playerList.begin(), playerList.end(), [&](const Player& player) {
        return player.getName() == username;
    });

    if (it != playerList.end()) {
        std::cout << "This username is already taken.\n";
        system("read");
        return;
    }

    FileManager fm;
    Player newPlayer(username, 10, 0, std::array<Armor, 4>{}, "");
    playerList.push_back(newPlayer);
    std::cout << "Successfully created user: " + username + "\n";
    system("read");
}

void createNewArmor(std::vector<Armor>& armorList, std::vector<Material>& materialList) {
    ItemManager im;
    FileManager fm;
    std::string name;
    std::string materialInput;
    Material itemMaterial;
    int defense;
    int slot;
    int health;

    std::cout << "Choose a name for the armor\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    name = trim_copy(name);

    std::cout << "\nChoose a material for the armor.\n";
    std::cout << "[1] Leather\n";
    std::cout << "[2] Iron\n";
    std::cout << "[3] Diamond\n";

    std::getline(std::cin, materialInput);
    materialInput = toLower(materialInput);
    bool materialFound = false;

    for (Material material : materialList) {
        if (toLower(material.getName()) == materialInput) {
            itemMaterial = material;
            materialFound = true;
            break;
        }
    }

    if (!materialFound) {
        std::cout << "This material does not exist.\n";
        system("read");
        return;
    }


    std::cout << "\nHow much defense should this armor have?\n";
    std::cin >> defense;

    std::cout << "\nHow much health should this armor give?\n";
    std::cin >> health;

    std::cout << "\nWhat slot should this armor occupy?\n";
    std::cin >> slot;

    Armor newArmor;
    newArmor.setName(name);
    newArmor.setMaterial(itemMaterial);
    newArmor.setDefense(defense);
    newArmor.setSlot(slot);
    newArmor.setHealth(health);

    armorList.push_back(newArmor);
    std::cout << "This armor has been added to the armor list.\n";
    system("read");
}

void createNewMaterial(std::vector<Material>& materialList) {
    std::string materialName;
    std::cout << "What should the material be called?\n";
    std::cin >> materialName;

    Material newMaterial(materialName);
    materialList.push_back(newMaterial);
    std::cout << "Material successfully added to the list.\n";
    system("read");
}

void displayHealth(std::vector<Player>& playerList, std::vector<Material> materialList, std::vector<Armor> armorList) {
    if (playerList.empty()) {
        std::cout << "No players available.\n";
        system("read");
        return;
    }
    std::thread regenThread([&]() {
        regen_obj regenObj(playerList);
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            regenObj();
        }
    });
    std::thread displayThread([&]() {
        display_obj displayObj(playerList);
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            displayObj();
        }
    });
    // std::thread inputThread([&]() {
    //     input_obj inputObj(playerList);
    //     while (true) {
    //         inputObj();
    //     }
    // });
    regenThread.detach();
    displayThread.detach();
    // inputThread.detach();
}

void setHpLow(std::vector<Player>& playerList) {
    for (Player player : playerList) {
        player.setCurrentHealth(1);
        std::cout << player.getName() << "\'s HP has been set to 1.\n";
    }
    system("read");
}

void saveToFile(std::vector<Player>& playerList, std::vector<Armor>& armorList, std::vector<Material>& materialList) {
    FileManager fm;
    std::fstream file("things.txt", std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        fm.writeToFileP(playerList, file);
        fm.writeToFileM(materialList, file);
        fm.writeToFileA(armorList, file);
        file.close();
    } else {
        std::cout << "Failed to open file.\n";
    }
}


void displayGui(std::vector<Player>& playerList, std::vector<Armor>& armorList, std::vector<Material>& materialList) {
    int choice;
    while (true) {
        std::cout << "\033[H\033[2J";
        saveToFile(playerList, armorList, materialList);
        std::cout << "[1] Display Armor List\n";
        std::cout << "[2] Display Player List\n";
        std::cout << "[3] Create player\n";
        std::cout << "[4] Create armor\n";
        std::cout << "[5] Create material\n";
        std::cout << "[6] Add armor to player\n";
        std::cout << "[7] Show armor of a player\n";
        std::cout << "[8] Set HP low\n";
        std::cout << "[9] Start\n";

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again\n";
            continue;
        }
        switch (choice) {
        case 1:
            displayArmorList(armorList);
            continue;

        case 2:
            displayPlayerList(playerList);
            continue;

        case 3:
            createNewPlayer(playerList);
            continue;

        case 4:
            createNewArmor(armorList, materialList);
            continue;
        
        case 5:
            createNewMaterial(materialList);
            continue;

        case 6:
            addArmorToPlayer(playerList, armorList);
            continue;

        case 7:
            displayArmorForPlayer(playerList, armorList);
            continue;

        case 8:
            setHpLow(playerList);
            continue;

        case 9:
            displayHealth(playerList, materialList, armorList);
            continue;
        }
    }
}


int main() {
    ItemManager itemManager;
    FileManager fm;

    std::fstream file = fm.makeFile();

    std::vector<Armor> armorList;
    std::vector<Player> playerList;
    std::vector<Material> materialList;

    fm.parseFile(file, playerList, materialList, armorList);

    displayGui(playerList, armorList, materialList);

    file.close();
    return 0;
}