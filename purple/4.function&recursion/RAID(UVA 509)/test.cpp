#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std; 
int sizeofBlock,numofBlock,numofDisk;
char diskData[10][10000],parityType,tempData[10000];
void BinaryToHex(char link[])
{
	int len=strlen(link),i=0,num;
	for(int j=0;j<len;j++) link[j]-='0';
	for(;i<len-4;i+=4)
	{
		num=link[i];
		num=num*2+link[i+1];
		num=num*2+link[i+2];
		num=num*2+link[i+3];
		printf("%X",num);
	}
	num=link[i++];
	for(;i<len;i++)
	{
		num=num*2+link[i];
	}
	for(int j=0;j<3-(len-1)%4;j++)
	{
		num*=2;
	}
	printf("%X\n",num);
}
void LinkData(char link[])
{
	int len=0;
	for(int i=0;i<numofBlock;i++)
	{
		for(int j=0;j<numofDisk;j++)
		{
			if(i%numofDisk==j)
			{
				continue;
			}
			else
			{
				memcpy(link+len,
					   diskData[j]+i*sizeofBlock,
					   sizeof(char)*sizeofBlock);
				len+=sizeofBlock;
			}
		}
	}
}
int CheckDisk()
{
	int x,k0,parity;
	for(int i=0;i<numofBlock;i++)
	{
		for(int j=0;j<sizeofBlock;j++)
		{
			x=parity=0;
			for(int k=0;k<numofDisk;k++)
			{
				if(diskData[k][i*sizeofBlock+j]=='1')
				{
					parity++;
				}
				if(diskData[k][i*sizeofBlock+j]=='x')
				{
					x++;
					k0=k;
				}
			}
			if(x>1) return 0;
			parity%=2;
			if(parityType=='E')
			{
				if(x==1)
				{
					diskData[k0][i*sizeofBlock+j]='0'+parity;
				}
				else
				{
					if(parity==1)
					{
						return 0;
					}
				}
			}
			else
			{
				if(x==1)
				{
					diskData[k0][i*sizeofBlock+j]='0'+1-parity;
				}
				else
				{
					if(parity==0)
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}
int ReadDisk()
{
	memset(diskData,0,sizeof(diskData));
	cin>>numofDisk;
	if(numofDisk==0) return 0;
	cin>>sizeofBlock>>numofBlock;
	cin>>parityType;
	for(int i=0;i<numofDisk;i++)
	{
		cin>>tempData;
		for(int j=0;j<numofBlock;j++)
		{
			memcpy(diskData[i],tempData,
				   sizeof(char)*sizeofBlock*numofBlock);
		}
	}
	return 1;
}
int main()
{
	int kase=1;
	char link[10000];
	std::ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(ReadDisk())
	{
		if(CheckDisk()) 
		{
			memset(link,0,sizeof(link));
			LinkData(link);
			printf("Disk set %d is valid, contents are: ",kase);
			BinaryToHex(link);
		}
		else
		{
			printf("Disk set %d is invalid.\n",kase);
		}
		kase++;
	}
	return 0;
}
