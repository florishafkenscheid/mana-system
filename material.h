#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <iostream>
#include <sstream>
#include "itemmanager.h"
#include "utils.h"       // Include utils.h header file

class Material {
public:
    Material() : material() {}
    Material(std::string& material) : material(material) {}

    std::string& getName() { return material; }

    void setName(std::string material) { this->material = material; }

    Material findMaterial(std::string materialToFind, std::vector<Material> materialList) {
        Material materialFound;
        materialToFind = toLower(materialToFind); // Call toLower on each character in the string
        for (Material materialFound : materialList) {
            if (materialFound.material == materialToFind) {
                return materialFound;
            }
        }
        std::cout << "This material does not exist.\n";
        return materialFound;
    }

    std::string serialize() {
        std::ostringstream oss;
        oss << getName();
        return oss.str();
    }

    Material deserialize(std::istringstream& iss) {
        std::string name;
        iss >> name;
        Material material(name);
        return material;
    }

private:
    std::string material;
};

#endif // MATERIAL_H