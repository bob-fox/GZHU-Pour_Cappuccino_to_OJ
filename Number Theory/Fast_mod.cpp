/*--waltz26--*/

ll fast_mod(ll a,ll b,ll mod)
{
    ans=0;
    while(b)
    {
        if(b&1)
        ans=(ans+a)%c;
        b=b>>1;
        a=(a+a)%c;
    }
    return ans;
}