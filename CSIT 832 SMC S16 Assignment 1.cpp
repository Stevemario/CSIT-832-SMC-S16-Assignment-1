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
typedef PriorityQueue<printjob> PJPrioQ;
void processChoice (
	bool&,
	const char&,
	int&,
	PJPrioQ&
);
void addJob (
	int&,
	PJPrioQ&
);
void processJob (
	PJPrioQ&
);
void inspectQueue (
	const PJPrioQ&
);
int main (
) {
	bool bUserWantsToManageQueue = true;
	char chOperationToDo;
	int nJobs = 0;
	PJPrioQ PrinterQueue (20);
	while (bUserWantsToManageQueue) {
		displayMenu (chOperationToDo);
		processChoice (bUserWantsToManageQueue, chOperationToDo, nJobs, PrinterQueue);
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
	int& nJobs,
	PJPrioQ& PrinterQueue
) {
	switch (chOperationToDo) {
		case '1': { addJob (nJobs, PrinterQueue); break; }
		case '2': { processJob (PrinterQueue); break; }
		case '3': { inspectQueue (PrinterQueue); break; }
		case '4': { bUserWantsToManageQueue = false; break; }
		default: { break; }
	}
}
void addJob (
	int& nJobs,
	PJPrioQ& PrinterQueue
) {
	if (PrinterQueue.bIsFull ()) {
		std::cout << "\n";
		std::cout << "Heap is full.\n";
		std::cout << "\n";
	} else {
		char chUserType;
		std::cout << "\n";
		std::cout << "Instructor (I or i), TA (T or t), or Student (S or s)? ";
		std::cin >> chUserType;
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
		std::cout << "\n";
		switch (chUserType) {
			case 'I':
			case 'i': { nJobs++; PrinterQueue.enqueue (printjob (printerusertype::Instructor, nJobs)); break; }
			case 'T':
			case 't': { nJobs++; PrinterQueue.enqueue (printjob (printerusertype::TeachersAssistant, nJobs)); break; }
			case 'S':
			case 's': { nJobs++; PrinterQueue.enqueue (printjob (printerusertype::Student, nJobs)); break; }
			default: { break; }
		}
	}
}
void processJob (
	PJPrioQ& PrinterQueue
) {
	if (PrinterQueue.bIsEmpty ()) {
		std::cout << "\n";
		std::cout << "No print jobs in queue.\n";
		std::cout << "\n";
	} else {
		printjob jobProcessed;
		PrinterQueue.dequeue (jobProcessed);
		std::cout << "\n";
		std::cout << "Now printing job #" <<
			std::to_string (jobProcessed.nJob ()) << ": " <<
			s_ (jobProcessed.printerusertype_ ()) << "\n";
		std::cout << "\n";
	}
}
void inspectQueue (
	const PJPrioQ& PrinterQueue
) {
	if (PrinterQueue.bIsEmpty ()) {
		std::cout << "\n";
		std::cout << "No print jobs in queue.\n";
		std::cout << "\n";
	} else {
		PJPrioQ PrinterQueueTempCopy (PrinterQueue);
		printjob printjobToInspect;
		std::cout << "\n";
		while (PrinterQueueTempCopy.bIsEmpty () == false) {
			PrinterQueueTempCopy.dequeue (printjobToInspect);
			std::cout << "job #" <<
				std::to_string (printjobToInspect.nJob ()) << ": " <<
				s_ (printjobToInspect.printerusertype_ ()) << "\n";
		}
		std::cout << "\n";
	}
}