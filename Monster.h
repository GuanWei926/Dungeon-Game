#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include"Room.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    Room room;
    int money;
public:
    Monster();
    //Monster(string Name,int MaxHealth,int Attack,int Defense);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object* object);

    void combatSystem(Player* player);

    void setRoom(Room assignedRoom);

    void setMoney(int Money);

    int getMoney();
};


#endif // ENEMY_H_INCLUDED
