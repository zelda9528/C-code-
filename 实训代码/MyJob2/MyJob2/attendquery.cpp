#include "stdafx.h"
#include "attendquery.h"
using namespace adosql;

attendquery::attendquery()
{
}


attendquery::~attendquery()
{
}
void attendquery::CreatePage()
{
	AdoCenter QUERYDB;
	cout << "*******************欢迎使用考勤汇总查询功能*******************" << endl;
	cout << "请输入员工名称：";
	cin >> NAME;
	cout << "请输入年月(2021-07)：";
	cin >> DATE;
	DATE = DATE + "-04";
	string SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('"+ DATE +"')+1 day) AND last_day(curdate()) AND `NAME`='"+NAME+"'; ";
	vector<string> Result;
	int res = QUERYDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		for (int i = 0; i < Result.size(); i++)
		{
			cout << Result[i] << endl;
		}
		cout << NAME + "该月工作天数为：" + to_string(Result.size())<< endl;
		SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('" + DATE + "')+1 day) AND last_day(curdate()) AND SUBTIME(NORSTART,`START`)<0 AND `NAME`='"+NAME+"'; ";
		Result.clear();
		QUERYDB.selectData(SQL, Result);
		cout << NAME+"该月迟到天数为：" + to_string(Result.size()) << endl;
		SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('" + DATE + "')+1 day) AND last_day(curdate()) AND SUBTIME(NOREND,`END`)>0 AND `NAME`='" + NAME + "'; ";
		Result.clear();
		QUERYDB.selectData(SQL, Result);
		cout << NAME + "该月早退天数为：" + to_string(Result.size()) << endl;
	}
	else
	{
		cout << "未查询到该记录!!!" << endl;
		return ;
	}

}
