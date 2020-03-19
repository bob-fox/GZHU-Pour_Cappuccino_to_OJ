/*--WinnieVenice--*/

//堆优化
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