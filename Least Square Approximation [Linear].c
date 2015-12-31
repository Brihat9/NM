#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 10

int main(void)
{
    float x[N],y[N];
    int n,i;
    printf("Enter number of data : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter data x[%d] and y[%d] : ",i+1,i+1);
        scanf("%f%f",&x[i],&y[i]);
    }
    float sumx2=0,sumx=0,sumxy=0,sumy=0;
    for(i=0;i<n;i++)
    {
        sumx2+=pow(x[i],2);
        sumx+=x[i];
        sumxy+=x[i]*y[i];
        sumy+=y[i];
    }

    float det=sumx2*n-pow(sumx,2);
    float deta=sumxy*n-sumy*sumx;
    float detb=sumx2*sumy-sumx*sumxy;

    float a=deta/det;
    float b=detb/det;

    printf("Best Fit Expression is\n Y = %.4f X %+.4f",a,b);
    getch();
    return 0;
}
