#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count[10] = { 0 };
		for (const int & e : numbers)
		{
			count[e]++;
		}
		for (int i = 0; i < 10; i++)
		{
			if (count[i] > (numbers.size() / 2))
				return i;
		}
		return 0;
	}
};