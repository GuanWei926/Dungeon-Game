#include "Room.h"

// constructor
Room::Room(){}
/*Room::Room(bool IsExit, int Index, vector<Object*>things):
    isExit(IsExit), index(Index), objects(things){}
Room::Room(int Index){
    index = Index;
}*/


// function
/*bool popObject(Object*object){
    if(object.)
} */

void Room::setUpRoom(Room*room){
    upRoom = room;
}

void Room::setDownRoom(Room*room){
    downRoom = room;
}

void Room::setLeftRoom(Room*room){
    leftRoom = room;
}

void Room::setRightRoom(Room*room){
    rightRoom = room;
}

void Room::setIsExit(bool IsExit){
    isExit = IsExit;
}

void Room::setIndex(int Index){
    index = Index;
}

void Room::setObjects(Object* thing){
    objects.push_back(thing);
}

bool Room::getIsExit(){
    return exit;
}

int Room::getIndex(){
    return index;
}

vector<Object*> Room::getObjects(){
    return objects;
}

Room* Room::getUpRoom(){
    return upRoom;
}

Room* Room::getDownRoom(){
    return downRoom;
}

Room* Room::getLeftRoom(){
    return leftRoom;
}

Room* Room::getRightRoom(){
    return rightRoom;
}
