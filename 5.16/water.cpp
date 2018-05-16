#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t,tx,ans;
    ans = 0;
    scanf("%d",&n);
    t = 0;
    tx = 0;
    for(int i  =1; i<=n; i++)
    {
        scanf("%d",&m);
        if(m)
        {
            if(tx)
            t -=pow(2,tx-1);
            if(t<0)
                t = 0;
            t++;
            tx = 0;
        if(t>=1&&t<3)
            ans++;
        else if(t>=3&&t<7)
            ans+=2;
        else if(t>=7&&t<30)
            ans+=3;
        else if(t>=30&&t<120)
            ans+=4;
        else if(t>=120&&t<365)
            ans+=5;
        else if(t>=365)
            ans+=6;
        }
        else
        {
            tx++;
        }
    }
    cout<<ans<<endl;
}
