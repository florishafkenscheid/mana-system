#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "items.h"

class Player {
public:
  Player() : name(), maxHealth(10), currentHealth(10), defense(0), armor(), weapon() {}
  Player(const std::string& name, int health, int defense, const std::array<Armor, 4>& armor, const std::string& weapon)
    : name(name), maxHealth(health), currentHealth(health), defense(defense), armor(armor), weapon(weapon) {}

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

  int getDefense() {
    return defense;
  }

  std::string getName() const {
    return name;
  }

  std::array<Armor, 4> getArmor() const {
    return armor;
  }

  std::string getWeapon() const {
    return weapon;
  }

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

  void setWeapon(const std::string& newWeapon) {
    weapon = newWeapon;
  }

  std::string serialize() {
    std::ostringstream oss;
    oss << getName() << ' ' << getMaxHealth() << ' ' << getDefense() << ' ';
    
    // Serialize each Armor object in the armor array
    for (Armor& a : getArmor()) {
      if (a.isInitialized()) {
        oss << a.serialize() << ' ';
      } else {
        oss << "NULL ";
      }
    }

    // Serialize the weapon
    oss << getWeapon();

    return oss.str();
  }

  Player deserialize(std::istringstream& iss) {
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
        if (tokens.size() <= 4 + i + 1 || tokens[4 + i + 1] == "NULL") {
          Armor a;
          armor[i] = a;
        } else {
          std::istringstream armorStream(tokens[4 + i + 1]);
          Armor a;
          a.deserialize(armorStream);
          armor[i] = a;
        }
      }

      std::string weapon = tokens[tokens.size() - 1];

      Player player(name, maxHealth, defense, armor, weapon);
      player.setCurrentHealth(maxHealth);

      return player;
  }

private:
  std::string name;
  int currentHealth;
  int maxHealth;
  int defense;
  std::array<Armor, 4> armor;
  std::string weapon;
};

#endif // PLAYER_H