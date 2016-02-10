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
	private: printerusertype m_printerusertype;
	private: int m_nJob;
	public: printjob (printerusertype, int);
	public: printerusertype printerusertype_ () const;
	public: int nJob () const;
	public: bool operator< (const printjob&) const;
	public: bool operator== (const printjob&) const;
	public: bool operator<= (const printjob&) const;
};
#endif