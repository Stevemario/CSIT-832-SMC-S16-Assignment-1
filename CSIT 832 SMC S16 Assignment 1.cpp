//Los Angeles Valley College
//CSIT 832
//Spring 2016
//Steve Mario Correa
//Assignment 1
//This software manages the queue for the printer in Engineering #107 using heaps, prioritiy queues, and template classes.
#include "pqtype.h"
#include <iostream>
void displayMenu (
	char&
);
void processChoice (
	bool&,
	const char&,
	int&
);
void addJob (
	int&
);
void processJob (
	int&
);
void inspectQueue (
	const int&
);
int main (
) {
	bool bUserWantsToManageQueue = true;
	char chOperationToDo;
	int PrinterQueue;
	while (bUserWantsToManageQueue) {
		displayMenu (chOperationToDo);
		processChoice (bUserWantsToManageQueue, chOperationToDo, PrinterQueue);
	}
	return 0;
}
void displayMenu (
	char& chOperationToDo
) {
	std::cout << "Printer queue\n";
	std::cout << "=========\n";
	std::cout << "1. Add job\n";
	std::cout << "2. Print job\n";
	std::cout << "3. View jobs\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter choice: ";
	std::cin >> chOperationToDo;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
}
void processChoice (
	bool& bUserWantsToManageQueue,
	const char& chOperationToDo,
	int& PrinterQueue
) {
	switch (chOperationToDo) {
		case '1': { addJob (PrinterQueue); break; }
		case '2': { processJob (PrinterQueue); break; }
		case '3': { inspectQueue (PrinterQueue); break; }
		case '4': { bUserWantsToManageQueue = false; break; }
	}
}
void addJob (
	int& PrinterQueue
) {
	char chUser;
	std::cout << "Instructor (I or i), TA (T or t), or Student (S or s)? ";
	std::cin >> chUser;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
	switch (chUser) {
		case 'I':
		case 'i': { break; }
		case 'T':
		case 't': { break; }
		case 'S':
		case 's': { break; }
		default: { break; }
	}
}
void processJob (
	int& PrinterQueue
) {
}
void inspectQueue (
	const int& PrinterQueue
) {
}