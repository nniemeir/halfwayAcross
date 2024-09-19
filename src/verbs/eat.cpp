#include "../../include/audio.h"
#include "../../include/handling.h"
#include "../../include/player.h"

void Handling::eat(MainWindow *mainWindow, QString target) {
  int targetIndex = inventoryObj.searchInventory(player.getInventory(), target);
  if (targetIndex != -1) {
    if (inventoryObj.getInventoryItem(player.getInventory(), targetIndex)
            .getType() == "FOOD") {
      if (player.getHunger() < 100) {
      sfxPlayer.play("qrc:/audio/sfx/eat.mp3", sfxPlayer.getdefSfxVol(), 0);
      QString itemName =
          inventoryObj.getInventoryItem(player.getInventory(), targetIndex)
              .getName();
      mainWindow->setDescription(
          QString("I ate %1 %2.").arg(getArticle(itemName)).arg(itemName));
      player.setHunger(
          player.getHunger() +
          inventoryObj.getInventoryItem(player.getInventory(), targetIndex)
              .getEffect());
      inventoryObj.removeItem(player.getInventory(), targetIndex);
      } else {
          mainWindow->setDescription("I wasn't hungry at the time.");
      }
    } else {
      mainWindow->setDescription(QString("It didn't seem wise to eat %1 %2.")
                                     .arg(handle.getArticle(target))
                                     .arg(target.toLower()));
    }
  } else {
    mainWindow->setDescription(QString("I didn't have %1 %2 to eat.")
                                   .arg(getArticle(target))
                                   .arg(target.toLower()));
  }
}
