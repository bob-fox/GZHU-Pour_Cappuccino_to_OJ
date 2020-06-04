/*--waltz26--*/


//半封装
int n;    //矩阵阶数
long long k;

struct Matrix    //矩阵结构体
{
    #define mod int(1e9+7)

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
    Matrix a;

    cin>>n>>k;
    a.in();

    fast_matrix_power(a,k).out();
    return 0;
}