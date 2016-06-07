#include"SearchBinaryTree.h"


void Test()
{
	//5,3,4,1,7,8,2,6,0,9
	BinarySearchTree<int,int> t;
	t.Insert_NonR(5, 1);
	t.Insert_NonR(3, 1);
	t.Insert_NonR(4, 1);
	t.Insert_NonR(1, 1);
	t.Insert_NonR(7, 1);
	t.Insert_NonR(8, 1);
	t.Insert_NonR(2, 1);
	t.Insert_NonR(6, 1);
	t.Insert_NonR(0, 1);
	t.Insert_NonR(9, 1);
	t.InOrder();
	
	t.Remove_NonR(8);
	t.Remove_NonR(4);
	t.Remove_NonR(2);
	t.Remove_NonR(1);
	t.Remove_NonR(9);

	t.Remove_NonR(7);
	t.Remove_NonR(3);
	t.Remove_NonR(6);
	t.Remove_NonR(0);
	t.Remove_NonR(5);

	t.InOrder();
}
void Test2()
{
	BinarySearchTree<int, int> t;
	t.Insert_R(5, 1);
	t.Insert_R(2, 1);
	t.Insert_R(4, 1);
	t.Insert_R(3, 1);
	t.Insert_R(9, 1);
	t.Insert_R(0, 1);
	t.Insert_R(6, 1);
	t.Insert_R(8, 1);
	t.Insert_R(7, 1);
	t.Insert_R(1, 1);
	t.InOrder();

	t.Remove_R(5);
	t.Remove_R(2);
	t.Remove_R(7);
	t.Remove_R(0);
	t.Remove_R(9);
	t.Remove_R(4);

	t.Remove_R(3);
	t.Remove_R(1);
	t.Remove_R(8);
	t.Remove_R(6);
	t.InOrder();
}
int main()
{
	//Test();
	Test2();
	return 0;
}