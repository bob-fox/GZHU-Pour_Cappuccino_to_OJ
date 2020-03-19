/*--waltz26--*/

int fa[maxn]    //存储祖先
int connected[maxn]={1};    //以下标为祖先的联通数
int ans;    //存储最大联通数

int check_anc(int x)    //寻找祖先
{
    if (fa[x]) return fa[x]=check_anc(fa[x]);
    return x;
}
void union_anc(int x,int y)    //合并
{
    x=check_anc(x); y=check_anc(y);
    if (x!=y)
    fa[x]=y;
}
bool is_same_anc(int x,int y)    //是否有相同祖先
{
    if (check_anc(x)==check_anc(y)) return 1;
    else return 0;
}
void union_anc_2(int x,int y)    //合并和联通并计算最大联通数
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