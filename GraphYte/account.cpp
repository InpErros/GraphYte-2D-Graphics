#include "account.h"

string p = "";

bool userExists(string user){
    std::ifstream fin;
    fin.open("db.txt");
    string u;

    while(!fin.eof()){
        getline(fin,u);
        if(!fin.peek())
            return false;
        getline(fin,p);
        if(user.compare(u))
            break;
    }
    fin.close();
    return user.compare(u);
}

bool passwordMatch(string pass){
    if(pass == p)
        return true;
    else
        return false;
}
