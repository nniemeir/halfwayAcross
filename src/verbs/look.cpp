#include "../../include/characters.h"
#include "../../include/handling.h"
#include "../../include/player.h"
#include "../../include/world.h"

void Handling::look(MainWindow *mainWindow, QString target,
                    Location *location) {
  if (!ensembleObj.isCharacterName(target)) {
    QMap<QString, std::function<void()>> lookLocations;
    lookLocations["Camp"] = [mainWindow, target, this]() {
      lookCamp(mainWindow, target);
    };
    lookLocations["The forest path"] = [mainWindow, target, this]() {
      lookForestPath(mainWindow, target);
    };
    lookLocations["The dark cave"] = [mainWindow, target, this]() {
      lookCave(mainWindow, target);
    };
    lookLocations["The cave's entrance"] = [mainWindow, target, this]() {
      lookCaveEntrance(mainWindow, target);
    };
    lookLocations["The lake"] = [mainWindow, target, this]() {
      lookLake(mainWindow, target);
    };
    lookLocations["The valley"] = [mainWindow, target, this]() {
      lookValley(mainWindow, target);
    };

    if (lookLocations.contains(location->getName())) {
      lookLocations[location->getName()]();
    } else {
      notAllowedInLocMsg(mainWindow, "look anywhere");
    }
  } else {
    if (QString::compare(target, worldObj.getActiveCharacter()->getName(),
                         Qt::CaseInsensitive) == 0) {
      mainWindow->setDescription(
          worldObj.getActiveCharacter()->getDescription());
    } else {
      characterNotActiveMsg(mainWindow, target);
    }
  }
}

void Handling::lookCamp(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", camp.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"FIRE", "The fire burned low."},
      {"BED", "The bed seemed to be quite worn."},
      {"GROUND", camp.locInventory()},
      {"SELF", playerObj.displayClothesInventory()},
      {"UP", "The cave ceiling seemed sturdy enough that it wouldn't collapse "
             "on me."},
      {"DOWN", camp.locInventory()},
      {"OUTSIDE", QString("It was %1 outside.")
                      .arg(worldObj.getCurrentWeather().toLower())}};

  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}

void Handling::lookForestPath(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", forestPath.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"GROUND", forestPath.locInventory()},
      {"PATH", "The other branches of the path went off into the distance.\n"},
      {"UP", "The sky seemed empty that day."},
      {"DOWN", forestPath.locInventory()},
      {"SELF", playerObj.displayClothesInventory()}};

  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}

void Handling::lookCave(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", valley.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"GROUND", cave.locInventory()},
      {"UP", "The cave ceiling seemed sturdy enough that it wouldn't collapse "
             "on me."},
      {"DOWN", cave.locInventory()},
      {"SELF", playerObj.displayClothesInventory()}};
  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}

void Handling::lookCaveEntrance(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", caveEntrance.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"GROUND", caveEntrance.locInventory()},
      {"UP", "I felt smaller looking at the mountain."},
      {"DOWN", caveEntrance.locInventory()},
      {"SELF", playerObj.displayClothesInventory()}};
  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}

void Handling::lookLake(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", lake.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"GROUND", lake.locInventory()},
      {"LAKE", "The lake had frozen over.\n"},
      {"MOUNTAIN", "Who knew what that mountain held?\n"},
      {"UP", "The sky felt empty that day."},
      {"DOWN", lake.locInventory()},
      {"SELF", playerObj.displayClothesInventory()}};

  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}

void Handling::lookValley(MainWindow *mainWindow, QString target) {
  QMap<QString, QString> descriptions = {
      {"AROUND", valley.getDescription()},
      {"BAG", playerObj.displayBagInventory()},
      {"GROUND", valley.locInventory()},
      {"TREES", "The trees were covered in snow."},
      {"UP", "The sky felt empty that day."},
      {"DOWN", valley.locInventory()},
      {"SELF", playerObj.displayClothesInventory()}};
  if (descriptions.contains(target)) {
    mainWindow->setDescription(descriptions.value(target));
  } else {
    notAllowedDirMsg(mainWindow, "look", target);
  }
}
