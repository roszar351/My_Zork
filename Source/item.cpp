#include "item.h"

Item::Item (string inDescription, float inWeightGrams, float inValue) {
	description = inDescription;
	setWeight(inWeightGrams);
    value = inValue;
}

Item::Item(string inDescription) {
	description = inDescription;
}

void Item::setWeight(float inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    return description + ",  "+ util::fTs(weightGrams) + "kg,  " + util::fTs(value) + "g";
}

int Item::getATK()
{
    return 0;
}
