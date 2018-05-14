//#include<bits/stdc++.h>
//copy by hzwer
//叉积加二分
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct point{int x,y;};
struct segment{point a,b;}s[5001];
int n,m,ans[5001];
point sub(point a,point b)
{point t;t.x=a.x-b.x;t.y=a.y-b.y;return t;}
int cross(point a,point b)
{return a.x*b.y-b.x*a.y;}//叉叉
int turn(point p1,point p2,point p3)
{return cross(sub(p2,p1),sub(p3,p1));}
void search(point x)
{
	int l=1,r=n,mid,t=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(turn(s[mid].a,s[mid].b,x)>=0){t=mid;l=mid+1;}
		else r=mid-1;
	}
	ans[t]++;
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(ans,0,sizeof(ans));
		int x1,x2,y1,y2,t1,t2;
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&t1,&t2);
			s[i].a.x=t1;s[i].a.y=y1;
			s[i].b.x=t2;s[i].b.y=y2;
		}
		for(int i=1;i<=m;i++)
		{
			point t;
			scanf("%d%d",&t.x,&t.y);
			search(t);
		}
		for(int i=0;i<=n;i++)
		   printf("%d: %d\n",i,ans[i]);
        printf("\n");
	}
	return 0;
}
