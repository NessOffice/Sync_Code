#include <cstdio>
#include <string.h>

char s[30];
int a[30];
int b[30];
int bx[90], by[90];
int numb;
int step;
int x, y;
int flag;
int l; 

void Put(int a) {
    if (a == 0) {
        bx[numb]=x;
        by[numb]=y+1;
    }
    if (a == 1) {
        bx[numb]=x;
        by[numb]=y-1;
    }
    if (a == 2) {
        bx[numb]=x-1;
        by[numb]=y;
    }
    if (a == 3) {
        bx[numb]=x+1;
        by[numb]=y;
    }
    numb++;
}

int main() {
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l;i++) {
        if (s[i]=='U') {
            a[i]=0;
        }
        if (s[i]=='D') {
            a[i]=1;
        }
        if (s[i]=='L') {
            a[i]=2;
        }
        if (s[i]=='R') {
            a[i]=3;
        }
    }
    
    flag = 1;
    
    //for (int i = 0; i < l; i++) {
    //    printf("%d\n", a[i]);
    //}
    
    int temp = a[l-1]/2;
    int j = 1;
    for (int i = l-2; i >= 0; i--) {
        if (temp != a[i]/2) break;
        if (a[l-1]==a[i]) {
            flag = 0;
            break;
        }
    }
    
    for (int i = 0; i < l-1; i++ ) {
        if (a[i] == a[i+1]) {
            flag = 0;
            break;
        }
    }
    
    if (flag == 0 ) {
        printf("impossible\n");
        return 0;
    }
    
    b[0]=a[l-1];
    for (int i = l-2; i >= 0; i--) {
        if (a[i]/2 == b[j-1]/2) {
            continue;
        }
        b[j] = a[i];
        j++;
    }
    //for(int i=0;i<j;i++){
    //    printf("%d\n",b[i]);
    //}
    
    numb = 0;
    step = 1<<24;
    x = y = 0;
    b[j]=-1;
    for (int i = 0; i < j;i++) {
        if (b[i] == 0) {
            Put(0);
            y-=step;
            y--;
            Put(1);
            y++;
            step/=2;
        }
        if (b[i] == 1) {
            Put(1);
            y+=step;
            y++;
            Put(0);
            y--;
            step/=2;
        }if (b[i] == 2) {
            Put(2);
            x+=step;
            x++;
            Put(3);
            x--;
            step/=2;
        }if (b[i] == 3) {
            Put(3);
            x-=step;
            x--;
            Put(2);
            x++;
            step/=2;
        }
    }
    
    printf("%d %d\n%d\n",x,y,numb);
    for (int i = numb-1; i>=0; i--) {
        printf("%d %d\n", bx[i], by[i]);
    }
    
    return 0;
}
