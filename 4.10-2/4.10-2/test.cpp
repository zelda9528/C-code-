#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		//vector<int> maxSum(array);
		int i = 1;
		int ret = array[0];
		for (; i < array.size(); i++)
		{
			array[i] = max(array[i - 1] + array[i], array[i]);
			ret = max(ret, array[i]);
		}

		/*int ret=maxSum[0];
		for(int i=0;i<array.size();i++)
		{
			if(maxSum[i]>ret)
				ret=maxSum[i];
		}*/
		return ret;

	}
};