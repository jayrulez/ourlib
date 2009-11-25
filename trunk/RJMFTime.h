#if !defined(RJMF_TIMESTAMP_DEFDSdslkmdslk)
#define RJMF_TIMESTAMP_DEFDSdslkmdslk

#define RJMFTIME_NULL 0

class RJMF_TimeStamp {
public:
	RJMF_TimeStamp* ptr() {return this;};

	//construction
	RJMF_TimeStamp(); //When constructed with no paramaters take the current datetime
	RJMF_TimeStamp(unsigned int hdth, unsigned int sec, unsigned int minutes, unsigned int hours, unsigned int mday, unsigned int month, unsigned int year);
	RJMF_TimeStamp(const char *pTime, const char*pFormat = RJMFTIME_NULL);
	RJMF_TimeStamp(const RJMF_TimeStamp& p);
	
	//Arythmetic
	RJMF_TimeStamp& operator= (const RJMF_TimeStamp& o);
	void AddYear(int num); //Adds a number of years preserves date
	void AddMonth(int num); //Adds a number of months. If day is greater than days in month reduces to last day
	void AddDay(int num); //Adds a predefined number of days
	void AddHour(int num); //Adds a number of hours - calls add day if needed
	void AddMinute(int num); //Adds a number of minutes - calls add hour if needed
	void AddSecond(int num); //Adds a number of seconds - calls add minute if needed
	void AddHdthsecond(int num); //Adds a number of Hundrandeth of a second - calls add second if needed
	
	//Find the time elapsed between two dates
	float DiffYear(RJMF_TimeStamp* pO);
	unsigned int DiffMonth(RJMF_TimeStamp* pO); //Diffrence in months
	unsigned int DiffDay(RJMF_TimeStamp* pO); //Diffrence in days
	unsigned int DiffSecond(RJMF_TimeStamp* pO); //Diffrence in Seconds
	unsigned int DiffHdthSecond(RJMF_TimeStamp* pO); //Diffrence in hdth Seconds

	//I don't know if I want these - should use other functions
	//+
	//-
	//+=
	//-=
	
	//Comparison
	bool operator== (const RJMF_TimeStamp& o) const;
	bool operator!= (const RJMF_TimeStamp& o) const;
	bool operator<  (const RJMF_TimeStamp& rhs ) const;
	bool operator<= (const RJMF_TimeStamp& rhs ) const;
	bool operator>  (const RJMF_TimeStamp& rhs ) const;
	bool operator>= (const RJMF_TimeStamp& rhs ) const;
	
	//output
	bool valid() {return m_valid;};
	bool IsLeapYear();
	unsigned int GetYear() {return m_year;};
	unsigned int GetHdthsecondsRAW() {return m_hdth_secs;};
	unsigned int GetMonth();
	unsigned int GetDay();
	unsigned int GetDOW(); //0 = sunday, 1=monday etc.
	unsigned int GetDOY();
	unsigned int GetHour();
	unsigned int GetMinute();
	unsigned int GetSecond();
	unsigned int GetHdthsecond();
	
	//    http://uk3.php.net/strftime
	void strftime(char* pOutput, const char* pFormat);
	char buf[100];
	const char* c_str() {
		strftime(buf, "%d-%b-%Y %H:%M:%!");
		return buf;
	};
	
	//statics
	static bool IsLeapYear(unsigned int Year);
	
private:
	void InitC(unsigned int hdth, unsigned int sec, unsigned int minutes, unsigned int hours, unsigned int mday, unsigned int month, unsigned int year); //Instalise to this time
	unsigned int DIY(unsigned int year); //Days in Year

//	This class stores the date  as a year and the number of seconds past the start of the year
//	year	1
//	day	366
//	hours	8784
//	minutes	527040
//	seconds	31622400
//	hdth secs	3162240000

	unsigned int m_year;
	unsigned int m_hdth_secs; //hundredth of a second since start of year
	bool m_valid;
};


static RJMF_TimeStamp glob_RJMFTIMEDefault(1,1,1,1,1,1,1);

#endif
