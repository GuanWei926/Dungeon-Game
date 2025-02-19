#include "Dungeon.h"
#include <cmath>


Dungeon::Dungeon(){}
void Dungeon::createMap(){
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
    bonus1->setAttack(0);
    bonus1->setDefense(50);
    bonus1->setHealth(0);
    bonus1->setPrice(0);
    bonus1->setMaxHealth(0);
    room[3]->setObjects(monster1);
    room[3]->setObjects(bonus1);

    room[4]->setDownRoom(room[0]);
    room[4]->setUpRoom(room[0]);
    room[4]->setLeftRoom(room[0]);
    room[4]->setRightRoom(room[2]);
    room[4]->setIsExit(0);
    NPC* npc1 = new NPC;
    npc1->setCurrentHealth(1);
    npc1->setScript("I...I encountered a horrible monster and got attacked. I am afraid I'll die soon.\nPl..Please defeat the monster and save the world on my behalf. (adventurer died)");
    npc1->setName("adventurer");
    Item* item = new Item;
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
    room[10]->setObjects(boss);
}

void Dungeon::createPlayer(){
    string name;
    cout << "What's your name? " << endl;
    cin >> name;
    player.setName(name);
    cout << endl;
    cout << "Which occupation do you want to choose?(TYPE NUMBER)" << endl;
    cout << "1.WARRIOR    2.TANK    3.WIZARD" << endl;
    int choice;
    cin >> choice;
    player.setPreviousRoom(room[0]);
    player.setCurrentRoom(room[1]);
    player.setCurrentCD(5);
    player.setMoney(500);
    player.setKey(0);
    if(choice==1){
        player.setAttack(400);
        player.setDefense(200);
        player.setMaxHealth(300);
        player.setCurrentHealth(300);
        player.setOccupation("Warrior");
        player.setSkill("Whirlwind");
    }
    else if(choice==2){
        player.setAttack(250);
        player.setDefense(300);
        player.setCurrentHealth(400);
        player.setMaxHealth(400);
        player.setOccupation("Tank");
        player.setSkill("Absolute-Shield");
    }
    else if(choice==3){
        player.setAttack(300);
        player.setDefense(250);
        player.setMaxHealth(400);
        player.setCurrentHealth(400);
        player.setOccupation("Wizard");
        player.setSkill("Fire-Ball");
    }
    cout << endl;
    player.triggerEvent(&player);
    cout << endl << "You are in room " << player.getCurrentRoom()->getIndex() << endl;
}

void Dungeon::handleMovement(){
    cout << "What do you want to do?" << endl;
    cout << "1.check your status    2.move to another room  3.check your backpack   4.save file" << endl;
    int Ans;
    cin >> Ans;
    cout << endl;
    if(Ans == 1)
        player.triggerEvent(&player);
    else if(Ans==2){
        int type = 0;
        cout << "Which direction do you want to go" << endl;
        cout << "A. go down" << endl;
        cout << "B. go up" << endl;
        cout << "C. go left" << endl;
        cout << "D. go right" << endl;
        char ans;
        cin >> ans;
        if(ans == 'A' || ans == 'a'){
            if(player.getCurrentRoom()->getDownRoom() == room[0]){
                type = 1;
            }
            else{
                Room* temp = player.getCurrentRoom();
                player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
                player.setPreviousRoom(temp);
            }
        }
        else if(ans == 'B' || ans == 'b'){
            if(player.getCurrentRoom()->getUpRoom() == room[0]){
                type = 1;
            }
            else if(player.getCurrentRoom()->getUpRoom() == room[10] && !player.getKey()){
                type = 2;
            }
            else{
                Room* temp = player.getCurrentRoom();
                player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
                player.setPreviousRoom(temp);
            }
        }
        else if(ans == 'C' || ans == 'c'){
            if(player.getCurrentRoom()->getLeftRoom() == room[0]){
                type = 1;
            }
            else{
                Room* temp = player.getCurrentRoom();
                player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
                player.setPreviousRoom(temp);
            }
        }
        else if(ans == 'D' || ans == 'd'){
            if(player.getCurrentRoom()->getRightRoom() == room[0]){
                type = 1;
            }
            else{
                Room* temp = player.getCurrentRoom();
                player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
                player.setPreviousRoom(temp);
            }
        }

        cout << endl;
        if(type == 1){
            cout << "There is no room in this direction. Please choose again." << endl;
        }
        else if(type == 2){
            cout << "The door of the room10 seems to be locked !\nYou cannot enter." << endl;
            cout << endl;
        }
        else{
            player.move_picture();
            cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
        }
    }

    else if(Ans==3){
        if(player.getInventory().empty())
            cout << "You don't have anything in your backpack.\n" << endl;
        else{
            cout << "backpack: ";
            for(int i=0 ; i<player.getInventory().size() ; i++){
                cout <<  player.getInventory()[i]->getName() ;
                if(i!=player.getInventory().size()-1)
                    cout << " | ";
            }
            cout << endl << endl;;
        }
    }

    else if(Ans==4){
        record->saveToFile(&player, room);
    }
}

void Dungeon::startGame(){
    cout << "Welcome to this magical dungeon." << endl;
    cout << "Your task is trying to find the exit. Good luck!" << endl;
    cout << "(Please enter the number to choose the decision.)" << endl;
    cout << endl;
    createMap();
    createPlayer();
}

void Dungeon::runDungeon(){
    bool retreat = 0;
    cout << "Do you want to load the previous record?\n1.Yes   2.No\n";
    int choice;
    cin >> choice;
    if(choice == 1){
        record->loadFromFile(&player, room);
        cout << "\nNow you are in room " << player.getCurrentRoom()->getIndex() << endl;
    }
    else
        startGame();
    while(true){
        Room* currentRoom = player.getCurrentRoom();
        if(!retreat){
            handleMovement();
        }
        if(player.getCurrentRoom() == currentRoom && !retreat)
            continue;
        if(player.getCurrentRoom() == room[3]){
            Monster* monster = dynamic_cast<Monster*>(room[3]->getObjects()[0]);
            Item* item = dynamic_cast<Item*>(room[3]->getObjects()[1]);
            retreat = 0;
            if(monster->triggerEvent(&player)){
                cout << "Monster " << room[3]->getObjects()[0]->getName() << " appears." << endl;
                cout << "Which action do you want to take?" << endl;
                int ans;
                cout << "1.fight    2.retreat" << endl;
                cin >> ans;
                cout << endl;
                if(ans==1){
                    while(monster->triggerEvent(&player)){
                        monster->combatSystem(&player);
                        cout << endl;
                        if(player.getCurrentHealth() <= 0){
                            cout << "do you want to save file?\n1.Yes   2.No\n";
                            int Ans;
                            cin >> Ans;
                            if(Ans == 1){
                                record->saveToFile(&player, room);
                                exit(1);
                            }
                            else
                                exit(1);
                        }
                        if(monster->triggerEvent(&player)){
                            cout << "Which action do you want to take?" << endl;
                            cout << "1.fight    2.retreat" << endl;
                            cin >> ans;
                            cout << endl;
                            if(ans==2){
                                player.changeRoom(player.getPreviousRoom());
                                retreat = 1;
                                cout << endl;
                                cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                                monster->setCurrentHealth(monster->getMaxHealth());
                                break;
                            }
                            else
                                continue;
                        }
                    }
                }

                else if(ans == 2){
                    player.changeRoom(player.getPreviousRoom());
                    retreat = 1;
                    cout << endl;
                    cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                }
            }

            if(!(monster->triggerEvent(&player)) && !(item->getIsTake())){
                cout << "You find a chest. Do you want to open it ?" << endl;
                cout << "1.Yes      2.No" << endl;
                int Ans;
                cin >> Ans;
                if(Ans==1){
                    cout << "Congratulations ! You got a new weapon: " << item->getName() << endl;
                    cout << "Now your defense will increase 50" << endl;
                    player.addItem(item);
                    item->triggerEvent(&player);
                    item->setIsTake(1);
                }
                cout << endl;
            }
        }

        else if(player.getCurrentRoom() == room[4]){
            retreat = 0;
            NPC* npc_temp = dynamic_cast<NPC*>(room[4]->getObjects()[0]);
            Item* item = dynamic_cast<Item*>(room[4]->getObjects()[1]);
            if(npc_temp->getCurrentHealth() != 0){
                cout << npc_temp->getName() << " : ";
                cout << npc_temp->getScript() << endl;
                cout << endl;
                npc_temp->setCurrentHealth(0);
            }
            if(!(item->getIsTake())){
                cout << "The adventurer left a weapon to you.\nDo you want to take?\n1.Yes      2.No" << endl;
                int ans;
                cin >> ans;
                if(ans == 1){
                    item->setIsTake(1);
                    if(player.getOccupation() == "Warrior"){
                        cout << "Congratulations you got a sword!!!" << endl;
                        item->setName("sword");
                        item->setAttack(100);
                        item->setDefense(0);
                        item->setHealth(0);
                        item->setPrice(0);
                        item->setMaxHealth(0);
                        item->triggerEvent(&player);
                        player.addItem(item);
                        cout << "Now your attack will increase 100.\n" << endl;
                    }

                    else if(player.getOccupation() == "Tank"){
                        cout << "Congratulations you got a shield!!!" << endl;
                        item->setName("shield");
                        item->setAttack(0);
                        item->setDefense(100);
                        item->setHealth(0);
                        item->setPrice(0);
                        item->setMaxHealth(0);
                        item->triggerEvent(&player);
                        player.addItem(item);
                        cout << "Now your defense will increase 100.\n" << endl;
                    }

                    else if(player.getOccupation() == "Wizard"){
                        cout << "Congratulations you got a magic wand!!!" << endl;
                        item->setName("magic-wand");
                        item->setAttack(50);
                        item->setDefense(0);
                        item->setHealth(0);
                        item->setPrice(0);
                        item->setMaxHealth(50);
                        item->triggerEvent(&player);
                        if(player.getCurrentHealth()+50 >= player.getMaxHealth())
                            player.setCurrentHealth(player.getMaxHealth());
                        else
                            player.setCurrentHealth(player.getCurrentHealth()+50);
                        player.addItem(item);
                        cout << "Now your attack and Health will increase 50 respectively.\n" << endl;
                    }
                }
            }
        }

        else if(player.getCurrentRoom() == room[5]){
            retreat = 0;
            NPC* npc_temp = dynamic_cast<NPC*>(room[5]->getObjects()[0]);
            cout << npc_temp->getName() << " : ";
            cout << npc_temp->getScript() << endl;
            int ans;
            cin >> ans;
            if(ans==2){
                cout << "Ok! Maybe you will change your decision soon!" << endl;
                cout << endl;
            }
            else if(ans==1){
                npc_temp->triggerEvent(&player);
            }
        }

        else if(player.getCurrentRoom() == room[6]){
            Monster* monster = dynamic_cast<Monster*>(room[6]->getObjects()[0]);
            Item* item = dynamic_cast<Item*>(room[6]->getObjects()[1]);
            retreat = 0;
            if(monster->triggerEvent(&player)){
                cout << "Monster " << room[6]->getObjects()[0]->getName() << " appears." << endl;
                cout << "Which action do you want to take?" << endl;
                int ans;
                cout << "1.fight    2.retreat" << endl;
                cin >> ans;
                cout << endl;
                if(ans==1){
                    while(monster->triggerEvent(&player)){
                        //cout << "MONSTER HP:" << monster->getCurrentHealth() << endl;
                        monster->combatSystem(&player);
                        cout << endl;
                        if(player.getCurrentHealth() <= 0){
                            cout << "do you want to save file?\n1.Yes   2.No\n";
                            int Ans;
                            cin >> Ans;
                            if(Ans == 1){
                                record->saveToFile(&player, room);
                                exit(1);
                            }
                            else
                                exit(1);
                        }
                        if(monster->triggerEvent(&player)){
                            cout << "Which action do you want to take?" << endl;
                            cout << "1.fight    2.retreat" << endl;
                            cin >> ans;
                            cout << endl;
                            if(ans==2){
                                player.changeRoom(player.getPreviousRoom());
                                retreat = 1;
                                cout << endl;
                                cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                                monster->setCurrentHealth(monster->getMaxHealth());
                                break;
                            }
                            else
                                continue;
                        }
                    }
                }

                else if(ans == 2){
                    player.changeRoom(player.getPreviousRoom());
                    retreat = 1;
                    cout << endl;
                    cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                }
            }

            if(!(monster->triggerEvent(&player)) && !(item->getIsTake())){
                cout << "You find a chest. Do you want to open it ?" << endl;
                cout << "1.Yes      2.No" << endl;
                int Ans;
                cin >> Ans;
                if(Ans==1){
                    cout << "Congratulations ! You got a " << item->getName() << endl;
                    cout << "Maybe it may be used soon !!!" << endl;
                    player.addItem(item);
                    player.setKey(1);
                    item->triggerEvent(&player);
                    item->setIsTake(1);
                }
                cout << endl;
            }
        }

        else if(player.getCurrentRoom() == room[7]){
            Monster* monster = dynamic_cast<Monster*>(room[7]->getObjects()[0]);
            retreat = 0;
            if(monster->triggerEvent(&player)){
                cout << "Monster " << room[7]->getObjects()[0]->getName() << " appears." << endl;
                cout << "Which action do you want to take?" << endl;
                int ans;
                cout << "1.fight    2.retreat" << endl;
                cin >> ans;
                cout << endl;
                if(ans==1){
                    while(monster->triggerEvent(&player)){
                        monster->combatSystem(&player);
                        cout << endl;
                        if(player.getCurrentHealth() <= 0){
                            cout << "do you want to save file?\n1.Yes   2.No\n";
                            int Ans;
                            cin >> Ans;
                            if(Ans == 1){
                                record->saveToFile(&player, room);
                                exit(1);
                            }
                            else
                                exit(1);
                        }
                        if(monster->triggerEvent(&player)){
                            cout << "Which action do you want to take?" << endl;
                            cout << "1.fight    2.retreat" << endl;
                            cin >> ans;
                            cout << endl;
                            if(ans==2){
                                player.changeRoom(player.getPreviousRoom());
                                retreat = 1;
                                cout << endl;
                                cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                                monster->setCurrentHealth(monster->getMaxHealth());
                                break;
                            }
                            else
                                continue;
                        }
                    }
                }

                else if(ans == 2){
                    player.changeRoom(player.getPreviousRoom());
                    retreat = 1;
                    cout << endl;
                    cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                }
            }
        }

        else if(player.getCurrentRoom() == room[8]){
                retreat = 0;
                Item* item = dynamic_cast<Item*>(room[8]->getObjects()[0]);
                if(!(item->getIsTake())){
                    cout << "You find a chest. Do you want to open it ?" << endl;
                    cout << "1.Yes      2.No" << endl;
                    int Ans;
                    cin >> Ans;
                    if(Ans==1){
                        cout << "Oops ! You got a " << item->getName()  << " from a demon" << endl;
                        cout << "Your attack, defense, and health decrease 50 !!!" << endl;
                        item->triggerEvent(&player);
                        item->setIsTake(1);
                    }
                    cout << endl;
                }
            }

        else if(player.getCurrentRoom() == room[9]){
            retreat = 0;
            NPC* npc_temp = dynamic_cast<NPC*>(room[9]->getObjects()[0]);
            cout << npc_temp->getName() << " : ";
            cout << npc_temp->getScript() << endl;
            cout << "1.Healing(need cost $100)      2.No,thanks" << endl;
            int ans;
            cin >> ans;
            cout << endl;
            if(ans == 1){
                player.setCurrentHealth(player.getMaxHealth());
                cout << "Now you can have more adventure!" << endl;
                player.triggerEvent(&player);
            }
            else{
                cout << "Hope I can see you soon." << endl;
            }
            cout << endl;
        }

        else if(player.getCurrentRoom() == room[10]){
            cout << "You use the key opening the boss room !!!" << endl;
            Monster* monster = dynamic_cast<Monster*>(room[10]->getObjects()[0]);
            retreat = 0;
            if(monster->triggerEvent(&player)){
                cout << "Monster " << room[10]->getObjects()[0]->getName() << " appears." << endl;
                cout << "Which action do you want to take?" << endl;
                int ans;
                cout << "1.fight    2.retreat" << endl;
                cin >> ans;
                cout << endl;
                if(ans==1){
                    while(monster->triggerEvent(&player)){
                        //cout << "MONSTER HP:" << monster->getCurrentHealth() << endl;
                        monster->combatSystem(&player);
                        cout << endl;
                        if(player.getCurrentHealth() <= 0){
                            cout << "do you want to save file?\n1.Yes   2.No\n";
                            int Ans;
                            cin >> Ans;
                            if(Ans == 1){
                                record->saveToFile(&player, room);
                                exit(1);
                            }
                            else
                                exit(1);
                        }
                        if(monster->triggerEvent(&player)){
                            cout << "Which action do you want to take?" << endl;
                            cout << "1.fight    2.retreat" << endl;
                            cin >> ans;
                            cout << endl;
                            if(ans==2){
                                player.changeRoom(player.getPreviousRoom());
                                retreat = 1;
                                cout << endl;
                                cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                                monster->setCurrentHealth(monster->getMaxHealth());
                                break;
                            }
                            else
                                continue;
                        }
                    }
                    if(!(monster->triggerEvent(&player))){
                        cout << "You defeat the boss and save the world !!! \nGame Over!!!\n";
                        exit(1);
                    }
                }

                else if(ans == 2){
                    player.changeRoom(player.getPreviousRoom());
                    retreat = 1;
                    cout << endl;
                    cout << "now you are in the room " << player.getCurrentRoom()->getIndex() << endl;
                }
            }
        }
    }
}
