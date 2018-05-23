//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct rec
{
    int x,y,z;
} edge[10001];//开小会re

int fa[1001],n,m,t, ans;

bool operator <(rec a,rec b)
{
    return a.z<b.z;
}

int get(int x)
{
    if(x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}
int main()
{

    while(cin>>n)
    {
        ans = 0;
        m = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
            {
                cin>>t;
                if(t)
                {
                    m++;
                    edge[m].x = i,edge[m].y = j,edge[m].z = t;
                }
            }
        sort(edge+1,edge+m+1);
        for(int i = 1; i<=n; i++)
            fa[i] = i;
        for(int i = 1; i<=m; i++)
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
