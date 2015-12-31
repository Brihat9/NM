/** Numerical Integration - Data **/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define N 200

int main(void)
{
    int i,n,itr=0,extra;
    float a,b,h,y[N],ans;

    printf("Enter number of interval :");
    scanf("%d",&n);

    printf("Enter lower and upper interval : ");
    scanf("%f%f",&a,&b);

    h=(b-a)/n;

    for(i=0;i<=n;i++)
    {
        printf("Enter y(%.3f) : ",a+i*h);
        scanf("%f",&y[i]);
    }

    extra=n%3;
    ans=0;

    //simpson's 3/8 rule
    for(i=itr;i<n-2;i+=3)
          ans+=((3*h/8)*(y[i]+3*y[i+1]+3*y[i+2]+y[i+3]));

    if(extra==2)
        //simpson's 1/3 rule
        for(;i<n-1;i+=2)
            ans+=((h/3)*(y[i]+4*y[i+1]+y[i+2]));

    if(extra==1)
        //trapezoidal method
        for(;i<n;i++)
            ans+=((h/2)*(y[i]+y[i+1]));

    printf("answer = %.4f",ans);
    getch();
    return 0;
}
