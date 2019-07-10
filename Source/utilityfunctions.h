#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <string>

using namespace std;

namespace util
{
    string fTs(float&);
    string toLower(const string&);
    bool equalIgnoreCase(const string&, const string&);
    bool containsStringIgnoreCase(const string&, const string&);
}


#endif // UTILITYFUNCTIONS_H
