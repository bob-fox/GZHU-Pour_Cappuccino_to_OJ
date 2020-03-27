/*--WinnieVenice--*/


struct BinarySearchTree
{
    #define type_data long long
    #define ERROR -1    //某个值,表示不行
    static const int maxsize=5+1e6;
    
    struct Node
    {
        type_data key;    //节点信息(二分标准)
        type_data val;    //额外维护的节点信息(不一定要看需求)
        Node *ls,*rs;

        Node()
        {
        	ls=rs=NULL;    //初始化
		}
    }*root;    //树根(每次操作都从树根开始)

    inline void create(Node *&cur,type_data key,type_data val)    //节点创建
    {       
        cur=new Node;
        cur->key=key;
        cur->val=val;
    }   
    inline void insert(Node *&cur,type_data key,type_data val)    //插入操作
    {       
        if (cur==NULL)
        	return create(cur,key);
        if (key<=cur->key)    //判断向左还是向右递归
            insert(cur->ls,key,val);
        else
            insert(cur->rs,key,val);     
    }
    inline bool check(Node *&cur,type_data key)    //(根据二分值)检查操作
    {       
        if (key==cur->key)
            return true;
        else if(key<=cur->key)
            return check(cur->ls,key);
            else
                return check(cur->rs,key);
        return false;
    }
    inline type_data query(Node *&cur,type_data key)    //询问操作(询问该二分的key值下额外信息)
    {       
        if (key==cur->key)
            return cur->val;
        else if (key<=cur->key)
            return query(cur->ls,key);
            else
                return query(cur->rs,key);
        return ERROR;    //该树里没有这样的key
    } 
    inline void inorder(Node *&cur)    //中序遍历
    {        
        if (cur!=NULL)
        {
            inorder(cur->ls);
            cout<<"->"<<(cur->key);
            inorder(cur->rs);
        }
    }
}bst;