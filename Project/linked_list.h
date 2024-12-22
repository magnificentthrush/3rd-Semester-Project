#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;

class LinkedList {
private:
    struct Node {
        string fileName; // Store the file name
        Node* next;      // Pointer to the next node
    };
    Node* head;// Pointer to the head of the linked 
public:
    LinkedList();      // Constructor
    ~LinkedList();     // Destructor

    void addFile(const string& fileName);   // Add a file to the list
    void deleteList();                      // Delete the entire list
    void decompressFiles() const;           // Decompress all files
    void sortFiles();                       // Sort files in alphabetical order
};

#endif // LINKED_LIST_H
