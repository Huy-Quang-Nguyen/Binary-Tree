#include <fstream>
#include <iostream>
#include "BinaryTree.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char *argv[]){

    BinaryTree tree;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);
    if (fs.is_open())
    {
        fs >> input;
        while (!fs.eof())
        {
            item.initialize(input);
            tree.insertItem(item);
            fs >> input;
        }
    }else{
        cout << "Failed to open the input file" << endl;
        return 0;
    }

    cout << "insert (i), delete(d), retrieve(r), length(l), in-order(n)," << endl
         << "pre-order(p), post-order(o), getSameLevelNonSiblings(c), quit (q)" << endl;
    
    string command = "";
    while(command != "q"){
  
        cout << "Enter a command: ";
        cin >> command;
        if(command == "i"){
            cout << "Item to insert: ";
            int num;
            cin >> num;
            ItemType pItem;
            pItem.initialize(num);
            tree.insertItem(pItem);
            cout << "In-Order: ";
            tree.inOrder();
            cout << endl;
        }
        else if(command == "d"){
            cout << "Item to delete: ";
            int num;
            cin >> num;
            ItemType pItem;
            pItem.initialize(num);
            tree.deleteItem(pItem);
            cout << "In-Order: ";
            tree.inOrder();
            cout << endl;
        }

        else if(command == "l"){
            cout << "List Length: " << tree.getLength() << endl;
        }

        else if(command == "p"){
            cout << "Pre-Order: ";
            tree.preOrder();
        }

        else if(command == "q"){
            cout << "Quitting program..." << endl;
            return 0;
        }

        else if(command == "r"){
            cout << "Item to be retrieved: " << endl;
            int num;
            cin >> num;
            ItemType pItem;
            pItem.initialize(num);
            bool found = false;
            tree.retrieve(pItem, found);
            if(found == false){
                cout << "Item not in tree." << endl;
            }
        }

        else if(command == "o"){
            cout << "Post-Order: ";
            tree.postOrder();
        }
        
        else if(command == "n"){
            cout << "In-Order: ";
            tree.inOrder();
        }

        else if(command == "c"){
            cout << "Did not attempt;" << endl;
        }
        
        else{
            cout << "Command not recognized. Try again " << endl;
        }
    }
}
