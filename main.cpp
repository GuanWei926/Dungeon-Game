#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Object.h"
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "GameCharacter.h"
#include "Dungeon.cpp"
using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    return 0;
}
