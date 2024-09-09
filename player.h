#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "items.h"

class Player {
public:
  Player() : name(), maxHealth(10), currentHealth(10), defense(0), armor() {}
  Player(const std::string& name, int health, int defense, const std::array<Armor, 4>& armor)
    : name(name), maxHealth(health), currentHealth(health), defense(defense), armor(armor) {}

  // Getters
  int getEffectiveHP() {
    return currentHealth*(1+defense/100);
  }
  
  int getMaxEffectiveHP() {
    return maxHealth*(1+defense/100);
  }

  int getHealth() {
    return currentHealth;
  }

  int getMaxHealth() {
    return maxHealth;
  }

  int getRegenAmount() {
    int regenAmount = 10;
    for (Armor& piece : armor) {
      regenAmount += piece.getHealth();
    }
    return 1.5+regenAmount*0.025;
  }

  int getDefense() {
    return defense;
  }

  std::string getName() const {
    return name;
  }

  std::array<Armor, 4> getArmor() const {
    return armor;
  }

  // std::string getWeapon() const {
  //   return weapon;
  // }

  // Setters
  void setName(const std::string& newName) {
    name = newName;
  }

  void setCurrentHealth(int newHealth) {
    currentHealth = newHealth;
  }

  void setMaxHealth(int newHealth) {
    maxHealth = newHealth;
  }

  void setDefense(int newDefense) {
    defense = newDefense;
  }


  void setArmor(const std::array<Armor, 4>& newArmor) {
    armor = newArmor;
    defense = 0;
    maxHealth = 10;
    for (Armor piece : armor) {
      defense += piece.getDefense();
      maxHealth += piece.getHealth();
    }
  }

  // void setWeapon(const std::string& newWeapon) {
  //   weapon = newWeapon;
  // }

  std::string serialize() {
    std::ostringstream oss;
    oss << getName() << ' ' << getMaxHealth() << ' ' << getDefense() << ' ';
    
    // Serialize each Armor object in the armor array
    for (Armor& piece : getArmor()) {
        oss << piece.serialize() << ' ';
    }

    // Serialize the weapon
    // oss << getWeapon();

    return oss.str();
  }

  Player deserialize(std::istringstream& iss) {
    // Player blousy 40 30 NULL Diamond_Chestplate Diamond 30 1 30 NULL NULL NULL
    //    0     1    2  3   4          5              6    7  8 9   10   11   12
      std::string line;
      std::getline(iss, line);

      std::istringstream lineStream(line);
      std::vector<std::string> tokens;
      std::string token;

      while (std::getline(lineStream, token, ' ')) {
        tokens.push_back(token);
      }

      if (tokens.size() < 5) {
        throw std::runtime_error("Invalid number of tokens in input line");
      }

      std::string name = tokens[1];
      int maxHealth = std::stoi(tokens[2]);
      int defense = std::stoi(tokens[3]);

      std::array<Armor, 4> armor;
      for (int i = 0; i < 4; ++i) {
        if (tokens.size() <= 4 + i || tokens[4 + i] == "NULL") {
          Armor a;
          armor[i] = a;
        } else {
          std::istringstream armorStream(tokens[4 + i]);
          Armor a;
          a.deserialize(armorStream);
          armor[i] = a;
        }
      }

      // std::string weapon = tokens[12];

      Player player(name, maxHealth, defense, armor);
      player.setCurrentHealth(maxHealth);

      return player;
  }

private:
  std::string name;
  int currentHealth;
  int maxHealth;
  int defense;
  std::array<Armor, 4> armor;
  // std::string weapon;
};

#endif // PLAYER_H