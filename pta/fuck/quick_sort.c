#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
int Partition ( SqList  L,int low,  int  high );
void Qsort ( SqList  L,int low,  int  high );
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  Qsort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
   {		
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void Qsort ( SqList  L,int low,  int  high ) 
{  int  pivotloc;
   if(low<high)
    {  
	pivotloc = Partition(L, low, high ) ;
        Qsort (L, low, pivotloc-1) ; 
        Qsort (L, pivotloc+1, high );
     }
}
/*你的代码将被嵌在这里 */
void  CreatSqList(SqList *L)
{
	int i;
	L->elem = (int *)malloc(sizeof(int *));
	scanf("%d", &L->Length);
	for(i = 1;i <= L->Length;i++)
		scanf("%d", &L->elem[i]);
}
int Partition ( SqList  L,int low,  int  high )
{
	int sb = L.elem[low], temp, l = low+1, r = high;
	while(l < r)
	{
		while(l < r && L.elem[r] >= sb) r--;
		while(l < r && L.elem[l] <= sb) l++;
		if(l < r)
		{
			temp = L.elem[r];
			L.elem[r] = L.elem[l];
			L.elem[l] = temp;
		}
	}
	int offset = (L.elem[l] > sb ? 1 : 0);
	L.elem[low] = L.elem[l - offset];
	L.elem[l - offset] = sb;
	return l - offset;
}
