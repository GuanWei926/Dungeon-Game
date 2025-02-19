#include <string>
#include <cstdlib>
#include <iostream>
#include "Object.h"
using namespace std;

// constructor
Object::Object(){}

//Object::Object(string Name,string Tag):name(Name), tag(Tag){}

//Object::Object(string Name):name(Name){}

// function
void Object::setName(string Name){
    name = Name;
}

void Object::setTag(string Tag){
    tag = Tag;
}

string Object::getName() const{
    return name;
}

string Object::getTag() const{
    return tag;
}

