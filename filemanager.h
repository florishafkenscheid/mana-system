#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include "items.h"
#include "player.h"

class FileManager {
public:
    std::fstream makeFile() {
        if (doesFileExist("things.txt")) {
            std::fstream itemFile("things.txt", std::ios::in | std::ios::out);
            return itemFile;
        } else {
            std::fstream itemFile("things.txt", std::ios::out);
            itemFile.close();
            std::fstream newItemFile("things.txt", std::ios::in | std::ios::out);
            return newItemFile;
        }
    }

    void saveFile(std::fstream& file) {
        file.close();
    }

    void writeToFileA(std::vector<Armor>& content, std::fstream& file) {
        file.close();
        file.open("things.txt", std::ios::out | std::ios::app);
        for (Armor& armor : content) {
            file << "Armor " << armor.serialize() << "\n";
        }
        file.close();
    }

    void writeToFileM(std::vector<Material>& content, std::fstream& file) {
        file.close();
        file.open("things.txt", std::ios::out | std::ios::app);
        for (Material& material : content) {
            file << "Material " << material.serialize() << "\n";
        }
        file.close();
    }

    void writeToFileP(std::vector<Player>& content, std::fstream& file) {
        file.close();
        file.open("things.txt", std::ios::out | std::ios::app);
        for (Player& player : content) {
            file << "Player " << player.serialize() << "\n";
        }
        file.close();
    }

    void parseFile(std::fstream& file, std::vector<Player>& playerList, std::vector<Material>& materialList, std::vector<Armor>& armorList) {
        if (!file.is_open()) {
            std::cerr << "File is not open.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            try {
                if (type == "Armor") {
                    Armor armor;
                    armorList.push_back(armor.deserialize(iss));
                } else if (type == "Material") {
                    Material material;
                    materialList.push_back(material.deserialize(iss));
                } else if (type == "Player") {
                    Player player;
                    playerList.push_back(player.deserialize(iss));
                }
            } catch (const std::exception& e) {
                std::cerr << "Exception caught during deserialization: " << e.what() << '\n';
                return;
            }
        }
    }

    inline bool doesFileExist(const std::string& name) {
        struct stat buffer;
        return (stat (name.c_str(), &buffer) == 0);
    }
};