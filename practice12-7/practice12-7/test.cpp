#include<iostream>
using namespace std;
double Pay(double price, int month, int day, int coupon)
{
	if (month == 11 && day == 11)
	{
		if (coupon == 1)
			return price * 0.7 - 50;
		else
			return price * 0.7;
	}
	else if (month == 12 && day == 12)
	{
		if (coupon == 1)
			return price * 0.8 - 50;
		else
			return price * 0.8;
	}
	else
		return price;
}

int main()
{
	double price;
	int month;
	int day;
	int coupon;
	cin >> price >> month >> day >> coupon;
	double a= Pay(price, month, day, coupon);
	cout.precision(2);
	cout << a;
	return 0;
}