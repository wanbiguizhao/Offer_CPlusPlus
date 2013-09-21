
typedef struct BinTreeNode
{
	int mData;
	BinTreeNode *pLChild;
	BinTreeNode *pRChild;
}BTN,* BiTree;
typedef struct BSTNode
{
	int mData;
	int bf;
	struct BSTNode *pLChild,*pRChild;
}BSTNode,*BSTree;