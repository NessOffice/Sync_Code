#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
int main(){
	const char *name[]={"Ǯ����","�����","���","���۷�","Ҧ����","��־Զ"};
	srand((unsigned)time(NULL));
	printf("%s",name[rand()%6]);
	return 0;
} 
