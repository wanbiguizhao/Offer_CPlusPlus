//数组中，两个元素之差的最小值
int main()
{
	int *maxArray;
	int *minArray;
	int *data;
	int count;
	cin>>count;
	data=new int[count];
	int i=0;
	for(;i<count;i++)
	{
		cin>>data[i];
	}
	int min=max=data[0];
	for(i=1;i<count;i++)
	{
		if(min>data[i])
			min=data[i];
		if(max<data[i])
			max=data[i];
	}
	int ans=0;
	int step=(max-min)/count;
	
	if(step==0)
	{
		ans=0;
		return;
	}
	else
	{
		for(i=0;i<count;i++)
		{
			int j=(data[i]-min)/step;

		}
	}


} 