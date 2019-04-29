#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
using std::fstream;
using std::endl;
using std::string;

class AccountList{
private:
    struct Account{
        string name;
        string email;
        string username;
        string password;
    };
    vector<Account> list;
public:
    AccountList(){}
    ~AccountList(){}

    void fillList();
    void pushList();
    void newMember();
    bool usernameExists(string);
    bool passwordMatch(string);
    void pushNewMember(string,string,string,string);
    bool isEmpty(fstream&);
};

#endif // ACCOUNTLIST_H
