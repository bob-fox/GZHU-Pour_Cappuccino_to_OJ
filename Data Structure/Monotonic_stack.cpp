/*--waltz26--*/


//单调递增栈
struct node
{
    int h,i;
};
stack<node> s;
int op[2];

void monotonic_stack()
{
    for (int i=1;i<=n;i++)
    {
        cin>>h;
        int pd=0,pi;
        while (!s.empty())
        {
            if (s.top().h>a[i]) {pd=1; op[1]=s.top().i; break;}
            else s.pop();
        }
        s.push((node){h,i});
        cout<<op[pd];
    }
}
