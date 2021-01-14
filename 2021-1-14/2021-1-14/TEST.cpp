#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string toLowerCase(string str) {
		int len = str.size();
		for (int i = 0; i < len; ++i)
		{
			if (str[i] <= 'Z' && str[i] >= 'A')
			{
				str[i] += 32;
			}
		}
		return str;
	}
};