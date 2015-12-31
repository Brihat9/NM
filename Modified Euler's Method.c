/** Modified Euler's Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define STEP    0.1     //step value
#define ERROR   .0001   //error tolerance

float dfx(float a,float b)
{
    return a+pow(b,2);
    //return 1-b;  //your function here
}

float ynew(float y,float dy)
{
    return (y+(STEP*dy));
}

float mslope(float x,float y)
{
    return (x+y)/2;
}

int main(void)
{
    float x,y,y1;
    int i,j,k=0;
    int count=0;
    float f1,g1,g2;
    float f,g,m;
    float yconst,yback,mconst;
    printf(" Modified Euler's Method :\n\n Enter initial condition x0 and y0 for [y(x0) = y0] : ");
    scanf("%f%f",&x,&y);
    printf(" Enter no of iteration : ");
    scanf("%d",&i);
    printf("\n\t\t\tMODIFIED EULER'S METHOD\n");
    printf("\n --------------------------------------------------------------------------\n");
    printf("  Itr\t  x\tdy/dx\t      Mean Slope\t y(new)=y(old)+%.1f*(dy/dx)",STEP);
    printf("\n --------------------------------------------------------------------------\n");
    g2=y;

    for(j=0;k<i;j++)
    {
        k++;
        yconst=y;
        if(count==0)
        {
            f=dfx(x,g2);
            g=ynew(g2,f);
            printf("\n   %d\t%.1f\t%.4f\t\t ----\t\t\t%.4f\n",k,x,f,g);
            y1=g;
            x+=STEP;
            j--;
            count++;
            k--;
        }
        else
        {
            mconst=f;
            do{
                f1=dfx(x,y1);
                m=mslope(mconst,f1);
                yback=g;
                g1=ynew(yconst,m);
            //  printf("   %d\t%.1f\t%.4f\t\t%.4f\t\t\t%.4f\n",k,x,f1,m,g1);
                printf("    \t%.1f\t%.4f\t\t%.4f\t\t\t%.4f\n",x,f1,m,g1);
                f=f1;
                y1=g1;
                count++;
                g=g1;
            }while(fabs(yback-g1)>ERROR);
            count=0;
            j++;
            y=g1;
        }
        g2=g1;
    }
    printf("\n --------------------------------------------------------------------------\n");
    getch();
    return 0;
}
