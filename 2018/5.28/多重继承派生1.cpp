#include <bits/stdc++.h>
using namespace std;

class Furniture
{
private:
    string type;
    string mat;
    int price;
public:
    Furniture(string ma,int pri)
    {
        this->type = "unknown";
         this->mat = ma;
         this->price = pri;
         cout<<"Function #1 is called!"<<endl;
    }
    string GetType()
    {
        return type;
    }
    string GetMat()
    {
        return mat;
    }
    int GetPrice()
    {
        return price;
    }
    void Show()
    {
        cout<<type<<"/"<<mat<<"/"<<price<<endl;
        cout<<"Function #2 is called!"<<endl;
    }
};

class Bed : virtual public Furniture
{
private:
 string bedtype;
public:
    Bed(string bedtype,string ma,int pr):
       Furniture(ma,pr)
    {
        this->bedtype = bedtype;
        cout<<"Function #3 is called!"<<endl;
    }
    string GetBedType()
    {
        return bedtype;
    }
    void Show()
    {
        cout<<"床/"<<GetMat()<<"/"<<bedtype<<"/"<<GetPrice()<<endl;
        cout<<"Function #4 is called!"<<endl;
    }

};

class Sofa : virtual public Furniture
{
private:
    int seats;
public:
    Sofa(int s,string ma,int pr):
        Furniture(ma,pr)
        {
             cout<<"Function #5 is called!"<<endl;
             seats = s;
        }
        int GetSeats()
        {
            return seats;
        }
        void Show()
        {
            cout<<"沙发/"<<GetMat()<<"/"<<seats<<"/"<<GetPrice()<<endl;
            cout<<"Function #6 is called!"<<endl;
        }
};

class SofaBed : public Sofa,public Bed
{
public:
    SofaBed(int s,string bedtype,string ma,int pr):
        Furniture(ma,pr),Sofa(s,ma,pr),Bed(bedtype,ma,pr)
        {

             cout<<"Function #7 is called!"<<endl;
        }
        void Show()
        {
            cout<<"沙发床/"<<GetBedType()<<"/"<<GetMat()<<"/"<<GetSeats()<<"/"<<GetPrice()<<endl;
            cout<<"Function #8 is called!"<<endl;
        }
};
int main()
{
    string mat,bedtype;
    int price,seats,cas=0;
    while(cin>>mat>>price>>bedtype>>seats)
    {
        cas++;
        cout<<"Case #"<<cas<<":"<<endl;
        Furniture furniture(mat,price);
        Bed bed(bedtype,mat,price);
        Sofa sofa(seats,mat,price);
        SofaBed sofabed(seats,bedtype,mat,price);
        cout<<"Furniture:";    furniture.Show();
        cout<<"Bed:";          bed.Show();
        cout<<"Sofa:";         sofa.Show();
        cout<<"SofaBed:";      sofabed.Show();
    }
    return 0;
}
