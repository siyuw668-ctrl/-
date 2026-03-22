/*模板：全排列*/
/*
#include <bits/stdc++.h>
using namespace std;

int n;
bool st[10];
int path[10];

void dfs(int u)
{
	if(u>n)
	{
		for(int i=1;i<=n;++i)
		{
			cout<<path[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(st[i]) continue;
		st[i]=true;
		path[u]=i;
		dfs(u+1);
		st[i]=false;
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
*/

/*lg P8599 
[蓝桥杯 2013 省 B] 带分数*/
/*法一：手写dfs生成全排列*/
/* 
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n,ans; 
int path[10];
bool st[10];

ll calc(int l,int r)
{
	ll res=0;
	for(int i=l;i<=r;++i)
	{
		res=res*10+path[i];
	}
	return res;
}
void dfs(int u)
{
	if(u>9)
	{
		for(int i=1;i<=7;++i)
		{
			for(int j=i+1;j<=8;++j)
			{
				ll a=calc(1,i);
				ll b=calc(i+1,j);
				ll c=calc(j+1,9);
				if(n*c==a*c+b) ans++;
			}
		}
		return;
	}
	for(int i=1;i<=9;++i)
	{
		if(st[i]) continue;
		st[i]=true;
		path[u]=i;
		dfs(u+1);
		st[i]=false;
	}
}

int main()
{
	cin>>n;
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
*
/*法二：使用next_permutation()函数生成全排列*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ans;
int path[]={1,2,3,4,5,6,7,8,9};

ll calc(int l,int r)
{
	ll res=0;
	for(int i=l;i<=r;++i)
	{
		res=res*10+path[i];
	}
	return res;
}
int main()
{
	cin>>n;
	sort(path,path+9);
	do
	{
		for(int i=0;i<=6;++i)
		{
			for(int j=i+1;j<=7;++j)
			{
				ll a=calc(0,i);
				ll b=calc(i+1,j);
				ll c=calc(j+1,8);
				if(n*c==a*c+b) ans++;
			}
		}
	}
	while(next_permutation(path,path+9));
	cout<<ans<<'\n';
	return 0;
}
*/

/*lg P1618 
三连击（升级版*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c;
int num[]={1,2,3,4,5,6,7,8,9};
bool found=false;

int main()
{
	cin>>a>>b>>c;
	if(a==0)
	{
		cout<<"No!!!"<<'\n';
		return 0;
	}
	do
	{
		int x=num[0]*100+num[1]*10+num[2];
		int y=num[3]*100+num[4]*10+num[5];
		int z=num[6]*100+num[7]*10+num[8];
		if(1ll*x*b==1ll*y*a&&1ll*y*c==1ll*z*b)
		{
			cout<<x<<' '<<y<<' '<<z<<'\n';
			found=true;
		}
	}
	while(next_permutation(num,num+9));
	if(!found) cout<<"No!!!"<<'\n';
	return 0;
}
*/

/*模板：子集枚举*/
/*
#include <bits/stdc++.h>
using namespace std;

int n;
bool st[16];

void dfs(int u)
{
	if(u>n)
	{
		for(int i=1;i<=n;++i)
		{
			if(st[i]) cout<<i<<' ';
		}
		cout<<'\n';
		return;
	}
	st[u]=false;
	dfs(u+1);
	st[u]=true;
	dfs(u+1);
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
*/

/*删数游戏*/
/*
#include <bits/stdc++.h>
using namespace std;

const int N=1e9+10;
int n,ans;
string s;
bool st[15];

bool isprime(int x)
{
	if(x<=1) return false;
	for(int i=2;i<=x/i;++i)
	{
		if(x%i==0) return false;
	}
	return true;
}

void dfs(int u)
{
	if(u>n)
	{
		int x=0;
		for(int i=1;i<=n;++i)
		{
			if(st[i]) x=x*10+(s[i-1]-'0');
		}
		if(isprime(x)) ans++;
		return;
	}
	st[u]=false;
	dfs(u+1);
	st[u]=true;
	dfs(u+1);
}
int main()
{
	cin>>n;
	s=to_string(n);
	n=s.size();
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
*/

/*模板：组合枚举*/
/*
#include <bits/stdc++.h>
using namespace std;

int n,m;
int path[30];

void dfs(int u,int start)
{
	if(m-u>n-start+1) return; 
	if(u>m)
	{
		for(int i=1;i<=m;++i)
		{
			cout<<path[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=start;i<=n;++i)
	{
		path[u]=i;
		dfs(u+1,i+1);
	}
}
int main()
{
	cin>>n>>m;
	dfs(1,1);
	return 0;
}
*/

/*选数*/
#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
int x[25];
int path[25];

bool isprime(int x)
{
	if(x<=1) return false;
	for(int i=2;i<=n/i;++i)
	{
		if(x%i==0) return false;
	}
	return true;
}

void dfs (int u,int start)
{
	if(u>k)
	{
		int sum=0;
		for(int i=1;i<=k;++i)
		{
			sum+=path[i];
		}
		if(isprime(sum)) ans++;
	}
	for(int i=start;i<=n;++i)
	{
		path[u]=x[i];
		dfs(u+1,i+1);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
