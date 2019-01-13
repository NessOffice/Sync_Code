#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int fre1[26],fre2[26];
	char s1[102],s2[102];
	while(cin>>s1>>s2){
		memset(fre1,0,sizeof(fre1));
		memset(fre2,0,sizeof(fre2));
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=0;i<len1;i++) fre1[s1[i]-'A']++; 
		for(int i=0;i<len2;i++) fre2[s2[i]-'A']++; 
		sort(fre1,fre1+26);
		sort(fre2,fre2+26);
		if(!memcmp(fre1,fre2,sizeof(int)*26)) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	return 0;
} 
