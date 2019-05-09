#include "account.h"

bool usernameMatch(string u){
    string username;
    bool found = false;

    fstream fin;
    fin.open("db.txt");

    while(!fin.eof() && !found){
        getline(fin, username);
        fin.ignore(1000, '\n');
        fin.ignore(1000, '\n');
        if(username == u)
            found = true;
    }
    fin.close();
    return found;
}

bool passwordMatch(string u, string p){
    string username;
    string password;
    bool found = false;

    fstream fin;
    fin.open("db.txt");

    while(!fin.eof() && !found){
        getline(fin, username);
        getline(fin, password);
        fin.ignore(1000, '\n');

        if(username == u && password == p)
            found = true;
    }
    fin.close();
    return found;
}
