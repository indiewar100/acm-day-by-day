#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 200010
struct node
{
    int l,r;
    long long cnt,sum;
} tree[maxn*4];

int n,q;
long long a[maxn];

void build(int x,int l,int r)
{
    tree[x].l = l ,tree[x].r = r;
    tree[x].cnt = 0;
    if(l==r)
        tree[x].sum = a[l];
    else
    {
        int mid = (l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        tree[x].sum = tree[x<<1].sum+tree[x<<1|1].sum;
    }
}

void push_up(int x)
{
    tree[x].sum = tree[x<<1].sum+tree[x<<1|1].sum;
    if(tree[x<<1].cnt>=7&&tree[x<<1|1].cnt>=7)
        tree[x].cnt = 7;
}

void update(int x,int l,int r)
{
    int L = tree[x].l,R = tree[x].r;
    if(tree[x].cnt >= 7)
    {
        tree[x].sum = R - L +1;
        return ;
    }
    if(l<=L&&R<=r)
    {
        tree[x].cnt += 1;
        if(L == R)
            tree[x].sum = (long long)sqrt(tree[x].sum);
        else
        {
            update(x<<1,l,r);
            update(x<<1|1,l,r);
            push_up(x);
        }
    }
    else
    {
        int mid = (L+R)>>1;
        if(l<=mid)
            update(x<<1,l,r);
        if(r>mid)
            update(x<<1|1,l,r);
        push_up(x);
    }
}

long long query(int x,int l,int r)
{
    int L = tree[x].l, R = tree[x].r;
    if(l<=L&&R<=r)
        return tree[x].sum;
    else
    {
        int mid = (L+R)>>1;
        long long ans  = 0;
        if(l<=mid)
            ans+= query(x<<1,l,r);
        if(r>mid)
            ans+= query(x<<1|1,l,r);
        return ans;
    }
}
int f,l,r;
int main()
{
    int cas = 1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof a);
        memset(tree,0,sizeof tree);
        for(int i =1;i<=n;i++)
            scanf("%lld",&a[i]);
        printf("Case #%d:\n",cas++);
        scanf("%d",&q);
        build(1,1,n);
        for(int i =0;i<q;i++)
        {
            scanf("%d%d%d",&f,&l,&r);
            if(l>r) swap(l,r);
            if(f == 0)
                update(1,l,r);
            else
                printf("%lld\n",query(1,l,r));
        }
        cout<<endl;

    }
}
