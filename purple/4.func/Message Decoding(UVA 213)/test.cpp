#include <stdio.h>
char code[8][1<<8];
int readcode(){
	char c;
	int len = 1,i = 0;
	while(c = getchar()) if(c!='\n'&&c!='\r') {code[len++][i]=c;break;}
	while(c = getchar()){
		if(c == EOF) return 0;
		if(c == '\n' || c == '\r') return 1;
		code[len][i++]=c;
		if(i==(1<<len)-1){len++;i=0;}
	}
} 
int readint(int len){
	char c;
	int value = 0;
	while(len--){
		while(c = getchar())
			if(c!='\n'&&c!='\r')
				break;
		value = (value*2)+c-'0';
	}
	return value;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(readcode()){
		while(1){
			int len = readint(3),value;
			if(len == 0) break;
			while(1){
				value = readint(len);
				if(value==(1<<len)-1) break;
				putchar(code[len][value]);
			}
		}
		putchar('\n');
	}
	return 0;
}
