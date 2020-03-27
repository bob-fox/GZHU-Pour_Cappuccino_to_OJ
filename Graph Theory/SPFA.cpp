/*--waltz26--*/


//无优化
struct Edge
{
    int v;
    int w;
    int next;
}edge[1000005];

queue<int> q;
int head[20005];
int cnt=0;
bool vis[20005];    //有无访问
unsigned int F[20005];    //存最短路

void add(int u,int v,int w)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

int main()
{
    int n,m,s;
    cin>>n>>m>>s;

    for (int i=1;i<=n;i++) F[i]=INT_MAX;    //初始化

    for(int i=0;i<m;i++)
    {
	    int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }

    F[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;

        for(int i=head[x];i;i=edge[i].next)
            if(F[edge[i].v]>F[x]+edge[i].w)
            {
                F[edge[i].v]=F[x]+edge[i].w;
                if(!vis[edge[i].v])
                {
                    q.push(edge[i].v);
                    vis[edge[i].v]=1;
                }
            }
    }

    for (int i=1;i<=n;i++)
        cout<<F[i]<<' ';
    return 0;
}