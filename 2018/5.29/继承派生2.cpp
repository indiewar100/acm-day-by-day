#include<bits/stdc++.h>
using namespace std;

class Point
{
    private:
        int x,y;
    public:
        Point()
        {
            x = 0;
            y = 0;
            cout<<"Function #1 is called!"<<endl;
        };
        Point(int xx,int yy)
        {
            x = xx;
            y = yy;
            cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
            printf("(%d,%d)\n",x,y);
            cout<<"Function #3 is called!"<<endl;
        };
};
class Circle:public Point
{
    private:
        int radius;
    public:
        Circle():
            Point(1000,1000)
        {
                radius = 0;
                cout<<"Function #4 is called!"<<endl;
        };
        Circle(int x,int y,int r):
            Point(x,y)
        {
            radius = r;
            cout<<"Function #5 is called!"<<endl;
        };
        Circle(Point p,int r):
            Point(p)
        {
            radius = r;
            cout<<"Function #6 is called!"<<endl;
        };
        Circle(int r):Point(100,100){radius = r;cout<<"Function #7 is called!"<<endl;};
        Circle(Point p):Point(p){radius = 10;cout<<"Function #8 is called!"<<endl;};
        void Show()
        {
            printf(" Radius=%d Center=",radius);
            Point::Show();
            cout<<"Function #9 is called!"<<endl;
        };
};
int main()
{
    int x,y,r;
    int cas=0;
    Point p0;
    Circle c0;
    cout<<"Point 0: "; p0.Show();
    cout<<"Circle0: ";  c0.Show();
    while(cin>>x>>y>>r)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        Point p1(x,y);
        Circle c1(x+5,y+5,r);
        Circle c2(p1,r);
        Circle c3(r);
        Circle c4(p1);
        cout<<"Point 1: "; p1.Show();
        cout<<"Circle1: "; c1.Show();
        cout<<"Circle2: "; c2.Show();
        cout<<"Circle3: "; c3.Show();
        cout<<"Circle4: "; c4.Show();
    }
    return 0;
}
