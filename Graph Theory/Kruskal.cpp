/*--waltz26--*/


//标准
struct node
{
    int u,v,w;
}edge[1000005];

int fa[200005];
int connected[200005];
int ans;

int check_anc(int x)    //寻找祖先
{
    if (fa[x]) return fa[x]=check_anc(fa[x]);
    return x;
}
void union_anc(int x,int y)    //合并
{
    x=check_anc(x); y=check_anc(y);
    if (x!=y)
    {
	    fa[x]=y;
	    connected[y]+=connected[x];
        if (connected[y]>ans)
            ans=connected[y];
    }
}
bool is_same_anc(int x,int y)    //是否有相同祖先
{
    if (check_anc(x)==check_anc(y)) return 1;
    else return 0;
}

bool cmp(node x,node y)
{
    return x.w<y.w;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)    //初始化
        connected[i]=1;

    for (int i=0;i<m;i++)
        cin>>edge[i].u>>edge[i].v>>edge[i].w;

    sort(edge,edge+m,cmp);

    int sum=0;
    for (int i=0;i<m;i++)
    {
        if (is_same_anc(edge[i].u,edge[i].v)) continue;
        else
            {union_anc(edge[i].u,edge[i].v); sum+=edge[i].w;}
        if (ans==n)
            {cout<<sum<<'\n'; return 0;}
    }

    cout<<"I can't find\n";
}
