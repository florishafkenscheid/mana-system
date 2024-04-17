#ifndef ITEMS_H
#define ITEMS_H

#include "itemmanager.h"
#include "material.h"
#include <sstream>
#include <algorithm>

class Item {
public:
  Item() : name(), material(), displayName() {}
  Item(std::string& name, Material& material) : name(name), material(material), displayName(name) {}

  ~Item() {}

  void setName(std::string name) {  
    this->name = name;
  }

  void setDisplayName(std::string name) { this->displayName = name; }

  void setMaterial(Material material) { this->material = material; }

  std::string& getName() { return name; }

  Material& getMaterial() { return material; }

  std::string& getDisplayName() { return displayName; }

  Item getItem() { return *this; }

  std::string serialize() {
        std::ostringstream oss;
        std::replace(name.begin(), name.end(), ' ', '_');
        oss << name << ' ' << material.getName() << ' ' << displayName;
        std::cout << name;
        return oss.str();
  }

  Item deserialize(std::istringstream& iss) {
    std::string name, materialName, displayName;

    iss >> name >> materialName >> displayName;
    Material itemMaterial(material);
    Item item(name, itemMaterial);
    return item;
  }

private:
  std::string name;
  Material material;
  std::string displayName;
};

class Armor : public Item {
public:
    Armor() : Item(), defense(0), slot(0), health(0) {}

    Armor(std::string& name, Material material, int defense, int slot, int health) 
      : Item(name, material), defense(defense), slot(slot), health(health) {}

    int getDefense() { return defense; }

    void setDefense(int defense) { this->defense = defense; }

    int getSlot() { return slot; }

    void setSlot(int slot) { this->slot = slot; }

    int getHealth() const { return health; }

    void setHealth(int health) { this->health = health; }

  std::string serialize() {
    if (this->getName().empty()) {
      // Return an empty string if the Armor object is empty
      return "NULL";
    }

    std::ostringstream oss;
    std::string name = this->getName();
    std::replace(name.begin(), name.end(), ' ', '_');
    oss << name << ' ' << this->getMaterial().getName() << ' ' << getDefense() << ' ' << getSlot() << ' ' << getHealth();
    return oss.str();
  }

  Armor deserialize(std::istringstream& iss) {
    std::string name, materialName;
    int defense, slot, health;

    iss >> name >> materialName >> defense >> slot >> health;

    std::replace(name.begin(), name.end(), '_', ' ');

    Armor armor(name, Material(materialName), defense, slot, health);
    return armor;
  }

  bool isInitialized() {
    return !getName().empty() && !getMaterial().getName().empty() && getDefense() != 0;
  }

  

private:
  int defense;
  int slot;
  int health;
};

#endif // ITEMS_H