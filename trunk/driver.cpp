/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
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