#include<cstdio>
#include<cmath>
int main()
{
    int n,t=0,a,d=0,m=0;  
    scanf("%d",&n);      
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);  
        if(a==1)
        {
            if(m>0) d-=pow(2,m-1);
            if(d<0) d=0;
            t++;d++;m=0;                  
            if(d>=3) t++;                   
            if(d>=7) t++;                  
            if(d>=30) t++;                  
            if(d>=120) t++;              
            if(d>=365) t++;
        }else if(a==0) m++;         
    }
    printf("%d",t);              
    return 0;
}
