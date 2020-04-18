/*--waltz26--*/


//基础
int a[1000005],b[1000005],c[1000005];

int main() 
{
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
	b[i]=a[i];

    sort(b+1,b+n+1);
    int m=unique(b+1,b+n+1)-(b+1);

    for (int i=1;i<=n;i++) 
    {
	int v=a[i];
	a[i]=lower_bound(b+1,b+m+1,v)-b;
	c[a[i]]=v;
    }
}
