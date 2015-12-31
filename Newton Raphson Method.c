/** Newton Raphson Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float fx(float a)
{
    return 3*a-1;
    //return 3*a-cos(a)-1;
    //return (pow(a,3)-a-11);
    //return 4*pow(a,3)-1-exp(pow(a,2)/2);
}

float dfx(float a)
{
    return 3;
    //return 3+sin(a);
    //return (3*pow(a,2)-1);
    //return 12*pow(a,2)-exp(pow(a,2)/2)*a;
}

float nitr(float a)
{
    if(dfx(a)==0)
    {
        printf(" Calculation cannot continue, [ df(x)=0 ].");
        getch();
        exit(1);
    }
    else
        return (a-fx(a)/dfx(a));
}

int main(void)
{
    float a,b,c=0,d;
    printf(" Newton Raphson Method : \n Enter initial guess : ");
    scanf("%f",&a);
    printf(" Enter error tolerance : ");
    scanf("%f",&b);
    do{
        a=nitr(a);
        c++;
        printf("\n  %.0f approximation : x = %.4f\t  error = %f \n",c,a,fx(a));
        if(c>1000)
        {
            printf(" Root Oscillation.");
            getch();
            exit(1);
        }
    }while(fx(a)>b);
    printf("\n Root of given f(x) is %.4f.\n",a);
    getch();
    return 0;
}
