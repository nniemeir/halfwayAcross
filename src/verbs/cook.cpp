#include "../../include/handling.h"
#include "../../include/item.h"
#include "../../include/player.h"

void Handling::cook(MainWindow *mainWindow, QString target,
                    Location *location) {
  if (location->getName() == "camp") {
    int itemIndex = inventoryObj.searchInventory(player.getInventory(), target);
    if (itemIndex != -1) {
      if (inventoryObj.getInventoryItem(player.getInventory(), itemIndex).getType() ==
          "RAW MEAT") {
        mainWindow->setDescription(
            QString("I cooked some %1 over the fire.").arg(target.toLower()));
        Item cooker;
        Item cookedItem = cooker.cookMeat(
            inventoryObj.getInventoryItem(player.getInventory(), itemIndex));
        inventoryObj.removeItem(player.getInventory(), itemIndex);
        int cookedIndex = inventoryObj.searchInventory(player.getInventory(),
                                                       cookedItem.getName());
        inventoryObj.addItem(player.getInventory(), cookedItem, cookedIndex);
      } else if (inventoryObj.getInventoryItem(player.getInventory(), itemIndex).getType() ==
                 "FAT") {
        mainWindow->setDescription(
            QString("I rendered the %1.").arg(target.toLower()));
        inventoryObj.removeItem(player.getInventory(), itemIndex);
        int fatIndex = inventoryObj.searchInventory(player.getInventory(),
                                                    "RENDERED FAT");
        inventoryObj.addItem(player.getInventory(),
                             {"RENDERED FAT", 1, 1, 10, "ANIMAL FAT", "NONE"},
                             fatIndex);
      } else {
          mainWindow->setDescription(QString("I thought of cooking %1 %2, but dismissed the idea.").arg(handle.getArticle(target)).arg(target.toLower()));
      }
    } else {
        mainWindow->setDescription(QString("I didn't have %1 %2 to cook.").arg(handle.getArticle(target)).arg(target.toLower()));
    }
  } else {
    mainWindow->setDescription("I needed to be near a campfire to cook.");
  }
}
