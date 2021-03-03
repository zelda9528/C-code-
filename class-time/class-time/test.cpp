#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date {
public:
	Date(int y = 1, int m = 1,int d=1)
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
			_y= y;
			_m = m;
			_d = d;
		}

	}
	int getday(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day= days[m];
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

	//Date + int
	//返回相加之后的结果，操作数不改变
	Date operator+(int day)
	{
		Date copy = *this;
		return copy += day;
	}

	//++Date
	Date& operator++()
	{
		return *this += 1;
	}

	//Date++
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;

		return copy;
	}

	//Date -= int 
	Date& operator-=(int day)
	{
		//首先日期相减
		_d -= day;

		//判断是否溢出
		while (_d < 0 )
		{
			//加上当月天数
			_d += getday(_y, _m-1);

			//月份退位
			--_m;

			//月份是否溢出
			if (_m < 0 )
			{
				//年份退位
				--_y;

				//月份更新为12月
				_m = 12;
			}

		}
		//返回相加之后的结果
		return *this;
	}

	// 后置--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_y > d._y)
		{
			return true;
		}
		else if (_y == d._y)
		{
			if (_m > d._m)
			{
				return true;
			}
			else if (_m == d._m)
			{
				if (_d > d._d)
				{
					return true;
				}
			}
		}
		return false;
	}

	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _y == d._y
			&& _m == d._m
			&& _d == d._d;
	}

	// 下面复用上面两个的实现
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// d1 - d2
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++(min);
			++day;
		}
		return day * flag;
	}

private:
	int _y;
	int _m;
	int _d;

};

void test()
{
	Date d1(2021,2,4);
	Date d2(2021, 2, 4);
	Date d3(2021, 2, 4);
	Date d4(2021, 2, 4);
	Date d5(2021, 2, 4);


}

int main()
{
	test();
	return 0;
}