/*--waltz26--*/


//枚举式
struct Edge
{
    int v;
    int w;
    int next;
}edge[1000005];

int head[200005];
int cnt;
bool vis[200005];
unsigned F[200005];

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
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
	    int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    
    memset(F,0xFF,sizeof(F));

    int x=1;
    F[x]=0;
    int ans=0;
    int pick=0;

    while(!vis[x]&&++pick<n)
    {
        vis[x]=1;
        for(int i=head[x];i;i=edge[i].next)
        {
            if(!vis[edge[i].v]&&F[edge[i].v]>edge[i].w)
                F[edge[i].v]=edge[i].w;
        }

        int minn=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&minn>F[i])    //取新的最小值
            {
                minn=F[i];
                x=i;
            }
        }
        ans+=minn;
    }

    cout<<ans<<'\n';
    return 0;
}


/*--waltz26--*/


//二叉堆优化
struct Edge
{
    int v;
    int w;
    int next;
}edge[1000000];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int head[20005];
int cnt=0;
bool vis[20005];
unsigned F[20005];

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
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
	    int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    
    memset(F,0xFF,sizeof(F));

    F[1]=0;
    q.push(make_pair(0,1));
    int ans=0;
    
    while(!q.empty())
    {
        pair<int,int> temp=q.top();
        int x=temp.second;
        q.pop();
        if (vis[x]) continue;
        ans+=temp.first;
        vis[x]=1;
        
        for(int i=head[x];i;i=edge[i].next)
        {
            if(!vis[edge[i].v]&&F[edge[i].v]>edge[i].w)
            {
                F[edge[i].v]=edge[i].w;
                q.push(make_pair(F[edge[i].v],edge[i].v));
            }
        }
    }

    cout<<ans<<'\n';
    return 0;
}