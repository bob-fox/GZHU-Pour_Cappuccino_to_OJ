/*--waltz26--*/


//f[n]=f[n-1]+f[n-3],f[1]=f[2]=f[3],求第n项
const int mod=int(1e9+7);
int n;    //矩阵阶数

struct Matrix    //矩阵结构体
{
    long long m[105][105];

    void init()    //初始化
    {
        memset(m,0,sizeof(m));
        return;
    }

    Matrix operator*(const Matrix b) const    //矩阵乘法
    {
        Matrix t;
        t.init();
        for (int i=1;i<=n;i++)//基本枚举，下同
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    t.m[i][j]=(t.m[i][j]+(m[i][k]*b.m[k][j])%mod)%mod;
        return t;
    }
    Matrix& operator*=(const Matrix b)
    {
        return *this=*this*b;
    }

    //输入输出
    void in()
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>m[i][j];
        return;
    }
    void out()
    {
        for (int i=1;i<=n;i++,cout<<'\n')
            for (int j=1;j<=n;j++)
                cout<<m[i][j]<<' ';
        return;
    }
};

Matrix fast_matrix_power(Matrix a,long long b)
{
    Matrix ans,base=a;
    ans.init();
    for (int i=1;i<=n;i++)    //构建单位矩阵
        ans.m[i][i]=1;
    while(b)
    {
        if(b&1)
            ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}

int main()
{
    Matrix A;
    A.init();
    A.m[1][1]=1;
    A.m[1][3]=1;
    A.m[2][1]=1;
    A.m[3][2]=1;
    n=3;

    int t;
    cin>>t;

    while (t--)    //多次查询
    {
        int k;
        cin>>k;

        if (k<=3) cout<<1<<'\n';
        else 
        {
            Matrix Ak=fast_matrix_power(A,k-3);
            long long ans=0;
            for (int i=1;i<=n;i++)
                ans+=Ak.m[1][i];
            cout<<ans%mod<<'\n';
        }
    }
    return 0;
}


/*--waltz26--*/


//斐波那契数列，求两项的公约数
const int mod=int(1e8);
int n;    //矩阵阶数

struct Matrix    //矩阵结构体
{
    long long m[105][105];

    void init()    //初始化
    {
        memset(m,0,sizeof(m));
        return;
    }

    Matrix operator*(const Matrix b) const    //矩阵乘法
    {
        Matrix t;
        t.init();
        for (int i=1;i<=n;i++)//基本枚举，下同
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    t.m[i][j]=(t.m[i][j]+(m[i][k]*b.m[k][j])%mod)%mod;
        return t;
    }
    Matrix& operator*=(const Matrix b)
    {
        return *this=*this*b;
    }

    //输入输出
    void in()
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>m[i][j];
        return;
    }
    void out()
    {
        for (int i=1;i<=n;i++,cout<<'\n')
            for (int j=1;j<=n;j++)
                cout<<m[i][j]<<' ';
        return;
    }
};

Matrix fast_matrix_power(Matrix a,long long b)
{
    Matrix ans,base=a;
    ans.init();
    for (int i=1;i<=n;i++)    //构建单位矩阵
        ans.m[i][i]=1;
    while(b)
    {
        if(b&1)
            ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}

int main()
{
    Matrix A;
    A.init();
    A.m[1][1]=1;
    A.m[1][2]=1;
    A.m[2][1]=1;
    n=2;

    int p,q;
    cin>>p>>q;

    //gcd(f[p],f[q])=f[gcd(p,q)]
    if (__gcd(p,q)<=2)
        cout<<1;
    else
    {
        Matrix Ak=fast_matrix_power(A,__gcd(p,q)-2);
        cout<<(Ak.m[1][1]+Ak.m[1][2])%mod<<'\n';
    }
    return 0;
}