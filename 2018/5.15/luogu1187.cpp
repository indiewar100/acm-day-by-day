#include <bits/stdc++.h>
using namespace std;
int ma[1005][1005];
int main()
{
    int n,m,ans;
    while(cin>>n>>m)
    {
        ans = 0;
        for(int i =1; i<=n; i++)
        {
            string s;
            cin>>s;
            for(int j =1; j<=m; j++)
            {
                ma[i][j]=s[j-1]-'0';
            }
        }
        /*for(int i =1; i<=n; i++)
            for(int j =1; j<=m; j++)
                cout<<ma[i][j]<<" ";*/
        for(int i =1; i<=n; i++)
            for(int j =1; j<=m; j++)
            {
                if(!ma[i][j])
                    continue;
                ans += ma[i][j]*4+2;
                if (i > 1)
                    ans -= 2 * min(ma[i][j],ma[i - 1][j]);
                if (j > 1)
                    ans -= 2 * min(ma[i][j],ma[i][j - 1]);
            }
            cout<<ans<<endl;
    }
    return 0;
}
