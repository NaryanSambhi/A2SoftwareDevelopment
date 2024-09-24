
//Naryan Sambhi 

//A2 
// Project V : Advanced Software Development
//CSCN73030 - Fall 2024 - Section 1

//Goal:
/*
The purpose of this assignment is to have you walk through the development
process that will be used during the class project. While going through the development 
process, you will implement a set of code that will contain compiler directives for
controlling debug, release, and pre-release testing code using the Visual Studio IDE and C++.
*/



/* 

Next you need to implement the main function to read the StudentData.txt file, create 
student objects and store them into a vector space. Create a struct STUDENT_DATA that 
contains the first and last names of the students. Each line read from the input file 
contains a first/last name pair separated by a comma. Parse the data, create an object 
and push that object into a vector space. When you are finished you should have all
the students listed in your vector space. Commit and push your changes into the repository master.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

//Student data structure 
     //Create a struct STUDENT_DATA that contains the first and last names of the students.
struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};


void parseIntoVector(std::ifstream& file, std::vector<STUDENT_DATA>& students) {
    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        // Parse the line
        std::istringstream iss(line);
        std::string firstName, lastName;

        // Extract first name
        iss >> firstName;

        // Extract last name
        iss >> lastName;

        // Check if parsing was successful
        if (!iss.fail()) {
            // Create STUDENT_DATA object and push to vector
            students.push_back({ firstName, lastName });
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }
}


int main(void) {

    
    //Each line read from the input file  contains a first / last name pair separated 
    // by a comma.Parse the data, create an object and push that object into a vector space.

    // Open the file
    std::ifstream inputFile("StudentData.txt");

    //error handling
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Vector to store student data
    std::vector<STUDENT_DATA> students;


    parseIntoVector(inputFile, students);

    //close
    inputFile.close();

    // Print the parsed data
    std::cout << "Parsed student data:" << std::endl;
    for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << std::endl;
    }

    return 0;
}