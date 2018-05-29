#include <bits/stdc++.h>
using namespace std;
class Point
{
    private:
        int x,y;
    public:
        Point()
        {
            x = y  =0;
            cout<<"Function #1 is called!"<<endl;
        };
        Point(int xx,int yy)
        {
            x =xx;
            y = yy;
            cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
           printf("(%d,%d)\n",x,y);
           cout<<"Function #3 is called!"<<endl;
        };
        int GetX()
        {
            return x;
        };
        int GetY()
        {
            return y;
        };
};

class Three_dimensional:public Point
{
    private:
        int z;
    public:
        Three_dimensional():Point()
        {
            z = 0;
            cout<<"Function #4 is called!"<<endl;
        };
        Three_dimensional(int x,int y,int r):Point(x,y)
        {
            z = r;
            cout<<"Function #5 is called!"<<endl;
        };
        Three_dimensional(Point p,int r):Point(p)
        {
            z = r;
            cout<<"Function #6 is called!"<<endl;
        };
        Three_dimensional(int r):Point(100,100)
        {
            z = r;
            cout<<"Function #7 is called!"<<endl;
        };
        Three_dimensional(Point p):Point(p)
        {
            z = 10;
            cout<<"Function #8 is called!"<<endl;
        };
        void Show()
        {
            printf("(%d,%d,%d)\n",GetX(),GetY(),z);
            cout<<"Function #9 is called!"<<endl;
        };
};

int main()
{
    int x,y,z;
    int cas=0;
    Point p0;
    Three_dimensional t0;
    cout<<"Point 0: "; p0.Show();
    cout<<"Three_dimensional0: ";  t0.Show();
    while(cin>>x>>y>>z)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        Point p1(x,y);
        Three_dimensional t1(x,y,z);
        Three_dimensional t2(p1,z);
        Three_dimensional t3(z);
        Three_dimensional t4(p1);
        cout<<"Point 1: "; p1.Show();
        cout<<"Three_dimensional1: "; t1.Show();
        cout<<"Three_dimensional3: "; t2.Show();
        cout<<"Three_dimensional3: "; t3.Show();
        cout<<"Three_dimensional4: "; t4.Show();
    }
    return 0;
}
