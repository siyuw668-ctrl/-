/*lg B2142
求 1+2+3+...+N 的值*/
/*
#include <bits/stdc++.h>

using namespace std;

int n;

int f(int x)
{
	if(x==1) return 1;
	return f(x-1)+x;
}
int main()
{
	cin>>n;
	cout<<f(n)<<'\n';
	return 0;
}
*/
/*lg B2147 
求 f(x,n)*/
/*
#include <bits/stdc++.h>

using namespace std;

double x,n;

double f(double x,double n)
{
	if(n==1) return sqrt(n+x);
	return sqrt(n+f(x,n-1));
}
int main()
{
	cin>>x>>n;
	cout<<fixed<<setprecision(2)<<f(x,n)<<'\n';
	return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

int n,k;

int f(int n)
{
	if(n-k>0&&(n-k)%2==0) return f((n+k)/2)+f((n-k)/2);
	return 1;
}

int main()
{
	cin>>n>>k;
	cout<<f(n)<<'\n';
	return 0;
}
