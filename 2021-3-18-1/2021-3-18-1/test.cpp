#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date {
public:

	friend ostream& operator<<(ostream& _cout, const Date& d);


	Date(int y = 1, int m = 1, int d = 1)
	{
		//判断日期是否有效
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getday(y, m))
		{
			//日期无效
			y = 1;
			m = 1;
			d = 1;
			cout << "日期无效,设为默认值：1-1-1" << endl;
		}
		else
		{
			_y = y;
			_m = m;
			_d = d;
		}

	}


	int getday(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[m];
		//如果为二月，并且为闰年，修改天数
		if (m == 2 && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))
			day += 1;
		return day;
	}


	//日期的运算
	//Date += int
	//左操作数改变为相加后的结果
	//2021。2.4 + 90 ： 2021.2.94 -28 ---> 2021.3.66 - 31 ---> 2021.4.35 - 30 ---> 2021.5.5
	Date& operator+=(int day)
	{
		//首先天数相加
		_d += day;
		//判断是否溢出
		while (_d > getday(_y, _m))
		{
			//减去当月天数
			_d -= getday(_y, _m);
			//月份进位
			++_m;
			//月份是否溢出
			if (_m == 13)
			{
				//年份进位
				++_y;
				//月份更新为一月
				_m = 1;
			}
		}
		//返回相加之后的结果
		return *this;
	}

	

private:
	int _y;
	int _m;
	int _d;


};

ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._y << "-" << d._m << "-" << d._d;
	printf("%04d-",d._y);
	printf("%02d-", d._m);
	printf("%02d", d._d);

	return _cout;
}

int main()
{
	int i = 0;
	cin >> i;
	int y, m, d,num;
	while (i-- > 0)
	{
		cin >> y >> m >> d >> num;
		Date a(y, m, d);
		a += num;
		cout << a << endl;
	}

	return 0;
}