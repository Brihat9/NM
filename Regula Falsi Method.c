/** Regula Falsi Method (False Position Method)**/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define ERROR 0.00005

float fx(float a)                        //your function here
{
    return cos(a)-a*exp(a);
    //return a-3*cos(a);
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
    float a,b,c;
    int count=0;
    printf(" Regula Falsi Method\n Enter lower and upper limit of interval : ");
    scanf("%f%f",&a,&b);
    int root=isroot(a,b);               //assert given interval is valid using Bisection Method
    if(root)
    {
        printf("\n\t\t\t    REGULA FALSI METHOD");
        printf("\n --------------------------------------------------------------------------\n");
        printf("  itr\t   a\t\tb\t  c=(af(b)-bf(a))/(f(b)-f(a))\t   f(c)\n");
        printf(" --------------------------------------------------------------------------\n");
        do{
            if(fx(b)==fx(a))
            {
                printf("\n Error in calculation.\n");
                getch();
                exit(1);
            }
            count++;
            c=(a*fx(b)-b*fx(a))/(fx(b)-fx(a));
            printf("\n   %d%11.4f%13.4f%23.4f%+22.4f",count,a,b,c,fx(c));
            a=b;
            b=c;
        }while(fabs(fx(c))>ERROR);
        printf("\n\n --------------------------------------------------------------------------\n");
        printf("\n Required root is x = %.4f.\n",c);
    }
    else
        printf("\n No roots found in given interval.\n");
    getch();
    return 0;
}
