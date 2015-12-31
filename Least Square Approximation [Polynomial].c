/** Curve Fitting for any degree polynomial **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define N 25            //max number of data
#define MAX 10          //max number of degree

int main(void)
{
    int d,i,j,k,n;
    float sum,ratio;
    float x[N],y[N];
    float matA[MAX+1][MAX+2],ans[MAX];

    printf("Least Square Approximation - Polynomial\n");
    printf("\n Enter no of data : ");
    scanf("%d",&n);

    printf(" Enter required degree of polynomial ( max = %d ) : ",n-1);
    scanf("%d",&d);

    if(n<=d)
    {
        printf("  ERROR : Degree of polynomial should be less than no of data.\n");
        getch();
        exit(1);
    }

    //take input data
    for(i=0;i<n;i++)
    {
        printf("  Enter x%d and y%d : ",i+1,i+1);
        scanf("%f%f",&x[i],&y[i]);
    }

    //calculates coeff part of augmented matrix
    for(i=0;i<d+1;i++)
        for(j=0;j<d+1;j++)
        {
            sum=0.0;
            for(k=0;k<n;k++)
                sum+=pow(x[k],i+j);
            matA[i][j]=sum;
        }

    //calculates constant part of augmented matrix
    for(i=0;i<d+2;i++)
    {
        sum=0.0;
        for(k=0;k<n;k++)
            sum+=(pow(x[k],i)*y[k]);
        matA[i][d+1]=sum;
    }

/*    //displays matrix
    for(i=0;i<d+1;i++)
    {
        for(j=0;j<d+2;j++)
            printf("%15.5f",matA[i][j]);
        printf("\n");
    }
*/
    //gauss jordan method
    for(j=0;j<d+1;j++)
    {
        if(matA[j][j]==0)
        {
            printf("   ERROR IN CALCULATION\n");
            getch();
            exit(1);
        }
        for(i=0;i<d+2;i++)
            if(i!=j)
            {
                ratio=matA[i][j]/matA[j][j];
                for(k=0;k<d+2;k++)
                    matA[i][k]-=ratio*matA[j][k];
            }
    }
/*
    printf("\n\n");

    //display matrix
    for(i=0;i<d+1;i++)
    {
        for(j=0;j<d+2;j++)
            printf("%15.5f",matA[i][j]);
        printf("\n");
    }
*/
    printf("\n\n Required solution is \n   y = ");

    //value finder
    for(i=0;i<d+1;i++)
        ans[i]=matA[i][d+1]/matA[i][i];

    //displays required solution
    for(i=d;i>=0;i--)
        printf("%+9.4f x^%d",ans[i],i);

    getch();
    return 0;
}
