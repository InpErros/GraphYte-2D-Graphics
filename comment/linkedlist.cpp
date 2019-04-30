#include "linkedlist.h"


linkedListType::linkedListType ()
{
    first = nullptr;
    last = nullptr;
}



void linkedListType::insertlast(const string &newComment, const int &newRate)
{
    nodeType *newNode;

    newNode = new nodeType;
    newNode->r = newRate;
    newNode->c = newComment;
    newNode->link = nullptr;

    if(first == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        last->link = newNode;
        last = newNode;
    }
}



void linkedListType::saveToTxt()
{
    ofstream outFile;
    outFile.open ("/Users/kentrick/homework/comment/savedComments.txt");

    if (outFile.fail())
    {
        cout << "There is a problem opening output file savedComments.txt";
        exit(1);
    }


    nodeType *current;

    current = first;

    while(current != nullptr)
    {
       outFile << current->r << endl;
       outFile << current->c << endl;



       current = current->link;
    }

    outFile.close();

}



void linkedListType::retrieveFromTxt()
{
    ifstream inFile;

    inFile.open("/Users/kentrick/homework/comment/savedComments.txt");

    if (!inFile)
    {
        cout << "There is a problem opening input file savedComments.txt";
        exit(1);
    }


    while(!inFile.fail())
    {
        nodeType *newNode;

        newNode = new nodeType;
        inFile >> newNode->r;
        inFile.ignore (1000, '\n');
        getline (inFile, newNode->c);


        newNode->link = nullptr;

        // If the text file is empty, exit the while loop
        if(newNode->r == 0)
            continue;           // Go to the beginning of the while loop and
                                // the condition (!inFile.fail()) will return false,
                                // which will then exit the while loop.

        // else...
        else
        {
            if(first == nullptr)
            {
                first = newNode;
                last = newNode;
            }
            else
            {
                last->link = newNode;
                last = newNode;
            }
        }


    }

    inFile.close();

}



linkedListType::~linkedListType()
{
    nodeType *temp;

    while(first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }

    last = nullptr;

}
