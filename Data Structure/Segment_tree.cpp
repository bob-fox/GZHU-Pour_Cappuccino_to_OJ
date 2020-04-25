/*--waltz26--*/


//线段树1-区间修改+区间查询/下放式标记/堆式存储
#define P (k<<1)
#define S (P+1)
#define M (i+j>>1)

long long a[200005];
long long f[800020],b[800020];

void update_sum(int k)    //更新
{
    f[k]=f[P]+f[S];
}
void push_down(int k,int i,int j)    //下放标记
{
    //更新子区间的值
    f[P]+=b[k]*(M-i+1);    
    f[S]+=b[k]*(j-M);
    //给子区间加上懒惰标记
    b[P]+=b[k];
    b[S]+=b[k];
    b[k]=0;
}
void build(int i,int j,int k)    //建树
{
    if (i==j)
        f[k]=a[i];
    else
    {
        build(i,M,P);
        build(M+1,j,S);
        update_sum(k);
    }
}
void change_Interval(int u,int v,long long d,int i,int j,int k)
{
    if (u<=i&&v>=j)    //当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    {
        f[k]+=(j-i+1)*d;
        b[k]+=d;
        return;
    }

    push_down(k,i,j);

    if (u<=M)
        change_Interval(u,v,d,i,M,P);
    if (v>M)
        change_Interval(u,v,d,M+1,j,S);
    update_sum(k);
}
long long ask_sum(int u,int v,int i,int j,int k)
{
    if (u<=i&&v>=j)    //当前区间为修改区间的子集时直接取区间答案
        return f[k];

    push_down(k,i,j);

    long long sum=0;
    if (u<=M)
        sum+=ask_sum(u,v,i,M,P);
    if (v>M)
        sum+=ask_sum(u,v,M+1,j,S);
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    build(1,n,1);

    while (m--)
    {
        int cmd,l,r;
        long long d;
        cin>>cmd;

        switch (cmd)
        {
            case 1:    //区间修改
                cin>>l>>r>>d;
                change_Interval(l,r,d,1,n,1);
                break;
            case 2:    //区间查询
                cin>>l>>r;
                cout<<ask_sum(l,r,1,n,1)<<'\n';
                break;
        }
    }
}