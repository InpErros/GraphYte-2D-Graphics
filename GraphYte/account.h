#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

bool userExists(string);
bool passwordMatch(string);
#endif // ACCOUNT_H
