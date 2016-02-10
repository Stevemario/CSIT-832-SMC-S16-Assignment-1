//Los Angeles Valley College
//CSIT 832
//Spring 2016
//Steve Mario Correa
//Assignment 1
//This software manages the queue for the printer in Engineering #107 using heaps, prioritiy queues, and template classes.
#include "printjob.h"
#include "pqtype.h"
#include <iostream>
void displayMenu (
	char&
);
typedef PQType<int> prioq;
void processChoice (
	bool&,
	const char&,
	prioq&
);
void addJob (
	prioq&
);
void processJob (
	prioq&
);
void inspectQueue (
	const prioq&
);
int main (
) {
	bool bUserWantsToManageQueue = true;
	char chOperationToDo;
	prioq PrinterQueue (20);
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
	prioq& PrinterQueue
) {
	switch (chOperationToDo) {
		case '1': { addJob (PrinterQueue); break; }
		case '2': { processJob (PrinterQueue); break; }
		case '3': { inspectQueue (PrinterQueue); break; }
		case '4': { bUserWantsToManageQueue = false; break; }
	}
}
void addJob (
	prioq& PrinterQueue
) {
	char chUser;
	std::cout << "\n";
	std::cout << "Instructor (I or i), TA (T or t), or Student (S or s)? ";
	std::cin >> chUser;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
	std::cout << "\n";
	switch (chUser) {
		case 'I':
		case 'i': { PrinterQueue.Enqueue (1); break; }
		case 'T':
		case 't': { PrinterQueue.Enqueue (2); break; }
		case 'S':
		case 's': { PrinterQueue.Enqueue (3); break; }
		default: { break; }
	}
}
void processJob (
	prioq& PrinterQueue
) {
	if (PrinterQueue.IsEmpty ()) {
		std::cout << "\n";
		std::cout << "No print jobs in queue.\n";
		std::cout << "\n";
	} else {
		int jobProcessed;
		PrinterQueue.Dequeue (jobProcessed);
		std::cout << "\n";
		std::cout << "Now printing job #" << "X" << ": " << "Y" << "\n";
		std::cout << "\n";
	}
}
void inspectQueue (
	const prioq& PrinterQueue
) {
	if (PrinterQueue.IsEmpty ()) {
		std::cout << "\n";
		std::cout << "No print jobs in queue.\n";
		std::cout << "\n";
	} else {
	}
}