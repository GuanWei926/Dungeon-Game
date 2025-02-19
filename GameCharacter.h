#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
//#include "Object.cpp"
using namespace std;

class GameCharacter: public Object
{
private:
    //string name;
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    //int CD;
    int currentCD;
    string occupation;
    string skill;
public:
    GameCharacter();
    //GameCharacter(string Name,int MaxHealth,int Attack,int Defense);
    bool checkIsDead();

    /* Set & Get function*/
    //void setName(string Name);
    void setMaxHealth(int MaxHealth);
    void setCurrentHealth(int CurrentHealth);
    void setAttack(int Attack);
    void setDefense(int Defense);
    //void setCD(int cd);
    void setCurrentCD(int CurrentCD);
    void setSkill(string Skill);
    void setSkill_attact(int Skill_attack);
    void setOccupation(string Occupation);
    int getMaxHealth() const;
    int getCurrentHealth() const;
    int getAttack() const;
    int getDefense() const;
    //int getCD();
    int getCurrentCD();
    //string getName();
    string getOccupation();
    string getSkill();
    //int getSkill_attact();
};
#endif // GAMECHARACTER_H_INCLUDED


