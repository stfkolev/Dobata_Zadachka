#pragma once
#include <iostream>
#include <string>

#include "Grade.h"

struct Student {
	std::string facultyNumber;
	std::string name;

	Discipline disciplines[5];

	int gender;
	int age;
	int status;
};

/*! Single student operations */

Student createStudent() {
	Student student;

	do {
		std::cout << "Enter student's factulty number: ";
		std::getline(std::cin, student.facultyNumber);

	} while (student.facultyNumber.length() != 8);

	do {
		std::cout << "Enter student's name: ";
		std::getline(std::cin, student.name);
	} while (std::cin.fail());


	std::cout << "=== Disciplines ===" << std::endl;

	for (int i = 0; i < 5; i++) {
		student.disciplines[i] = createGrade();
	}

	do {
		std::cout << "Enter student's gender( 0 - male, 1 - female, 2 - unknown): ";
		std::cin >> student.gender;
	} while (std::cin.fail() || student.gender < 0 || student.gender > 2);

	do {
		std::cout << "Enter student's age: ";
		std::cin >> student.age;
	} while (std::cin.fail() || student.age < 0 || student.age > 100);

	do {
		std::cout << "Enter student's status(0 - active, 1 - inactive): ";
		std::cin >> student.status;
	} while (std::cin.fail() || student.status < 0 || student.status > 1);


	std::cin.ignore(); // flush input

	return student;
}

void printStudent(Student student) {
	std::cout << "=================== Student's Information ===================" << std::endl;
	std::cout << "Student's Faculty Number: " << student.facultyNumber << std::endl;
	std::cout << "Student's Name: " << student.name << std::endl;
	std::cout << "Student's Gender: " << (student.gender == 0 ? "Male" : student.gender == 1 ? "Female" : "Unknown") << std::endl;
	std::cout << "Student's Age: " << student.age << std::endl;
	std::cout << "Student's Status: " << (student.status == 0 ? "Active" : "Inactive") << std::endl << std::endl;

	std::cout << "=================== Student's Disciplines ===================" << std::endl << std::endl;

	for (int i = 0; i < 5; i++) {
		printDiscipline(student.disciplines[i]);
	}

	std::cout << "=============================================================" << std::endl << std::endl << std::endl;
}

/*! Multiple students operations */

Student* inputStudents(int& numberOfStudents) {
	do {
		std::cout << "Input number of students: ";
		std::cin >> numberOfStudents;
	} while (numberOfStudents < 0 || numberOfStudents > 30 || std::cin.fail());

	std::cin.ignore(); // flush input

	Student* students = new Student[numberOfStudents];

	for (int i = 0; i < numberOfStudents; i++) {
		students[i] = createStudent();
	}

	return students;
}

void printAllStudents(Student* students, int count) {
	for (int i = 0; i < count; i++)
		printStudent(students[i]);
}
