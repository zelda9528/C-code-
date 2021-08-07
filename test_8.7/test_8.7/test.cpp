#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


//n���ƷŽ�n�����ӣ����м��ַ���
void DFS(vector<int>& box,vector<int>& used,int idx)
{
	//�ݹ�ı߽�����
	if (idx == box.size())
	{
		for (int i = 1; i < box.size(); i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	
	//����ǰ����
	for (int i = 1; i < box.size(); i++)
	{
		//�жϵ�ǰ�����Ƿ��ù�
		if (used[i] == 0)
		{
			used[i] = 1;
			box[idx] = i;

			//����ʣ��ĺ���
			DFS(box, used, idx+1);

			//���յ�ǰʹ�õ���
			used[i] = 0;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> box(n+1, 0);
	vector<int> used(n+1, 0);

	DFS(box, used, 1);


	return 0;
}