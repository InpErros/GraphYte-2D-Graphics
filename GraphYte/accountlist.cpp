#include "accountlist.h"

void AccountList::pushList(){
    fstream fout;
    fout.open("db.text");

    for(auto i: list){
        fout << i.name << endl;
        fout << i.email << endl;
        fout << i.username << endl;
        fout << i.password << endl;
    }
    fout.close();
}

void AccountList::fillList(){
    fstream fin;
    fin.open("db.txt");

    if(isEmpty(fin)){
        return;
    }
    do{
        Account a;
        getline(fin,a.name);
        getline(fin,a.email);
        getline(fin,a.username);
        getline(fin,a.password);

        list.push_back(a);
    }while(fin.eof());
    fin.close();
}


bool AccountList::passwordMatch(string pass){
    for(auto i: list){
        if(pass.compare(i.password) == 0){
            return true;
        }
    }

    return false;
}

void AccountList::pushNewMember(string n, string e, string u, string p){
    Account a;

    a.name = n;
    a.email = e;
    a.username = u;
    a.password = p;

    list.push_back(a);
}

bool AccountList::isEmpty(fstream& fin){
    return fin.peek() == std::ifstream::traits_type::eof();
}
