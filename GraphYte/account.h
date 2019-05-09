#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::endl;

bool usernameMatch(string);
bool passwordMatch(string, string);
#endif // ACCOUNT_H
