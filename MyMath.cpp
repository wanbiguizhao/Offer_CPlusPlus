#include "MyMath.h"
int MathHelper::GCD(int m,int n)
{	
	int t=0;
	while(n!=0)
	{
		BigExchange(&m,&n);
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}
void MathHelper::BigExchange(int *a,int *b)
{
	if(*a>*b)
		return;
	int c=*a;
	*a=*b;
	*b=c;
}