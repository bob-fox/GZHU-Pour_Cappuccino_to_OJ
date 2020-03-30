/*--waltz26--*/


//树上DP
struct Edge
{
    int v;
    int w;
    int next;
}edge[1000005];

int head[200005];
int cnt;
int n,m;
int size[200005];
int sub_cnt[200005];
int g;    //存储重心编号

void add(int u,int v,int w)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void getcenter_g(int x,int fa)
{
    size[x]=1;      //总结点数-该结点父亲结点子树的结点数
    sub_cnt[x]=0;    //该结点除父亲结点子树以外最大子树结点数
    for (int i=head[x];i;i=edge[i].next) 
    {
        int y=edge[i].v;
        if (y!=fa) 
        {
            getcenter_g(y,x);
            size[x]+=size[y];
            sub_cnt[x]=max(sub_cnt[x], size[y]);
        }
    }
    sub_cnt[x]=max(sub_cnt[x],n-size[x]);
    if (g==0||sub_cnt[x]<sub_cnt[g]) g=x;
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }

    getcenter_g(1,0);

    for (int i=1;i<=n;i++)    //可能会有两个重心，再遍历一遍
        if (g!=i&&sub_cnt[g]==sub_cnt[i])
            cout<<i<<' ';
    cout<<g<<'\n';
    return 0;
}