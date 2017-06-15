#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "room.h"

class Notebook {

public:
    Notebook();
    void determineLore();

private:
    Room *currRoom;
    std::string lore;

#endif
