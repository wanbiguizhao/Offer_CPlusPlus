#include <iostream>
#include <string>
#include "BinarySortTree.h"

bool BinarySortTree::SearchBST(BiTree pRoot,int key,BiTree f,BiTree &p)
{
	if(pRoot==NULL){p=f;return false;}
	else if(pRoot->mData==key){p=pRoot;return true;}
	else if(pRoot->mData>key){return SearchBST(pRoot->pLChild,key,pRoot,p);}
	else return SearchBST(pRoot->pRChild,key,pRoot,p);
} 
bool BinarySortTree::SearchBST(BiTree &root,int key)
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
		return SearchBST(root->pLChild,key);
	}
	else
	{
		return SearchBST(root->pRChild,key);
	}
}
bool BinarySortTree::InsertBST(BiTree &pRoot,int key)
{
	BiTree p;
	bool find_flag=SearchBST(pRoot,key,NULL,p);
	if(find_flag)
		return false;
	else 
	{
		BiTree s=new BTN();
		s->pLChild=NULL;
		s->pRChild=NULL; 
		s->mData=key;
		if(!p){pRoot=s;}
		else if(p->mData>key)
			{
				//s->pLChild=p->pLChild; 好好想想为什么注释这句
				p->pLChild=s;}
		else {
			//s->pRChild=p->pRChild;好好想想为什么注释这句
			p->pRChild=s;
		}
		return true;
	}
}
bool BinarySortTree::DeleteBST(BiTree &pRoot,int key)
{
	if(!pRoot)
		return false;
	else if(pRoot->mData==key){Delete(pRoot);return true;}
	else if(pRoot->mData>key) return DeleteBST(pRoot->pLChild,key);
	else DeleteBST(pRoot->pRChild,key);

}
void BinarySortTree::Delete(BiTree &pRoot)
{
	if(!pRoot->pRChild)
	{
		BiTree q=pRoot;
		pRoot=pRoot->pLChild;
		delete q;
	}
	else if(!pRoot->pLChild)
	{
		BiTree q=pRoot;
		pRoot=pRoot->pRChild;
		delete q;
	}
	else
	{
		BiTree q,s;
		q=pRoot;
		s=pRoot->pLChild;
		while(!s){q=s;s=s->pRChild;}
		pRoot->mData=s->mData;
		if(pRoot!=q)
			q->pRChild=s->pLChild;
		else
			q->pLChild=s->pLChild;
		delete s;
	}
}