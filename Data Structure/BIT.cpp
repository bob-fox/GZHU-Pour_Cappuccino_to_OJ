/*--waltz26--*/


//树状数组1-单点修改+区间查询
int bit[500005];

int lowbit(int x)
{
    //算出x二进制的从右往左出现第一个1以及这个1之后的那些0组成数的二进制对应的十进制的数
    return x&-x;
}
void change_point(int u,int d,int j)    //单点修改
{
    while (u<=j)    //不能越界
    {
        bit[u]+=d;
        u+=lowbit(u);
    }
}
int ask_sum(int x)    //区间查询
{
    int ans=0;
    while (x>=1)
    {
        ans+=bit[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        int d;
        cin>>d;
        change_point(i,d,n);
    }

    while (n--)
    {
        int cmd,x,y,k;
        cin>>cmd;

        switch (cmd)
        {
            case 1:    //单点修改
                cin>>x>>k;
                change_point(x,k,n);
                break;
            case 2:
                cin>>x>>y;    //区间查询
                cout<<ask_sum(y)-ask_sum(x)<<'\n';
                break;
        }
    }
}


/*--waltz26--*/


//树状数组2-区间修改+单点查询
int a[500005];    //原数组
int bit[500005];    //现在变成差分树状数组

int lowbit(int x)
{
    //算出x二进制的从右往左出现第一个1以及这个1之后的那些0组成数的二进制对应的十进制的数
    return x&-x;
}
void change_interval(int u,int d,int j)    //区间修改
{
    while (u<=j)    //不能越界
    {
        bit[u]+=d;
        u+=lowbit(u);
    }
}
int ask_sum(int u)    //单点查询
{
    int ans=0;
    while (u>=1)
    {
        ans+=bit[u];
        u-=lowbit(u);
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    while (m--)
    {
        int cmd,x,y,k;
        cin>>cmd;

        switch (cmd)
        {
            case 1:    //区间修改
                cin>>x>>y>>k;
                change_point(x,k,n);    //差分左修改点
                change_point(y+1,-k,n);    //差分右修改点
                break;
            case 2:    //单点查询
                cin>>x;
                cout<<a[x]+ask_sum(x)<<'\n';
                break;
        }
    }
}