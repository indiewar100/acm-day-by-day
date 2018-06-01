#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;


int n,q,a[maxn];
struct node
{
    int l,r,mn;
} tr[maxn*4];

void build(int x,int l,int r)
{
    tr[x].l=l;
    tr[x].r=r;
    if(l==r)
    {
        tr[x].mn=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    tr[x].mn=max(tr[x<<1].mn,tr[x<<1|1].mn);
}

int query(int k,int s,int t)
{
    int l=tr[k].l,r=tr[k].r;
    if(s==l&&t==r)
        return tr[k].mn;
    int mid=(l+r)>>1;
    if(t<=mid)
        return query(k<<1,s,t);
    if(s>mid)
        return query(k<<1|1,s,t);
    return max(query(k<<1,s,mid),query(k<<1|1,mid+1,t));
}

void update(int k,int x,int y)
{
    int l=tr[k].l,r=tr[k].r;
    if(l==r)
    {
        tr[k].mn=y;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        update(k<<1,x,y);
    if(x>mid)
        update(k<<1|1,x,y);
    tr[k].mn=max(tr[k<<1].mn,tr[k<<1|1].mn);
}

int main()
{
    char str;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        build(1,1,n);
        for(int i = 1; i<=q; i++)
        {
            cin>>str;
            int l,r;
            scanf("%d%d",&l,&r);
            if(str=='Q')
                printf("%d\n",query(1,l,r));
            else
                update(1,l,r);
        }
    }
}
