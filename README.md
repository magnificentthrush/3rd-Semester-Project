3rd Semester Project: Huffman Compression and Decompression
This project implements Huffman Encoding and Huffman Decoding algorithms for file compression and decompression. Huffman encoding is an efficient algorithm used to reduce file size by using variable-length codes for characters, where frequently occurring characters use shorter codes.

Features:
Compression: Compresses files into smaller sizes using Huffman encoding.
Decompression: Restores the compressed files to their original form using Huffman decoding.
How to Run the Code:
Prerequisites:
Visual Studio 2022 (or later)
C++ compiler
Steps:
Clone the Repository: Clone this repository to your local machine using the following command:
git clone <repository_url>

Open the Project in Visual Studio:

Open Project.sln in Visual Studio 2022 (or later versions).
Build and Run the Solution:

Click on Build > Build Solution (or press Ctrl + Shift + B) to compile the project.
After building, click on Debug > Start Without Debugging (or press Ctrl + F5) to run the program.
Input Files and Output:

For Compression: You will be prompted to provide the full path to the text file you want to compress. For example:

graphql
Copy code
C:\Users\yawar\OneDrive\Desktop\Project\input.rtf
The program will create the compressed file in the project directory (where main.cpp is located).

For Decompression: Similarly, provide the full path to the compressed file and give the desired name for the output file (with extension). E.g., output.txt.

Instructions for Use:
Compression:
After running the program, select Option 1 to compress a file.
Enter the full path of the file you want to compress (e.g., C:\Users\yawar\OneDrive\Desktop\Project\input.rtf).
The program will generate a compressed file in the project directory, with the name you specify for the output file.
Decompression:
Select Option 2 to decompress a file.
Provide the full path to the compressed file when prompted.
Enter the desired name for the decompressed file (make sure to include the file extension, e.g., output.txt).
Notes:
File Extensions: When providing a name for the output file during decompression, ensure you include the file extension (e.g., .txt, .rtf). This is necessary for proper handling of the file.
The program will end after each compression or decompression. If you want the program to run in a loop and process multiple files without restarting, you can modify the main() function to run in an infinite loop.

Example Flow:
Compression:
Please select an option:
1. Compress a file
2. Decompress a file
Enter your choice: 1
Enter the path of the file to compress: C:\Users\yawar\OneDrive\Desktop\Project\input.rtf
Enter the name of the output file: compressed_output.huff
File compressed successfully as 'compressed_output.huff'.

Decompression:
Please select an option:
1. Compress a file
2. Decompress a file
Enter your choice: 2
Enter the path of the compressed file: C:\Users\yawar\OneDrive\Desktop\Project\compressed_output.huff
Enter the name of the output file: decompressed_output.txt
File decompressed successfully as 'decompressed_output.txt'.

