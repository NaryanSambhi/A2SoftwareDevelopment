
// Naryan Sambhi 

// A2 
// Project V : Advanced Software Development
// CSCN73030 - Fall 2024 - Section 1

// Goal:
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

//#define STANDARD
#define PRE_RELEASE

// Student data structure 
    #ifdef PRE_RELEASE
    struct STUDENT_DATA {

        std::string firstName;
        std::string lastName;
        std::string email;

    };
    #endif
    #ifdef STANDARD
    struct STUDENT_DATA {

        std::string firstName;
        std::string lastName;

    };
    #endif

//parse into vector function
void parseIntoVector(std::ifstream& file, std::vector<STUDENT_DATA>& students) {
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

      

#ifdef STANDARD     //standard has two vars

        std::string firstVar, lastVar;


        iss >> firstVar;
        iss >> lastVar;
        if (!iss.fail()) {
            students.push_back({ firstVar, lastVar });
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
#endif

#ifdef PRE_RELEASE  //prelease has three vars

        std::string firstVar, middleVar, lastVar;


        std::getline(iss, firstVar, ','); //had to change method for prerelease
        std::getline(iss, middleVar, ',');
        std::getline(iss, lastVar);
        if (!iss.fail()) {
            students.push_back({ firstVar, middleVar, lastVar });
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
#endif
    }
}

int main() {

//print version 
        std::cout << "This Application is running in ";
    #ifdef STANDARD
        std::cout << "standard" << std::endl;
    #endif

    #ifdef PRE_RELEASE
        std::cout << "PRE_RELEASE" << std::endl;
    #endif


//file used
    #ifdef STANDARD
        std::ifstream inputFile("StudentData.txt");
    #endif

    #ifdef PRE_RELEASE
        std::ifstream inputFile("StudentData_Emails.txt");
    #endif

//error handling
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

//put in vector and parse
    std::vector<STUDENT_DATA> students;
    parseIntoVector(inputFile, students);
    inputFile.close();


//print in debug
        #ifdef _DEBUG
            #ifdef STANDARD //standard has two vars
                    std::cout << "Parsed student data:" << std::endl;
                    for (const auto& student : students) {
                        std::cout << "First Name: " << student.firstName << " Last Name: " << student.lastName << std::endl;
                    }
            #endif

            #ifdef PRE_RELEASE //Pre has three vars
                    std::cout << "Parsed student data:" << std::endl;
                    for (const auto& student : students) {
                        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << ", Email: " << student.email << std::endl;
                    }
            #endif

        #endif


    return 0;
}