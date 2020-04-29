/*--waltz26--*/


//string转int
long long basek_to_base10(string s,int base)
{
    long long ans=0;
    for(int i=0;i<s.size();i++)
    {
	    char t=s[i];
	    if(t>='0'&&t<='9') 
            ans=ans*base+t-'0';
	    else 
            ans=ans*base+t-'A'+10;
    }
    return ans;
}
