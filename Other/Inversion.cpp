/*--waltz26--*/


//归并排序求逆序对
int a[maxn],p[maxn];
long long ans=0;

void msort(int l,int r)
{
    if(l>=r) return;

    int mid=l+r>>1;
    msort(l,mid);
    msort(mid+1,r);

    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j]) 
            p[k++]=a[i++];//先赋值再+1 
        else 
            {p[k++]=a[j++]; ans+=(long long)mid-i+1;}

    while(i<=mid) p[k]=a[i],k++,i++;
    while(j<=r) p[k]=a[j],k++,j++;
    for(int i=l;i<=r;i++) 
        a[i]=p[i];
}