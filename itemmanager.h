#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

#include "items.h"
#include "material.h"


class ItemManager {
private:
  std::vector<Armor> armorList;
  std::vector<Item> itemList;
  std::vector<Material> materialList;
public:
  ItemManager() {}

  ~ItemManager() {}

  std::vector<Item> getItems() {
    return itemList;
  }

  std::vector<Armor> getArmorList() {
    return armorList;
  }

  std::vector<Material> getMaterialList() {
    return materialList;
  }
};

#endif //ITEM_MANAGER_H