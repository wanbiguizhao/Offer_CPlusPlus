#include <string>
#include <iostream>
using namespace std;

void ReverseString(char * begin,char *end)
{
	if(begin!='\0'&&end!='\0')
	{
		while(begin<end)
		{
			char temp=*begin;
			*begin=*end;
			*end=temp;
			begin++;
			end--;
		}
	}
}
char *LeftRotateString(char *pStr,unsigned int n)
{
	if(pStr!=NULL)
	{
		int nLength=static_cast<int>(strlen(pStr));
		if(nLength>0&&n!=0&&n<nLength)
		{
			char *pFirstStart=pStr;
			char *pFirstEnd=pStr+n-1;
			char *pSecondStart=pStr+n;
			char *pSecondEnd=pStr+nLength-1;
			ReverseString(pFirstEnd,pFirstEnd);
			ReverseString(pSecondStart,pSecondEnd);;
			ReverseString(pFirstStart,pSecondEnd);
		}
	}
	return pStr;
}
int main()
{
	char a[100]="hello july";
	char *ps=a;
	LeftRotateString(ps,6);
	int length=strlen(ps);
	int i=0;
	while(i<length)
	{
		cout<<*(ps+i);
		i++;
	}
	cout<<endl;
	ps=NULL;
	return 0;
}