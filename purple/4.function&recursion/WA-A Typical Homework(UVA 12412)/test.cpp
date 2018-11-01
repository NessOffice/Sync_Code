#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10000
#define SIDLEN 10
#define EPS 1e-6//帮助除以0的浮点数误差！ 
using namespace std;
int num=0,invalid=0;
struct info{
	char SID[12];
	int CID;
	char name[12];
	int score[5];
	int total;
	int valid;
	double average;
}STU[MAXN];
int Rank(int total)
{
	int rank=1;
	for(int i=0;i<num;i++)
		if(STU[i].valid && STU[i].total>total)
			rank++;
	return rank;
}
void Add()
{
	char SID[12];
	int CID;
	char name[12];
	int score[5];
	int flag;
	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
	while(cin>>SID && strlen(SID)==SIDLEN)
	{
		cin>>CID>>name>>score[0]>>score[1]>>score[2]>>score[3];
		flag=1;
		for(int i=0;i<num;i++)
		{
			if(STU[i].valid && memcmp(STU[i].SID,SID,sizeof(char)*SIDLEN)==0)
			{
				printf("Duplicated SID.\n");
				flag=0;
			}
		}
		if(flag)
		{
			STU[num].CID=CID;
			STU[num].total=0;
			STU[num].valid=1;
			for(int i=0;i<4;i++)
			{
				STU[num].score[i]=score[i];
				STU[num].total+=score[i];
			}
			STU[num].average=STU[num].total/4.0;
			memcpy(STU[num].name,name,sizeof(char)*strlen(name));
			memcpy(STU[num].SID,SID,sizeof(char)*SIDLEN);
			num++;
		}
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
	}
}
void Remove()
{
	printf("Please enter SID or name. Enter 0 to finish.\n");
	int removal;
	char temp[12];
	while(cin>>temp)
	{
		removal=0;
		if(strlen(temp)==1 && temp[0]=='0') break;
		for(int i=0;i<num;i++)
		{
			if(STU[i].valid)
			if((temp[0]<='9' && memcmp(STU[i].SID,temp,sizeof(char)*SIDLEN)==0)
			|| (temp[0]>'9' && strlen(temp)==strlen(STU[i].name) 
				&& memcmp(STU[i].name,temp,sizeof(char)*strlen(temp))==0))
			{
				STU[i].valid=0;
				invalid++;
				removal++;
			}
		}
		printf("%d student(s) removed.\n",removal);
		printf("Please enter SID or name. Enter 0 to finish.\n");
	}
}
void Query()
{
	printf("Please enter SID or name. Enter 0 to finish.\n");
	char temp[12];
	while(cin>>temp)
	{
		if(strlen(temp)==1 && temp[0]=='0') break;
		for(int i=0;i<num;i++)
		{
			if(STU[i].valid)
			if((temp[0]<='9' && memcmp(STU[i].SID,temp,sizeof(char)*SIDLEN)==0)
			|| (temp[0]>'9' && strlen(temp)==strlen(STU[i].name) 
				&& memcmp(STU[i].name,temp,sizeof(char)*strlen(temp))==0))
			{
				printf("%d % s %d %s %d %d %d %d %d %.2lf\n",
						Rank(STU[i].total),STU[i].SID,STU[i].CID,STU[i].name,
						STU[i].score[0],STU[i].score[1],STU[i].score[2],STU[i].score[3],
						STU[i].total,STU[i].average);
			}
		}
		printf("Please enter SID or name. Enter 0 to finish.\n");
	}
}
void Statistics()
{
	printf("Please enter class ID, 0 for the whole statistics.\n");
	int cid,total[5],passed[5],failed[5],passer[5];
	double average[5];
	cin>>cid;
	for(int j=0;j<=4;j++) passed[j]=failed[j]=total[j]=passer[j]=0;
	for(int i=0;i<num;i++)
	{
		if(STU[i].valid)
		if(!cid || STU[i].CID==cid)
		{
			int pass=0;
			for(int j=0;j<4;j++)
			{
				if(STU[i].score[j]>=60) 
				{
					passed[j]++;
					pass++;
					passer[pass]++;
				}
				else failed[j]++;
				total[j]+=STU[i].score[j];
			}
			if(pass==0) passer[pass]++;
		}
	}
	for(int j=0;j<4;j++) average[j]=total[j]*1.0/(passed[j]+failed[j]+EPS);
	printf("Chinese\nAverage Score: %.2lf\
\nNumber of passed students: %d\
\nNumber of failed students: %d\n\n",
				   average[0]+EPS,passed[0],failed[0]);
	printf("Mathematics\nAverage Score: %.2lf\
\nNumber of passed students: %d\
\nNumber of failed students: %d\n\n",
					   average[1]+EPS,passed[1],failed[1]);
	printf("English\nAverage Score: %.2lf\
\nNumber of passed students: %d\
\nNumber of failed students: %d\n\n",
				   average[2]+EPS,passed[2],failed[2]);
	printf("Programming\nAverage Score: %.2lf\
\nNumber of passed students: %d\
\nNumber of failed students: %d\n\n",
					   average[3]+EPS,passed[3],failed[3]);
	printf("Overall:\nNumber of students who passed all subjects: %d\
\nNumber of students who passed 3 or more subjects: %d\
\nNumber of students who passed 2 or more subjects: %d\
\nNumber of students who passed 1 or more subjects: %d\
\nNumber of students who failed all subjects: %d\n\n",
				   passer[4],passer[3],passer[2],passer[1],passer[0]);
}
void PrintMenu()
{
	printf("Welcome to Student Performance Management System (SPMS).\n\
\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\
\n5 - Show Statistics\n0 - Exit\n\n");
	int cmd;
	while(cin>>cmd && cmd)
	{
		switch(cmd)
		{
		case 1:Add();break;
		case 2:Remove();break;
		case 3:Query();break;
		case 4:printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");break;
		case 5:Statistics();break;
		}
		printf("Welcome to Student Performance Management System (SPMS).\n\
\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\
\n5 - Show Statistics\n0 - Exit\n\n");
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	PrintMenu();
	return 0;
}
