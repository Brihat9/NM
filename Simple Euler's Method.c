/** Simple Euler's Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define STEP 0.01

float dfx(float a,float b)
{
    return 1-b;
}

float ynew(float y,float dy)
{
    return y+STEP*dy;
}

int main(void)
{
    float x,y,a,b,c;
    int i,j;
    printf(" Simple Euler's Method :\n\n Enter initial condition x0 and y0 for [y(x0) = y0] : ");
    scanf("%f%f",&x,&y);
    printf(" Enter no of iteration : ");
    scanf("%d",&i);
    printf("\n\n -------------------------------------------------------------------\n");
    printf("  Itr\t  x\t     y\t   \t dy/dx\t y(new)=y(old)+%.1f*(dy/dx)",STEP);
    printf("\n -------------------------------------------------------------------\n\n");
    for(j=0;j<i;j++)
    {
        float f,g,h;
        f=dfx(x,y);
        g=ynew(y,f);
        printf("   %d\t %.2f\t   %.4f\t%.4f\t\t%.4f\n",j+1,x,y,f,g);
        y=g;
        x+=STEP;
    }
    printf("\n -------------------------------------------------------------------\n");
    getch();
    return 0;
}
