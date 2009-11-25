#include "RJMFTime.h"
#include <time.h>

#include <iostream> //sprintf used
#include <string.h> //DJGPP needs strcmp

RJMF_TimeStamp::RJMF_TimeStamp() {
	//When constructed with no paramaters put the current date and time into members
	//This works from 1970-1938
	//But the rest of the class is designed to store dates from year 0-9999
	m_valid = false;
	time_t rt;
	time ( &rt );
	struct tm * ti;
	ti = localtime ( &rt );
	InitC(0,ti->tm_sec,ti->tm_min,ti->tm_hour,ti->tm_mday,ti->tm_mon+1,ti->tm_year+1900);
};

RJMF_TimeStamp::RJMF_TimeStamp(unsigned int hdth, unsigned int sec, unsigned int minutes, unsigned int hours, unsigned int mday, unsigned int month, unsigned int year) {
	m_valid = false;
	InitC(hdth,sec,minutes,hours,mday,month,year);
};

RJMF_TimeStamp::RJMF_TimeStamp(const RJMF_TimeStamp& p) {
	m_valid = p.m_valid;
	m_year = p.m_year;
	m_hdth_secs = p.m_hdth_secs;
};

void RJMF_TimeStamp::InitC(unsigned int hdth, unsigned int sec, unsigned int minutes, unsigned int hours, unsigned int mday, unsigned int month, unsigned int year) {
	m_valid = false;
	m_year = year;

	unsigned int mon_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear()) {
		mon_days[1] = 29;
	};
	if (month>12) return;
	if (mday>mon_days[month-1]) return;
	if (hours>23) return;
	if (minutes>59) return;
	if (sec>59) return;
	if (hdth>99) return;
	if (month==0) return;
	if (mday==0) return;

	m_hdth_secs = hdth;
	m_hdth_secs += sec * 100;
	m_hdth_secs += minutes * 100 * 60;
	m_hdth_secs += hours * 100 * 60 * 60;
	m_hdth_secs += (mday-1) * 100 * 60 * 60 * 24;
	for (int c=0;c<(month-1);c++) {
		m_hdth_secs += ((mon_days[c]) * 100 * 60 * 60 * 24);
	};
	m_valid = true;
};

unsigned int RJMF_TimeStamp::GetMonth() {
	unsigned long rem = m_hdth_secs;
	rem -= GetHdthsecond();
	rem = rem / 100;
	rem -= GetSecond();
	rem = rem / 60;
	rem -= GetMinute();
	rem = rem / 60;
	rem -= GetHour();
	rem = rem / 24;

	unsigned int mon_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear()) {
		mon_days[1] = 29;
	};

	unsigned long cc = 0;
	for (int c=0;c<12;c++) {
		cc = cc + mon_days[c];
		if ((rem+1)<=cc) {
			return c+1;
		};
	};
	return 12;
};

unsigned int RJMF_TimeStamp::GetDay() {
	unsigned long rem = m_hdth_secs;
	rem -= GetHdthsecond();
	rem = rem / 100;
	rem -= GetSecond();
	rem = rem / 60;
	rem -= GetMinute();
	rem = rem / 60;
	rem -= GetHour();
	rem = rem / 24;

	unsigned int mon_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear()) {
		mon_days[1] = 29;
	};
	
	for (int c=0;c<12;c++) {
		if (mon_days[c]>=(rem+1)) return rem+1;
		rem -= mon_days[c];
	};

	return rem+1;
};

unsigned int RJMF_TimeStamp::GetHour() {
	return (m_hdth_secs % (100 * 60 * 60 * 24))/(100 * 60 * 60);
};

unsigned int RJMF_TimeStamp::GetMinute() {
	return (m_hdth_secs % (100 * 60 * 60))/(100 * 60);
};

unsigned int RJMF_TimeStamp::GetSecond() {
	return (m_hdth_secs % (100 * 60))/100;
};

unsigned int RJMF_TimeStamp::GetHdthsecond() {
	return m_hdth_secs % 100;
};

bool RJMF_TimeStamp::IsLeapYear() {
	return IsLeapYear(m_year);
};

bool RJMF_TimeStamp::IsLeapYear(unsigned int Year) {
//http://en.wikipedia.org/wiki/Leap_year
//if year modulo 400 is 0 then leap
// else if year modulo 100 is 0 then no_leap
// else if year modulo 4 is 0 then leap
// else no_leap
	if ((Year % 400)==0) return true;
	if ((Year % 100)==0) return false;
	if ((Year % 4)==0) return true;
	return false;
};

RJMF_TimeStamp::RJMF_TimeStamp(const char *pTime, const char*pFormat /*= RJMFTIME_NULL*/) {
	m_valid = false;
	//Creates object from  input 
	unsigned int forma = 1;
	char *sFormats[] = {
	"INVALID",
	"DD-MON-YYYY", //01
	"DD-MON-YY",  //02
	"DD/MM/YYYY",  //03
	"DD/MM/YY", //04
	"DD-MON-YYYY hh:mm:ss.ss", //05
	"DD-MON-YY hh:mm:ss.ss", //06
	"DD/MM/YYYY hh:mm:ss.ss", //07
	"DD/MM/YY hh:mm:ss.ss", //08
	"DD-MON-YYYY hh:mm:ss", //09
	"DD-MON-YY hh:mm:ss", //10
	"DD/MM/YYYY hh:mm:ss", //11
	"DD/MM/YY hh:mm:ss", //12

	//SQLite formats from http://www.sqlite.org/cvstrac/wiki?p=DateAndTimeFunctions
	"YYYY-MM-DD", //13
	"YYYY-MM-DD HH:MM", //14
	"YYYY-MM-DD HH:MM:SS", //15
	"YYYY-MM-DD HH:MM:SS.SSS", //16
	"YYYY-MM-DDTHH:MM", //17
	"YYYY-MM-DDTHH:MM:SS", //18
	"YYYY-MM-DDTHH:MM:SS.SSS", //19
	"HH:MM", //20
	"HH:MM:SS", //21
	"HH:MM:SS.SSS", //22

	//SM Added
	"YYYYMMDD", //23

	};
	char *sMonths[] = {
		"ZERO_NONE",
		"JAN",
		"FEB",
		"MAR",
		"APR",
		"MAY",
		"JUN",
		"JUL",
		"AUG",
		"SEP",
		"OCT",
		"NOV",
		"DEC"
	};
	if (pFormat!=RJMFTIME_NULL) {
		forma = 0;
		for (int c=1;c<24;c++) {
			if (strcmp(pFormat,sFormats[c])==0) {
				forma = c;
				break;
			};
		};
	};
	if (forma == 0) return; //Invalid format - valid will be false

	unsigned int locDD = 255;
	unsigned int locMM = 255;
	unsigned int locMON = 255;
	unsigned int locYY = 255;
	unsigned int locYYYY = 255;
	unsigned int locHHMM = 255;
	unsigned int locHHMMSS = 255;
	unsigned int locHHMMSSSS = 255;
	unsigned int locHHMMSSSSS = 255;
	
	//Error check and set up conver params
	switch (forma) {
	case 1: //"DD-MON-YYYY"
		if (pTime[2]!='-') {return;};
		if (pTime[6]!='-') {return;};
		locDD = 0;
		locMON = 3;
		locYYYY = 7;
		break;
	case 2: //"DD-MON-YY"
		if (pTime[2]!='-') {return;};
		if (pTime[6]!='-') {return;};
		locDD = 0;
		locMON = 3;
		locYY = 7;
		break;
	case 3: //"DD/MM/YYYY"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		locDD = 0;
		locMM = 3;
		locYYYY = 6;
		break;
	case 4: //"DD/MM/YY"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		locDD = 0;
		locMM = 3;
		locYY = 6;
		break;
	case 5: //DD-MON-YYYY hh:mm:ss.ss"
		if ((pTime[2]!='-')) {return;};
		if ((pTime[6]!='-')) {return;};
		if (pTime[11]!=' ') return;
		if (pTime[14]!=':') return;
		if (pTime[17]!=':') return;
		if (pTime[20]!='.') return;
		locDD = 0;
		locMON = 3;
		locYYYY = 7;
		locHHMMSSSS = 12;
		break;
	case 6: //"DD-MON-YY hh:mm:ss.ss"
		if ((pTime[2]!='-')) {return;};
		if ((pTime[6]!='-')) {return;};
		if (pTime[9]!=' ') return;
		if (pTime[12]!=':') return;
		if (pTime[15]!=':') return;
		if (pTime[18]!='.') return;
		locDD = 0;
		locMON = 3;
		locYY = 7;
		locHHMMSSSS = 10;
		break;
	case 7: //"DD/MM/YYYY hh:mm:ss.ss"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		if (pTime[10]!=' ') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		if (pTime[19]!='.') return;
		locDD = 0;
		locMM = 3;
		locYYYY = 6;
		locHHMMSSSS = 11;
		break;
	case 8: //"DD/MM/YY hh:mm:ss.ss"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		if (pTime[8]!=' ') return;
		if (pTime[11]!=':') return;
		if (pTime[14]!=':') return;
		if (pTime[17]!='.') return;
		locDD = 0;
		locMM = 3;
		locYY = 6;
		locHHMMSSSS = 9;
		break;
	case 9: //"DD-MON-YYYY hh:mm:ss"
		if ((pTime[2]!='-')) {return;};
		if ((pTime[6]!='-')) {return;};
		if (pTime[11]!=' ') return;
		if (pTime[14]!=':') return;
		if (pTime[17]!=':') return;
		locDD = 0;
		locMON = 3;
		locYYYY = 7;
		locHHMMSS = 12;
		break;
	case 10: //"DD-MON-YY hh:mm:ss"
		if ((pTime[2]!='-')) {return;};
		if ((pTime[6]!='-')) {return;};
		if (pTime[9]!=' ') return;
		if (pTime[12]!=':') return;
		if (pTime[15]!=':') return;
		locDD = 0;
		locMON = 3;
		locYY = 7;
		locHHMMSS = 10;
		break;
	case 11: //"DD/MM/YYYY hh:mm:ss"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		if (pTime[10]!=' ') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		locDD = 0;
		locMM = 3;
		locYYYY = 6;
		locHHMMSS = 11;
		break;
	case 12: //"DD/MM/YY hh:mm:ss"
		if ((pTime[2]!='/') && (pTime[2]!='\\')) {return;};
		if ((pTime[5]!='/') && (pTime[5]!='\\')) {return;};
		if (pTime[8]!=' ') return;
		if (pTime[11]!=':') return;
		if (pTime[14]!=':') return;
		locDD = 0;
		locMM = 3;
		locYY = 6;
		locHHMMSS = 9;
		break;
	case 13: //"YYYY-MM-DD", //13
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		break;
	case 14: //	"YYYY-MM-DD HH:MM", //14
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!=' ') return;
		if (pTime[13]!=':') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMM = 11;
		break;
	case 15: //	"YYYY-MM-DD HH:MM:SS", //15
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!=' ') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMMSS = 11;
		break;
	case 16: //	"YYYY-MM-DD HH:MM:SS.SSS", //16
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!=' ') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		if (pTime[19]!='.') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMMSSSSS = 11;
		break;
	case 17: //	"YYYY-MM-DDTHH:MM", //17
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!='T') return;
		if (pTime[13]!=':') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMM = 11;
		break;
	case 18: //	"YYYY-MM-DDTHH:MM:SS", //18
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!='T') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMMSS = 11;
		break;
	case 19: //	"YYYY-MM-DDTHH:MM:SS.SSS", //19
		if (pTime[4]!='-') return;
		if (pTime[7]!='-') return;
		if (pTime[10]!='T') return;
		if (pTime[13]!=':') return;
		if (pTime[16]!=':') return;
		if (pTime[19]!='.') return;
		locDD = 8;
		locMM = 5;
		locYYYY = 0;
		locHHMMSSSSS = 11;
		break;
	case 20: //	"HH:MM", //20
		if (pTime[2]!=':') return;
		locHHMM = 0;
		break;
	case 21: //	"HH:MM:SS", //21
		if (pTime[2]!=':') return;
		if (pTime[5]!=':') return;
		locHHMMSS = 0;
		break;
	case 22: //	"HH:MM:SS.SSS", //22
		if (pTime[2]!=':') return;
		if (pTime[5]!=':') return;
		if (pTime[8]!='.') return;
		locHHMMSSSSS = 0;
		break;
	case 23: // "YYYYMMDD", //23
		locDD = 6;
		locMM = 4;
		locYYYY = 0;
		break;
	};
	
	unsigned int hdth = 0;
	unsigned int sec = 0;
	unsigned int min = 0;
	unsigned int hour = 0;
	unsigned int day = 1;
	unsigned int mon = 1;
	unsigned int year = 0;
	
	char buf[10];
//	unsigned int locDD = 255;
	if (locDD!=255) {
		buf[0] = pTime[locDD];
		buf[1] = pTime[locDD+1];
		buf[2] = '\0';
		sscanf(buf,"%d",&day);
	};
//	unsigned int locMM = 255;
	if (locMM!=255) {
		buf[0] = pTime[locMM];
		buf[1] = pTime[locMM+1];
		buf[2] = '\0';
		sscanf(buf,"%d",&mon);
	};
//	unsigned int locMON = 255;
	if (locMON!=255) {
		buf[0] = toupper(pTime[locMON]);
		buf[1] = toupper(pTime[locMON+1]);
		buf[2] = toupper(pTime[locMON+2]);
		buf[3] = '\0';
		for (int d=1;d<13;d++) {
			if (strcmp(buf,sMonths[d])==0) {
				mon = d;
			};
		};
	};
//	unsigned int locYY = 255;
	if (locYY!=255) {
		buf[0] = pTime[locYY];
		buf[1] = pTime[locYY+1];
		buf[2] = '\0';
		sscanf(buf,"%d",&year);
		if (year<70) {
			year += 2000;
		} else {
			year += 1900;
		};
	};
//	unsigned int locYYYY = 255;
	if (locYYYY!=255) {
		buf[0] = pTime[locYYYY];
		buf[1] = pTime[locYYYY+1];
		buf[2] = pTime[locYYYY+2];
		buf[3] = pTime[locYYYY+3];
		buf[4] = '\0';
		sscanf(buf,"%d",&year);
	};
//	unsigned int locHHMMSS = 255;
	if (locHHMM!=255) {
		buf[0] = pTime[locHHMM];
		buf[1] = pTime[locHHMM+1];
		buf[2] = pTime[locHHMM+2];
		buf[3] = pTime[locHHMM+3];
		buf[4] = pTime[locHHMM+4];
		buf[5] = '\0';
		sscanf(buf,"%d:%d",&hour,&min);
	};//	unsigned int locHHMMSS = 255;
	if (locHHMMSS!=255) {
		buf[0] = pTime[locHHMMSS];
		buf[1] = pTime[locHHMMSS+1];
		buf[2] = pTime[locHHMMSS+2];
		buf[3] = pTime[locHHMMSS+3];
		buf[4] = pTime[locHHMMSS+4];
		buf[5] = pTime[locHHMMSS+5];
		buf[6] = pTime[locHHMMSS+6];
		buf[7] = pTime[locHHMMSS+7];
		buf[8] = '\0';
		sscanf(buf,"%d:%d:%d",&hour,&min,&sec);
	};
//	unsigned int locHHMMSSSS = 255;
	if (locHHMMSSSS!=255) {
		buf[0] = pTime[locHHMMSSSS];
		buf[1] = pTime[locHHMMSSSS+1];
		buf[2] = pTime[locHHMMSSSS+2];
		buf[3] = pTime[locHHMMSSSS+3];
		buf[4] = pTime[locHHMMSSSS+4];
		buf[5] = pTime[locHHMMSSSS+5];
		buf[6] = pTime[locHHMMSSSS+6];
		buf[7] = pTime[locHHMMSSSS+7];
		buf[8] = '\0';
		sscanf(buf,"%d:%d:%d",&hour,&min,&sec);
		buf[0] = pTime[locHHMMSSSS+9];
		buf[1] = pTime[locHHMMSSSS+10];
		buf[2] = '\0';
		sscanf(buf,"%d",&hdth);
	};

	if (locHHMMSSSSS!=255) {
		buf[0] = pTime[locHHMMSSSSS];
		buf[1] = pTime[locHHMMSSSSS+1];
		buf[2] = pTime[locHHMMSSSSS+2];
		buf[3] = pTime[locHHMMSSSSS+3];
		buf[4] = pTime[locHHMMSSSSS+4];
		buf[5] = pTime[locHHMMSSSSS+5];
		buf[6] = pTime[locHHMMSSSSS+6];
		buf[7] = pTime[locHHMMSSSSS+7];
		buf[8] = '\0';
		sscanf(buf,"%d:%d:%d",&hour,&min,&sec);
		buf[0] = pTime[locHHMMSSSSS+9];
		buf[1] = pTime[locHHMMSSSSS+10];
		//buf[2] = pTime[locHHMMSSSSS+11];
		buf[2] = '\0'; //Lowest digit ignored
		sscanf(buf,"%d",&hdth);
	};
	
	InitC(hdth,sec,min,hour,day,mon,year);

};

void RJMF_TimeStamp::strftime(char* pOutput, const char* pFormat) {
	if (!valid()) {
		pOutput[0] = 'I';
		pOutput[1] = 'N';
		pOutput[2] = 'V';
		pOutput[3] = 'A';
		pOutput[4] = 'L';
		pOutput[5] = 'I';
		pOutput[6] = 'D';
		pOutput[7] = '\0';
		return;
	};
	
	char *pOut = pOutput;
	const char *pIn = pFormat;

	char *sMonths[] = {
		"ZERO_NONE",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	char *sSMonths[] = {
		"ZERO_NONE",
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec"
	};
	char *sDays[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	char *sSDays[] = {
		"Sun",
		"Mon",
		"Tue",
		"Wed",
		"Thu",
		"Fri",
		"Sat"
	};
	
	char buf[25];
	char *pS2 = RJMFTIME_NULL;
	
	while ((*pIn)!='\0') {
		
		if (*pIn=='%') {
			*pIn++;
			switch (*pIn) {
			case 'a':
				pS2 = sSDays[GetDOW()];
				while ((*pS2)!='\0') {
					*pOut = *pS2;
					*pOut++;
					*pS2++;
				};
				break;
			case 'A':
				pS2 = sDays[GetDOW()];
				while ((*pS2)!='\0') {
					*pOut = *pS2;
					*pOut++;
					*pS2++;
				};
				break;
			case 'j':
				sprintf(buf,"%0.3d",GetDOY());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				*pOut = buf[2];
				*pOut++;
				break;
			case 'w':
				sprintf(buf,"%0.1d",GetDOW());
				*pOut = buf[0];
				*pOut++;
				break;
			case 'b':
				pS2 = sSMonths[GetMonth()];
				while ((*pS2)!='\0') {
					*pOut = *pS2;
					*pOut++;
					*pS2++;
				};
				break;
			case 'B':
				pS2 = sMonths[GetMonth()];
				while ((*pS2)!='\0') {
					*pOut = *pS2;
					*pOut++;
					*pS2++;
				};
				break;
			case 'H': //hour 24 with leading 0
				sprintf(buf,"%0.2d",GetHour());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 'I': //hour 12 with leading 0
				sprintf(buf,"%0.2d",GetHour()%12);
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 'm': //month with leading 0
				sprintf(buf,"%0.2d",GetMonth());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 'M': //minute with leading 0
				sprintf(buf,"%0.2d",GetMinute());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 'S': //second with leading 0
				sprintf(buf,"%0.2d",GetSecond());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 'Y': //Long Year
				sprintf(buf,"%0.4d",GetYear());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				*pOut = buf[2];
				*pOut++;
				*pOut = buf[3];
				*pOut++;
				break;
			case 'y': //Short Year
				sprintf(buf,"%0.4d",GetYear());
				*pOut = buf[2];
				*pOut++;
				*pOut = buf[3];
				*pOut++;
				break;
			case 'd': //Day of month with leading 0
				sprintf(buf,"%0.2d",GetDay());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case 't':
				*pOut = '\t';
				*pOut++;				
				break;
			case '%':
				*pOut = *pIn;
				*pOut++;				
				break;
			case '\0':
				return;
				break;
			case '!':
				sprintf(buf,"%0.2d", GetSecond());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				*pOut = '.';
				*pOut++;
				sprintf(buf,"%0.2d", GetHdthsecond());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			case '£':
				sprintf(buf,"%0.2d", GetHdthsecond());
				*pOut = buf[0];
				*pOut++;
				*pOut = buf[1];
				*pOut++;
				break;
			};
		} else {
			*pOut = *pIn;
			*pOut++;
		};
		
		pIn++;
	};
	
	*pOut = '\0';
};

unsigned int RJMF_TimeStamp::GetDOY() { //Jan 1 = 1, etc.
	unsigned long rem = m_hdth_secs;
	rem -= GetHdthsecond();
	rem = rem / 100;
	rem -= GetSecond();
	rem = rem / 60;
	rem -= GetMinute();
	rem = rem / 60;
	rem -= GetHour();
	rem = rem / 24;

	//Now we have the number of days
	return rem+1;
};
unsigned int RJMF_TimeStamp::GetDOW() { //0 = sunday, 1=monday etc.
	
	//Step 1 Work out what DOW 1-Jan-Year is
	//1-jan-2007 = Monday = 1
	unsigned int dow = 1;

	unsigned int y = GetYear();
	unsigned int cy = 2007;
	while (y<cy) {
		cy--;
		dow -= 362;
		if (GetMonth()<2) {
			if (IsLeapYear(cy)) {
				dow -= 1;
			};
		} else {
			if (IsLeapYear(cy)) {
				dow -= 1;
			};
		};
		dow = dow % 7;
	};
	while (y>cy) {
		cy++;
		dow += 365;
		if (GetMonth()<3) {
			if (IsLeapYear(cy-1)) {
				dow += 1;
			};
		} else {
			if (IsLeapYear(cy-1)) {
				dow += 1;
			};
		};
		dow = dow % 7;	
	};
	
	//Step 2 Get number of days in year
	//Step 3 add that number of days mod 7
	dow += ((GetDOY()-1) % 7) % 7;
	dow = dow % 7;
	
	return dow;
};

bool RJMF_TimeStamp::operator== (const RJMF_TimeStamp& o) const {
	if (m_year!=o.m_year) return false;
	if (m_hdth_secs!=o.m_hdth_secs) return false;
	return true;
};

bool RJMF_TimeStamp::operator!= (const RJMF_TimeStamp& o) const {
	if (m_year!=o.m_year) return true;
	if (m_hdth_secs!=o.m_hdth_secs) return true;
	return false;
};

bool RJMF_TimeStamp::operator<  (const RJMF_TimeStamp& rhs ) const {
	if (m_year<rhs.m_year) return true;
	if (m_year==rhs.m_year) {
		if (m_hdth_secs<rhs.m_hdth_secs) return true;
	};
	return false;
};

bool RJMF_TimeStamp::operator<= (const RJMF_TimeStamp& rhs ) const {
	if (m_year>rhs.m_year) return false;
	if (m_year<rhs.m_year) return true;
	if (m_hdth_secs>rhs.m_hdth_secs) return false;
	return true;
};

bool RJMF_TimeStamp::operator>  (const RJMF_TimeStamp& rhs ) const {
	if (m_year>rhs.m_year) return true;
	if (m_year==rhs.m_year) {
		if (m_hdth_secs>rhs.m_hdth_secs) return true;
	};
	return false;
};

bool RJMF_TimeStamp::operator>= (const RJMF_TimeStamp& rhs ) const {
	if (m_year<rhs.m_year) return false;
	if (m_year>rhs.m_year) return true;
	if (m_hdth_secs<rhs.m_hdth_secs) return false;
	return true;
};

RJMF_TimeStamp& RJMF_TimeStamp::operator= (RJMF_TimeStamp const &o) {
	if ( this != &o ) { //avoid copying to self
		m_year = o.m_year;
		m_hdth_secs = o.m_hdth_secs;
		m_valid = o.m_valid;
	};
	return *this;
};

void RJMF_TimeStamp::AddYear(int num) { //Adds a number of years preserves date
	//Adds (or subtracts the number of years)
	//Must be careful to preserve the Month, Day, and time
	unsigned int ny = GetYear();
	ny += num;
	//Leap days always go to 1 mar unless mutiple of 4
	unsigned int nm = GetMonth();
	unsigned int nd = GetDay();
	if (nm==2) {
		if (nd==29) {
			if (!(IsLeapYear(ny))) {
				nm=3;
				nd=1;
			};
		};
	};
	InitC(GetHdthsecond(),GetSecond(),GetMinute(),GetHour(),nd,nm,ny);
};

void RJMF_TimeStamp::AddMonth(int num) { //Adds a number of years preserves date
	//Adds (or subtracts the number of months)
	//if number of days is greater than days in month where we land then the last day in the month is selected
	unsigned int ny = GetYear();
	int nm = GetMonth();
	
	nm+=num;
	while (nm>12) {
		nm -= 12;
		ny += 1;
	};
	while (nm<1) {
		nm += 12;
		ny -= 1;
	};
	
	unsigned int mon_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear()) {
		mon_days[1] = 29;
	};
	
	unsigned int nd = GetDay();	

	//printf("nm=%d\nnd=%d\nmon_days[nm-1]=%d\n",nm,nd,mon_days[nm-1]);
	if (nd>mon_days[nm-1]) nd=mon_days[nm-1];
	//printf("nm=%d\nnd=%d\n",nm,nd);

	InitC(GetHdthsecond(),GetSecond(),GetMinute(),GetHour(),nd,nm,ny);
};

void RJMF_TimeStamp::AddDay(int num) { //Adds a number of days
	if (num>0) {
		unsigned int d = GetDOY();
		unsigned int ct = d+num;
		//printf("ct=%d\nd=%d\nDIR=%d\n",ct,d,DIY(m_year));
		if (ct>DIY(m_year)) {
			while (ct>DIY(m_year)) {
				ct -= DIY(m_year);
				m_year++;
			};
			//What remains in CT must be the day in year
			unsigned int hdth_secs = ((ct-1)*100*60*60*24) + (GetHour()*100*60*60) + (GetMinute() * 100 * 60) + (GetSecond() * 100) + GetHdthsecond();
			m_hdth_secs = hdth_secs;
		} else {
			m_hdth_secs += (100*60*60*24*num);
		};
	} else {
		//Subtract days
		num = num * -1;
		unsigned int d = GetDOY();
		int ct = d-num;
		if (ct>0) {
			m_hdth_secs -= (100*60*60*24*num);			
		} else {
			//Going back over year boundry
			while (ct<=0) {
				m_year -= 1;
				ct += DIY(m_year);
			};
			//printf("ct=%d\n",ct);
			unsigned int hdth_secs = ((ct-1)*100*60*60*24) + (GetHour()*100*60*60) + (GetMinute() * 100 * 60) + (GetSecond() * 100) + GetHdthsecond();
			m_hdth_secs = hdth_secs;
		};
	};
};

void RJMF_TimeStamp::AddHour(int num) { //Adds a number of hours - calls add day if needed
	//This should call Add day if nessecary
	int wd;
	if (num>0) {
		wd = (num - (num % 24))/24;
		num = num - (wd * 24);
		AddDay(wd);
		while (num+GetHour()>=24){
			AddDay(1);
			num -= 24;
		};
		m_hdth_secs += (num  * 60 * 60 * 100);
		
	} else {
		num = num * -1;
		wd = (num - (num % 24))/24;
		num = num - (wd * 24);
		AddDay(-wd);
		int ct = GetHour() - num;
		
		while (ct<0) {
			AddDay(-1);
			num -= 24;
			ct = GetHour()-num;
		};
		m_hdth_secs-= (num  * 60 * 60 * 100);		
	};
};

void RJMF_TimeStamp::AddMinute(int num) { //Adds a number of minutes - calls add hour if needed
	if (num>0) {
		int ah = num + GetMinute();
		while (ah>=60) {
			AddHour(1);
			num -= 60;
			ah = num + GetMinute();
		};
		m_hdth_secs += (num*60*100);
	} else {
		num = num * -1;
		int ah = GetMinute()-num;
		while (ah<0) {
			AddHour(-1);
			num -= 60;
			ah = GetMinute()-num;
		};
		m_hdth_secs -= (num*60*100);		
	};
};

void RJMF_TimeStamp::AddSecond(int num) { //Adds a number of seconds - calls add minute if needed
	if (num>0) {
		int as = num + GetSecond();
		while (as>=60) {
			AddMinute(1);
			num -= 60;
			as = num + GetSecond();
		};
		m_hdth_secs += (num*100);
	} else {
		num = num * -1;
		int as = GetSecond()-num;
		while (as<0) {
			AddMinute(-1);
			num -= 60;
			as = GetSecond()-num;
		};
		m_hdth_secs -= (num*100);
	};
};

void RJMF_TimeStamp::AddHdthsecond(int num) { //Adds a number of hdth seconds - calls add second if needed
	if (num>0) {
		int am = num + GetHdthsecond();
		while (am>=100) {
			AddSecond(1);
			num -= 100;
			am = num + GetHdthsecond();
		};
		m_hdth_secs += num;
	} else {
		num = num * -1;
		int am = GetHdthsecond() - num;
		while (am<0) {
			AddSecond(-1);
			num -= 100;
			am = GetHdthsecond()-num;
		};
		m_hdth_secs -= num;
	};
};

unsigned int RJMF_TimeStamp::DIY(unsigned int year) { //Days in Year
	if (IsLeapYear(year)) return 366;
	return 365;
};

float RJMF_TimeStamp::DiffYear(RJMF_TimeStamp* pO) {
	//return the number of years diffrence between two dates
	//fraction works on number of days - actual time is ignored
	float rv;
	if ((*this)==(*pO)) return 0;
	if ((*this)<(*pO)) {
		//return -1;
		rv = pO->DiffYear(this);
		return rv * -1;
	};
	unsigned int rem_in_start_year= 0;
	unsigned int rem_in_end_year = 0;
	unsigned int whole = 0;
	unsigned int ms;
	unsigned int ms2;
	//We know that this > pO
	if (m_year==pO->m_year) {
		//Same year
		ms = GetDOY() - pO->GetDOY();
		rv = ms;
		ms = (DIY(m_year));
		rv = rv / ms;
	} else {
		//Three parts
		//Remainder in this year
		ms = (DIY(pO->m_year)) - (pO->GetDOY());
		ms2 = (DIY(pO->m_year));
		rv = ms / ms2;
		rem_in_start_year = ms;
		
		//Whole years in between
		ms = pO->m_year;
		while ((ms+1)<m_year) {
			ms++;
			whole++;
		};
		
		//Remainder in final year  - this
		rem_in_end_year = (GetDOY());

		ms = rem_in_start_year + rem_in_end_year;
		ms2 = 365;
		if (IsLeapYear(pO->m_year)) {
			if (pO->GetMonth()<3) {
				ms2++;
			};
		};
		if (IsLeapYear(m_year)) {
			if (pO->GetMonth()==2) {
				if (pO->GetDay()==29) ms2++;
			} else if (pO->GetMonth()>2) {
				ms2++;
			};
		};
		rv = ms;
		rv = rv / ms2;
		rv += whole;

		//printf("\n\nRem in Start=%u\nRem in End=%u\nWhole Years=%u\nms=%u\nms2=%u\nrv=%f\n",rem_in_start_year,rem_in_end_year,whole,ms,ms2,rv);
	};
	return rv;
};

unsigned int RJMF_TimeStamp::DiffMonth(RJMF_TimeStamp* pO) { //Diffrence in months
	unsigned int rv;
	if ((*this)==(*pO)) return 0;
	if ((*this)<(*pO)) {
		//return -1;
		rv = pO->DiffMonth(this);
		return rv * -1;
	};
	//pO<this
	RJMF_TimeStamp f = (*pO);
	rv = 0;
	while (f<=(*this)) {
		f.AddMonth(1);
		rv++;
	};
	return (rv-1);
};

unsigned int RJMF_TimeStamp::DiffDay(RJMF_TimeStamp* pO) { //Diffrence in months
	unsigned int rv;
	if ((*this)==(*pO)) return 0;
	if ((*this)<(*pO)) {
		//return -1;
		rv = pO->DiffDay(this);
		return rv * -1;
	};

	//pO<this
	if (m_year==pO->m_year) {
		return (GetDOY()-pO->GetDOY());
	};

	rv = 0;
	//Days in rest of this year
	rv = DIY(pO->m_year) - pO->GetDOY();
	
	//Whole years in between
	unsigned int ms = pO->m_year;
	while ((ms+1)<m_year) {
		ms++;
		rv += DIY(ms);
	};
	
	//Days in rest of final year
	rv += GetDOY();
	
	return rv;
};

unsigned int RJMF_TimeStamp::DiffSecond(RJMF_TimeStamp* pO) { //Diffrence in Seconds
	unsigned int rv;
	if ((*this)==(*pO)) return 0;
	if ((*this)<(*pO)) {
		//return -1;
		rv = pO->DiffSecond(this);
		return rv * -1;
	};
	//pO<this
	if (m_year==pO->m_year) {
		return ((m_hdth_secs - pO->m_hdth_secs)/100);
	};
	//Seconds until end of this year
	rv = (DIY(pO->m_year) * 24 * 60 * 60) - (pO->m_hdth_secs/100);
	unsigned int rb = 0;
	//Whole years in between
	unsigned int ms = 0;
	ms = pO->m_year;
	while ((ms+1)<m_year) {
		ms++;
		rb += DIY(ms) * 24 * 60 * 60;
	};
	unsigned int rn = (m_hdth_secs/100);
	
	return rv + rb + rn;
};

unsigned int RJMF_TimeStamp::DiffHdthSecond(RJMF_TimeStamp* pO) { //Diffrence in Seconds
	unsigned int rv;
	if ((*this)==(*pO)) return 0;
	if ((*this)<(*pO)) {
		//return -1;
		rv = pO->DiffHdthSecond(this);
		return rv * -1;
	};
	//pO<this
	if (m_year==pO->m_year) {
		return ((m_hdth_secs - pO->m_hdth_secs));
	};
	//Seconds until end of this year
	rv = (DIY(pO->m_year) * 24 * 60 * 60 * 100) - (pO->m_hdth_secs);
	unsigned int rb = 0;
	//Whole years in between
	unsigned int ms = 0;
	ms = pO->m_year;
	while ((ms+1)<m_year) {
		ms++;
		rb += DIY(ms) * 24 * 60 * 60 * 100;
	};
	unsigned int rn = (m_hdth_secs);
	
	return rv + rb + rn;
};
