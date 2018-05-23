#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
struct rec{int x,y,z;} edge[100001] ;

int n,m,ans;
int fa[10001];

bool operator <(rec a,rec b)
{
    return a.z<b.z;
}

int t;
int get(int x)
{
    if(x==fa[x])
        return x;
    return x = get(fa[x]);
}

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
        m = 0;
        ans = 0;
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
            for(int j =1;j<=n;j++)
        {
            scanf("%d",&t);
            if(t)
            {
                m++;
                edge[m].x = i,edge[m].y = j,edge[m].z = t;
            }
        }
        sort(edge+1,edge+m+1);
        for(int i = 1;i<=n;i++)
            fa[i] = i;
        for(int i = 1;i<=m;i++)
        {
            int x = get(edge[i].x);
            int y = get(edge[i].y);
            if(x==y)
                continue;
            fa[x] = y;
            if(ans<=edge[i].z)
            ans = edge[i].z;
        }
        cout<<ans<<endl;
        }
    }
}
