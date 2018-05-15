//问题转化为问是否存在一条线和所有线段相交；
//该直线必定经过这些线段的某两个端点(较难理解的地方，重点是该直线可以任意变化）
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;
int T,n;
bool flag;
struct point
{
    double x,y;
};
struct seg
{
    point a,b;
} s[101];
point sub(point a,point b)
{
    point t;
    t.x=a.x-b.x;
    t.y=a.y-b.y;
    return t;
}
double cross(point a,point b)
{
    return a.x*b.y-b.x*a.y;
}
double turn(point p1,point p2,point p3)
{
    return cross(sub(p2,p1),sub(p3,p1));
}
bool equ(double x,double y)
{
    if(fabs(x-y)<eps)
        return 1;
    return 0;
}
bool jud(point a,point b)
{
    if(equ(a.x,b.x)&&equ(a.y,b.y))
        return 0;
    for(int i=1; i<=n; i++)
        if(turn(a,b,s[i].a)*turn(a,b,s[i].b)>eps)
            return 0;
    return 1;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i = 1;i<=n;i++)
            cin>>s[i].a.x>>s[i].a.y>>s[i].b.x>>s[i].b.y;
            flag = 0;
            for(int i = 1;i<=n;i++)
                if(!flag)
                for(int j =1;j<=n;j++)
            {
                if(jud(s[i].a,s[j].a))
                {
                    flag = 1;
                    break;
                }
                if(jud(s[i].a,s[j].b))
                {
                    flag = 1;
                    break;
                }
                if(jud(s[i].b,s[j].a))
                {
                    flag = 1;
                    break;
                }
                if(jud(s[i].b,s[j].b))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                cout<<"Yes!"<<endl;
            else
                cout<<"No!"<<endl;
    }
    return 0;

}
