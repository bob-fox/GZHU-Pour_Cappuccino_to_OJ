/*--waltz26--*/


//二路归并
void mergesort(int l,int r)
{
    if (l>=r) return;    //空区间或者只有一个元素的区间

    int mid=(l+r)/2;
    mergesort(l,mid); 
    mergesort(mid+1,r);

    int i=l,j=mid+1,k=l;
    while (i<=mid&&j<=r)
    {
        if (array[i]<array[j]) p[k++]=array[i++];
        else p[k++]=array[j++];
    }
    
    while (i<=mid) p[k++]=array[i++];
    while (j<=r) p[k++]=array[j++];
    for (int i=l;i<=r;i++)
        array[i]=p[i];
}