/*beginners example: write a text file with NO append, just overwriting (includes a template)*/

#include <iostream>
#include <fstream> //<fstream> library provides functions for files

/*templates are useful because they adapt to each type of variable*/

template<typename T>
// /template function to write content to a file
void writeThisToFile_x(T whatToWrite, std::string writeToFile){
	std::ofstream myfile(writeToFile); // Open the file specified by writeToFile
	myfile<<whatToWrite; // Write the content (whatToWrite) to the file
	myfile.close();

}

int main(){
    // Call the template function with different types of arguments
	writeThisToFile_x("value 1\n", "test.txt");	
	writeThisToFile_x(2.56, "testDouble.txt");
	writeThisToFile_x('c', "testChar.txt");
	return 0;
}
