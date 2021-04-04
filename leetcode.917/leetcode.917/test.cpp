#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	bool isLetter(const char&ch)
	{
		return ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z';
	}
	string reverseOnlyLetters(string S)
	{
		if (S.empty())
			return S;
		string::iterator start = S.begin();
		string::iterator end = S.end() - 1;
		while (start < end)
		{
			while (start != end && !isLetter(*start))
				++start;
			while (start != end && !isLetter(*end))
				--end;


			/*int start=0;
			int end=S.size()-1;
			while(start <end )
			{
				//找到有效字符
				while(start<end && !isLetter(S[start]))
					++start;
				while(start<end && !isLetter(S[end]))
					--end;
			*/
			//交换
			swap(*start, *end);
			start++;
			end--;
		}
		return S;

	}

};
