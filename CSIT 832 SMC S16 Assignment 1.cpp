//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 5
//This software manages the queue for the printer in Engineering #107 using heaps, prioritiy queues, and template classes.
#include <iostream>
#include "pqtype.h"
void displayMenu (
	char&
);
void processChoice (
	bool&,
	const char&,
	int&
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
		case '1': { PrinterQueue++; break; }
		case '2': { PrinterQueue++; break; }
		case '3': { PrinterQueue++; break; }
		case '4': { bUserWantsToManageQueue = false; break; }
	}
}