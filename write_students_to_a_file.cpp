/*Example: write a text file NO append just overwrite using a template, writing students to a file*/
/*Using vector as a buffer, and the operator<< overloaded as a template function for the Student class*/

#include <iostream>
#include <fstream>
#include <vector>

// Template function to write data to a file (overwrite)
template<typename T>
void writeThisToFile_x(T whatToWrite, std::string writeToFile){
	std::ofstream myfile(writeToFile); // Open the file specified by writeToFile (overwrite)
	myfile<<whatToWrite;// Write the content (whatToWrite) to the file
	myfile.close();

}

class Student{
	private:
		std::string m_name;
		std::string m_firstName;
		unsigned int m_age;

	public:
		Student(std::string name, std::string firstName, unsigned int age): m_name{name}, m_firstName{firstName}, m_age{age}{}
		template<typename T> /*overloaded insertion operator<< as template for the class Student*/
		friend std::ostream& operator<<(std::ostream& out, const T& st){
			out<< st.m_firstName<<' '<< st.m_name<<' '<<st.m_age<< '\n';
			return out;
		}
};

int main(){
	std::vector<Student> vectOfStudents;
	vectOfStudents.insert( vectOfStudents.begin(), {
		{"Taylor", "Anna", 12},
		{"Jacobs", "Brian", 15},
		{"Knight", "Claire", 13},
		{"Smith", "David", 14}, }); // Fill vector with instances of Student (this is a nameless container with instances of nameless students)
        
	for (auto el: vectOfStudents) writeThisToFile_x(el, "students.txt"); // Iterate through each student in the vector and write to file "students.txt" (overwriting)
	return 0;
}

/*Explaining results: 
1) Main function creates a vector named vectOfStudents.
2) It uses vectOfStudents.insert() to insert the for Student objects in the vector.
3) It iterates through each Student object in the vector using a range-based for loop:
    For each object, it calls writeThisToFile_x(el, "students.txt"), which writes the 
    Student object to the "students.txt" file. Since the function always
    overwrites the file each time it's called, the final content is simply:
    Smith David 14.*/
    