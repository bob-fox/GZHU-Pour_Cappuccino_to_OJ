/*--waltz26--*/

string base10_to_basek(long long n,int base)   
{
    string ans="";
    do
    {
	    int t=n%base;
	    if(t>=0&&t<=9)	ans+=t+'0';
	    else ans+=t-10+'A';
	    n/=base;
    } while(n!=0);	
    reverse(ans.begin(),ans.end());
    return ans;
}