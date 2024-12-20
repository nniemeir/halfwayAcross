#include "../../../include/core/handling/verbhandler.h"
#include "../../../include/entities/player.h"

void VerbHandler::cry(MainWindow *mainWindow) {
  if (playerObj.getMental() == 100) {
    mainWindow->setDescription(
        "I was content enough that I didn't feel like crying.");
    return;
  }
  if (playerObj.getCryCooldown() != 0) {
    mainWindow->setDescription("I felt too numb to cry.");
    return;
  }
  playerObj.setMental(playerObj.getMental() + 10);
  mainWindow->setDescription("Crying made me feel a little better.");
  playerObj.setCryCooldown(3);
}
