/** Fixed Point Iteration Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float fx(float x)                       //original function f(x)=0
{
    return pow(x,2)-2*x-3;
    //return 3*x+cos(x)-2;
}

float gx(float x)                       //transformed function x=g(x) from f(x)=0
{
    return pow((2*x+3),0.5);
    //return ((2-cos(x))/3.0);
}

float dgx(float x)                      //derivative of g(x) : slope of tangent
{
    return pow((2*x+3),-0.5);
    //return (sin(x)/3.0);
}

int isroot(float a,float b)             //checks if given interval contains at least one root
{
    int i;
    for(i=a;i<=b;i++)
        if((fx(i)*fx(b))<0)
            return 1;
    return 0;
}

int main(void)
{
    int a,b,count=0;
    float x,y;
    printf(" Fixed Point Iteration Method\n Enter lower and upper limit of interval : ");
    scanf("%d%d",&a,&b);
    x=(a+b)/2;
    if(isroot(a,b))
        if(fabs(x)>1)                       //if slope of tangent is greater than 1
        {
            printf("  Error in calculation\n");
            getch();
            exit(1);
        }
        else
        {
            printf("\n FIXED POINT ITERATION METHOD\n\n");
            do
            {
                count++;
                y=gx(x);
                printf(" %d\tx = %9.6f\n",count,y);
                x=y;
            }while(fabs(fx(y))>0.000005);
        }
    else
    {
        printf("\n  No root found in given interval.\n");
        getch();
        exit(1);
    }
    printf("\n Required root is x = %.5f\n",x);
    getch();
    return 0;
}
