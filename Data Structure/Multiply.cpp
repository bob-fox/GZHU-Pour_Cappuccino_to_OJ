/*--waltz26--*/


//最小值
int f[20][100005];
int a[100005];

int main() 
{
    int n;
    cin>>n;
	for (int i=1;i<=n;i++)
        cin>>f[0][i];

	for (int j=1;j<17;j++)
        for (int i=1;i<=n;i++)
		    f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);

	int l,r;
    cin>>l>>r;

	int i=l;
	int minn=INT_MAX;
	for (int j=16;~j;j--)
		if (r-l+1&1<<j) 
        {
			minn=min(minn,f[j][i]);
			i+=1<<j;
		}
	cout<<minn<<'\n';
}