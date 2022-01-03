#pragma once
#include <iostream>
#include <string>

struct Discipline {
	std::string name;
	double grade;
};

Discipline createGrade() {
	Discipline grade;

	std::cout << "Enter Discipline Name: ";
	std::getline(std::cin, grade.name);

	do {
		std::cout << "Enter Discipline Grade: ";
		std::cin >> grade.grade;
	} while (grade.grade < 2 || grade.grade > 6  || std::cin.fail());

	std::cin.ignore(); // flush input

	return grade;
}

void printDiscipline(Discipline discipline) {
	std::cout << "=================== Discipline ===================" << std::endl << std::endl;

	std::cout << "Name: " << discipline.name << std::endl;
	std::cout << "Grade: " << discipline.grade << std::endl;

	std::cout << "==================================================" << std::endl << std::endl;
}