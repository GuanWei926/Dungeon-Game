#include <string>
#include <cstdlib>
#include <iostream>
#include "GameCharacter.h"
using namespace std;

//constructor
GameCharacter :: GameCharacter(){}

/*GameCharacter::GameCharacter(string Name,int MaxHealth,int Attack,int Defense):
    name(Name), maxHealth(MaxHealth), attack(Attack), defense(Defense){}*/

//function
bool GameCharacter::checkIsDead(){
    if(currentHealth < 0)
        return 0;
    else
        return 1;
}

/*void GameCharacter::setName(string Name){
    name = Name;
}*/
void GameCharacter::setMaxHealth(int MaxHealth){
    maxHealth = MaxHealth;
}

void GameCharacter::setCurrentHealth(int CurrentHealth){
    currentHealth = CurrentHealth;
}

void GameCharacter::setAttack(int Attack){
    attack = Attack;
}

void GameCharacter::setDefense(int Defense){
    defense = Defense;
}

/*void GameCharacter::setCD(int cd){
    CD = cd;
}*/

void GameCharacter::setCurrentCD(int CurrentCD){
    currentCD = CurrentCD;
}

void GameCharacter::setOccupation(string Occupation){
    occupation = Occupation;
}

void GameCharacter::setSkill(string Skill){
    skill = Skill;
}

/*void GameCharacter::setSkill_attact(int Skill_attack){
    skill_attack = Skill_attack;
}*/

int GameCharacter::getMaxHealth() const{
    return maxHealth;
}

int GameCharacter::getCurrentHealth() const{
    return currentHealth;
}

int GameCharacter::getAttack() const{
    return attack;
}

int GameCharacter::getDefense() const{
    return defense;
}

/*int GameCharacter::getCD(){
    return CD;
}*/

int GameCharacter::getCurrentCD(){
    return currentCD;
}

string GameCharacter::getOccupation(){
    return occupation;
}

string GameCharacter::getSkill(){
    return skill;
}

/*int GameCharacter::getSkill_attact(){
    return skill_attack;
}*/

/*string GameCharacter::getName(){
    return name;
}*/



