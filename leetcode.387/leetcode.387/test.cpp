#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int firstUniqChar(string s) {
		int count[128] = { 0 };
		for (const char&ch : s)
		{
			count[ch]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i]] == 1)
				return i;
		}
		return -1;
	}
};





