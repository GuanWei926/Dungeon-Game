#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"


using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    void showStatus();
    vector<Item*> inventory;
    int money;
    bool key;
public:
    Player();
    //Player(string Name,int MaxHealth,int Attack,int Defense);
    void addItem(Item* item);
    void increaseStates(int Attack,int Defense,int Maxhealth, int Health);
    void changeRoom(Room*room);
    void move_picture();

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*object);

    /* Set & Get function*/
    void setCurrentRoom(Room*room);
    void setPreviousRoom(Room*room);
    void setMoney(int Money);
    void takeAction();
    void setKey(bool Key);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    bool getKey();
    vector<Item*> getInventory();
    int getMoney();
};

#endif // PLAYER_H_INCLUDED
