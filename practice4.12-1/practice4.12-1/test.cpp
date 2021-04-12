#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>st;
		for (const auto&str : tokens)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				//进行运算
				//从栈中去两个操作数
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				//运算，结果再入栈
				if (str == "+")
					st.push(left + right);
				if (str == "-")
					st.push(left - right);
				if (str == "*")
					st.push(left*right);
				if (str == "/")
					st.push(left / right);
			}
			else
				st.push(stoi(str));//操作数入栈
		}
		return st.top();
	}
};