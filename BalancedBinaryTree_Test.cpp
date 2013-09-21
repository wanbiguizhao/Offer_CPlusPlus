#include "BalancedBinaryTree.h"
#include <iostream>
#include <string>

void testAVLTree();
int main()
{
	testAVLTree(); 
	char c;
	std::cin>>c;
}
void testAVLTree()
{
	BSTree pRoot=NULL;
	AVLTree test_avl;
	int i=0;
	bool taller=false;
	std::cout<<"test Init Data"<<std::endl;
	for(;i<6;i++)
	{
		test_avl.InsertAVL(pRoot,i,taller);
		std::cout<<"{"<<pRoot->mData<<","<<pRoot->bf<<"}"<<endl;
	}
	std::cout<<"Init Data end"<<std::endl;
	std::cout<<"test AVL:"<<std::endl;
	for(i=0;i<1024;i++)
	{
		std::cout<<i<<endl;
		if(0!=test_avl.InsertAVL(pRoot,i,taller))
		{
			std::cout<<"Test AVL ERROR"<<endl;
			break;
		}
	}
	std::cout<<"test AVL end"<<std::endl;
}