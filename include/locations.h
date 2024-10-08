#ifndef LOCATIONS_H
#define LOCATIONS_H
#include "inventory.h"
#include "item.h"

class Location : public Inventory {
public:
  Location();
  Location(const QString &name, const QString &description,
           const QString &image, const QString &musicPath,
           const QString &ambiencePath, const std::vector<Item> &inventory);

  QString getName() const;
  QString getDescription() const;
  QString getImage() const;
  QString getAmbiencePath() const;
  QString getMusicPath() const;
  QString setDescription(QString message);
  std::vector<Item> &getInventory();
  QString locInventory() const;

private:
  QString name;
  QString description;
  QString image;
  QString musicPath;
  QString ambiencePath;
  std::vector<Item> inventory;
};

extern Location camp;
extern Location forestPath;
extern Location cave;
extern Location caveEntrance;
extern Location caveLit;
extern Location intro;
extern Location lake;
extern Location perished;
extern Location valley;

#endif
