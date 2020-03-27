/*--waltz26--*/


//指针版
struct node
{
    int key;
    node* rt;

    node(int _key,node* _rt)    //构造函数
    {
        key=_key;
        rt=_rt;
    }
};
node *root=new node(-1,NULL);    //root是一个假结点

int find_key(int key)    //查找key
{
    for(node* p=root->rt;p;p=p->rt)
        if(p->key==key) return 1;
    return 0;
}
void insert_key(int key,int pos)    //插入key，需保证pos输入合法
{
    node* p=root;
    while (--pos)
        p=p->rt;
    node* target=new node(key,p->rt);
    p->rt=target;
}
void delete_key(int pos)    //删除key，需保证pos输入合法
{
    node* p=root;
    while (--pos)
        p=p->rt;
    node* target=p->rt;
    p->rt=target->rt;
    delete target;    //释放节点
}
void go_list()    //遍历链表
{
    for(node* p=root->rt; p; p=p->rt)
        printf("%d\n", p->key);
}
void debug()    //检查运行是否正确
{
    for(node* p=root->rt; p; p=p->rt)
        printf("Node[%p] key=%d rt=%p\n", p, p->key, p->rt);
}