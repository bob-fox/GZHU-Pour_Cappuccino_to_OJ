/*--waltz26--*/


//set存储方式,进制hash
set<string> a[100005];
    
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
 
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int key=0;
 
        for (auto i:s)
            key=(key*256+(long long)i)%10000;
        
        if (!a[key].count(s))
            {cnt++; a[key].insert(s);}
        else continue;
    }
 
    cout<<cnt<<'\n';
    return 0;
}