#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Rectangle {
private:
	pair<int, int> lower_left_coner;//左下角坐标
	pair<int, int> upper_right_coner;//右上角坐标
public:
	Rectangle(int a, int b, int c, int d) :
		lower_left_coner(make_pair(a, b))
		, upper_right_coner(make_pair(c, d)) {}
	int area()
	{
		return (upper_right_coner.first - lower_left_coner.first)
			  *(upper_right_coner.second-lower_left_coner.second);
	}
	
	~Rectangle() = default;
};
void test()
{
	Rectangle a(1, 1, 9, 9);
	cout << a.area() << endl;
}
int main()
{
	test();
	return 0;
}