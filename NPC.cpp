#include "NPC.h"
//#include "Item.cpp"

//constructor
NPC::NPC(){}
/*NPC::NPC(string Name, string Script){
    this->setName(Name);
    script = Script;
}*/

// function
void NPC::setScript(string Script){
    script = Script;
}

void NPC::listCommodity(){
    for(int i=0 ; i<commodity.size() ; i++){
        cout << "(" << i+1 << ")" << commodity[i]->getName() << "($" <<commodity[i]->getPrice() << ")" << "     ";
    }
    cout << endl;
}

bool NPC::triggerEvent(Object* object){
    Player* player = dynamic_cast<Player*>(object);
    while(true){
        cout << "Which commodity do you want to trade? (If you want to leave, press 0)" << endl;
        cout << "(Now you have $" << player->getMoney() << ")" << endl;
        listCommodity();
        int choice;
        cin >> choice;
        if(choice == 0)
            break;
        else if(choice<0 || choice > commodity.size()){
            cout << "We don't sell that item. Please choose again!" << endl;
            continue;
        }

        if(commodity[choice-1]->getPrice() > player->getMoney()){
            cout << "You do not have enough money." << endl;
        }
        else{
            cout << endl;
            cout << "Congratulations !!! Now you are more powerful !" << endl;
            player->addItem(commodity[choice-1]);
            int money = player->getMoney() - commodity[choice-1]->getPrice();
            player->setMoney(money);
            player->increaseStates(commodity[choice-1]->getAttack(), commodity[choice-1]->getDefense(), commodity[choice-1]->getMaxHealth(), commodity[choice-1]->getHealth());
            if(player->getCurrentHealth() > player->getMaxHealth())
                player->setCurrentHealth(player->getMaxHealth());
        }
    }
    return true;
}

void NPC::setCommodity(vector<Item*>Commodity){
    commodity = Commodity;
}

string NPC::getScript(){
    return script;
}

vector<Item*>NPC::getCommodity(){
    return commodity;
}
