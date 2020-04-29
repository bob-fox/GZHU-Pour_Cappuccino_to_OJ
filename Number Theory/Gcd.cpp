/*--waltz26--*/


//标准
long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
//可以用STL的__gcd()函数
