#include <bits/stdc++.h>
using namespace std;
int check (int N, int i)
    {
        if( N & (1 << i) )
            return 1;
        else
            return 0;
    }
int main() {
	int n,q;
	cin >> n >>q;
	long long int a[n],b[31][n],sum,i,j;
	for(int i=0;i<n;i++)
	{
	cin >> a[i];
	}
	for(j=0;j<31;j++)
	{
	for(int i=0;i<n;i++)
	{
	b[j][i]=0;
	}
	}
	for(i=0;i<31;i++)
	{
	    sum=0;
	    for(j=0;j<n;j++)
	    {
	    b[i][j]=check (a[j],i);
	    sum+=b[i][j];
	    b[i][j]=sum;
	    }
	}
	while(q--)
	{
	    long long int l,r,k,c,x=0;
	    cin >> l >>r;
	for(i=0;i<31;i++)
	{   
	    if(l-2>=0)
	    c=b[i][r-1]-b[i][l-2];
	    else
	    c=b[i][r-1];
	    if(c<ceil(double(r-l+1)/2))
	    k=1;
	    else
	    k=0;
	    if(k)
	    x+=pow(2,i);
	}
	cout << x << endl;
	}
	return 0;
} 
