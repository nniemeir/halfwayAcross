#include "../../include/handling.h"

void Handling::help(MainWindow *mainWindow)
{
  mainWindow->setDescription(
      "AGAIN/G - repeat last command\n"
      "COOK (object) - cook something\n"
      "CRAFT (object) - craft something\n"
      "CRY - relieve some stress\n"
      "DRINK (object) - relieve some thirst\n"
      "DROP (object) - place possessed item on ground\n"
      "EAT (object) - relieve some hunger\n"
      "EXAMINE/X (object) - examine an object in my inventory\n"
      "GO/MOVE (direction)- move in a cardinal direction\n"
      "HELP - show this message\n"
      "HUNT (object) - hunt something\n"
      "LOAD (object) - place a payload into an item\n"
      "LOOK/L (object) - look at something\n"
      "QUIT - terminate the session\n"
      "READ - read something\n"
      "REFLECT - get information about stats\n"
      "REMOVE (object) - take off a clothing item\n"
      "SCREAM/SHOUT/YELL - alert animals to my presence\n"
      "SCRIPT - start writing journal to file\n"
      "SHOOT (object) - shoot an arrow at something\n"
      "SIT (object) - sit on something\n"
      "SKIN (object) - harvest fat, meat, and pelt from a slain animal\n"
      "SLEEP - advance to the next day\n"
      "STAND - stand up\n"
      "TAKE (object) - add an item to my inventory\n"
      "USE (object) - use something\n"
      "UNSCRIPT - stop writing journal to file\n"
      "VERSION - show program version\n"
      "WAIT/Z - advance time\n"
      "WEAR (object) - wear a clothing item");
}
