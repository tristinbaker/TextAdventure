#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "room.h"

class Notebook {

public:
    Notebook();
    void determineLore();
    std::string getLore() { return this->lore; }
    void setRoom(Room *room) { this->currRoom = room; }

private:
    Room *currRoom;
    std::string lore;
};
#endif
