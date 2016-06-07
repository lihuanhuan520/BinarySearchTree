#pragma once
#include<iostream>
using namespace std;
   
template <class K,class V> 
struct BinaryNode{
	struct BinaryNode<K,V>* _left;
	struct BinaryNode<K,V>* _right;
	K _key;
	V _value;

	BinaryNode(const K& key,const V& value)
		:_left(NULL)
		, _right(NULL)
		, _key(key)
		, _value(value)
	{}

};

template <class K, class V>
class BinarySearchTree
{
	typedef BinaryNode<K, V> Node;
private:
	Node  *_root;
public:
	BinarySearchTree()
		:_root(NULL)
	{}

	bool Insert_R(const K& key, const V& value) //递归插入
	{
		return _Insert_R(_root, key, value);
	}

	bool Insert_NonR(const K& key, const V& value)//非递归插入
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		else           //root不为空
		{
			Node* cur = _root;
			Node* parent = NULL;
			
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			if (key > parent->_key)
			{
				parent->_right = new Node(key, value);
				return true;
			}
			else
			{
				parent->_left = new Node(key, value);
				return true;
			}
		}
	}

	bool Remove_NonR(const K& key)//非递归删除
	{
		if (_root == NULL)//根为空
		{
			return false;
		}
		if (_root->_left == NULL && _root->_right == NULL)//只有root一个节点
		{
			delete _root;
			_root = NULL;
			return true;
		}
		Node* cur = _root;
		Node* parent = _root;
		if (_root->_left != NULL || _root->_right != NULL)    //多个节点                                         //多个节点
		{
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else							//key=cur->_key
				{
					break;
				}
			}
			if (cur != NULL)
			{
				Node* del = cur;
				//一个孩子的情况
				if (cur->_left == NULL)//只有右孩子 ，左孩子为空
				{
					if (del == _root)//删除的节点是root
					{
						_root = del->_right;
					}
					else            //删除的节点不是root
					{
						if (del == parent->_left)   //删除的节点是父亲节点的左孩子
						{
							parent->_left = del->_right;
						}
						else                       //删除的节点是父亲节点的右孩子
						{
							parent->_right = del->_right;
						}
					}
					delete del;
					cur = NULL;
					return true;
				}
				else if (del->_right == NULL)//只有左孩子，右孩子为空
				{
					if (del == _root)        //删除的节点是root
					{
						_root = del->_left;
					}
					else                    //删除的节点不是root
					{
						if (del == parent->_left)
						{
							parent->_left = del->_left;
						}
						else
						{
							parent->_right = del->_left;
						}
					}
					delete cur;
					cur = NULL;
					return true;
				}
				else						//两个孩子的情况 找到左子树的最右节点 与要删除节点交换  然后删除
				{
					if (del->_left->_right == NULL &&  del == _root)//	左子树没有右边（右子树）为空 且为root
					{
						Node* tmp = _root->_left;
						swap(_root->_key, tmp->_key);
						swap(_root->_value, tmp->_value);
						_root->_left = tmp->_left;
						delete tmp;
						tmp = NULL;
						return true;
					}
					if (del->_left->_right == NULL)  //	左子树没有右边（右子树）为空
					{
						if (parent->_left == del)//在左子树上
						{
							parent->_left = del->_left;
						}
						else					//在右子树上
						{
							parent->_right = del->_left;
							del->_left->_right = del->_right;
						}
						delete del;
						del = NULL;
						return true;
					}
					else                            //左子树有右子树
					{
						Node* tmp = del->_left;
						while (tmp->_right)
						{
							parent = tmp;
							tmp = tmp->_right;
						}

						swap(del->_key, tmp->_key);
						swap(del->_value, tmp->_value);
						parent->_right = NULL;
						delete tmp;
						tmp = NULL;
						return true;
					}
				}
				return false;
			}

		}
	}

	bool Remove_R(const K& key)//递归删除
	{
		return _Remove_R(_root, key);
	}

	bool Find_R(const K& key)		//	递归查找 查找某一节点是否存在
	{
		return _Find(_root, key);
	}
	
	void InOrder()//中序遍历
	{
		_InOrder(_root);
		cout << endl;
	}

	bool Find_NonR(const K& key)//非递归查找
	{
		if (_root == NULL)
		{
			return false;
		}
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
protected:
	void _InOrder(Node* _root)
	{
		if (_root == NULL)
		{
			return;
		}
		if (_root != NULL)
		{
			_InOrder(_root->_left);
			cout << _root->_key << " ";
			_InOrder(_root->_right);
		}
	}
	bool _Find(Node* _root, const K& key)
	{
		if (_root)
		{
			return false;
		}
		else if (key < _root->_key)
		{
			_Find(_root->_left, key);
		}
		else if (key>_root->_key)
		{
			_Find(_root->_right, key);
		}
		else
		{
			return true;
		}
	}

	bool _Insert_R(Node*& _root, const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		else
		{
			if (key < _root->_key)
			{
				return _Insert_R(_root->_left, key, value);
			}
			else if (key > _root->_key)
			{
				return _Insert_R(_root->_right, key, value);
			}
			else
			{
				return false;
			}
		}
	}

	bool _Remove_R(Node*& _root, const K& key)
	{
		if (_root == NULL)
		{
			return false;
		}
		else
		{
			if (key < _root->_key)
			{
				return _Remove_R(_root->_left, key);
			}
			else if (key> _root->_key)
			{
				return _Remove_R(_root->_right, key);
			}
			else
			{
				Node* del = _root;
				if (_root->_left == NULL)  //左为空
				{
					_root = _root->_right;
				}
				else if (_root->_right == NULL)//右为空
				{
					_root = _root->_left;
				}
				else                          //左右都不为空
				{
					Node* tmp = _root->_left;
					while (tmp->_right)
					{
						tmp = tmp->_right;
					}

					swap(del->_key, tmp->_key);
					swap(del->_value, tmp->_value);
					
					return _Remove_R(_root->_left, key);
				}
			}
		}
	}

};

