//data 的数据是升序
/*
* 搜索的函数，二分查找，斐波那契数列查找，二叉树查找
*/
#include "MyDataStruct.h"

class Search
{
public:
	int search_bin(int data[],int key,int length);
	//二分查找
	int search_bin(int data[],int key,int begin,int end);

	// Fibonacci 斐波那契 搜索
	int search_fib(int data[],int key,int length);
	int Fibonacci(int &f0,int &f1);
	bool search_BST(BTN *&root,int key);
	//bool deleteBSTN(BiTree &root,BiTree delNode);
};