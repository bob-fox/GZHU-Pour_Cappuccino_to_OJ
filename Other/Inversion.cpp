/*--waltz26--*/


//归并排序求逆序对
int a[maxn],p[maxn];
long long ans=0;

void msort(int l,int r)
{
    if(l>=r) return;

    int mid=l+r>>1;
    msort(l,mid);
    msort(mid+1,r);

    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j]) 
            p[k++]=a[i++];//先赋值再+1 
        else 
            {p[k++]=a[j++]; ans+=(long long)mid-i+1;}

    while(i<=mid) p[k]=a[i],k++,i++;
    while(j<=r) p[k]=a[j],k++,j++;
    for(int i=l;i<=r;i++) 
        a[i]=p[i];
}


/*--waltz26--*/


//树状数组求逆序对
int a[500005],bit[500005],r[500005];
long long ans;
 
bool cmp(const int &x,const int &y)
{
    return a[x]<a[y];
}
 
int lowbit(int x)
{
    //算出x二进制的从右往左出现第一个1以及这个1之后的那些0组成数的二进制对应的十进制的数
    return x&-x;
}
void change_point(int u,int d,int j)    //单点修改
{
    while (u<=j)    //不能越界
    {
        bit[u]+=d;
        u+=lowbit(u);
    }
}
int ask_sum(int u)    //区间查询
{
    int ans=0;
    while (u>=1)
    {
        ans+=bit[u];
        u-=lowbit(u);
    }
    return ans;
}
 
int main()
{
    int n;
    cin>>n;
 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        r[i]=i;
    }
    sort(r+1,r+1+n,cmp);
 
    for(int i=1;i<=n;i++)
    {
        change_point(r[i],1,n);
        ans+=i-ask_sum(r[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
