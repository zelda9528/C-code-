#include<iostream>
#include<vector>

using namespace std;

//开散列

//单链表的结点
template<class V>
struct HashNode {

	V _val;
	HashNode<V>* _next;


	HashNode(const V& val)
		:_val(val)
		,_next(nullptr)
	{}

};

//哈希表前置声明
template<class K, class V, class KeyOfValue>
class HashTable;

//哈希表的迭代器
//封装单链表的结点
template<class K,class V,class KeyOfValue>
struct HashIterator{
	typedef HashIterator<K, V, KeyOfValue> Self;
	typedef HashTable<K, V, KeyOfValue> HT;
	//成员：结点指针  哈希表指针
	typedef HashNode<V> Node;

	HT* _hptr;
	Node* _node;

	HashIterator(Node* node,HT* hptr):_node(node),_hptr(hptr)
	{}

	V& operator*()
	{
		return _node->_val;
	}
	V* operator->()
	{
		return &_node->_val;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//查找下一个非空链表的的头结点
			//计算当前节点在哈希表中的位置
			KeyOfValue kov;
			size_t idx = kov(_node->_val) % _hptr->_ht.size();
			//从下一个哈希位置开始查找
			++idx;
			for (; idx < _hptr->_ht.size(); idx++)
			{
				if (_hptr->_ht[idx])
				{
					_node = _hptr->_ht[idx];
					break;
				}
			}
			//有效结点遍历结束	
			if (idx == _hptr->_ht.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}

};

template<class K,class V,class KeyOfValue>
class HashTable {
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue> iterator;
	//把迭代器声明成友元类
	template<class K, class V, class KeyOfValue>
	friend struct HashIterator;

	HashTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//第一个有效元素的位置
		for (size_t i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
				return iterator(_ht[i], this);
		}
		return iterator(nullptr,this);
	}
	iterator end()
	{
		return iterator(nullptr, this);	
	}



	pair <iterator, bool> insert(const V& val)
	{
		//0.检查容量
		checkCapacity();
		//1.计算hash位置
		KeyOfValue kov;
		size_t idx = kov(val) % _ht.size();
		//2.查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key存在，插入失败
				//return false;
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		//3.插入:头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;

		//return true;
		return make_pair(iterator(cur, this), true);
	}

	void checkCapacity()
	{
		//开散列：当有效元素个数等于哈希表长度时（即负载因子等于1时）发生增容
		//负载因子=有效元素个数/哈希表长度
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;
			//创建新数组
			vector<Node*> newHT(newC);

			KeyOfValue kov;
			//遍历旧表
			for (size_t i = 0; i < _ht.size(); i++)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					//计算新位置
					size_t idx = kov(cur->_val ) % newHT.size();
					//头插

					cur->_next = newHT[idx];
					newHT[idx] = cur;

					cur = next;
				}
				//旧表置空
				_ht[i] = nullptr;
			}
			swap(_ht, newHT);
		}
	}

	Node* Find(const K& key)
	{}	
	bool Eraser(const K& key)
	{}


private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};



//模拟实现Set
template<class K>
class Set {
	struct SetKeyOfValue {
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue>::iterator iterator;
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& key)
	{
		return _ht.insert(key);
	}

private:
	HashTable<K, K, SetKeyOfValue> _ht;
};


//模拟实现Map
template<class K,class V>
class Map
{	
	struct MapKeyOfValue {
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	pair<iterator, bool>insert(const pair<K,V>& val)
	{
		return _ht.insert(val);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key,V()));
		return ret.first->second;
	}
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue> _ht;

};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1,1));
	m[10] = 10;
	m[20] = 20;
	m[30] = 30;


	Map<int,int>::iterator it=m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << " ";
		++ it;
	}
	cout << endl;

	for (const auto& e : m)
	{
		cout << e.first << "--->"<<e.second<<" ";
	}
	cout << endl;
}


//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(4);
//	s.insert(7);
//	s.insert(9);
//	s.insert(11);
//	s.insert(44);
//	s.insert(55);
//	s.insert(16);
//	s.insert(17);
//	s.insert(13);
//
//	Set<int>::iterator it=s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++ it;
//	}
//	cout << endl;
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}