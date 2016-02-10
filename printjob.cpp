#include "printjob.h"
std::string s_ (printerusertype printerusertype_) {
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