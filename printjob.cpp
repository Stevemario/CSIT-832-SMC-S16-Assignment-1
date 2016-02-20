#include "printjob.h"
std::string s_ (
	printerusertype printerusertype_
) {
	std::string s_;
	switch (printerusertype_) {
		case printerusertype::Instructor: { s_ = "Instructor"; break; }
		case printerusertype::TeachersAssistant: { s_ = "TA"; break; }
		case printerusertype::Student: { s_ = "Student"; break; }
		default: { s_ = "UNKNOWN USER TYPE"; break; }
	}
	return s_;
}
printjob::printjob (
) {
}
printjob::printjob (
	printerusertype printerusertype_,
	int nJob
) {
	m_printerusertype = printerusertype_;
	m_nJob = nJob;
}
printerusertype printjob::printerusertype_ (
) const {
	return m_printerusertype;
}
int printjob::nJob (
) const {
	return m_nJob;
}
bool printjob::operator< (
	const printjob& printjobToCompare
) const {
	bool bMemberHasWorsePriority = false;
	int nUTMember = int (m_printerusertype);
	int nUTToCompare = int (printjobToCompare.printerusertype_ ());
	if (nUTMember > nUTToCompare) {
		bMemberHasWorsePriority = true;
	} else if (nUTMember == nUTToCompare) {
		int nJobMember = m_nJob;
		int nJobToCompare = printjobToCompare.nJob ();
		if (nJobMember > nJobToCompare)
			bMemberHasWorsePriority = true;
	}
	return bMemberHasWorsePriority;
}