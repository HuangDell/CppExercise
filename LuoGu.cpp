#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
ll dp[30][30][30]={0};
ll w(ll a,ll b,ll c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	else if(a>=20 || b>=20 || c>=20)
		return w(20,20,20);
		
	else if(a<b && b<c)
		return w(a,b,c-1)+w(a,b-1,c-1)+w(a,b-1,c);
	else 
		return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	ll a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if(a==-1 &&b==-1 && c==-1)
		break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	}
}