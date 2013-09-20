#include <string>
#include <iostream>
#include "MyMath.h"
using namespace std;
using namespace MathHelper;
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
	int CompareString(string LongString,string ShortString);
	void DelExcessBlank(string &str);
};
void StringHelper::DelExcessBlank(string &str)
{
	if(str.)
}
void StringHelper::Swap(char *a,char *b)
{
	char c=*a;
	*a=*b;
	*b=c;
}
void StringHelper::LeftRotate(string &str,int m)
{
	int length=str.length();
	if(length==0||m<=0||m>=length)
		return ;
	int p1=0;int p2=m;
	int k=(length-m)-length%m;//移动的距离
	while(k--)
	{
		Swap(&str[p1],&str[p2]);
		p1++;
		p2++;
	} 
	int rest=length-p2;
	while(rest--)//剩下移动的长度
	{
		int i=p2;
		while(i>p1)
		{
			Swap(&str[i],&str[i-1]);
			i--;
		}
		p2++;
		p1++;
	}
}
//str="abcde";
//head=0;
//tail=4;
//n=length;
//m=
void StringHelper::LeftRotate(string &str,int n,int m,int head,int tail)
{
	if (head==tail||m<=0)
		return;
	int p1=head;
	int p2=head+m;
	int k=n-m-n%m;
	while(k--)
	{
		Swap(&str[p1],&str[p2]);
		p1++;
		p2++;
	}
	int new_m=n%m;
	int new_n=new_m+m;
	int new_head=tail;
	int new_tail=p1;
	RightRotate( str,new_n,new_m,new_head,new_tail);
}
void StringHelper::RightRotate(string &str,int n,int m,int head,int tail)
{
	if(head==tail||m<=0)
		return;
	int p1=head;
	int p2=head-m;
	int k=n-m-n%m;
	while(k--)
	{
		Swap(&str[p1],&str[p2]);
		p1--;
		p2--;
	}
	LeftRotate(str,m+n%m,n%m,tail,p1);
}
int StringHelper::CompareString(string LongString,string ShortString)
{
	bool isFinded=false;
	int lth=LongString.length();
	int sth=ShortString.length();
	for(int i=0;i<=lth-sth;i++)
	{
		int k=i;
		for(int j=0;j<ShortString.length();j++)
		{
			if(LongString[k]==ShortString[j])
			{
				k++;j++;
			}
		}
	}
}
int main()
{
	StringHelper strhelp;
	string str="abcaab1b1b1b";
	//strhelp.Swap(&str[0],&str[5]);
	strhelp.LeftRotate(str,str.length(),3,0,str.length()-1);
	cout<<str.c_str()<<endl;

	char ch;
	cin>>ch;
}
