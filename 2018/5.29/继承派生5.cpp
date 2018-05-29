#include <bits/stdc++.h>
using namespace std;

class Point
{
    private:
        int x,y;
    public:
        Point()
        {
            x = y = 0;
             cout<<"Function #1 is called!"<<endl;
        };
        Point(int xx,int yy):x(xx),y(yy)
        {
             cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
           printf("(%d,%d)\n",x,y);
             cout<<"Function #3 is called!"<<endl;
        };
};

class Rectangle:public Point
{
    private:
        int width,height;
    public:
        Rectangle():Point(1000,1000)
        {
            width = height = 0;
             cout<<"Function #4 is called!"<<endl;
        };
        Rectangle(int x,int y,int w,int h):Point(x,y)
        {
            width = w;
            height = h;
             cout<<"Function #5 is called!"<<endl;
        };
        Rectangle(Point p,int w,int h):Point(p)
        {
             width = w;
            height = h;
             cout<<"Function #6 is called!"<<endl;
        };
        Rectangle(int w,int h):Point(100,100)
        {
             width = w;
            height = h;
             cout<<"Function #7 is called!"<<endl;
        };
        Rectangle(Point p):Point(p)
        {
             width = 10;
            height = 10;
             cout<<"Function #8 is called!"<<endl;
        };
        void Show()
        {
             printf("Width=%d Height=%d Left_Up=",width,height);
             Point::Show();
             cout<<"Function #9 is called!"<<endl;
        };
};
int main()
{
    int x,y,w,h;
    int cas=0;
    Point p0;
    Rectangle r0;
    cout<<"Point    0: "; p0.Show();
    cout<<"Rectangle0: ";  r0.Show();
    while(cin>>x>>y>>w>>h)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        Point p1(x,y);
        Rectangle r1(x+5,y+5,w,h);
        Rectangle r2(p1,w,h);
        Rectangle r3(w,h);
        Rectangle r4(p1);
        cout<<"Point    1: "; p1.Show();
        cout<<"Rectangle1: "; r1.Show();
        cout<<"Rectangle2: "; r2.Show();
        cout<<"Rectangle3: "; r3.Show();
        cout<<"Rectangle4: "; r4.Show();
    }
    return 0;
}
