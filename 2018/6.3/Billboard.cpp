#include <bits/stdc++.h>
using namespace std;
#define maxn 200010

struct nopde
{
    int l,r,mx;
} tree[maxn*4];

int h,w,n,d;

void build( int x,int l,int r)
{
    tree[x].l = l,tree[x].r = r;
    tree[x].mx = w;
    if(l == r)
        return ;
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}

int update(int x,int val)
{
    int l = tree[x].l,r = tree[x].r;
    if( l == r)
    {
        tree[x].mx -= val;
        return l;
    }
    else
    {
        int ans = 0;
        if(tree[x<<1].mx>=val)
            ans = update(x<<1,val);
        else
            ans = update(x<<1|1,val);
        tree[x].mx = max(tree[x<<1].mx,tree[x<<1|1].mx);
        return ans;
    }
}


int main()
{
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        memset(tree,0,sizeof tree);
        build(1,1,min(h,maxn));
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&d);
            if(tree[1].mx<d)
                cout<<"-1"<<endl;
            else
                cout<<update(1,d)<<endl;
        }
    }
    return 0;
}
