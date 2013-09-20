#include <iostream>
#include <string>
#include "Search.h"

void test_fibSearch();
void test_BSTSearch();
//构造一组平衡二叉树的数据
void FillData(int data[],int &i,int low,int high);
void test()
{
	bool exit_flag=false;
	while(!exit_flag)
	{
		int who;
		std::cout<<"1-----test_fibSearch"<<std::endl;
		std::cout<<"2-----test_BSTSearch"<<std::endl;
		std::cout<<"input number:";
		std::cin>>who;
		switch(who)
		{
			case 1:test_fibSearch();
				break;
			case 2:test_BSTSearch();
				break;
			default:
				exit_flag=true;
				break;
		}

	}
}
// 1 测试
void test_fibSearch()
{
	int data[10000];
	for(int i=0;i<10000;i++)
		data[i]=i;
	int key=8999;
	Search sch;
	int index=sch.search_fib(data,key,10000);
	std::cout<<index<<std::endl;
	while(key!=-1)
	{
		std::cout<<"input -1 break program"<<std::endl;
		std::cout<<"input test number:";
		std::cin>>key;
		std::cout<<"test result is:";
		std::cout<<sch.search_fib(data,key,10000)<<std::endl;
	}
	bool test_pass=true;
	for(int i=0;i<10000;i++)
		if(i!=sch.search_fib(data,i,10000))
		{
			test_pass=false;
			break;
		}
	if(test_pass)
		std::cout<<"0-9999 test pass "<<std::endl;
	else
		std::cout<<"ERROR 　Test 0-9999 not pass"<<std::endl;
	int test_data[]={-5,-4,10200};
	for(int i=0;i<3;i++)
		if(-1!=sch.search_fib(data,test_data[i],10000))
		{
			test_pass=false;
			break;
		}
	if(test_pass)
		std::cout<<" -5,-4,10200 test pass "<<std::endl;
	else
		std::cout<<"ERROR 　Test -5,-4,10200 not pass"<<std::endl;
}
void test_BSTSearch()
{
	int test_data[1000];
	int i=0;
	FillData(test_data,i,0,999);
	std::cout<<"i="<<i<<std::endl;
	/*for(i=0;i<1000;i++)
		std::cout<<test_data[i]<<"\t"<<std::endl;*/
	Search sch;
	bool flag=false;
	BTN *pRoot=new BTN();
	pRoot->mData=test_data[0];
	pRoot->pLChild=pRoot->pRChild=NULL;
	//构造树
	for(i=1;i<1000;i++)
	{
		if(sch.search_BST(pRoot,test_data[i]))
		{
			std::cout<<"ERROR!!!"<<std::endl;
		}
	}
	std::cout<<pRoot->mData<<std::endl;
	for(i=0;i<1000;i++)
	{
		bool find_flag=sch.search_BST(pRoot,i);
		if(!find_flag)
		{	
			std::cout<<"ERROR!!! number:"<<i<<"should be find!!!"<<std::endl;
			break;
		}

	}
}
//算法的思想是low-high 的中间值mid作为树根，low-mid-1作为左子树区间，递归构造左子树，同理右子树
void FillData(int data[],int &i,int low ,int high)
{
	if(low>high)
		return;
	int mid=(low+high)/2;
	data[i]=mid;
	i++;
	FillData(data,i,low,mid-1);
	FillData(data,i,mid+1,high);
}

int main()
{
	test();
}