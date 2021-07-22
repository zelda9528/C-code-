#include "stdafx.h"
#include "LoginPage.h"
using namespace std;
using namespace adosql;
LoginPage::LoginPage()
{

}

LoginPage::~LoginPage()
{

}
void LoginPage::CreatePage()
{
	rename("EOF", "adoEOF"), rename("BOF", "adoBOF");
	cout << "****************欢迎使用考勤管理系统*****************" << endl;
	cout << "请输入用户名：";
	cin >> UserName;
	cout << "请输入密码：";
	cin >> PassWord;
	AdoCenter AdminDB;
	AdminDB.connect();
	string SQL = "SELECT * FROM  administrator where ( NAME='"+UserName+"' and PASSWORD = '"+PassWord+"')";
	//cout << SQL;
	vector<string> Result;
	int res=AdminDB.selectData(SQL, Result);
	//cout << Result.size();
	if(Result.size()!=0&&res!=-1)
	{
		cout << "登录成功!!!"<<endl;
		HOMEPAGE.CreatePage();
	}	
	else
	{
		cout << "账号或者密码错误，请重新输入" << endl;
		CreatePage();
	}
}

