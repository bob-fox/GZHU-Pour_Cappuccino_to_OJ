/*--waltz26--*/


//单调递增栈
struct node
{
    int h,i;
};
stack<node> s;
int op[2];

int main()
{
    int n;
    cin>>n;
    
    for (int i=1;i<=n;i++)
    {
        int h;
        cin>>h;
        
        int pd=0;
        while (!s.empty())
        {
            if (s.top().h>h) {pd=1; op[1]=s.top().i; break;}
            else s.pop();
        }

        s.push((node){h,i});
        cout<<op[pd]<<' ';
    }
}
