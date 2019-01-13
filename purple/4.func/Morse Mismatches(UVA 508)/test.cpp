#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 
const int INF=1000;
char table[128][30],contextMorse[150][100],morse[300],contextWord[150][30];
struct match{
	int key;
	int deviation;
}contextMatch[150];
bool StringCmp(char A[], char B[])
{
	int len=strlen(A);
	for(int i=0;i<len;i++)
	{
		if(i>=strlen(B))
		{
			return false;
		}
		if(A[i]<B[i])
		{
			return true;
		}
		else if(A[i]>B[i]){
			return false;
		}
	}
	return true;
}
bool MorseCmp(struct match A, struct match B)
{
	return A.deviation==B.deviation?
		   StringCmp(contextWord[A.key],contextWord[B.key])
		   :A.deviation<B.deviation;
}
int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}
void Mismatch(int contextNum){
	int longLen,shortLen;
	for(int i=0;i<contextNum;i++)
	{
		longLen=max(strlen(morse),
					strlen(contextMorse[i]));
		shortLen=min(strlen(morse),
					 strlen(contextMorse[i]));
		contextMatch[i].deviation=memcmp(morse,
		                				 contextMorse[i],
										 sizeof(char)*shortLen);
		contextMatch[i].key=i;
		if(contextMatch[i].deviation)
		{
			contextMatch[i].deviation=INF;
		}
		else
		{
			contextMatch[i].deviation+=(longLen-shortLen);
		}
	}
	sort(contextMatch,contextMatch+contextNum,MorseCmp);
	cout<<contextWord[contextMatch[0].key];
	if(contextNum>1 && contextMatch[1].deviation==0)
	{
		cout<<'!';
	}
	if(contextMatch[0].deviation!=0)
	{
		cout<<'?';
	}
	cout<<endl;
} 
void ReadMorse()
{
	char khar;
	int contextNum=0;
	while(1)
	{
		cin>>khar;
		if(khar=='*') break;
		cin>>table[khar];
	}
	while(1)
	{
		cin>>contextWord[contextNum];
		if(contextWord[contextNum][0]=='*') break;
		int tempLen=strlen(contextWord[contextNum]),contextLen=0,tableLen;
		for(int i=0;i<tempLen;i++)
		{
			tableLen=strlen(table[contextWord[contextNum][i]]);
			memcpy(contextMorse[contextNum]+contextLen,
				   table[contextWord[contextNum][i]],
				   sizeof(char)*tableLen);
			contextLen+=tableLen;
		}
		contextNum++;
	}
	while(1)
	{
		cin>>morse;
		if(morse[0]=='*') break;
		Mismatch(contextNum);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ReadMorse();
	return 0;
}
