#include "BalanceBinaryTree.h"
class AVLTree{
private:
	const int LH=1;
	const int EH=0;
	const int RH=-1;
void LeftBalance(BSTree &pRoot);
void RightBalance(BSTree &pRoot);
public:
	void R_Rotate(BSTree &pRoot);
	void L_Rotate(BSTree &pRoot);
	int InsertAVL(BSTree &pRoot,int key,bool &taller);
	//void L_RRotate(BSTree &pRoot);
	//void R_LRotate(BSTree &pRoot);
}; 
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
}
int InsertAVL(BSTree &pRoot,int key,bool &taller)
{
	if(!pRoot)
	{
		pRoot=new BSTNode();
		pRoot->mData=key;
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
					case LF: LeftBalance(pRoot);taller=false; break;
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
					case LF: pRoot->bf=EH;taller=false; break;
					case EH: pRoot->bf=RH;taller=true;break;
					case RF: 
				}
			}
		}
		return 1;
	}
}