#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
template <class K,class V>
struct BNode {
	//T data_;
	K  _key;		//类似于索引
	V _value;		//类似于data_

	typedef BNode<K,V> Node;
	Node* left;
	Node* right;

	BNode(const K&key,const V&value) :_key(key),_value(value),left(nullptr), right(nullptr)
	{}
};

template<class K,class V>
class BTree {
public:
	typedef BNode<K,V> Node;
	BTree() :root_(nullptr)
	{}

	//不插入重复的值
	bool insert(const K&key,const V&value)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(key,value);
			return true;
		}

		//搜索
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//插入
		cur = new Node(key,value);
		if (parent->_key > key)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const K& key)
	{
		Node* cur = root_;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return cur;
	}



	void inorder()
	{
		_inorder(root_);
	}

	//搜索树中序遍历：有序
	void _inorder(Node* root_)
	{
		if (root_)
		{
			_inorder(root_->left);
			cout << root_->_key << "-->"<<root_->_value<<" ";
			_inorder(root_->right);
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		
		//拷贝根
		Node* newnode = new Node(root->_key,root->_value);
		//拷贝左子树
		newnode->left = copy(root->left);
		//拷贝右子树
		newnode->right = copy(root->right);

		return newnode;
	}

	//删除
	bool erase(const K& key)
	{
		//查找
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key == key)
				break;
			parent = cur;
			if (cur->_key > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//判断需要删除的结点是否找到
		if (cur == nullptr)
			return false;

		//删除
		//1.删除的为叶子节点
		if (cur->left == nullptr&&cur->right == nullptr)
		{
			//判断是否为根结点
			if (cur == root_)
			{
				root_ = nullptr;
			}
			else
			{
				//判断需要删除的结点在父节点哪一边
				if (parent->left == cur)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			//删除结点
			delete cur;
		}

		//2.删除的为非叶子结点:
		//2.1左子树为空
		else if (cur->left == nullptr)
		{
			//判断根结点是否为要删除的结点
			if (cur == root_)
			{
				root_ = cur->right;
			}
			else
			{
				//更新链接
				if (parent->left == cur)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
			//删除结点
			delete cur;
		}
		//2.2右子树为空
		else if (cur->right == nullptr)
		{
			//判断根结点是否为要删除的结点
			if (cur == root_)
			{
				//更新根结点
				root_ = cur->left;
			}
			else
			{
				//更新链接
				if (parent->left == cur)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
			//删除结点
			delete cur;
		}
		//2.3要删除的结点有左右孩子
		else
		{
			//1.假设找左子树的最右结点
			Node* leftRightMost = cur->left;
			parent = cur;
			while (leftRightMost->right)
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->right;
			}
			//2.交换
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);

			//3.删除最右结点
			if (parent->left == leftRightMost)
				parent->left = leftRightMost->left;
			else
				parent->right = leftRightMost->left;

			delete leftRightMost;
		}

		//else
		//{
		//	Node* RIGHT = cur->right;
		//	if (RIGHT->left == nullptr)
		//		RIGHT->left = cur->left;
		//	else
		//		RIGHT->left->left = cur->left;
		//	//判断要删除的结点是否为根结点
		//	if (cur == root_)
		//	{
		//		root_ = RIGHT;		//更新根结点
		//		delete cur;
		//		return true;
		//	}
		//	if (parent->left == cur)
		//		parent->left = RIGHT;
		//	else
		//		parent->right = RIGHT;
		//	delete cur;
		//}

		return true;
	}

	//在成员初始化列表阶段调用copy()函数进行拷贝构造
	BTree(const BTree<K,V>& btree) :root_(copy(btree.root_))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->left);
			destroy(root->right);
			cout << "destroy:" << root->_key <<"-->"<<root->_value<<endl;
			delete root;
		}
	}

	~BTree()
	{
		if (root_)
		{
			destroy(root_);
			root_ = nullptr;
		}
	}

private:
	Node* root_;
};


void test()
{
	BTree<int, int>b;
	b.insert(5,50);
	b.insert(3, 50);
	b.insert(7, 50);
	b.insert(1, 50);
	b.insert(4, 50);
	b.insert(6, 50);
	b.insert(8, 50);
	cout << endl;

	b.inorder();
	

}


int main()
{
	test();
	return 0;
}