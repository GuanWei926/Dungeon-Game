#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense, price, maxhealth;
    bool isTake = false;
public:
    Item();
    //Item(string Name, int Attack, int Health, int Defense, int Price, int MaxHealth);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object* object);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getPrice();
    int getMaxHealth();
    bool getIsTake();
    void setIsTake(bool IsTake);
    void setMaxHealth(int MaxHealth);
    void setHealth(int Health);
    void setAttack(int Attack);
    void setDefense(int Defense);
    void setPrice(int Price);
};

#endif // ITEM_H_INCLUDED
