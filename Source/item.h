#ifndef ITEM_H_
#define ITEM_H_

#include "utilityfunctions.h"

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
	string description;
	string longDescription;
    float weightGrams;
	float value;
	bool weaponCheck;

public:
    Item (string description, float inWeight, float inValue);
    Item (string description);
	int getWeight();
    void setWeight(float weightGrams);
	float getValue();
	void setValue(float value);
    virtual string getShortDescription();
    virtual string getLongDescription();
    virtual int getATK();
};

#endif /*ITEM_H_*/
