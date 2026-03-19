/*lg B3883*/ 
/*
#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

bool check(int x)
{
	string s=to_string(x);
	int l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		if(check(i)) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
*/

/*LQ 19709*/
/*
#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

bool check(int x)
{
	int l=1;
	int d=0;
	while(x)
	{
		d=x%10;
		if(d%2!=l%2) return false;
		x/=10;
		l++;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		if(check(i)) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int t,n,k;
int a[N];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;++i) cin>>a[i];
		int ans=n;
		for(int i=1;i<=60;++i)
		{
			int cnt=0;
			for(int j=1;j<=n;)
			{
				if(a[j]!=i)
				{
					j=j+k-1;
					++cnt; 
				}
				++j;
			}
			ans=min(cnt,ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
