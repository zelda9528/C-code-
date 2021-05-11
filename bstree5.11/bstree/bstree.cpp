#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
template <class T>
struct BNode {
	T data_;
	typedef BNode<T> Node;
	Node* left;
	Node* right;

	BNode(const T&data) :data_(data), left(nullptr), right(nullptr)
	{}

};

template<class T>
class BTree {
public:
	typedef BNode<T> Node;
	BTree():root_(nullptr)
	{}

	//不插入重复的值
	bool insert(const T&val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return true;
		}

		//搜索
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->data_ == val)
				return false;
			else if (cur->data_ > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//插入
		cur = new Node(val);
		if (parent->data_ > val)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const T& val)
	{
		Node* cur = root_;
		while (cur)
		{
			if (cur->data_ == val)
				return cur;
			else if (cur->data_ > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
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
			cout << root_->data_ << " ";
			_inorder(root_->right);
		}
	}

	//拷贝二叉搜索树的数据和结构
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		//拷贝根
		Node* newnode = new Node(root->data_);
		//拷贝左子树
		newnode->left = copy(root->left);
		//拷贝右子树
		newnode->right = copy(root->right);

		return newnode;
	}

	//删除
	bool erase(const T& val)
	{
		//查找
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->data_ == val)
				break;
			parent = cur;
			if (cur->data_ > val)
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
		else if(cur->left==nullptr)
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
			swap(cur->data_, leftRightMost->data_);
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
	BTree(const BTree<T>& btree):root_(copy(btree.root_))
	{}


	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->left);
			destroy(root->right);
			//cout << "destroy:" << root->data_ << " ";
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
	BTree<int> b;

	b.insert(5);
	b.insert(3);
	b.insert(7);
	b.insert(1);
	b.insert(4);
	b.insert(6);
	b.insert(8);
	b.insert(0);
	b.insert(2);
	b.insert(9);
	b.insert(90);
	b.insert(19);
	b.insert(28);
	b.insert(32);
	b.insert(56);
	b.insert(34);
	b.insert(21);
	b.insert(33);

	b.erase(5);



	b.inorder();


}

//void test()
//{
//	BTree<int> b;
//
//	b.insert(15);
//	b.insert(6);
//	b.insert(18);
//	b.insert(3);
//	b.insert(7);
//	b.insert(17);
//	b.insert(20);
//	b.insert(2);
//	b.insert(9);
//	b.insert(4);
//	b.insert(13);
//
//	BTree<int> a(b);
//
//	b.inorder();
//	cout << endl;
//
//
//}

int main()
{
	test();
	return 0;
}