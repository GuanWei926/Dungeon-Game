#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    /*void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room>&, ofstream&);
    void loadPlayer(Player*, ifstream&);
    void loadRooms(vector<Room>&, ifstream&);*/

    void savePlayer(Player* player);
    void saveRooms(vector<Room*>&room);
    void loadPlayer(Player*player, vector<Room*>&room);
    void loadRooms(vector<Room*>&room);


public:
    Record();
    void saveToFile(Player*player, vector<Room*>&room);
    void loadFromFile(Player*player, vector<Room*>&room);

};

#endif // RECORD_H_INCLUDED
