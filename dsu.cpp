#include<bits/stdc++.h>
using namespace std;
int par[100002];
int size[100002];
int findpar(int x)
{
	if(par[x]==x) return x;

	par[x]=findpar(par[x]);
	return par[x];
}	
int merge(int a,int b)
{
	int A=findpar(a);
	int B=findpar(b);
	if(A==B)
	{
		return 0 ;
	}
	else
	{
		if(size[A]>size[B])
		{
			par[B]=par[A];
			size[A]+=size[B];
		}
		else
		{
			par[A]=par[B] ;
			size[B]+=size[A] ;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	int a,b;
	int arr[100002][4];
	for (int i = 1; i <=n; ++i)
	{
		par[i]=i;
		size[i]=1;
	}
	int ans=0;
	set<int> ss;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a>>b;
		int ll=merge(a,b);
		if(ll==0)
		{
			arr[ans][0]=a;
			arr[ans][1]=b;
			ans++;
		}
	}
	cout<<ans<<endl;
	for (int i = 1; i <=n; ++i)
	{
		par[i]=findpar(i);
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout<<par[i]<<" ";
	// }
	// cout<<endl;
	for (int i = 1; i <=n; ++i)
	{
		ss.insert(par[i]);
	}
	// if(ans!=0)
	// 	cout<<arr[0][0]<<" "<<arr[0][1]<<" "<<arr[0][2]<<" "<<arr[1][2]<<endl;
	// cout<<endl;
	set<int>:: iterator it;
		it=ss.begin();
	for (int i = 0; i < ans; ++i)
	{
		cout<<arr[i][0]<<" "<<arr[i][1]<<" ";
		cout<<*it<<" ";
		it++;
		cout<<*it<<endl;
	}
}