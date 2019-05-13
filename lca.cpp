//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
std::vector<ll> v[100002];
ll visited[100002];
ll par[100002],depth[100002];
void dfs(ll n,ll d)
{
	visited[n]=1;
	depth[n]=d;
	for (int i = 0; i < v[n].size(); ++i)
	{
		dfs(v[n][i],d+1);
	}
}
ll p[100002][19];
ll lca(ll N)  //Nlogn
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 19; ++j)
		{
			p[i][j]=-1;
		}
	}
	for (int i = 1; i <=N; ++i)
	{
		p[i][0]=par[i];
		// cout<<par[i]<<'\n';
	}
	for (int i = 1; i < 19; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(p[j][i-1]!=-1)
			{
				p[j][i]=p[p[j][i-1]][i-1];
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for (int i = 1; i <=n; ++i)
    {
    	ll a;
    	cin>>a;
    	if(a==0)
    	{
    		par[i]=-1;
    		continue;
    	}
    	v[a].pb(i);
    	par[i]=a;
    }
    for (int i = 0; i <=n; ++i)
    {
    	if(visited[i]==0)
    	{
    		// cout<<i<<'\n';
    		dfs(i,0);
    	}
    }
    lca(n);
    // for (int i = 1; i <=n; ++i)
    // {
    // 	 code 
    // 	cout<<p[i][0]<<" "<<p[i][1]<<'\n';
    // }
    // cout<<'\n';
    // dfs(1,0);
    ll q;
    cin>>q;
    while(q--)
    {
    	ll v,parent;
    	cin>>v>>parent;
    	ll pthancestor=v,x=0;
    	while(parent)
    	{
    		if(parent%2==1)
    		{
    			pthancestor=p[pthancestor][x];
    		}
    		x++;
    		parent/=2;
    	}
    	
    }
}
