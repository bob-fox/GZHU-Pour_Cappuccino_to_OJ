/*--waltz26--*/


//快速排序-辅助数组
int array[maxn];
int t[maxn];    //临时数组

void quicksort(int l,int r)
{
    if (l>=r) return;    //空区间或者只有一个元素的区间

    int flag=array[rand()%(r-l+1)+l];    //rand%(r-l+1)+l表示随机取[l,r]的一个数

    int p=l,q=r;
    for (int i=l;i<=r;i++)
    {
        if (array[i]<flag) t[p++]=array[i];
        if (array[i]>flag) t[q--]=array[i];
    }
    
    //现在，[l,p-1]全是比flag小的，[q+1,r]全是比flag大的
    for (int i=l;i<=p-1;i++)
        array[i]=t[i];
    for (int i=p;i<=q;i++)    //与flag值相同的元素
        array[i]=flag;
    for (int i=q+1;i<=r;i++)
        array[i]=t[i];
    quicksort(l,p-1); 
    quicksort(q+1,r);
}