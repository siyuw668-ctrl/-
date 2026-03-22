/*lg B3696
[语言月赛202301] Hello, 2023*/
/*
#include <bits/stdc++.h>

using namespace std;

int x;

int main()
{
	cin>>x;
	cout<<((x%2023)+2023)%2023<<'\n';//cpp取模 
	return 0;
}
*/

/*lg B3953
[GESP202403 一级] 找因数*/
/*
#include <bits/stdc++.h>

using namespace std;

int a;

int main()
{
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		if(a%i==0) cout<<i<<'\n';
	}
	return 0;
} 
*/

/*lg B2127
求正整数 2 和 n 之间的完全数*/
/*
#include <bits/stdc++.h>

using namespace std;

int n;

bool check(int x)
{
	int sum=0;
	for(int i=1;i<x;i++)
	{
		if(x%i==0)
		{
			sum+=i;
		}
	}
	if(sum==x) return true;
	return false;
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(check(i)) cout<<i<<'\n';
	}
	return 0;
}
*/

/*模板：判断素数*/
/*
#include <bits/stdc++.h>

using namespace std;

int n;

bool check(int n)
{
	if(n==1) return false;
	for(int i=2;i<=n/i;++i)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	cin>>n;
	if(check(n)) cout<<"Yes";
	else cout<<"No";
	return 0;
}
*/

/*lg B2128
素数个数 
模板：埃氏筛*/
/*
#include <bits/stdc++.h>

using namespace std;

int n,ans;

vector<bool> isprime(50010,true);

int main()
{
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		if(isprime[i])
		{
			ans++; 
			if((long long)(i)*i>n) continue;
			for(int j=i*i;j<=n;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
*/

/*lg B2132 
素数对*/
/*
#include <bits/stdc++.h>

using namespace std;

int n;
bool b=false;//用于标记找没找到 

bool check(int x)
{
	if(x==1) return false;
	if(x==2) return true; 
	for(int i=2;i<=x/i;++i)
	{
		if(x%i==0) return false;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=3;i<=n;++i)
	{
		if(check(i-2)&&check(i))
		{
			cout<<i-2<<' '<<i<<'\n';
			b=true;
		}
	} 
	if(!b) cout<<"empty";
	return 0;
}
*/

/*模板：分解质因数*/
/*
#include <bits/stdc++.h>

using namespace std;

int l,r;

void divide(int x)
{
	vector<int> primes;
	cout<<x<<'=';
	for(int i=2;i<=x/i;++i)
	{
		while(x%i==0)//直到x不能再被i整除 
		{
			x/=i;
			primes.push_back(i);
		}
	}
	if(x>1) primes.push_back(x);//判断最后剩下的x有没有被分解完 
	for(int i=0;i<primes.size()-1;++i) cout<<primes[i]<<'*';//输出前n-1个元素和乘号 
	cout<<primes.back()<<'\n';//输出最后一个元素 
}
int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		divide(i);
	}
	return 0;
}
*/

/*模板：最大公约数*/
/*
#include <bits/stdc++.h>

using namespace std;

int a,b;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
*/

/*模板：最小公倍数*/
/*
#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int a,b;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	cin>>a>>b;
	cout<<1ll*a/gcd(a,b)*b<<'\n';//结果可能会溢出int，需要乘1ll转换long long类型 
	return 0;
} 
*/

/*求1~n的最小公倍数*/
/*
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int n;
map<int,int> mp;
long long ans=1;

void divide(int x)
{
	for(int i=2;i<=x/i;++i)
	{
		int cnt=0;
		while(x%i==0)
		{
			x/=i;
			cnt++;
		}
		mp[i]=max(mp[i],cnt);
	}
	if(x>1) mp[x]=max(mp[x],1);
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++) divide(i);
	for(auto key:mp)
	{
		int x=key.first,y=key.second;
		for(int i=1;i<=y;++i) ans=ans*x%mod;
	}
	cout<<ans<<'\n';
	return 0;
} 
*/

/*lg B2010 
带余除法*/
/*
#include <bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
	cin>>n>>m;
	cout<<n/m<<' '<<n%m;
	return 0;
}
*/

/*lg B2074 
计算星期几*/
/*
#include <bits/stdc++.h>

using namespace std;

int a,b,ans=1;
const string weekdays[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main()
{
	cin>>a>>b;
	for(int i=0;i<b;++i)
	{
		ans=ans*a;
		ans=ans%7;//边算边取模，防止数据溢出 
	}
	cout<<weekdays[ans]<<'\n';
	return 0;
}
*/

/*lg P12323
[蓝桥杯 2023 省 Java B] 阶乘求和*/

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

const ll mod=1e9;

int main()
{
	int sum=0;
	for(int i=1;i<=40;++i)
	{
		int n=1;
		n*=i;
		sum+=n;
		n%=mod;
		sum%=mod;
	}
	cout<<sum;
	return 0;
} 

/*lg P13928
[蓝桥杯 2022 省 Java B] 星期计算*/
/*
#include <bits/stdc++.h>

using namespace std;

const int weekdays[7]={6,7,1,2,3,4,5};

int main()
{
	int n=1;
	for(int i=1;i<=22;++i)
	{
		n*=20;
		n%=7;
	}
	cout<<weekdays[n];
	return 0;
}
*/
/*B3944
[语言月赛 202403] 传染病*/
/*
#include <bits/stdc++.h>

using namespace std;

long long k,a,q;
const int mod=722733748;

int main()
{
	cin>>k>>a>>q;
	long long ans=a;//累计感染人数 
	for(int i=1;i<=k-1;++i)
	{
		a*=q;
		ans*=a;
		ans%=mod 
		cout<<ans<<' '<<a<<'\n'; 
	}
	cout<<ans<<'\n';
	return 0;
}
*/

/*B2139
区间内的真素数*/
/*
#include <bits/stdc++.h>

using namespace std;

int m,n,cnt;

bool check(int x)
{
	if(x==1) return false;
	for(int i=2;i<=x/i;++i)
	{
		if(x%i==0) return false;
	}
	return true;
}
int main()
{
	cin>>m>>n;
	for(int i=m;i<=n;++i)
	{
		string s=to_string(i);
		reverse(s.begin(),s.end());
		int a=stoi(s);
		if(check(i)&&check(a))
		{
			if(cnt>0) cout<<','; //如果不是第一个数就先输出逗号 
			cnt++;
			cout<<i;
		}
	}
	if(cnt==0) cout<<"No";
	return 0;
}
*/
