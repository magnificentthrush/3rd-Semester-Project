#include "huffman.h"
#include "linked_list.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string getFileName(const string& filePath) {
    size_t pos = filePath.find_last_of("/\\");  // Find last '/' or '\\'
    if (pos != string::npos) {
        return filePath.substr(pos + 1);  // Return the substring after the last separator
    }
    return filePath;  // If no separator, return the whole string
}

int main() {

    unordered_map<string, string> map;

    cout << "Welcome to Huffman Coding Utility!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Compress multiple files" << endl;
    cout << "2. Decompress multiple files" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        // Compression of multiple files using a stack
        Stack<string> filesToCompress;
        string inputFile, outputFile;
        char anotherFile;

        // Input multiple files to compress
        do {
            cout << "Enter the path of the file to compress: ";
            cin >> inputFile;
            filesToCompress.push(inputFile);

            cout << "Would you like to compress another file? (y/n): ";
            cin >> anotherFile;
        } while (anotherFile == 'y' || anotherFile == 'Y');

        // Process each file in the stack (LIFO order)
        while (!filesToCompress.isEmpty()) {
            inputFile = filesToCompress.topValue();
            filesToCompress.pop();

            // Extract the filename from the full path
            string fileName = getFileName(inputFile);

            cout << "Processing file: " << fileName << endl;

            cout << "Enter the name of the output file: ";
            cin >> outputFile;

            // Perform Huffman compression
            huffman h(inputFile, outputFile);
            h.create_pq();
            h.create_huffman_tree();
            h.calculate_huffman_codes();
            h.coding_save();


            // Display only the filename in the success message
            string outputFileName = getFileName(outputFile);
            cout << "File compressed successfully as '" << outputFileName << "'." << endl;
            map[fileName] = outputFileName;
        }

    }
    else if (choice == 2) {
        // Decompression of multiple files using LinkedList
        LinkedList list;
        string inputFile;
        char anotherFile;

        // Input multiple compressed files to decompress
        do {
            cout << "Enter the path of the compressed file: ";
            cin >> inputFile;

            list.addFile(inputFile); // Add the file to the linked list
            cout << "Would you like to decompress another file? (y/n): ";
            cin >> anotherFile;
        } while (anotherFile == 'y' || anotherFile == 'Y');

        list.sortFiles();
        // Decompress all files stored in the linked list (FIFO order)
        list.decompressFiles();

    }
    else {
        cout << "Invalid choice. Please run the program again and select a valid option." << endl;
    }

    cout << "\nFile Processing Summary:" << endl;
    for (const auto& pair : map) {
        cout << "Input File: " << pair.first << " -> Output File: " << pair.second << endl;
    }

    return 0;
}
