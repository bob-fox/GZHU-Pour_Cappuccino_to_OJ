/*--waltz--*/


//卡恩算法
struct Edge
{
    int v;
    int next;
}edge[1000005];

int head[200005];
int cnt;
int vis[200005],inedge[200005],ans[200005];
int t;

void add(int u,int v)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    inedge[v]++;
}

void topological_sorting(int x)
{
    ans[t++]=x;
    vis[x]=1;

    for (int i=head[x];i;i=edge[i].next)
    {
        inedge[edge[i].v]--;
        if (!vis[i]&&!inedge[edge[i].v])
            topological_sorting(edge[i].v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
	    int u,v;
        cin>>u>>v;
        add(u,v);
    }

    for (int i=1;i<=n;i++)
        if (!vis[i]&&!inedge[i])
            topological_sorting(i);

    for (int i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}