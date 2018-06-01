#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 1e5+7;

int n,a[maxn],q;
struct node
{
    int l,r;
    int sum,lazy;
    void update(int x)
    {
        sum+=(r-l+1)*x;
        lazy += x;

    }
} tree[maxn*4];

void push_up(int  x)
{
    tree[x].sum = tree[x<<1].sum+tree[x<<1|1].sum;
}

void push_down(int x)
{
    int lazyval = tree[x].lazy;
    if(tree[x].lazy)
    {
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        tree[x].lazy = 0;
    }
}

void build(int x,int l,int r)
{
    tree[x].l = l,tree[x].r = r;
    tree[x].sum = tree[x].lazy = 0;
    if(l==r)
    {
        tree[x].sum = a[l];
    }
    else
    {
        int mid = (l+r)/2;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}

void update(int x,int l,int val)
{
    int L = tree[x].l, R = tree[x].r;
    if(l==L&&R==l)
    {
        tree[x].update(val);
    }
    else
    {
        push_down(x);
        int mid = (L+R)/2;
        if(mid>=l) update(x<<1,l,val);
        else update(x<<1|1,l,val);
        push_up(x);
    }
}
long long  query(int x,int l,int r)
{
    int L = tree[x].l, R = tree[x].r;
    if(l<=L&&R<=r)
        return tree[x].sum;
    else
    {
        push_down(x);
        int mid = (L+R)/2;
        long long ans = 0;
        if(mid>=l)
            ans+= query(x<<1,l,r);
        if(mid<r)
            ans += query(x<<1|1,l,r);
        push_up(x);
        return ans;
    }
}
int main()
{
    int T;
    string str;
    scanf("%d",&T);
    for(int t =1;t<=T;t++)
    {
        printf("Case %d:\n",t);
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,1,n);
        while(cin>>str&&str[0]!='E')
        {
            int r,l;
             scanf("%d%d",&l,&r);
            if(str[0]=='A')
           {

               update(1,l,r);
           }
            else if(str[0]=='S')
               {
               update(1,l,-r);
           }
            else if(str[0]=='Q')
                printf("%d\n",query(1,l,r));
        }
    }
}
