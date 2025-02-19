#include <string>
#include <cstdlib>
#include <iostream>
#include "Monster.h"
//#include "Room.cpp"
using namespace std;

// constructor
Monster::Monster(){}

/*Monster::Monster(string Name,int MaxHealth,int Attack,int Defense){
    this->setName(Name);
    this->setMaxHealth(MaxHealth);
    this->setAttack(Attack);
    this->setDefense(Defense);
}*/

// funtion
bool Monster::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    if (player == nullptr) {
        return false;
    }

    if(this->getCurrentHealth() > 0){
        return true;
    }

    else{
        return false;
    }
}

void Monster::combatSystem(Player* player){
    if(player->getCurrentCD()-1 >= 0){
        player->setCurrentCD(player->getCurrentCD()-1);
    }
    int playerHealth = player->getCurrentHealth();
    int playerAttack = player->getAttack();
    int playerDefense = player->getDefense();
    int monsterDefense = this->getDefense();
    if(player->getCurrentCD() == 0){
        cout << "Do you want to use skill?" << endl;
        cout << "1.Yes  2.No" << endl;
        int ans;
        cin >> ans;
        cout << endl;
        if(ans==1){
            cout << "using skill " << player->getSkill() << endl;
            if(player->getOccupation() == "Warrior"){
                playerAttack += 100;
                cout << "(Your attack +100!)" << endl;
                cout << endl;
            }

            else if(player->getOccupation() == "Tank"){
                monsterDefense -= 50;
                cout << "(Monster's defense -50!)" << endl;
                cout << endl;
            }

            else if(player->getOccupation() == "Wizard"){
                cout << "(Your health and attack +50 respectively!)" << endl;
                cout << "Your attack +50" << endl;
                cout << endl;
                playerHealth += 50;
                if(playerHealth > player->getMaxHealth()){
                    playerHealth = player->getMaxHealth();
                }
                playerAttack += 50;
            }
            player->setCurrentCD(5);
        }
    }

    int damage = playerAttack - monsterDefense;
    if(damage<0){
        damage = 1;
    }
    cout << this->getName() << "'s HP -" << damage << endl;
    this->setCurrentHealth(this->getCurrentHealth()-damage);

    if (this->getCurrentHealth() > 0) {
        damage = this->getAttack() - playerDefense;
        if (damage <= 0)
            damage = 1;
        playerHealth -= damage;
        player->setCurrentHealth(playerHealth);
        cout << "Your HP -" << damage << endl;
    }

    if(this->getCurrentHealth() <= 0 && player->getCurrentRoom()->getIndex() != 10){
        cout << this->getName() << " is defeated." << endl;
        cout << "You got $" << this->getMoney() << endl;
        player->setMoney(player->getMoney() + this->getMoney());
        cout << endl;
    }
    else if(player->getCurrentHealth() <= 0){
        cout << "You are dead." << endl;
        cout << endl;
    }
    else{
        cout << "monster's HP: " << this->getCurrentHealth() << endl;
        cout << "player's HP: " << player->getCurrentHealth() << endl;
        cout << endl;
    }
}

void Monster::setRoom(Room assignedRoom){
    room = assignedRoom;
}

void Monster::setMoney(int Money){
    money = Money;
}

int Monster::getMoney(){
    return money;
}

