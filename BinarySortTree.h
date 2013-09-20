#include "MyDataStruct.h"

class BinarySortTree
{
public:
	bool SearchBST(BiTree &pRoot,int key);
	bool SearchBST(BiTree pRoot,int key,BiTree f,BiTree &p); 
	bool InsertBST(BiTree &pRoot,int key);
	bool DeleteBST(BiTree &pRoot,int key);
private:
	void Delete(BiTree &pRoot);
};
void test_BST();
void fillData(int data[],int &i,int low,int high);