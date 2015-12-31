#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 10

int main(void)
{
    float x[N],y[N];
    int n,i,j,k,l;
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
        sumxy+=x[i]*log(y[i]);
        sumy+=log(y[i]);
    }

    float det=pow(sumx,2)-sumx2*n;
    float deta=sumxy*sumx-sumy*sumx2;
    float detb=sumx*sumy-sumxy*n;

    float a=exp(deta/det);
    float b=detb/det;

    printf("Best Fit Expression is\n Y = %.4f * e^(%.4f X).",a,b);
    getch();
    return 0;
}
