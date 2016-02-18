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
typedef PriorityQueue<printjob> prioq;
void processChoice (
	bool&,
	const char&,
	int&,
	prioq&
);
void addJob (
	int&,
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
	int nJobs = 0;
	prioq PrinterQueue (20);
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
	prioq& PrinterQueue
) {
	switch (chOperationToDo) {
		case '1': { addJob (nJobs, PrinterQueue); break; }
		case '2': { processJob (PrinterQueue); break; }
		case '3': { inspectQueue (PrinterQueue); break; }
		case '4': { bUserWantsToManageQueue = false; break; }
	}
}
void addJob (
	int& nJobs,
	prioq& PrinterQueue
) {
	if (PrinterQueue.bIsFull ()) {
		std::cout << "\n";
		std::cout << "Heap is full.\n";
		std::cout << "\n";
	} else {
		char chUser;
		std::cout << "\n";
		std::cout << "Instructor (I or i), TA (T or t), or Student (S or s)? ";
		std::cin >> chUser;
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
		std::cout << "\n";
		switch (chUser) {
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
	prioq& PrinterQueue
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
	const prioq& PrinterQueue
) {
	if (PrinterQueue.bIsEmpty ()) {
		std::cout << "\n";
		std::cout << "No print jobs in queue.\n";
		std::cout << "\n";
	} else {
		int nJobsQueued = PrinterQueue.nElements ();
		printjob* QueueJobs = PrinterQueue.copy_elements ();
		printjob* printjobToInspect;
		std::cout << "\n";
		for (int i = 0; i < nJobsQueued; i++) {
			printjobToInspect = &QueueJobs[i];
			std::cout << "job #" <<
				std::to_string (printjobToInspect->nJob ()) << ": " <<
				s_ (printjobToInspect->printerusertype_ ()) << "\n";
		}
		std::cout << "\n";
	}
}