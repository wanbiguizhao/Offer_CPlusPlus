#include <iostream>
#include <string>
#include "StringHelper.h"

//length   length+1
void GetNext(char *s,int *next,int length)
{
	//s[0,k-1]=s[j-k,j-1];
	next[0]=-1;
	int j=0;
	int k=-1;
	while(j<length-1)
	{
		if(k==-1)
		{
			k++;
			j++;
			next[j]=0;
		}
		if(s[j]==s[k])
		{
			j++;
			k++;
			next[j]=k;
		}		
		else
		{
			k=next[k];	
		}
	}
	std::cout<<" ";	
	for(j=0;j<length;j++)
	{
		std::cout<<" "<<s[j];
	}
	std::cout<<std::endl;
	for(j=0;j<length;j++)
	{
		std::cout<<" "<<next[j];
	}
}
int KMPMatch(char *p,char *s)
{
	if(!p||!s)
		return -1;
	int len_s=strlen(s);
	int len_p=strlen(p);
	if(len_s>len_p)
		return -1;
	int *next=new int[len_s];
	GetNext(s,next,len_s);
	int j=0;int i=0;
	while(j<len_p-len_s+1)
	{	
		if(i==-1||s[i]==p[j])
		{
 			j++;
 			i++;
 			if(i==len_s)
 				return (j-len_s);
		}
		else
		{
			i=next[i];
		}
	}
}
int main()
{
	char p[]="cu d cxcu d cuaaa ble class struct";
	char s[]="cu d cuaaa"; 
	int loc=KMPMatch(p,s);
	std::cout<<"loc:"<<loc<<std::endl;
	char a;
	std::cin>>a;
}

