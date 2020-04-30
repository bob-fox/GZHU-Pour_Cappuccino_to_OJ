/*--waltz26--*/


//单调递增队列
struct node
{
    int h,i;
};
deque<node> q;

void monotonic_queue()
{
    int n,k;    //窗口长度
    cin>>n>>k;

    for (int i=1;i<=n;i++)
    {
        int h;
        cin>>h;
        
        while (!q.empty()&&q.back().h>h)    //不能产生贡献的删掉
            q.pop_back();

        while (!q.empty()&&q.front().i<=i-k)    //过时元素
            q.pop_front();

        q.push_back((node){h,i});
        if (i>=k) cout<<q.front().h<<' ';
    }
}


/*--waltz26--*/


//单调递减队列
struct node
{
    int h,i;
};
deque<node> q;

void monotonic_queue()
{
    int n,k;    //窗口长度
    cin>>n>>k;

    for (int i=1;i<=n;i++)
    {
        int h;
        cin>>h;
        
        while (!q.empty()&&q.back().h<h)    //不能产生贡献的删掉
            q.pop_back();

        while (!q.empty()&&q.front().i<=i-k)    //过时元素
            q.pop_front();

        q.push_back((node){h,i});
        if (i>=k) cout<<q.front().h<<' ';
    }
}