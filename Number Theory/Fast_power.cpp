/*--waltz26--*/


long long fast_power(int a,int b,int mod)
{
    long long ans=1,base=a;
    while(b)
    {
        if(b&1)
            ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans%mod;    //非多余步，如果没有b=0这种数据可以去掉取余
}