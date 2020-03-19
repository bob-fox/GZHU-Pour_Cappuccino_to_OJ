/*--waltz26--*/


//暴力求LCA
int n,m,tot;
int deep[maxn],vis[maxn],head[maxn],f[maxn];    //deep记录结点深度，vis判断是否遍历过，head是指向结点的头的指针，f存储父亲结点
struct Node
{
    int v,next;
}e[maxn*2];    //双向建边乘2

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
void build_tree(int root,int depth)    //建树，当此前所站在的点有下一个连接的点的时候，depth+1，然后继续递归下一个点
{
    deep[root]=depth;
    vis[root]=1;
    for(int i=head[root];i!=-1;i=e[i].next)    
    {
        if(vis[e[i].v]!=0)    continue;
        f[e[i].v]=root;
        build_tree(e[i].v,depth+1);
    }
}
int LCA(int u,int v)    //暴力版的LCA
{
    while(deep[u]>deep[v])    u=f[u];//先保证u和v在同一深度
    while(deep[v]>deep[u])    v=f[v];
    while(u!=v)    //然后一起往上找祖先
    {
        u=f[u];
        v=f[v];
    }
    return u;    //返回去u，v都是一样的
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b;
        add_edge(a,b);
        add_edge(b,a);
    }
    build_tree(1,1);    //从结点1开始建树
    
    for(int i=1;i<=m;i++)    //查询LCA
    {
	int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
    return 0;
}