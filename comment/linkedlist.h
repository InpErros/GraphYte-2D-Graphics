#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QException>



//**************    Saving the ratings and comments    **************

struct nodeType
{
    int r;                      // rating
    string c;                   // comment
    nodeType *link;             // connector between nodes
};



class linkedListType
{
public:
    linkedListType ();
    void insertlast (const string &newComment, const int &newRate);
    void saveToTxt ();
    void retrieveFromTxt();
    ~linkedListType ();


protected:
    nodeType *first;
    nodeType *last;

};




#endif // LINKEDLIST_H
