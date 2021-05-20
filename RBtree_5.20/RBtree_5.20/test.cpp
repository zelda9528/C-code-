#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

enum Color{
	BLACK,
	RED
};

template<class V>
struct RBTreeNode {
	RBTreeNode<V>* _left;
	RBTreeNode<V>* _right;
	RBTreeNode<V>* _parent;
	V _val;
	Color _color;

	RBTreeNode(const V&val = V())
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_val(val)
		,_color(RED)
	{}
};

//KeyOfVal:通过V获取其对应的K值
template<class K, class V, class KeyOfVal>
class RBTree {
public:
	typedef RBTreeNode<V> Node;

	RBTree() :_header(new Node)
	{
		_header->_left = _header->_right = _header;
	}

	bool insert(const V&val)
	{
	//二叉搜索树的插入

		if (_header->_parent == nullptr)
		{
			//创建根结点
			Node* root = new Node(val);

			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;
			
			//根结点是黑色
			root->_color = BLACK;
			return true;
		}

		//从根节点开始搜索
		Node* cur = _header->_parent;
		Node* parent = nullptr;

		KeyOfVal kov;
		while (cur)
		{
			parent = cur;
			if (kov(cur->_val)==kov(val))
			{
				//key值不允许重复
				return false;
			}
			else if (kov(cur->_val) > kov(val))
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}

		//创建待插入的结点
		cur = new Node(val);
		if (kov(parent->_left) == kov(cur->_val))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

	//修改颜色或调整结构

		//判断是否有红色连续的结点
		while (cur != _header->_parent&&cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;
			
			//插入发生在祖父结点的左边时
			if (gfather->_left == parent)
			{

				Node* uncle = gfather->_right;

				//1.uncle存在并且是红色
				if (uncle&&uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;

					//继续向上更新
					if (gfather != _header->parent)
						cur = gfather;
				}
				else
				{
					//判断是否为双旋
					if (cur == parent->_right)
					{
						//左旋
						RotateL(parent);
						//交换cur和parent
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}	
			}

			//插入发生在祖父结点的右边时
			else
			{

			}

		}
		_header->_parent->_color = BLACK;
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur&&cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}

	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		_inorder(root->_left);
		cout << root->_val<<" ";
		_inorder(root->_right);
	}

	//左旋
	void RotateL(Node* cur)
	{
		Node* curR = cur->_right;
		Node* curRL = curR->_left;

		curR->_left = cur;
		cur->_right = curRL;

		if (curRL)
		{
			curRL->_parent = cur;
		}
		if (cur == _header->parent)
		{
			_header->parent = curR;
			curR->_parent = _header;
		}
		else
		{
			Node* pparent = cur->_parent;
			if (pparent->_left == cur)
				pparent->_left = curR;
			else
				pparent->_right = curR;
			curR->_parent = pparent;
		}
		cur->_parent = curR;
	}


	//右旋
	void RotateR(Node* cur)
	{
		Node* curL = cur->_left;
		Node* curLR = curL->_right;

		curL->_right = cur;
		cur->_left = curLR;
		if (curLR)
		{
			curLR->_parent = cur;
		}
		if (cur == _header->parent)
		{
			_header->parent = curL;
			curL->_parent = _header;
		}
		else
		{
			Node* pparent = cur->_parent;
			if (pparent->_left == cur)
				pparent->_left = curL;
			else
				pparent->_right = curL;
			curL->_parent = pparent;
		}
		cur->_parent = curL;
	}
	
	

private:
	Node* _header = nullptr;
};

void test()
{

}

int main()
{
	return 0;
}