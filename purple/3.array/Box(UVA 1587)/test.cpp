#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct plane{
	int w,h;
};
bool cmp(plane Box1,plane Box2){
	return Box1.h==Box2.h?Box1.w>Box2.w:Box1.h>Box2.h;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	plane Box[6];
	while(scanf("%d %d",&Box[0].w,&Box[0].h)!=EOF){
		if(Box[0].h>Box[0].w) swap(Box[0].w,Box[0].h);
		for(int i=1;i<6;i++){
			scanf("%d %d",&Box[i].w,&Box[i].h);
			if(Box[i].h>Box[i].w) swap(Box[i].w,Box[i].h);
		}
		sort(Box,Box+6,cmp);
		int flag=1;
		if(memcmp(Box,Box+1,sizeof(plane))||memcmp(Box+2,Box+3,sizeof(plane))||memcmp(Box+4,Box+5,sizeof(plane))) flag=0;
		if(Box[0].w!=Box[2].w||Box[0].h!=Box[4].w||Box[2].h!=Box[4].h) flag=0;
		if(flag) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
} 
