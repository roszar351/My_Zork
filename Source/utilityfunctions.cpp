#include "utilityfunctions.h"

string util::fTs(float &num)
{
    int temp = int(num * 100);
    return to_string((int(num))) + "." + to_string(temp % 100);
}

// Not used
string util::toLower(const string &s)
{
    string result = "";
    for(unsigned int i = 0; i < s.size(); i++)
        result += char(tolower(s[i]));

    return result;
}

bool util::equalIgnoreCase(const string &s1, const string &s2)
{
    if(s1.size() != s2.size())
        return false;
    else
        for(unsigned int i = 0; i < s1.size(); i++)
            if(tolower(s1[i]) != tolower(s2[i]))
                return false;

    return true;
}

bool util::containsStringIgnoreCase(const string &s1, const string &s2)
{
    if(s2.size() >= 3)
    {
        if(equalIgnoreCase(s1, s2))
            return true;
        else
            if(toLower(s1).find(toLower(s2)) != string::npos)
                return true;
    }

    return false;
}
