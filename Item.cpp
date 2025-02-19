#include "Item.h"

// constructor
Item::Item(){}
/*Item::Item(string Name, int Attack, int Health, int Defense, int Price, int MaxHealth):Object(Name, "Item"){
    attack = Attack;
    health = Health;
    defense = Defense;
    price = Price;
    maxhealth = MaxHealth;
}*/

// funtion
bool Item::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    int strengtheningCUR_HP = player->getCurrentHealth() + health;
    int strengtheningMAX_HP = player->getMaxHealth() + health;
    int strengtheningATK = player->getAttack() + attack;
    int strengtheningDFS = player->getDefense() + defense;
    player->setAttack(strengtheningATK);
    player->setDefense(strengtheningDFS);
    player->setMaxHealth(strengtheningMAX_HP);
    player->setCurrentHealth(strengtheningCUR_HP);
    return true;
}


int Item::getHealth(){
    return health;
}

int Item::getAttack(){
    return attack;
}

int Item::getDefense(){
    return defense;
}

int Item::getPrice(){
    return price;
}

int Item::getMaxHealth(){
    return maxhealth;
}

bool Item::getIsTake(){
    return isTake;
}

void Item::setMaxHealth(int MaxHealth){
    maxhealth = MaxHealth;
}
void Item::setHealth(int Health){
    health = Health;
}

void Item::setAttack(int Attack){
    attack = Attack;
}

void Item::setDefense(int Defense){
    defense = Defense;
}

void Item::setPrice(int Price){
    price = Price;
}

void Item::setIsTake(bool IsTake){
    isTake = IsTake;
}
