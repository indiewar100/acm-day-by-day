#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
    int x,y;
} p[500*500+50];
struct rec
{
    int x,y;
    double z;
} edge[1000005];

int fa[1005],n,m;
double ans[1000005];

bool operator <(rec a,rec b)
{
    return a.z<b.z;
}

int get(int x)
{
    if(x==fa[x])
    return x;
    return x = get(fa[x]);
}

double dis(point &a,point &b)
{
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main()
{
    int T,S,P;
    cin>>T;
    while(T--)
    {
        cin>>S>>P;
        memset(ans,0,sizeof ans);
         m = 0;
        for(int i =1;i<=P;i++)
        {
            cin>>p[i].x>>p[i].y;
        }
        for(int i = 1; i <= P; i++)
            for(int j = i + 1; j <= P; j++)
            {
                m++;
                edge[m].x = i,edge[m].y = j,edge[m].z = dis(p[i],p[j]);
                m++;
                edge[m].x = j,edge[m].y = i,edge[m].z = dis(p[i],p[j]);
            }
        sort(edge+1, edge+m+1);
        for(int i =1 ;i<=P;i++)
            fa[i] = i;
            int t;
            t = 0;
        for(int i =1;i<=m;i++)
        {
            int x = get(edge[i].x);
            int y = get(edge[i].y);
            if(x==y)
                continue;
            fa[x] = y;
            ans[t++] = edge[i].z;
            //cout<<ans[i]<<endl;
        }
        sort(ans,ans+t);
        printf("%.2f\n",ans[P-S-1]);
    }
}
