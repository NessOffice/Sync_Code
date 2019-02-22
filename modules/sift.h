const int maxn=1000010;
bool isP[maxn];
int P[maxn];
int total=0;
void SiftPrime(int m){
	memset(isP,true,sizeof(isP));
	memset(P,0,sizeof(P));
	isP[0]=false;
	isP[1]=false;
	for(int i=2;i<=m;i++){
		if(isP[i]) P[++total]=i;
		for(int j=1;j<=total && i*P[j]<=m;j++){
			isP[i*P[j]]=false;
			if(!(i%P[j])) break;
		}
	}
}
long long QuickPower(long long expo,long long base)
{
    long long ans=1;
    while(expo)
    {
        if(expo&1)
            ans*=base;
        expo>>=1;
        base*=base;
    }
    return ans;
}