/*--waltz26--*/


//ST表-最小值应用
int f[20][100005];
int lg2[100005];

int main() 
{
    int n;
    cin>>n;
	
    int t=0;
    for (int i=1;i<=n;i++)    //初始化log2
    {
        if (i>=(1<<(t+1))) t++;
        lg2[i]=t;
    }
	
    for (int i=1;i<=n;i++)
    	cin>>f[0][i];

    for (int j=1;j<17;j++)
        for (int i=1;i+(1<<(j-1))<=n;i++)
	    f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);

    int l,r;
    cin>>l>>r;

    int s=log2(r-l+1);
    cout<<min(f[s][l],f[s][r-(1<<s)+1])<<'\n';
}
