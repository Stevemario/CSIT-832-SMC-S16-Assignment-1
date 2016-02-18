#ifndef PRINTJOB_H
#define PRINTJOB_H
#include <string>
enum class printerusertype {
	Instructor,
	TeachersAssistant,
	Student,
};
std::string s_ (printerusertype);
class printjob {
	public: printjob ();
	public: printjob (printerusertype, int);
	private: printerusertype m_printerusertype;
	public: printerusertype printerusertype_ () const;
	private: int m_nJob;
	public: int nJob () const;
	public: bool operator< (const printjob&) const;
	public: bool operator== (const printjob&) const;
	public: bool operator<= (const printjob&) const;
};
#endif