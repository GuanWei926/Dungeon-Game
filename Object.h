#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    //Object(string Name,string Tag);
    //Object(string Name);

    /* pure virtual function */
    virtual bool triggerEvent(Object* object) = 0;

    /* Set & Get function*/
    void setName(string Name);
    void setTag(string Tag);
    string getName() const;
    string getTag() const;
};

#endif // OBJECT_H_INCLUDED
