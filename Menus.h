#pragma once
#include <iostream>
#include "Student.h"

void queriesMenu(Student* students, int count) {
    int choice;

    do {


        std::cout << "==== Queries Menu ====" << std::endl << std::endl;
        std::cout << "[1] Show all students" << std::endl;
        std::cout << "[2] Show all students by faculty number" << std::endl;
        std::cout << "[3] Show all students by group" << std::endl;
        std::cout << "[4] Back" << std::endl << std::endl;

        std::cout << "Your choice is: ";
        std::cin >> choice;

        std::cin.ignore(); // flush input

        switch (choice) {
        case 1:
            printAllStudents(students, count);
            break;

        case 2:

            break;

        default:
            break;
        }

        system("cls");

    } while (std::cin.fail() || choice < 1 || choice > 4 || choice != 4);
}

void mainMenu() {
    Student* students = nullptr;
    int choice, numberOfStudents;

    do {
        std::cout << "==== Main Menu ====" << std::endl << std::endl;
        std::cout << "[1] Input Student Data" << std::endl;
        std::cout << "[2] Query Student Data" << std::endl;
        std::cout << "[3] Update Student Data" << std::endl;
        std::cout << "[4] Exit" << std::endl << std::endl;

        std::cout << "Your choice is: ";
        std::cin >> choice;

        std::cin.ignore(); // flush input

        switch (choice) {
        case 1:
            students = inputStudents(numberOfStudents);
            break;

        case 2:
            if (students != nullptr)
                queriesMenu(students, numberOfStudents);
            else
                std::cout << "You don't have any students yet!";
            break;

        default:
            break;
        }

        system("cls");

    } while (std::cin.fail() || choice < 1 || choice > 4 || choice != 4);
}
