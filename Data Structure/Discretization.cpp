/*--waltz26--*/


//去重离散化
//a为原数组（离散化数组），b为离散化对照数组，c为映射数组
int a[1000005],b[1000005],c[1000005];

int main() 
{
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);
    int m=unique(b+1,b+n+1)-(b+1);

    for (int i=1;i<=n;i++) 
    {
        int v=a[i];
        a[i]=lower_bound(b+1,b+m+1,v)-b;
        c[a[i]]+=v;
    }
}


/*--waltz26--*/


//不去重离散化
int a[500005],r[500005];    //离散化数组
 
bool cmp(const int &x,const int &y)
{
    return a[x]<a[y];
}
 
int main()
{
    int n;
    cin>>n;
 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        r[i]=i;   //初始化r
    }
    sort(r+1,r+1+n,cmp);    //离散化
}
