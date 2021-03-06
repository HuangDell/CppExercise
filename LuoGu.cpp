#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct node{
	int l,r;
}a[1001000];//记录每个节点的左右节点
int Max=-1,n;
void dfs(int root,int step){
	if(root==0) return;//如果该节点为0（即上它的爸爸没有这个儿子），返回
	Max=max(Max,step);//记录最大值
	dfs(a[root].l,step+1);//搜索它的左儿子
	dfs(a[root].r,step+1);//搜索它的右儿子
}
int main(){
	cin>>n;//输入n
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;//输入该节点的左节点和右节点
	}
	dfs(1,1);//从1号节点，深度为1开始搜索 
	cout<<Max;//输出最大值
	return 0;
}