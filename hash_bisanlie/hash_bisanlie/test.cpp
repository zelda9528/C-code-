#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//哈希：闭散列
enum STATE {
	EXIST,
	DELETE,
	EMPTY
};

//哈希表：线性探测
template<class K, class V>
struct HashNode {


	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//顺序表实现哈希
template<class K, class V>
class HashTable {
public:
	typedef HashNode<K, V> Node;

	HashTable(size_t n = 10)
		:_hTable(n)
		, _size(0)
	{}

	bool insert(const pair<K, V>& kv)
	{

		//0.检查容量
		checkCapacity();
		//1.计算哈希位置
		int idx = kv.first % _hTable.size();
		//2.判断key是否存在：哈希不能存放重复的数据
		while (_hTable[idx]._state != EMPTY)
		{
			//如果当前位置数据有效，并且key相同，插入失败
			if (_hTable[idx]._state == EXIST && kv.first == _hTable[idx]._kv.first)
			{
				return false;
			}

			//继续搜索
			++idx;
			if (idx == _hTable.size())
			{
				idx = 0;
			}
		}

		_hTable[idx]._kv = kv;
		_hTable[idx]._state = EXIST;
		++_size;

		return true;
	}

	void checkCapacity()
	{
		//负载因子：当前有效元素个数/容量  一般 < 1

		//if (_size  / _hTable.size() >= 0.7)  转换成下面的写法更方便比较  
		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= 7)
		{
			//开新表
			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
			HashTable <K, V> newht(newC);

			for (size_t i = 0; i < _hTable.size(); i++)
			{
				if (_hTable[i]._state == EXIST)
				{
					newht.insert(_hTable[i]._kv);
				}
			}
			Swap(newht);
		}
	}

	void Swap(HashTable<K, V>& ht)
	{
		swap(_hTable, ht._hTable);
		swap(_size, ht._size);
	}

	Node* find(const K& key)
	{
		//计算位置
		int idx = key % _hTable.size();
		while (_hTable[idx]._state != EMPTY)
		{
			if (_hTable[idx]._state == EXIST && key == _hTable[idx]._kv.first)
			{
				return &_hTable[idx];
			}
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}
		return nullptr;
	}

	bool eraser(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			//假删除---
			--_size;
			node->_state = DELETE;
			return true;
		}
		return false;
	}

private:

	vector<Node> _hTable;
	size_t _size;			//表示当前有效元素的个数
};

void test()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(14, 14));
	ht.insert(make_pair(16, 16));
	ht.insert(make_pair(11, 11));
	ht.insert(make_pair(14, 14));

	ht.insert(make_pair(2, 1));
	ht.insert(make_pair(3, 14));
	ht.insert(make_pair(5, 16));
	ht.insert(make_pair(7, 11));
	ht.insert(make_pair(9, 14));

	cout << ht.find(11) << endl;
	ht.eraser(11);
	cout << ht.find(11) << endl;

}

int main()
{
	test();
	return 0;
}