/*--waltz26--*/


//二进制法
int Set[maxn];

void print_subset(int n,int s)
{
    for (int i=0;i<n;i++)
        if (s&(1<<i)) cout<<Set[i]<<' ';    //该位为1
    cout<<'\n';
}

int main()
{
    for (int i=0;i<(1<<n);i++)    //0为空集，这条循环遍历所有子集
	    print_subset(n,i);
}


/*--waltz26--*/


//位向量法
void print_subset(int n,int cur)
{
    if (cur==n)
    {
        for (int i=0;i<cur;i++)
            if (vec[i]) printf("%d ",i);
        puts("");
        return;
    }
    vec[cur]=1;    \\选第cur个元素
    print_subset(n,cur+1);
    vec[cur]=0;    \\不选第cur个元素
    print_subset(n,cur+1);
}