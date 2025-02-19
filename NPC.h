#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
//#include "Item.cpp"
//#include "Player.cpp"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item*> commodity;
public:
    NPC();
    //NPC(string Name, string Script);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object* object);

    /* Set & Get function*/
    void setScript(string Script);
    void setCommodity(vector<Item*>Commodity);
    string getScript();
    vector<Item*> getCommodity();
};


#endif // NPC_H_INCLUDED
