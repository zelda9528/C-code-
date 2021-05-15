#define _CRT_SECURE_NO_WARNINGS 1



//ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=182&tqId=34783&rp=1&ru=%2Fta%2Fexam-all&qru=%2Fta%2Fexam-all%2Fquestion-ranking&tab=answerKey

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_sum = 0, right_sum = 0;
		int left_min = INT_MAX, right_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (0 == left[i] * right[i])
			{
				sum = sum + left[i] + right[i];
			}
			else
			{
				left_sum += left[i];
				if (left[i] < left_min)
					left_min = left[i];

				right_sum += right[i];
				if (right[i] < right_min)
					right_min = right[i];

			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};