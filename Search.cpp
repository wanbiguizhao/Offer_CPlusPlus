#include <iostream>
#include <string>
#include "Search.h"

int Search::search_bin(int data[],int key,int length)
{
	int low,high,mid;
	low=0;
	high=length-1;
	int index=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(data[mid]==key)
		{	
			index=mid;
			break;
		}
		else if(data[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return index;
}
int Search::search_bin(int data[],int key,int begin,int end)
{
	int low=begin;
	int high=end;
	int index=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(data[mid]==key)
		{	
			index=mid;
			break;
		}
		else if(data[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return index;
}
int Search::search_fib(int data[],int key,int length)
{	
	int f0=0,f1=1,fn=f0+f1;
	int index=-1;
	if(key<data[0]||key>data[length-1])
		return -1;

	bool break_Flag=false;
	if(data[f0]==key)
		return 0;
	while(f1<length)
	{
		//f0 已经检查过了
		if(key==data[f1])
		{
			index=f1;
			break_Flag=true;
			break;
		}
		else if(key<data[f1])
		{//发现区间
			index=search_bin(data,key,f0+1,f1-1);
			break_Flag=true;
			break;
		}
		else
		{

			fn=f0+f1;
			f0=f1;
			f1=fn;
		}
	}
	//(f0,f1],while（）循环中fib都是前开后闭区间，f0已经进行过检查,f1>=length,检查[f0+1,length-1]部分
	if(!break_Flag&&f0+1<length)
		index=search_bin(data,key,f0+1,length-1);
	return index;
}
int Search::Fibonacci(int &f0,int &f1)
{
	int fn=f0+f1;
	f0=f1;
	f1=fn;
	return 0;
}
bool Search::search_BST(BTN *&root,int key)
{
	if(!root)
	{
		root=new BTN();
		root->pLChild=NULL;
		root->pRChild=NULL;
		root->mData=key;
		return false;
	}
	else if(root->mData==key)
	{
		return true;
	}
	else if(root->mData>key)
	{
		return search_BST(root->pLChild,key);
	}
	else
	{
		return search_BST(root->pRChild,key);
	}
}
/*
bool Search::deleteBSTN(BiTree &pRoot,BiTree pDelNode)
{
	if(!pRoot||!pDelNode)
		return false;
	BiTree p=pRoot;	
	while(!p&&p->mData!=pDelNode->mData)
	{
		if(p->mData>pDelNode->mData)
			p=p->pLChild;
		else
			p=p->pRChild;
	}
	if(!p)
		return false;
	//首先检查删除的是否是根节点	
	BiTree q=p;
	BiTree s=p;
	s=s->pLChild;
	while(!s->pRChild)
		{q=s;s=s->pRChild;}
	p->mData=s->mData;
	if(q!=p)
		q->pRChild=s->pLChild;
	else
		q->pLChild=s->pLChild;
	delete p;
	return true;
}*/
