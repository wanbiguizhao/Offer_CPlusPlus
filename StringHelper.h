#include <string>
#include <iostream>
using namespace std;
class StringHelper
{
public:
	inline void Swap(string &str,int p1,int p2)
	{
		char ch=str[p1];
		str[p1]=str[p2];
		str[p2]=ch;
	}
	void Swap(char *a,char *b);
	void LeftRotate(string &str,int m);	
	void LeftRotate(string &str,int n,int m,int head,int tail);
	void RightRotate(string &str,int n,int m,int head,int end);	
};