#include "Application.h"
#include "sqlite3.h"
#include "Glob_Defs.h"
#include "RJM_SQLite_Resultset.h"
#define DATABASE_FILE "database.sqlite"
#include <string>
int buildDatabase();
/*
* The entry point for the application.
* Create Application Object
* @Return @method Application::run()
*/
int main()
{
	/*
	Installer *ins = new Installer();
	if(ins->checkInstall()==false)
		ins->invoke();
	*/
	buildDatabase();
	Application *app = new Application();
	return app->run();
}

int buildDatabase()
{
	using namespace std;
	string l_filename = DATABASE_FILE;
	ostringstream l_query;
	sqlite3* l_sql_db = NULL;

	int rc = sqlite3_open(l_filename.c_str(), &l_sql_db);
	if( rc ){
		sqlite3_close(l_sql_db);
		cout << "Error couldn't open SQLite database " << l_filename;
		return 1;
	};

	RJM_SQLite_Resultset *pRS = NULL;
	pRS = SQL_Execute("SELECT name FROM sqlite_master WHERE type='table' and name='members';", l_sql_db);	
	if (!pRS->Valid()) {
		cout << "Invalid result set returned\n", pRS->GetLastError();
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
		return 0;
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if (0!=rc) {
		//printf("Table exists\n");
	} else {
		cout << "Table dosn't exist creating it\n";
		l_query.str("");
		l_query << "CREATE TABLE [member] (";
		l_query << "[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,";
		l_query << "[firstname] VARCHAR(25)  NULL,";
		l_query << "[lastname] VARCHAR(25)  NULL,";
		l_query << "[address] VARCHAR(50)  NULL,";
		l_query << "[contactnumber] INTEGER  NULL";
		l_query << ")";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid()) {
			cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
			return 0;
		};
	};
	SAFE_DELETE(pRS);
	pRS = SQL_Execute("SELECT name FROM sqlite_master WHERE type='table' and name='magazine';", l_sql_db);	
	if (!pRS->Valid()) {
		cout << "Invalid result set returned\n", pRS->GetLastError();
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
		return 0;
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if (0!=rc) {
		//printf("Table exists\n");
	} else {
		cout << "Table doesn't exist creating it\n";
		l_query.str("");
		l_query << "CREATE TABLE [magazine] (";
		l_query << "[referencenumber] VARCHAR(6)  NOT NULL PRIMARY KEY,";
		l_query << "[title] VARCHAR(25)  NULL,";
		l_query << "[author] VARCHAR(25)  NULL,";
		l_query << "[volume] VARCHAR(10)  NULL,";
		l_query << "[issuedate] VARCHAR(25)  NULL,";
		l_query << "[issuetopic] VARCHAR(25)  NULL";
		l_query << ")";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid()) {
			cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
			return 0;
		};
	};
	SAFE_DELETE(pRS);
	pRS = SQL_Execute("SELECT name FROM sqlite_master WHERE type='table' and name='researchpaper';", l_sql_db);	
	if (!pRS->Valid()) {
		cout << "Invalid result set returned\n", pRS->GetLastError();
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
		return 0;
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if (0!=rc) {
		//printf("Table exists\n");
	} else {
		cout << "Table dosn't exist creating it\n";
		l_query.str("");
		l_query << "CREATE TABLE [researchpaper] (";
		l_query << "[referencenumber] VARCHAR(6)  NOT NULL PRIMARY KEY,";
		l_query << "[title] VARCHAR(25)  NULL,";
		l_query << "[author] VARCHAR(25)  NULL,";
		l_query << "[researchtopic] VARCHAR(25)  NULL,";
		l_query << "[supervisor] VARCHAR(25)  NULL,";
		l_query << "[sponsor] VARCHAR(25)  NULL";
		l_query << ")";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid()) {
			cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
			return 0;
		};
	};
	SAFE_DELETE(pRS);
	pRS = SQL_Execute("SELECT name FROM sqlite_master WHERE type='table' and name='textbook';", l_sql_db);	
	if (!pRS->Valid()) {
		cout << "Invalid result set returned\n", pRS->GetLastError();
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
		return 0;
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if (0!=rc) {
		//printf("Table exists\n");
	} else {
		cout << "Table dosn't exist creating it\n";
		l_query.str("");
		l_query << "CREATE TABLE [textbook] (";
		l_query << "[referencenumber] VARCHAR(6)  NOT NULL PRIMARY KEY,";
		l_query << "[title] VARCHAR(25)  NULL,";
		l_query << "[author] VARCHAR(25)  NULL,";
		l_query << "[isbn] VARCHAR(25)  NULL,";
		l_query << "[course] VARCHAR(25)  NULL,";
		l_query << "[publisher] VARCHAR(25)  NULL,";
		l_query << "[datepublished] VARCHAR(25)  NULL";
		l_query << ")";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid()) {
			cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
			return 0;
		};
	};
	SAFE_DELETE(pRS);
	pRS = SQL_Execute("SELECT name FROM sqlite_master WHERE type='table' and name='loan';", l_sql_db);	
	if (!pRS->Valid()) {
		cout << "Invalid result set returned\n", pRS->GetLastError();
		SAFE_DELETE(pRS);
		sqlite3_close(l_sql_db);
		return 0;
	};
	rc = pRS->GetRowCount();
	SAFE_DELETE(pRS);
	if (0!=rc) {
		//printf("Table exists\n");
	} else {
		cout << "Table doesn't exist creating it\n";
		l_query.str("");
		l_query << "CREATE TABLE [loan] (";
		l_query << "[memberid] INTEGER  NOT NULL,";
		l_query << "[referencenumber] VARCHAR(6)  NOT NULL,";
		l_query << "[requestdate] VARCHAR(25)  NULL,";
		l_query << "[loantype] VARCHAR(25)  NULL";
		l_query << ")";
		pRS = SQL_Execute(l_query.str().c_str(), l_sql_db);	
		if (!pRS->Valid()) {
			cout << "Invalid result set returned " << pRS->GetLastError() << endl;
			SAFE_DELETE(pRS);
			sqlite3_close(l_sql_db);
			return 0;
		};
	};
	SAFE_DELETE(pRS);
	sqlite3_close(l_sql_db);
	return 1;
}
