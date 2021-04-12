#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		stack<int>st;
		int pushIdx = 0;
		int popIdx = 0;

		//»Î’ª
		while (pushIdx < pushV.size())
		{
			st.push(pushV[pushIdx++]);

			while (!st.empty() && st.top() == popV[popIdx])
			{
				st.pop();
				popIdx++;
			}
		}
		return st.empty();

	}
};