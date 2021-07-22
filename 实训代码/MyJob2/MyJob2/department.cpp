#include "stdafx.h"
#include "department.h"

using namespace adosql;
department::department()
{
}


department::~department()
{
}
void department::CreatePage()
{
	cout << "*******************欢迎使用部门管理功能*******************" << endl;
	cout << "+++++++++          1.部门信息增加           +++++++++" << endl;
	cout << "+++++++++          2.部门信息修改           +++++++++" << endl;
	cout << "+++++++++          3.部门信息查询           +++++++++" << endl;
	cout << "+++++++++          4.返回上一界面           +++++++++" << endl;
	cout << "*****************************************************" << endl;
	int In = 0;
	cout << "请输入指令：";
	cin >> In;
	switch (In)
	{
	case 1:Add(); break;
	case 2:Modify(); break;
	case 3:Query(); break;
	case 4:return; break;
	default:
		CreatePage();
		break;
	}
}
void department::Add()
{
	AdoCenter DEPARTDB;
	cout << "请输入部门名称：";
	cin >> NAME;
	cout << "请输入部门编号：";
	cin >> ID;
	cout << "请输入上级部门编号：";
	cin >> SENIORID;
	cout << "请输入备注：";
	cin >> REMARKS;
	string SQL = "INSERT INTO department VALUES ('" + NAME + "'," + ID + "," + SENIORID + ",'" + REMARKS + "')";
	int Res=DEPARTDB.executeSql(SQL);
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

void department::Modify()
{
	AdoCenter DEPARTDB;
	cout << "请输入要修改的部门名称：";
	cin >> NAME;
	string SQL = "SELECT * FROM  department where NAME='" + NAME + "'";
	vector<string> Result;
	int res = DEPARTDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "           名称            编号   上级编号    备注" << endl;
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]), ",", "          ") << endl;
		}
		cout << "请输入修改后的部门名称：";
		cin >> NAME;
		cout << "请输入修改后的部门编号：";
		cin >> ID;
		cout << "请输入修改后的上级部门编号：";
		cin >> SENIORID;
		cout << "请输入修改后的备注：";
		cin >> REMARKS;
		SQL = "UPDATE department SET `NAME`='"+NAME+"',ID="+ID+",SENIORID="+SENIORID+",REMARKS='"+REMARKS+"' WHERE `NAME`='"+NAME+"';";
		int Res = DEPARTDB.executeSql(SQL);
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

void department::Query()
{
	AdoCenter DEPARTDB;
	cout << "请输入部门名称：";
	cin >> NAME;
	string SQL = "SELECT * FROM  department where NAME='" + NAME + "'";
	vector<string> Result;
	int res = DEPARTDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "           名称            编号   上级编号    备注" << endl;
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]),",","          ") << endl;
		}
		SQL = "SELECT C.* FROM department AS A LEFT JOIN workers AS B on A.ID=B.DEPAERTID  JOIN attendance AS C on B.`NAME`=C.`NAME` WHERE A.`NAME`='" + NAME + "'; ";
		Result.clear();
		res = DEPARTDB.selectData(SQL, Result);
		if (Result.size() != 0 && res != -1)
		{
			cout << "姓名   上班打卡时间  下班打卡时间 日期 上班规定时间 下班规定时间" << endl;
			for (int i = 0; i < Result.size(); i++)
			{
				cout << Result[i] << endl;
			}

		}
		else
		{
			cout << "未查询到该记录!!!" << endl;
		}

	}
	else
	{
		cout << "未查询到该记录!!!" << endl;
	}
	CreatePage();
}