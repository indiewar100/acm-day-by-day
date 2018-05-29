#include <bits/stdc++.h>
using namespace std;

class Country
{
    private:
        char name[40];
        char capital[40];
        int population;
    public:
        Country(){strcpy(name,"Unknown");
        strcpy(capital,"Unknown");
        population  = 0;
        cout<<"Function #1 is called!"<<endl;
        };
        Country(char *n,char *c,int p)
        {
        strcpy(name,n);
        strcpy(capital,c);
        population  = p;
        cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
            cout<<"国家:"<<name<<"(首都:"<<capital;
            printf(" 人口:%d)\n",population);
            cout<<"Function #3 is called!"<<endl;
        };
};

class Province:public Country
{
    private:
        char name[40];
        char capital[40];
        int population;
    public:
        Province():Country(),population(0)
        {
        strcpy(name,"Unknown");
        strcpy(capital,"Unknown");
         cout<<"Function #4 is called!"<<endl;
        };
        Province(char *s1,char *s2,int p1,char *s3,char *s4,int p2):Country(s3,s4,p2),population(p1)
        {
           strcpy(name,s1);
           strcpy(capital,s2);
            cout<<"Function #5 is called!"<<endl;
        };
        Province(char *s1,char *s2,int p1,Country c):Country(c),population(p1)
        {
            strcpy(name,s1);
           strcpy(capital,s2);
           cout<<"Function #6 is called!"<<endl;
        };
        Province(char *s1,char *s2,int p1):Country(),population(p1)
        {
            strcpy(name,s1);
           strcpy(capital,s2);
           cout<<"Function #7 is called!"<<endl;
        };
        Province(Country c):Country(c),population(0)
            {
                strcpy(name,"Unknown");
        strcpy(capital,"Unknown");
        cout<<"Function #8 is called!"<<endl;
            };
        void Show()
        {
            printf("%s省:省会(%s),人口(%d),所在",name,capital,population);
            Country::Show();
            cout<<"Function #9 is called!"<<endl;
        };
};

int main()
{
    char s1[40],s2[40],s3[40],s4[40];
    int p1,p2;
    int cas=0;
    Country country0;
    Province province0;
    cout<<"Country 0:";  country0.Show();
    cout<<"Province0:";  province0.Show();
    while(cin>>s1>>s2>>p1>>s3>>s4>>p2)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        Country country1(s3,s4,p2);
        Province province1(s1,s2,p1,s3,s4,p2);
        Province province2(s1,s2,p1,country1);
        Province province3(s1,s2,p1);
        Province province4(country1);
        cout<<"Country 1:"; country1.Show();
        cout<<"Province1:"; province1.Show();
        cout<<"Province2:"; province2.Show();
        cout<<"Province3:"; province3.Show();
        cout<<"Province4:"; province4.Show();
    }
    return 0;
}
