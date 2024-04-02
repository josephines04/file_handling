/*beginners example: write a text file with NO append, just overwriting*/

#include <iostream>
#include <fstream> //<fstream> library provides functions for files

int main(){
	std::ofstream myfile("test.txt");
	myfile<<"hello\n";
	myfile.close();
	return 0;
}
