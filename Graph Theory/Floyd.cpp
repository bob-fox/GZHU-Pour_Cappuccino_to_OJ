/*--waltz26--*/


//原版
int f[maxn][maxn][maxn];

int main()
{
    //前面记得初始化
    for (int k=1;k<=n;k++)    // 注意顺序小心翻车  
		for (int i=1;i<=n;i++)  
	    	for (int j=1;j<=n;j++)  
				f[k][i][j]=min(f[k-1][i][j],f[k-1][i][k]+f[k-1][k][j]);
}


/*--waltz26--*/


//空间优化
int f[maxn][maxn][maxn];

int main()
{
    //前面记得初始化
    for (int k=1;k<=n;k++)    // 注意顺序小心翻车  
		for (int i=1;i<=n;i++)  
	    	for (int j=1;j<=n;j++)  
				f[i][j]=min(f[[i][j],f[i][k]+f[k][j]);
}