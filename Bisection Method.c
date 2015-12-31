/** Bisection Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define ERROR 0.00005

float fx(float a)
{
    return cos(a)-a*exp(a);
    //return a*sin(a)+cos(a);
    //return (pow(a,3)-a-11);
    //return 3*a+sin(a)-exp(a);
}

int isroot(float a,float b)
{
    int i;
    for(i=a;i<=b;i++)
        if((fx(i)*fx(b))<0)
            return 1;
    return 0;
}

float mvalue(float a,float b)
{
    return (a+b)/2;
}

int main(void)
{
    int count=0;
    float a,b,x;
    printf(" Bisection Method:\n Enter lower and upper limit of interval : ");
    scanf("%f%f",&a,&b);
    int root=isroot(a,b);
    if(root)
    {
        printf("\n---------------------------------------------------------\n");
        printf(" Itr\t   a\t    b\t\tmid value\t  f(c)\n");
        printf("---------------------------------------------------------\n");
        do{
            count++;
            x=mvalue(a,b);
            printf("  %d\t%.4f%10.4f%15.4f%+16.4f\n",count,a,b,x,fx(x));
            if(fx(a)*fx(x)<0)
                b=x;
            else
                a=x;
        }while(fabs(fx(x))>ERROR);
        printf("---------------------------------------------------------\n");
        printf("\n Root of f(x) is %.4f.",x);
    }
    else
         printf(" No roots found in given interval.\n");
    getch();
    return 0;
}
