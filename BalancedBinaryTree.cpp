#include "BalanceBinaryTree.h"
class AVLTree{
private:
	const int LH=1;
	const int EH=0;
	const int RH=-1;
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