#include "linked_list.h"
#include "huffman.h"
#include <iostream>
using namespace std;

// Constructor to initialize the linked list
LinkedList::LinkedList() : head(nullptr) {}

// Destructor to clean up the linked list
LinkedList::~LinkedList() {
    deleteList();
}


// Function to add a new file name to the linked list
void LinkedList::addFile(const string& fileName) {
    Node* newNode = new Node{ fileName, nullptr };
    if (!head) {
        head = newNode; // If the list is empty, add the first node
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add the new node at the end
    }
}

// Function to delete the linked list (free memory)
void LinkedList::deleteList() {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// Function to traverse the list and decompress files
void LinkedList::decompressFiles() const {
    Node* current = head;
    string inputFile, outputFile;

    while (current != nullptr) {
        inputFile = current->fileName;

        cout << "Enter the name of the output file (with extension) for '" << inputFile << "': ";
        cin >> outputFile;

        // Perform Huffman decompression
        huffman h(inputFile, outputFile);
        h.recreate_huffman_tree();
        h.decoding_save();

        cout << "File decompressed successfully as '" << outputFile << "'." << endl;
        current = current->next; // Move to the next file in the list
    }
}

// Function to sort files alphabetically using bubble sort
void LinkedList::sortFiles() {
    if (head == nullptr || head->next == nullptr) {
        return; // No need to sort if the list is empty or has only one file
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->next != nullptr) {
            if (current->fileName > current->next->fileName) {
                // Swap the file names of the nodes
                string temp = current->fileName;
                current->fileName = current->next->fileName;
                current->next->fileName = temp;

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped); // Repeat until no swaps are made (list is sorted)
}
