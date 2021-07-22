#include "stdafx.h"
#include "HomePage.h"


HomePage::HomePage()
{

}


HomePage::~HomePage()
{

}
void HomePage::CreatePage()
{
	while (1)
	{
		cout << "****************欢迎使用考勤管理系统*****************" << endl;
		cout << "+++++++++          1.人事信息管理           +++++++++" << endl;
		cout << "+++++++++          2.考勤信息管理           +++++++++" << endl;
		cout << "+++++++++          3.考勤汇总查询           +++++++++" << endl;
		cout << "+++++++++          4.部门信息管理           +++++++++" << endl;
		cout << "+++++++++          5.退出系统               +++++++++" << endl;
		cout << "*****************************************************" << endl;
		int In = 0;
		cout << "请输入指令：";
		cin >> In;
		switch (In)
		{
		case 1:WORKER.CreatePage(); break;
		case 2:ATTENDENCE.CreatePage(); break;
		case 3:ATTENDQUERY.CreatePage(); break;
		case 4:DEPARTMENT.CreatePage(); break;
		case 5:return; break;
		default:
			break;
		}
	}
}