#define _CRT_SECURE_NO_WARNINGS 1

// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
using namespace std;

int main() {
	std::pair <int, int> foo;
	std::pair <int, char> bar;

	foo = std::make_pair(10, 20);
	bar = std::make_pair(100, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

	cout << std::get<2>(bar) << endl;
	return 0;
}