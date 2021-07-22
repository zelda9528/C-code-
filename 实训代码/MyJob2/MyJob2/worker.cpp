#include "stdafx.h"
#include "worker.h"

using namespace adosql;
worker::worker()
{
}


worker::~worker()
{
}
void worker::CreatePage()
{
	cout << "*******************欢迎使用人事管理功能*******************" << endl;
	cout << "+++++++++          1.查询员工信息             +++++++++" << endl;
	cout << "+++++++++          2.增加员工信息             +++++++++" << endl;
	cout << "+++++++++          3.修改员工信息             +++++++++" << endl;
	cout << "+++++++++          4.删除员工信息             +++++++++" << endl;
	cout << "+++++++++          5.返回上一界面             +++++++++" << endl;
	cout << "**********************************************************" << endl;
	int In = 0;
	cout << "请输入指令：";
	cin >> In;
	switch (In)
	{
	case 1:Query(); break;
	case 2:Add(); break;
	case 3:Modify(); break;
	case 4:Delete(); break;
	case 5:return; break;
	default:
		CreatePage();
		break;
	}
}

void worker::Add()
{
	AdoCenter WORKERDB;
	cout << "请输入员工姓名：";
	cin >> NAME;
	cout << "请输入员工编号：";
	cin >> ID;
	cout << "请输入员工性别：";
	cin >> GENDER;
	cout << "请输入员工生日：";
	cin >> BIRTHDAY;
	cout << "请输入员工部门编号：";
	cin >> DEPAERTID;

	string SQL = "INSERT INTO workers VALUES('"+NAME+"',"+ID+",'"+GENDER+"','"+BIRTHDAY+"',"+DEPAERTID+")";
	int Res = WORKERDB.executeSql(SQL);
	if (Res != -1)
	{
		cout << "操作成功!!!" << endl;
	}
	else
	{
		cout << "操作失败!!!" << endl;
	}
	CreatePage();
}
void worker::Delete()
{
	AdoCenter WORKERDB;
	cout << "请输入员工姓名(王二)：";
	cin >> NAME;
	string SQL = "DELETE FROM workers WHERE (NAME = '" + NAME + "')";
	int Res = WORKERDB.executeSql(SQL);
	if (Res != -1)
	{
		cout << "操作成功!!!" << endl;
	}
	else
	{
		cout << "操作失败!!!" << endl;
	}
	CreatePage();
}
void worker::Modify()
{
	AdoCenter WORKERDB;
	cout << "请输入要修改的员工姓名：";
	cin >> NAME;
	string SQL = "SELECT * FROM  workers where NAME='" + NAME + "'";
	vector<string> Result;
	int res = WORKERDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]), ",", "     ") << endl;
		}
		cout << "请输入修改后的员工姓名：";
		cin >> NAME;
		cout << "请输入修改后的员工编号：";
		cin >> ID;
		cout << "请输入修改后的员工性别：";
		cin >> GENDER;
		cout << "请输入修改后的员工生日：";
		cin >> BIRTHDAY;
		cout << "请输入修改后的员工部门编号：";
		cin >> DEPAERTID;
		SQL = "UPDATE workers SET  `NAME`='"+NAME+"',ID="+ID+",GENDER='"+GENDER+"',BIRTHDAY='"+BIRTHDAY+"',DEPAERTID="+ DEPAERTID +" WHERE `NAME`='"+NAME+"'";
		int Res = WORKERDB.executeSql(SQL);
		if (Res != -1)
		{
			cout << "操作成功!!!" << endl;
		}
		else
		{
			cout << "操作失败!!!" << endl;
		}
		CreatePage();
	}
	else
	{
		cout << "未查询到该记录!!!" << endl;
	}
	CreatePage();
}
void worker::Query()
{
	AdoCenter WORKERDB;
	cout << "请输入员工姓名(王二)：";
	cin >> NAME;
	string SQL = "SELECT A.`NAME`,A.ID,A.GENDER,A.BIRTHDAY,B.`NAME` FROM workers AS A LEFT JOIN department AS B ON A.DEPAERTID=B.ID WHERE A.`NAME`='"+NAME+"'";
	vector<string> Result;
	int res = WORKERDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "姓名  编号   性别  生日  部门" << endl;
		for (int i = 0; i < Result.size(); i++)
		{
			cout << Result[i] << endl;
		}
	}
	else
	{
		cout << "未查询到该记录!!!" << endl;
		CreatePage();
	}
	CreatePage();
}