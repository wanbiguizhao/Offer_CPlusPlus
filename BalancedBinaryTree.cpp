#include <iostream>
#include <string>
#include "BalancedBinaryTree.h"
//左子树，左子树，右旋
void AVLTree::R_Rotate(BSTree &pRoot)
{
	BSTree lc=pRoot->pLChild;
	pRoot->pLChild=lc->pRChild;
	lc->pRChild=pRoot;
	pRoot=lc;
}
void AVLTree::L_Rotate(BSTree &pRoot)
{
	BSTree rc=pRoot->pRChild;
	pRoot->pRChild=rc->pLChild;
	rc->pLChild=pRoot;
	pRoot=rc;
}
int AVLTree::InsertAVL(BSTree &pRoot,int key,bool &taller)
{
	if(!pRoot)
	{
		pRoot=new BSTNode();
		pRoot->mData=key;
		std::cout<<"key="<<key<<endl;
		pRoot->bf=EH;
		pRoot->pLChild=pRoot->pRChild=NULL;
		taller=true;
		return 1;
	}
	else
	{
		if(pRoot->mData==key)
		{
			taller=false;return 0;
		}
		if(pRoot->mData>key)
		{
			if(InsertAVL(pRoot->pLChild,key,taller)==0) return 0;
			if(taller)
			{
				switch(pRoot->bf)
				{
					case LH: LeftBalance(pRoot);taller=false; break;
					case EH: pRoot->bf=LH; taller=true; break;
					case RH: pRoot->bf=EH; taller=false ;break;
				}
			}
		}
		else
		{
			if(InsertAVL(pRoot->pRChild,key,taller)==0) return 0;
			if(taller)
			{
				switch(pRoot->bf)
				{
					case LH: pRoot->bf=EH;taller=false; break;
					case EH: pRoot->bf=RH;taller=true;break;
					case RH: RightBalance(pRoot);taller=false;break;
				}
			}
		}
		return 1;
	}
}
void AVLTree::LeftBalance(BSTree &pRoot)
{
	BSTree lc=pRoot->pLChild;
	switch(lc->bf)
	{
		case LH:
		pRoot->bf=lc->bf=EH;
		R_Rotate(pRoot);
		break;
		case RH:
		BSTree rd=lc->pRChild;
		switch(rd->bf)
		{
			case LH:pRoot->bf=RH;lc->bf=EH;break; 
			case EH:pRoot->bf=EH;lc->bf=EH;break;
			case RH:pRoot->bf=EH;lc->bf=LH;break;
		}
		rd->bf=EH;
		L_Rotate(pRoot->pLChild);
		R_Rotate(pRoot);
		break;
	}
}
void AVLTree::RightBalance(BSTree &pRoot)
{
	BSTree rd=pRoot->pRChild;
	switch(rd->bf)
	{
		case RH:
		pRoot->bf=EH;rd->bf=EH;		
		L_Rotate(pRoot);
		break;
		case LH:
		BSTree lc=rd->pLChild;
		switch(lc->bf)
		{
			case LH:
				pRoot->bf=EH;rd->bf=RH;break;
			case EH:
				pRoot->bf=EH;rd->bf=EH;break;
			case RH:
				pRoot->bf=LH;rd->bf=EH;break;
		}
		lc->bf=EH;
		R_Rotate(pRoot->pRChild);
		L_Rotate(pRoot);
	}
}