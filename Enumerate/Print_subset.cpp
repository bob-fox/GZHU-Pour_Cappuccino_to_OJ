/*--waltz26--*/

int Set[maxn];

void print_subset(int n,int s)
{
    for (int i=0;i<n;i++)
        if (s&(1<<i)) printf("%d ",Set[i]);    //该位为1
    printf("\n");
}
int main()
{
    for (int i=0;i<(1<<n);i++)    //0为空集，这条循环遍历所有子集
	print_subset(n,i);
}