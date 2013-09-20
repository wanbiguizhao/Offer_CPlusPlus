#include <string>
#include <iostream>
class BitMap
{
	static const int BYTESIZE=8;
public:
	static void SetBit(char *p,int posi);
	void BitMapSortDemo();
};
void BitMap::SetBit()
{
	for(int i=0;i<(posi/BYTESIZE);i++)
		p++;
	*p=*p|(0x01<<(posi%BYTESIZE));;
}
