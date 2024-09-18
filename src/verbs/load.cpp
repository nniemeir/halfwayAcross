#include "../../include/handling.h"
#include "../../include/player.h"

void Handling::load(MainWindow *mainWindow, QString target) {
  int targetIndex = inventoryObj.searchInventory(player.getInventory(), target);
  if (targetIndex != -1) {
    QString payload =
      inventoryObj.getInventoryItem(player.getInventory(), targetIndex).getPayload();

    int payloadIndex =
        inventoryObj.searchInventory(player.getInventory(), payload);
    if (payloadIndex != -1) {
      mainWindow->setDescription(QString("I loaded %1 %2 into my %3.").arg(getArticle(payload))
                                     .arg(payload.toLower())
                                     .arg(target.toLower()));
      inventoryObj.removeItem(player.getInventory(), payloadIndex);
      inventoryObj.getInventoryItem(player.getInventory(), targetIndex).setEffect(100);
    } else {
      mainWindow->setDescription(
          QString("I needed %1 %2.").arg(getArticle(payload)).arg(payload.toLower()));
    }
  } else {
    mainWindow->setDescription(
        QString("I didn't have %1 %2.").arg(getArticle(target)).arg(target.toLower()));
  }
}
