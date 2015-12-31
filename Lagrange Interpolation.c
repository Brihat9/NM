#include<stdio.h>
#include<conio.h>
#define N 50

int main(void)
{
    int i,j,n;
    float x[N],y[N],a;
    float prod,ans;

    printf("Enter no of data : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter data x%d and y%d :",i+1,i+1);
        scanf("%f%f",&x[i],&y[i]);
    }

    printf("\n\nEnter value of x to calculate : ");
    scanf("%f",&a);

    ans=0;
    for(i=0;i<n;i++)
    {
        prod=1;
        for(j=0;j<n;j++)
            if(i!=j)
                prod=prod*((a-x[j])/(x[i]-x[j]));
        ans+=prod*y[i];
    }

    printf("\n\n\tf(%.4f) = %.4f.",a,ans);
    getch();
    return 0;
}
