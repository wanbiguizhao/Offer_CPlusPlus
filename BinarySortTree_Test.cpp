#include <iostream>
#include <string>
#include "BinarySortTree.h"

void test_BST()
{
	int test_data[1024];
	int i=0;
	std::cout<<"init data"<<std::endl;
	fillData(test_data,i,0,1023);
	std::cout<<"init data over"<<std::endl;
	BiTree pRoot=new BTN();
	pRoot->mData=test_data[0];
	pRoot->pLChild=NULL;
	pRoot->pRChild=NULL;
	BinarySortTree bst;
	std::cout<<"Construct Tree"<<std::endl;
	for(i=1;i<1024;i++)
	{
		bst.InsertBST(pRoot,test_data[i]);
	}
	std::cout<<"Construct Tree over"<<std::endl;
	std::cout<<"test search"<<std::endl;
	bool ok_flag=false;
	for(i=0;i<1024;i++)
	{
		ok_flag=bst.SearchBST(pRoot,i);
		if(!ok_flag)
		{
			std::cout<<"Search is Error!!!!!!!!!!!!!"<<std::std::endl;
			break;
		}
	}
	std::cout<<"test search Over"<<std::std::endl;
	std::cout<<"test delete"<<std::std::endl;
	for(i=0;i<1024;i++)
	{
		ok_flag=bst.DeleteBST(pRoot,i);
		if(!ok_flag)
		{
			std::cout<<"Delete is ErroR!!!!!!!"<<std::endl;
			break;
		}
		std::cout<<i<<endl;
	}
	std::cout<<"test delete is over"<<std::endl;	
}
//填充数据，由于现在的树不是平衡二叉树，填充树时应该
//应该把数据初始化成尽可能使树平衡的数据。
//算法的核心每次把数据分为两部分，[a,b]
//c=a+b/2;c是树根，[a,c-1]和[c+1,b]分别左子树和右子树
void fillData(int data[],int &i,int low,int high)
{
	if(low>high)
		return;
	int mid=(low+high)/2;
	data[i]=mid;
	i++;
	fillData(data,i,low,mid-1);
	fillData(data,i,mid+1,high);
}
int main()
{
	test_BST();
	char c;
	std::cin>>c;
}