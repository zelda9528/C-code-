#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>
using namespace std;

template <class T>
struct AVLNode {
	AVLNode<T>* parent_;
	AVLNode<T>* left_;
	AVLNode<T>* right_;	

	T val_;              

	int bf_;			 //平衡因子

	AVLNode(const T&val=T())
		:parent_(nullptr)
		,left_(nullptr)
		,right_(nullptr)
		,val_(val)
		,bf_(0)
	{}

private:
	AVLNode* root_ = nullptr;
};


template <class T>
struct AVLtree
{
public:
	typedef AVLNode<T> Node;

	bool insert(const T&val)
	{
		//二叉搜索树的插入
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return true;
		}
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->val_ == val)
				return false;
			else if (cur->val_ > val)
				cur = cur->left_;
			else
				cur = cur->right_;
		}
		cur = new Node(val);
		if (parent->val_ > val)
			parent->left_ = cur;
		else
			parent->right_ = cur;

		cur->parent_ = parent;

		//调整
		while (parent)
		{
			//更新父节点的平衡因子
			if (parent->left_ == cur)
				--parent->bf_;
			else
				++parent->bf_;

			if (parent->bf_ == 0)	//子树高度被补齐
				//结束更新
				break;
			else if (parent->bf_ == 1 || parent->bf_ == -1)
				//继续向上更新
			{
				cur = parent;
				parent = parent->parent_;
			}
			else if (abs(parent->bf_) == 2)
			{
				if (parent->bf_ == -2 && cur->bf_ == -1)
				{
					//左子树的左边高：右旋
					RotateR(parent);
				}
				else if (parent->bf_ == 2 && cur->bf_ == 1)
				{
					//右子树的右边高：左旋
					RotateL(parent);
				}

				else if (parent->bf_ == -2 && cur->bf_ == 1)
				{
					//保存subRL的平衡因子
					Node* subLR = cur->right_;
					int bf = subLR->bf_;
					//左-右双旋
					RotateL(cur);
					RotateR(parent);

					//调整平衡因子
					if (1 == bf)
					{
						cur->bf_ = -1;
						parent->bf_ = 0;
					}
					else if (-1 == bf)
					{
						cur->bf_ = 0;
						parent->bf_ = 1;
					}
				}
				else if (parent->bf_ == 2 && cur->bf_ == -1)
				{
					//保存subRL的平衡因子
					Node* subRL = cur->left_;
					int bf = subRL->bf_;

					//右-左双旋
					RotateR(cur);
					RotateL(parent);

					//调整平衡因子
					if (1 == bf)
					{
						cur->bf_ = 0;
						parent->bf_ = -1;
					}
					else if (-1 == bf)
					{
						cur->bf_ = 1;
						parent->bf_ = 0;
					}
				}
				break;
			}	
		}
		return true;
	}


	//右旋
	void RotateR(Node* cur)
	{
		Node* curL = cur->left_;
		Node* curLR = curL->right_;

		curL->right_ = cur;
		cur->left_ = curLR;
		if (curLR)
		{
			curLR->parent_ = cur;
		}
		if (cur == root_)
		{
			root_ = curL;
			curL->parent_ = nullptr;		
		}
		else
		{
			Node* pparent = cur->parent_;
			if (pparent->left_ == cur)
				pparent->left_ = curL;
			else
				pparent->right_ = curL;
			curL->parent_ = pparent;
		}
		cur->parent_ = curL;
		curL->bf_ = cur->bf_ = 0;
	}


	//左旋
	void RotateL(Node* cur)
	{
		Node* curR = cur->right_;
		Node* curRL = curR->left_;

		curR->left_ = cur;
		cur->right_ = curRL;

		if (curRL)
		{
			curRL->parent_ = cur;
		}
		if (cur == root_)
		{
			root_ = curR;
			curR->parent_ = nullptr;
		}
		else
		{
			Node* pparent = cur->parent_;
			if (pparent->left_ == cur)
				pparent->left_ = curR;
			else
				pparent->right_ = curR;
			curR->parent_ = pparent;
		}
		cur->parent_ = curR;
		cur->bf_ = curR->bf_ = 0;
	}

	void inorder()
	{
		_inorder(root_);
		cout << endl;

	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->left_);
			cout << root->val_ << " ";
			_inorder(root->right_);
		}
	}

	int getHight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHight(root->left_);
		int right = getHight(root->right_);
		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		
		//查看平衡因子是否和左右子树的高度差一致
		int left = getHight(root->left_);
		int right = getHight(root->right_);
		if (right - left != root->bf_)
		{
			cout << "Node: " << root->val_ << "  bf_: "
				<< root->bf_ << "  hight gap: " << right - left << endl;
			return false;
		}

		return abs(root->bf_) < 2
			&& _isBalance(root->left_)
			&& _isBalance(root->right_);
	}
	void isBalance()
	{
		_isBalance(root_);
	}

private:
	Node* root_=nullptr;
};


void test()
{
	srand(time(nullptr));
	cout << "num: " << endl;
	AVLtree<int> avl;
	
	int num ;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		avl.insert(rand());
	}

	avl.inorder();

	avl.isBalance();

}

int main()
{
	test();
	return 0;
}