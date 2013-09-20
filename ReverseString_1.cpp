#include <iostream>
#include <string>
using namespace std;
void rotate(string &str,int m)
{
	if(str.length()==0||m<=0)
		return;
	int n=str.length();
	if(m%n<=0)
		return;
	int p1=0,p2=m;
	int k=(n-m)-n%m;
	while(k--)
	{
		
	}
}