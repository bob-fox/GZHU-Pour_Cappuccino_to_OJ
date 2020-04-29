/*--waltz26--*/


//标准
long long fast_mod(long long a,long long b,long long mod)
{
    long long ans=0;
    while(b)
    {
        if(b&1)
            ans=(ans+a)%mod;
        b=b>>1;
        a=(a+a)%mod;
    }
    return ans;
}
