/*beginners example: write a text file with NO append, just overwriting (includes a function)*/

#include <iostream>
#include <fstream> //<fstream> library provides functions for files

// Function to write content to a file
void writeThisToFile_x(std::string whatToWrite, std::string writeToFile){
    std::ofstream myfile(writeToFile);// Open the file specified by writeToFile
	myfile<<whatToWrite; // Write the content (whatToWrite) to the file
	myfile.close();

}

int main(){
	writeThisToFile_x("value 1\n", "test.txt"); // Call the writeThisToFile_x function with arguments,  "wert 1\n" - content to write, "test.txt" - name of the file
	return 0;
}
