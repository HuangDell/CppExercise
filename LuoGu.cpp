#include<iostream>
#include<vector>
using namespace std;
bool *pick;
bool isPrimer(int num)
{
	for(int i=2;i*i<=num;i++)
		if(num%i==0)
		return false;
	return true;
}
int sum=0,an=0;
void funct(int n,int k,vector<int>& num,int head=0)
{
	if (k == 0)
	{
		if(isPrimer(sum))
		an++;
		return ;
	}
	for(int i=head;i<n;i++)
	{
		if(!pick[i] && n-i>=k)
		{
			sum += num[i];
			pick[i] = true;
			funct(n, k - 1, num,i+1);
			pick[i] = false;
			sum-=num[i];
		}
	}
}

int main(void)
{
	int n,k;
	int temp;
	cin>>n>>k;
	vector<int> num;
	pick=new bool[n];
	for(int i=0;i<n;i++)
	pick[i]=false;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		num.push_back(temp);
	}
	funct(n,k,num);
	printf("%d",an);
}