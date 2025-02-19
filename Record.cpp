#include "Record.h"
#include <cstdio>
#include <fstream>

void Record::savePlayer(Player* player){
    std::ofstream fout("record_player.txt");
    // name, attack, defense, maxHP, HP, occupation, skill, money, CD, prevRoom, currRoom, key
    fout << player->getName() << " ";
    fout << player->getAttack() << " ";
    fout << player->getDefense() << " ";
    fout << player->getMaxHealth() << " ";
    fout << player->getCurrentHealth() << " ";
    fout << player->getOccupation() << " ";
    fout << player->getSkill() << " ";
    fout << player->getMoney() << " ";
    fout << player->getCurrentCD() << " ";
    fout << player->getPreviousRoom()->getIndex() << " ";
    fout << player->getCurrentRoom()->getIndex() << " ";
    fout << player->getCurrentCD() << " ";
    fout << player->getKey() << " ";
    fout << player->getInventory().size() << " ";
    for(int i=0; i<player->getInventory().size() ; i++){
        fout << player->getInventory()[i]->getName();
        fout << " ";
    }
    fout << std::endl; // add new line
}

void Record::saveRooms(vector<Room*>&room){
    std::ofstream fout("record_room.txt");

    Monster* monster = dynamic_cast<Monster*>(room[3]->getObjects()[0]);
    if(monster->getCurrentHealth() <= 0)
        fout << "died ";
    else
        fout << "alive ";

    Item* item = dynamic_cast<Item*>(room[3]->getObjects()[1]);
    if(item->getIsTake())
        fout << "isTake ";
    else
        fout << "notTake ";

    NPC* npc = dynamic_cast<NPC*>(room[4]->getObjects()[0]);
    if(npc->getCurrentHealth() <= 0)
        fout << "died ";
    else
        fout << "alive ";

    item = dynamic_cast<Item*>(room[4]->getObjects()[1]);
    if(item->getIsTake())
        fout << "isTake ";
    else
        fout << "notTake ";

    monster = dynamic_cast<Monster*>(room[6]->getObjects()[0]);
    if(monster->getCurrentHealth() <= 0)
        fout << "died ";
    else
        fout << "alive ";

    item = dynamic_cast<Item*>(room[6]->getObjects()[1]);
    if(item->getIsTake())
        fout << "isTake ";
    else
        fout << "notTake ";

    monster = dynamic_cast<Monster*>(room[7]->getObjects()[0]);
    if(monster->getCurrentHealth() <= 0)
        fout << "died ";
    else
        fout << "alive ";

    item = dynamic_cast<Item*>(room[8]->getObjects()[0]);
    if(item->getIsTake())
        fout << "isTake ";
    else
        fout << "notTake ";


    monster = dynamic_cast<Monster*>(room[10]->getObjects()[0]);
    if(monster->getCurrentHealth() <= 0)
        fout << "died\n";
    else
        fout << "alive\n";
}

void Record::loadPlayer(Player* player, std::vector<Room*>& room){
    std::ifstream fin("record_player.txt");
    // name, attack, defense, maxHP, occupation, skill, money, CD, prevRoom, currRoom, key
    int read1;
    std::string read2;
    fin >> read2;
    player->setName(read2);

    fin >> read1;
    player->setAttack(read1);

    fin >> read1;
    player->setDefense(read1);

    fin >> read1;
    player->setMaxHealth(read1);

    fin >> read1;
    if(read1 <= 0)
        player->setCurrentHealth(player->getMaxHealth());
    else
        player->setCurrentHealth(read1);

    fin >> read2;
    player->setOccupation(read2);

    fin >> read2;
    player->setSkill(read2);

    fin >> read1;
    player->setMoney(read1);

    fin >> read1;
    player->setCurrentCD(read1);

    fin >> read1;
    player->setPreviousRoom(room[read1]);

    fin >> read1;
    player->setCurrentRoom(room[read1]);

    fin >> read1;
    player->setCurrentCD(read1);

    fin >> read1;
    player->setKey(read1);

    int len;
    fin >> len;
    for(int i=0 ; i<len ; i++){
        Item* item = new Item;
        string name;
        fin >> name;
        item->setName(name);
        player->addItem(item);
    }
}

void Record::loadRooms(vector<Room*>&room){
    std::ifstream fin("record_room.txt");
    for(int i=0; i<=10 ; i++){
        Room*roomTemp = new Room;
        roomTemp -> setIndex(i);
        room.push_back(roomTemp);
    }

    room[1]->setDownRoom(room[0]);
    room[1]->setUpRoom(room[0]);
    room[1]->setLeftRoom(room[2]);
    room[1]->setRightRoom(room[0]);
    room[1]->setIsExit(0);

    room[2]->setDownRoom(room[3]);
    room[2]->setUpRoom(room[5]);
    room[2]->setLeftRoom(room[4]);
    room[2]->setRightRoom(room[1]);
    room[2]->setIsExit(0);

    room[3]->setDownRoom(room[0]);
    room[3]->setUpRoom(room[2]);
    room[3]->setLeftRoom(room[0]);
    room[3]->setRightRoom(room[0]);
    room[3]->setIsExit(0);
    Monster* monster1 = new Monster;
    monster1->setName("Slime");
    monster1->setMaxHealth(200);
    monster1->setAttack(100);
    monster1->setDefense(150);
    monster1->setCurrentHealth(monster1->getMaxHealth());
    monster1->setMoney(500);
    monster1->setRoom(*room[3]);
    Item* bonus1 = new Item;
    bonus1->setName("armor");
    bonus1->setAttack(50);
    bonus1->setDefense(0);
    bonus1->setHealth(0);
    bonus1->setPrice(0);
    bonus1->setMaxHealth(0);
    string read;
    fin >> read;
    if(read == "died")
        monster1->setCurrentHealth(0);
    fin >> read;
    if(read == "isTake")
        bonus1->setIsTake(1);
    room[3]->setObjects(monster1);
    room[3]->setObjects(bonus1);

    room[4]->setDownRoom(room[0]);
    room[4]->setUpRoom(room[0]);
    room[4]->setLeftRoom(room[0]);
    room[4]->setRightRoom(room[2]);
    room[4]->setIsExit(0);
    NPC* npc1 = new NPC;
    npc1->setScript("I...I encountered a horrible monster and got attacked. I am afraid I'll die soon.\nPl..Please defeat the monster and save the world on my behalf. (adventurer died)");
    npc1->setName("adventurer");
    Item* item = new Item;
    fin >> read;
    if(read == "died")
        npc1->setCurrentCD(0);
    fin >> read;
    if(read == "isTake")
        item->setIsTake(1);
    room[4]->setObjects(npc1);
    room[4]->setObjects(item);

    room[5]->setDownRoom(room[2]);
    room[5]->setUpRoom(room[7]);
    room[5]->setLeftRoom(room[0]);
    room[5]->setRightRoom(room[6]);
    room[5]->setIsExit(0);
    vector<Item*> buff;
    NPC* npc2 = new NPC;
    npc2->setScript("Welcome my shop, youngster. Do you want to buy something?\n1.of course.     2. No.You look suspicious!");
    npc2->setName("trader");

    Item* item1 = new Item;
    item1->setName("attack_rune");
    item1->setAttack(200);
    item1->setDefense(0);
    item1->setHealth(0);
    item1->setPrice(300);
    item1->setMaxHealth(0);
    buff.push_back(item1);

    Item* item2 = new Item;
    item2->setName("defense_rune");
    item2->setAttack(0);
    item2->setDefense(200);
    item2->setHealth(0);
    item2->setPrice(300);
    item2->setMaxHealth(0);
    buff.push_back(item2);

    Item* item3 = new Item;
    item3->setName("health_rune");
    item3->setAttack(0);
    item3->setDefense(0);
    item3->setHealth(0);
    item3->setPrice(300);
    item3->setMaxHealth(200);
    buff.push_back(item3);

    Item* item4 = new Item;
    item4->setName("health_potion");
    item4->setAttack(0);
    item4->setDefense(0);
    item4->setHealth(150);
    item4->setPrice(100);
    item4->setMaxHealth(0);
    buff.push_back(item4);
    npc2->setCommodity(buff);
    room[5]->setObjects(npc2);

    room[6]->setDownRoom(room[0]);
    room[6]->setUpRoom(room[0]);
    room[6]->setLeftRoom(room[5]);
    room[6]->setRightRoom(room[0]);
    room[6]->setIsExit(0);
    Monster* monster2 = new Monster;
    monster2->setName("Gargotle");
    monster2->setMaxHealth(500);
    monster2->setAttack(350);
    monster2->setDefense(150);
    monster2->setCurrentHealth(monster2->getMaxHealth());
    monster2->setMoney(1500);
    monster2->setRoom(*room[6]);
    Item* bonus2 = new Item;
    bonus2->setName("key");
    bonus2->setAttack(0);
    bonus2->setDefense(0);
    bonus2->setHealth(0);
    bonus2->setPrice(0);
    bonus2->setMaxHealth(0);
    fin >> read;
    if(read == "died")
        monster2->setCurrentHealth(0);
    fin >> read;
    if(read == "isTake")
        bonus2->setIsTake(1);
    room[6]->setObjects(monster2);
    room[6]->setObjects(bonus2);


    room[7]->setDownRoom(room[5]);
    room[7]->setUpRoom(room[10]);
    room[7]->setLeftRoom(room[9]);
    room[7]->setRightRoom(room[8]);
    room[7]->setIsExit(0);
    Monster* monster3 = new Monster;
    monster3->setName("Cerberus");
    monster3->setMaxHealth(800);
    monster3->setAttack(500);
    monster3->setDefense(200);
    monster3->setCurrentHealth(monster3->getMaxHealth());
    monster3->setMoney(2500);
    monster3->setRoom(*room[7]);
    fin >> read;
    if(read == "died"){
        monster3->setCurrentHealth(0);
    }
    room[7]->setObjects(monster3);

    room[8]->setDownRoom(room[0]);
    room[8]->setUpRoom(room[0]);
    room[8]->setLeftRoom(room[7]);
    room[8]->setRightRoom(room[0]);
    room[8]->setIsExit(0);
    Item* bonus3 = new Item;
    bonus3->setName("curse");
    bonus3->setAttack(-50);
    bonus3->setDefense(-50);
    bonus3->setHealth(-50);
    bonus3->setPrice(0);
    bonus3->setMaxHealth(0);
    bonus3->setIsTake(0);
    fin >> read;
    if(read == "isTake")
        bonus3->setIsTake(1);
    room[8]->setObjects(bonus3);

    room[9]->setDownRoom(room[0]);
    room[9]->setUpRoom(room[0]);
    room[9]->setLeftRoom(room[0]);
    room[9]->setRightRoom(room[7]);
    room[9]->setIsExit(0);
    NPC* npc3 = new NPC;
    npc3->setScript("It has been a long time no visitors coming! Brave man, how can I help you?");
    npc3->setName("goddess");
    room[9]->setObjects(npc3);

    room[10]->setDownRoom(room[7]);
    room[10]->setUpRoom(room[0]);
    room[10]->setLeftRoom(room[0]);
    room[10]->setRightRoom(room[0]);
    room[10]->setIsExit(1);
    Monster* boss = new Monster;
    boss->setName("dragon");
    boss->setMaxHealth(1000);
    boss->setAttack(800);
    boss->setDefense(300);
    boss->setCurrentHealth(boss->getMaxHealth());
    boss->setRoom(*room[10]);
    fin >> read;
    if(read == "died")
        boss->setCurrentHealth(0);
    room[10]->setObjects(boss);
}

Record::Record(){}

void Record::saveToFile(Player*player, vector<Room*>&room){
    saveRooms(room);
    savePlayer(player);
}

void Record::loadFromFile(Player*player, vector<Room*>&room){
    loadRooms(room);
    loadPlayer(player,room);
}
