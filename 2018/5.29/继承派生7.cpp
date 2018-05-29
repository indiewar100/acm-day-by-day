#include <bits/stdc++.h>
using namespace std;

class CDate
{
    private:
        int year,month,day;
    public:
        CDate()
        {
            year = 2015;
            month = 5;
            day = 25;
            cout<<"Function #1 is called!"<<endl;
        };
        CDate(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;
           cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
            printf("%d-%d-%d\n",year,month,day);
            cout<<"Function #3 is called!"<<endl;
        };
};

class Person:public CDate
{
    private:
        char name[20];
        int score;
    public:
        Person():CDate()
        {
            strcpy(name,"Unknown");
            score = 0;
            cout<<"Function #4 is called!"<<endl;
        };
        Person(char *n,int s,int y,int m,int d):CDate(y,m,d)
        {
            strcpy(name,n);
            score = s;
            cout<<"Function #5 is called!"<<endl;
        };
        Person(char *n,int s,CDate d):CDate(d)
        {
            strcpy(name,n);
            score = s;
            cout<<"Function #6 is called!"<<endl;
        };
        Person(char *n,int s):CDate()
        {
            strcpy(name,n);
            score = s;
            cout<<"Function #7 is called!"<<endl;
        };
        Person(CDate d):CDate(d)
        {
            strcpy(name,"Unknown");
            score = 0;
            cout<<"Function #8 is called!"<<endl;
        };
        void Show()
        {
            printf("Name:%s  score:%d birth:",name,score);
            CDate::Show();
            cout<<"Function #9 is called!"<<endl;
        };
};

int main()
{
    int year,month,day,score,cas=0;
    char name[20];
    CDate d0;
    Person p0;
    cout<<"D0:";    d0.Show();
    cout<<"P0:";    p0.Show();
    while(cin>>name>>score>>year>>month>>day)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        CDate d1(year,month,day);
        Person p1(name,score,year,month,day);
        Person p2(name,score,d1);
        Person p3(name,score);
        Person p4(d1);
        cout<<"D1:";    d1.Show();
        cout<<"P1:";    p1.Show();
        cout<<"P2:";    p2.Show();
        cout<<"P3:";    p3.Show();
        cout<<"P4:";    p4.Show();
    }
    return 0;
}
