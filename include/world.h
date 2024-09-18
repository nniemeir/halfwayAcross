#ifndef WORLD_H
#define WORLD_H
#include "../include/item.h"
#include "../include/locations.h"

class World {
public:
  World();
  typedef enum {
    TRAVEL_YES = 1,
    TRAVEL_BLIZZARD,
    TRAVEL_TIRED
  } TravelResponses;

  // Day
  int advanceDay();
  int getDay() const;

  // Location
  Location *getCurrentLocation() const;
  void initializeLocation(Location *initialLocation);
  void setCurrentLocation(Location *location);

  // Day-specific
  int getCurrentTemperature() const;
  QString getCurrentWeather() const;
  int getChiseledIce() const;
  void setChiseledIce(int newValue);
  int getLineSet() const;
  void setLineSet(int newValue);
  bool getConspicuous() const;
  void setConspicuous(bool newValue);
  int travelChecks();

  // Fishing
  QString generateFish();
  std::vector<Item> &getFishInventory();

  // Movement
  bool validDirection(const QString &value);

private:
  int day;
  Location *currentLocation;
  int currentTemperature;
  QString currentWeather;
  int chiseledIce;
  int lineSet;
  bool conspicuous;
  int generateTemperature();
  QString generateWeather();
  std::vector<Item> fish;
  std::vector<QString> directions;
};

extern World world;
#endif // WORLD_H
