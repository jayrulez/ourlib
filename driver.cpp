#include <windows.h>
#include <iostream>
#include "sqlite3.h"

using namespace std;

int main()
{ 
	sqlite3* db;
	char* db_err;
	const char* vfs;//= sqlite_vfs();
	int i = sqlite3_open("my_db.sql3", &db);
	cout << i << endl;
	sqlite3_exec(db, "create table 'helloworld' (id integer);", NULL, 0, &db_err);
	sqlite3_close(db);
	system("pause");
	return 0;
}