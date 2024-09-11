#include "../include/locations.h"

Location::Location(const QString &name, const QString &description,
                   const QString &image, const QString &musicPath,
                   const QString &ambiencePath,
                   const std::vector<item> &inventory)
    : name(name), description(description), image(image), musicPath(musicPath),
      ambiencePath(ambiencePath), inventory(inventory) {}

Location camp("camp",
              "You wake up sore, that familiar ache of winter mornings felt "
              "once again.\n\nExit: North",
              ":/images/camp.png", "qrc:/audio/music/placeholder.mp3",
              "qrc:/audio/ambience/mountainWind.mp3",
              {{"FISHING ROD", 1, 0, 0, "tools"}});

Location
    campPath("campPath",
             "You move through a break in the trees for a while before "
             "reaching a fork in the road.\n\nExits: North, South, East, West",
             ":/images/campPath.png", "qrc:/audio/music/placeholder.mp3",
             "qrc:/audio/ambience/mountainWind.mp3",
             {{"ROCK", 1, 0, 0, "tools"}});

Location caveEntrance("caveEntrance",
                      "You happen upon a cave, it might not be a good idea to "
                      "find out what it contains.\n\nExits: West, East",
                      ":/images/caveEntrance.png", "qrc:/audio/music/placeholder.mp3",
                      "qrc:/audio/ambience/mountainWind.mp3",
                      {{"ROCK", 1, 0, 0, "tools"}});

Location cave("cave",
              "Entering the cave, you see nothing but darkness.\n\nExit: West",
              ":/images/cave.png", "qrc:/audio/music/placeholder.mp3",
              "qrc:/audio/ambience/mountainWind.mp3",
              {{"ROCK", 1, 0, 0, "tools"}});

Location intro("intro", "HALFWAY ACROSS\n\nType BEGIN to continue.\n",
               ":/images/intro.png", "qrc:/audio/music/placeholder.mp3",
               "qrc:/audio/ambience/mountainWind.mp3",
               {{"MOTIVATION", 1, 0, 0, "Resources"}});

Location lake("lake", "You reach a lake after an hour's journey.\n\nExit: East",
              ":/images/lake.png", "qrc:/audio/music/placeholder.mp3",
              "qrc:/audio/ambience/mountainWind.mp3",
              {{"CHISEL", 1, 0, 0, "tools"}});

Location perished("perished",
                  "You have perished.\n\nType QUIT to exit.",
                  ":/images/perished.png", "qrc:/audio/music/placeholder.mp3",
                  "qrc:/audio/ambience/mountainWind.mp3",
                  {{"FISHING ROD", 1, 0, 0, "tools"}});

Location valley("valley",
                "You reach a clearing. This could be a good spot for "
                "hunting.\n\nExit: South",
                ":/images/valley.png", "qrc:/audio/music/placeholder.mp3",
                "qrc:/audio/ambience/mountainWind.mp3",
                {{"STICK", 1, 0, 0, "tools"}});

QString Location::getName() const { return name; }
QString Location::getDescription() const { return description; }
QString Location::getImage() const { return image; }
QString Location::getAmbiencePath() const { return ambiencePath; }
QString Location::getMusicPath() const { return musicPath; }

std::vector<item> &Location::getInventory() { return inventory; }

QString Location::locInventory() const {
  QString inventoryText;
  inventoryText.append("You see:\n");
  for (const auto &item : inventory) {
    inventoryText.append(QString("%1\n").arg(item.name));
  }
  return inventoryText;
}
