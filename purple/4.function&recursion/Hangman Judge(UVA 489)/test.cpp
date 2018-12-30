#include <iostream>
#include <cstring>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,check[26];
	char s1[102],s2[102];
	while(cin>>n && n>0){
		cin>>s1>>s2;
		cout<<"Round "<<n<<endl;
		int num=0,chance=7;
		memset(check,0,sizeof(check));
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=0;i<len1;i++)
			if(!check[s1[i]-'a']){check[s1[i]-'a']=1;num++;}
		for(int j=0;j<len2;j++){
			if(check[s2[j]-'a']){
				check[s2[j]-'a']=0;
				num--;
				if(!num) break;
			}
			else chance--;
			if(!chance) break;
		}
		if(!num) cout<<"You win.\n";
		else if(!chance) cout<<"You lose.\n";
		else cout<<"You chickened out.\n";
	}
	return 0;
} 
