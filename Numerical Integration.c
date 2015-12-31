/** Numerical Integration - Function **/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define N 200
float fx(float a)
{
    //return exp(a);
    //return sin(a);
    //return a;
    return 3*a*a+2*a+1;
}

int main(void)
{
    int i,j,k,l,n;
    float a,b,h;
    float y[N];
    float ans,sum;
    printf("Enter number of interval :");
    scanf("%d",&n);

    printf("Enter lower and upper interval : ");
    scanf("%f%f",&a,&b);

    if(n%6!=0)
            n+=(6-n%6);

//    printf("%d",n);

    h=(b-a)/n;

    for(i=0;i<=n;i++)
    {
        y[i]=fx(a+i*h);
    }

    ans=0;
    //trapezoidal method
    for(i=0;i<n;i++)
           ans+=((h/2)*(y[i]+y[i+1]));
    printf("\n\nTrapezoidal : %.4f",ans);

    ans=0;
    //simpson's 1/3 rule
    for(i=0;i<n-1;i+=2)
           ans+=((h/3)*(y[i]+4*y[i+1]+y[i+2]));
     printf("\n\nSimpson 1/3 : %.4f",ans);

    ans=0;
    //simpson's 3/8 rule
    for(i=0;i<n-2;i+=3)
           ans+=((3*h/8)*(y[i]+3*y[i+1]+3*y[i+2]+y[i+3]));
    printf("\n\nSimpson 3/8 : %.4f",ans);

    getch();
    return 0;


}
