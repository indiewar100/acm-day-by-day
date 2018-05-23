#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct rec{int x,y,z;} edge[5000];

int fa[1000],n,m,t,ans;

bool operator <(rec a,rec b)
{
    return a.z<b.z;
}

int get(int x)
{
    if(x==fa[x])
        return x;
    return get(fa[x]);
}

int main()
{
    while(cin>>n&&n)
    {
        cin>>m;
        ans = 0;
        for(int i = 1;i <=m;i++)
        {
            cin>>edge[i].x>>edge[i].y>>edge[i].z;
        }
        for(int i = 1;i<=n;i++)
            fa[i] = i;
        sort(edge+1,edge+1+m);
        for(int i =1;i<=m;i++)
        {
            int x = get(edge[i].x);
            int y = get(edge[i].y);
             if(x==y)
                continue;
             fa[x] = y;
             ans += edge[i].z;
        }
        cout<<ans<<endl;
    }
}
