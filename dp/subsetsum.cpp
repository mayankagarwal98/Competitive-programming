//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
//recurssion 

// ll n,a[10002];
// ll subsetsum(ll x, ll sum)
// {
// 	if(x==0)
// 	{
// 		if(sum==0)
// 			return 1;
// 		else 
// 			return 0;
// 	}
// 	return subsetsum(x-1,sum-a[x-1])|| subsetsum(x-1,sum);
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//     	cin>>n;
//     	ll sum=0;
//     	for (int i = 0; i < n; ++i)
//     	{
//     		cin>>a[i];
//     		sum+=a[i];	
//     	}
//     	if(sum%2!=0)
//     	{
//     		cout<<"NO"<<'\n';
//     		continue;
//     	}
//     	else
//     	{
//     		if(subsetsum(n,sum/2))
//     		{
//     			cout<<"YES"<<'\n';
//     		}
//     		else
//     		{
//     			cout<<"NO"<<'\n';
//     		}
//     	}
//     }

// }



//dp solution 
ll subset[102][100002];
int main()
{
	ll t;
	cin>>t;
	for (int i = 0; i <=100000; ++i)
	{
		subset[0][i]=0;
	}
	for (int i = 0; i <=100 ; ++i)
	{
		subset[i][0]=1;
	}
	while(t--)
	{
		ll n,a[1003];
		ll sum=0;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%2!=0)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		sum/=2;
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <=sum; ++j)
			{
				if(j<a[i-1])
				{
					subset[i][j]=subset[i-1][j];
				}
				else
				{
					subset[i][j]=subset[i-1][j] || subset[i-1][j-a[i-1]];
				}
			}
		}
		if(subset[n][sum])
		{
			cout<<"YES"<<'\n';
		}
		else
		{
			cout<<"NO"<<'\n';
		}
	}

}

