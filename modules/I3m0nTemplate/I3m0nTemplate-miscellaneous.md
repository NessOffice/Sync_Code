# 二分图

顶点覆盖：所有边都存在端点在点集中

独立集：两两之间无边的点集

路径覆盖：覆盖所有点且不交叉的路径

最大匹配数 = 最小顶点覆盖

最大团 = 补图的最大独立集

最小边覆盖 = 最大独立集 = 顶点个数 - 最小路径覆盖

最小路径覆盖 = 顶点个数 - 最大匹配数

最小割 = 最小点权覆盖集 = 点权和 - 最大点权独立集

# Matrix-Tree


度数矩阵 D：

$D[i][j] = 0 (i ≠ j)$，$D[i][i] = i$号点的度数

邻接矩阵 A：

$A[i][i] = 0$，$A[i][j] = A[j][i] = i,j$之间的边数

基尔霍夫 Kirchhoff 矩阵 $K = D - A$

对于一个无向图 G ，生成树个数等于其基尔霍夫 Kirchhoff 矩阵任何一个 N-1 阶主子式的行列式的绝对值。

## expend

### 无向图

$i == j$ 时，A [i][j] 存 i 点的度数。$i != j$时，存 i，j 之间是否有边，有边为 - 1，没边是 。

### 有向图

求外向树，把$d [i][i]$改成一个点的入度。

求内向树，把$d [i][i]​$改成一个点的出度。

# 后缀数组

$height[i] = suffix(sa[i-1]), suffix(sa[i])$ 最长公共前缀

后缀 j 和 k 的最长公共前缀：$min( height[rank[j] + 1], height[rank[j] + 2], ...,height[rank[k]] )$

可重叠最长重复子串：$max(height[...])$

不可重叠最长重复子串：二分答案 k，用 $height[i] >= k$ 分组，并验证是否存在某一组 $max(sa[])-min(sa[])$ 不小于 k

可重叠最长 k 次重复子串：二分答案 ans，用 $height[i] >= ans$ 分组, 验证是否存在某一组含有不少于 k 个后缀

不相同子串个数：$sum(n-sa[k]+1-height[k])$

# 卡常

```c++
#pragma GCC optimize(2)
inline char my_getchar(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
template <typename T> inline T read(){
	T x=0,f=1;char ch=my_getchar();int t=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=my_getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=my_getchar();}
	if(ch=='.'){
		ch=my_getchar();
		while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=my_getchar();t++;}
		while(t--)x/=10.0;
	}
	return x*f;
}

//if(__builtin_expect(表达式,期望值))语句;
//unordered_map, unordered_set 代替 map, set
```