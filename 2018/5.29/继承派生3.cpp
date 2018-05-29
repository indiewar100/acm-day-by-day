#include <bits/stdc++.h>
using namespace std;

class CPU
{
    private:
        char factory[40];
        char type[40];
    public:
        CPU()
        {
            strcpy(factory,"Unknown");
            strcpy(type,"Unknown");
            cout<<"Function #1 is called!"<<endl;
        };
        CPU(char *f,char *t)
        {
            strcpy(factory,f);
            strcpy(type,t);
            cout<<"Function #2 is called!"<<endl;
        };
        void Show()
        {
            cout<<factory<<" "<<type<<endl;
            cout<<"Function #3 is called!"<<endl;
        };
};

class Computer:public CPU
{
    private:
        char factory[40];
        char type[40];
        int ram;
        int price;
    public:
        Computer():CPU(),ram(0),price(0)
        {
            strcpy(factory,"Unknown");
            strcpy(type,"Unknown");
            cout<<"Function #4 is called!"<<endl;
        };
        Computer(char *s1,char *s2,int r,int p,char *s3,char *s4):CPU(s3,s4),ram(r),price(p)
        {
            strcpy(factory,s1);
            strcpy(type,s2);
            cout<<"Function #5 is called!"<<endl;
        };
        Computer(char *s1,char *s2,int r,int p,CPU c):CPU(c),ram(r),price(p)
        {
           strcpy(factory,s1);
            strcpy(type,s2);
             cout<<"Function #6 is called!"<<endl;
        };
        Computer(char *s1,char *s2,int r,int p):CPU(),ram(r),price(p)
        {
             strcpy(factory,s1);
            strcpy(type,s2);
            cout<<"Function #7 is called!"<<endl;
        };
        Computer(CPU c):CPU(c),ram(0),price(0)
        {
            strcpy(factory,"Unknown");
            strcpy(type,"Unknown");
            cout<<"Function #8 is called!"<<endl;
        };
        void Show()
        {
            cout<<"品牌:"<<factory<<" 型号:"<<type;

            printf(" 内存:%dG  价格:%d元 CPU:",ram,price);
            CPU::Show();
            cout<<"Function #9 is called!"<<endl;
        };
};

int main()
{
    char s1[40],s2[40],s3[40],s4[40];
    int r,p;
    int cas=0;
    CPU cpu0;
    Computer computer0;
    cout<<"CPU 0:"; cpu0.Show();
    cout<<"Computer0: ";  computer0.Show();
    while(cin>>s1>>s2>>r>>p>>s3>>s4)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        CPU cpu1(s3,s4);
        Computer computer1(s1,s2,r,p,s3,s4);
        Computer computer2(s1,s2,r,p,cpu1);
        Computer computer3(s1,s2,r,p);
        Computer computer4(cpu1);
        cout<<"CPU 1: "; cpu1.Show();
        cout<<"Computer1: "; computer1.Show();
        cout<<"Computer2: "; computer2.Show();
        cout<<"Computer3: "; computer3.Show();
        cout<<"Computer4: "; computer4.Show();
    }
    return 0;
}
