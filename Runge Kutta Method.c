/** Runge Kutta Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define STEP 0.1                    //step

void rk1(float,float,int);
void rk2(float,float,int);
void rk4(float,float,int);

float dfx(float a,float b)          //type your function here: dy/dx or f(x,y).
{
    return 1-b;
    //return a+pow(b,2);
    //return b-a;
}

int main(void)
{
    float x,y,a,b,c;
    int i,j;
    printf(" Runge Kutta Method :\n\n Enter initial condition x0 and y0 for [y(x0) = y0] : ");
    scanf("%f%f",&x,&y);
    printf(" Enter no of iteration : ");
    scanf("%d",&i);
    printf("\n\n Select Method:\n "
           "1. Runge Kutta Method 1st order.\n "
           "2. Runge Kutta Method 2nd order.\n "
           "3. Runge Kutta Classical Method.\n -> ");
    scanf("%d",&j);
    switch(j)
    {
    case 1:
        printf("\n Runge Kutta Method 1st order.\n\n");
        rk1(x,y,i);
        break;
    case 2:
        printf("\n Runge Kutta Method 2nd order.\n\n");
        rk2(x,y,i);
        break;
    case 3:
        printf("\n Runge Kutta Classical Method.\n\n");
        rk4(x,y,i);
        break;
    default:
        system("cls");
        printf("\n Selection option INVALID.\n\n");
        main();
    }
    getch();
    return 0;
}

void rk1(float x,float y,int itr)           /** Runge Kutta Method 1st Order **/
{
    int i,j;
    float ynew;
    for(i=0;i<itr;i++)
    {
        ynew=y+STEP*dfx(x,y);
        printf(" %d iteration : \t y[%d] = %.4f\n\n",i+1,i+1,ynew);
        y=ynew;
        x+=STEP;
    }
}

void rk2(float x,float y,int itr)       /** Runge Kutta Method 2nd Order **/
{
    int i;
    float k,k1,k2;
    float ynew;
    for (i=0;i<itr;i++)
    {
        k1=STEP*dfx(x,y);
        k2=STEP*dfx(x+STEP,y+k1);
        ynew=y+(k1+k2)/2;
        printf(" %d iteration : \t y[%d] = %.4f\n\n",i+1,i+1,ynew);
        y=ynew;
        x+=STEP;
    }
}

void rk4(float x,float y,int itr)       /** Runge Kutta Classical Method **/
{
    int i;
    float ynew;
    float k,k1,k2,k3,k4;
    for(i=0;i<itr;i++)
    {
        k1=STEP*dfx(x,y);
        k2=STEP*dfx(x+STEP/2,y+k1/2);
        k3=STEP*dfx(x+STEP/2,y+k2/2);
        k4=STEP*dfx(x+STEP,y+k3);
        k=(k1+2*(k2+k3)+k4)/6;
        ynew=y+k;
        printf(" %d iteration : \t y[%d] = %.4f\n\n",i+1,i+1,ynew);
        y=ynew;
        x+=STEP;
    }
}
