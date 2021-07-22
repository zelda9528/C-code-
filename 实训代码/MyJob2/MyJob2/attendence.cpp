#include "stdafx.h"
#include "attendence.h"

using namespace adosql;
attendence::attendence()
{
}


attendence::~attendence()
{
}
void attendence::CreatePage()
{
	cout << "*******************欢迎使用考勤管理功能*******************" << endl;
	cout << "+++++++++          1.考勤信息增加          +++++++++" << endl;
	cout << "+++++++++          2.考勤信息删除           +++++++++" << endl;
	cout << "+++++++++          3.考勤信息查询           +++++++++" << endl;
	cout << "+++++++++          4.返回上一界面           +++++++++" << endl;
	cout << "*****************************************************" << endl;
	int In = 0;
	cout << "请输入指令：";
	cin >> In;
	switch (In)
	{
	case 1:Add(); break;
	case 2:Delete(); break;
	case 3:Query(); break;
	case 4:return; break;
	default:
		CreatePage();
		break;
	}
}
void attendence::Add()
{
	AdoCenter ATTENDENCEDB;
	cout << "请输入员工姓名：";
	cin >> NAME;
	cout << "请输入日期：";
	cin >> DATE;
	cout << "请输入员工上班打卡时间：";
	cin >> START;
	cout << "请输入员工下班打卡时间：";
	cin >> END;
	cout << "请输入员工规定上班时间：";
	cin >> NORSTART;
	cout << "请输入员工规定下班时间：";
	cin >> NOREND;
	string SQL = "INSERT INTO attendance VALUES ('"+ NAME +"','"+ START +"','"+ END +"','"+DATE+"','"+NORSTART+"','"+NOREND+"')";
	int Res = ATTENDENCEDB.executeSql(SQL);
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
void attendence::Delete()
{
	AdoCenter ATTENDENCEDB;
	cout << "请输入员工姓名：";
	cin >> NAME;
	cout << "请输入日期：";
	cin >> DATE;
	string SQL = "DELETE FROM attendance WHERE (NAME = '"+ NAME +"' and DATE='"+DATE+"')";
	int Res = ATTENDENCEDB.executeSql(SQL);
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

void attendence::Query()
{
	AdoCenter ATTENDENCEDB;
	cout << "*******************欢迎使用考勤管理功能*******************" << endl;
	cout << "+++++++++          1.按员工姓名查询          +++++++++" << endl;
	cout << "+++++++++          2.按日期查询              +++++++++" << endl;
	cout << "+++++++++          3.按年份查询              +++++++++" << endl;
	cout << "+++++++++          4.返回上一界面            +++++++++" << endl;
	cout << "**********************************************************" << endl;
	int In = 0;
	cout << "请输入指令：";
	cin >> In;
	switch (In)
	{
	case 1:
	{
		cout << "请输入员工姓名(王二)：";
		cin >> NAME;
		string SQL = "SELECT * FROM  attendance where ( NAME='" + NAME + "')";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
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
			CreatePage();
		}
		break;
	}
	case 2:
	{
		cout << "请输入日期(2021-07-15)：";
		cin >> DATE;
		string SQL = "SELECT * FROM  attendance where ( DATE='" + DATE + "')";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
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
			CreatePage();
		}
		break;
	}
	case 3:
	{
		cout << "请输入年份(2021)：";
		cin >> DATE;
		string SQL = "SELECT * FROM attendance WHERE DATE BETWEEN '"+DATE+"-01-01' AND '"+DATE+"-12-31'";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
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
			CreatePage();
		}
		break;
	}
	default:
		CreatePage();
		break;
	}
	CreatePage();

}
