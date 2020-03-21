/*--WinnieVenice--*/


//二叉堆优化-封装
struct Dijstra
{
    #define type_data int;    //节点权值数据类型
    #define upper_bound 1e9L    //权值数据范围的上界
    static const int maxsize=5+2e5;    //最大节点数
    int size;    //节点数
    vector<pair<type_data,int>> V[maxsize];    //邻接表:某点i的边表V[i],pair<该边权值,该边的另一端点>
    type_data d[maxsize];    //d[i]: i到源头的最短路
    priority_queue<pair<type_data,int>,vector<pair<type_data,int>>,greater<pair<type_data,int>>> q;//最小堆


    Dijstra(vector<pair<type_data,int>> a[],int n,int start)
    {    //参数表:(图,节点数,源头)
        assert(start<=n);    //防止溢出
        size=n;
        for(int i=1;i<=n;i++)
        {    //初始化图和d[]
            V[i]=a[i];
            d[i]=upper_bound;
        }

        d[start]=0;    //源头到自身的距离为0
        q.push({0,start});
        while(q.size())
        {
            int cur=q.top().second;    //输出当前被考虑过的点中的最小d
            q.pop();
            for(int i=0;i<V[cur].size();i++)
                if(d[V[cur][i].second]>d[cur]+V[cur][i].first)    //松弛操作
                {    
                    d[V[cur][i].second]=d[cur]+V[cur][i].first;
                    q.push({d[V[cur][i].second],V[cur][i].second});    //这个点被考虑过,丢进最小堆里维护
                }
        }
    }
}dij;


/*--waltz26--*/


//枚举式
struct Edge
{
    int v;
    int w;
    int next;
}edge[1000000];

int head[20000];
int cnt=0;
bool vis[20000];    //有无访问
unsigned int F[20000];    //存最短路

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

    int cur=s;
    F[s]=0;
    long long minn;

    while(!vis[cur])
    {
        vis[cur]=1;
        for(int i=head[cur];i!=0;i=edge[i].next)
        {
            if(!vis[edge[i].v]&&F[edge[i].v]>F[cur]+edge[i].w)
                F[edge[i].v]=F[cur]+edge[i].w;
        }

        minn=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&minn>F[i])//取新的最小值
            {
                minn=F[i];
                cur=i;
            }
        }
    }

    for(int i=1;i<=n;i++)
	    cout<<F[i]<<' ';
    return 0;
}


/*--waltz26--*/


//二叉堆优化
struct Edge
{
    int v;
    int w;
    int next;
}edge[200005];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int head[100005];
int cnt=0;
bool vis[100005];
int F[100005];

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
    q.push(make_pair(0,s));
    while (!q.empty())  
    {
        int x=q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x]=1;

        for (int i=head[x];i;i=edge[i].next) 
        {
            if(F[edge[i].v]>F[x]+edge[i].w)
            {
                F[edge[i].v]=F[x]+edge[i].w;
                q.push(make_pair(F[edge[i].v],edge[i].v));
            }
        }
    }

    for (int i=1;i<=n;i++)
        cout<<F[i]<<' ';
    return 0;
}