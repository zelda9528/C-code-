#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		vector<int> maxSum(array);
		int i = 1;
		for (; i < array.size(); i++)
		{
			maxSum[i] = max(maxSum[i - 1] + array[i], array[i]);
		}

		int ret = maxSum[0];
		for (int i = 0; i < array.size(); i++)
		{
			if (maxSum[i] > ret)
				ret = maxSum[i];
		}
		return ret;

	}
};