/** Secant Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define ERROR 0.00005           //error tolerance

float fx(float a)               //your function here
{
    return pow(a,3)-a-11;
    //return cos(a)-a*exp(a);
    //return a-3*cos(a);
}

int main(void)
{
    float a,b,c;
    int count=0;
    printf("Secant Method\nEnter lower and upper limit of interval : ");
    scanf("%f%f",&a,&b);
    printf("\n\t\t\t\tSECANT METHOD");
    printf("\n--------------------------------------------------------------------------\n");
    printf(" itr\t   a\t\tb\t  c=(af(b)-bf(a))/(f(b)-f(a))\t   f(c)\n");
    printf("--------------------------------------------------------------------------\n");
    do{
        if(fx(b)==fx(a))
        {
            printf("\nError in calculation.\n");
            getch();
            exit(1);
        }
        count++;
        c=(a*fx(b)-b*fx(a))/(fx(b)-fx(a));                  //Secant Method Iterative Formula
        printf("\n  %d%11.4f%13.4f%23.5f%+22.4f",count,a,b,c,fx(c));
//        printf(" Iteration %d : %7.4f\n",count,c);
        a=b;
        b=c;
    }while(fabs(fx(c))>ERROR);
    printf("\n\n--------------------------------------------------------------------------\n");
    printf("\nRequired root is x = %.4f.\n",c);
    getch();
    return 0;
}
