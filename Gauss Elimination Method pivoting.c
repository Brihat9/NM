/** Gauss Elmination Method with Partial Pivoting **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define N 5

void partialpivot(float a[N][N],int n)
{
    float newmat[N][N];
    int i,j,k;
    for(j=0;j<n;j++)
    {
        float pivot=fabs(a[j][j]);
        int pvtrow=j;
        int pvtemprow=j;
        for(i=j+1;i<n;i++)
        {
            if(fabs(a[i][j])>pivot)
            {
                pivot=fabs(a[i][j]);
                pvtemprow=i;
            }
        }
        if(pvtrow!=pvtemprow)
        {
                for(j=0;j<n;j++)
                {
                    newmat[0][j]=a[pvtemprow][j];
                    a[pvtemprow][j]=a[pvtrow][j];
                    a[pvtrow][j]=newmat[0][j];
                }
        }
    }
}

int main(void)
{
    float mat[N][N],x[N];
    float ratio,sum=0;
    int i,j,k,n;
    printf("Gauss Elimination Method\nEnter number of unknown(s) : ");
    scanf("%d",&n);

    for (i=0;i<n;i++)                   //read augmented matrix
        for (j=0;j<=n;j++)
        {
            printf("Enter element a[%d][%d] : ",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }
/**
    for (i=0;i<n;i++)                   //display matrix
    {
        for (j=0;j<=n;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
**/
    for(j=0;j<n;j++)                    //Gauss Elimination Algorithm
    {
        if(mat[j][j]==0.0)
        {
            printf("An error has occured.\n");
            getch();
            exit(1);
        }
        for(i=0;i<n;i++)
        {
            if(i>j)
            {
                partialpivot(mat,n);
                ratio=mat[i][j]/mat[j][j];
                for(k=0;k<=n;k++)
                    mat[i][k]-=ratio*mat[j][k];
            }
        }
    }
/**
    printf("\n");
    for (i=0;i<n;i++)                   //display matrix
    {
        for (j=0;j<=n;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
**/
    printf("\nRequired solution :\n");

    for(i=n-1;i>=0;i--)                 //Backward Substitution Algorithm and Display Answer
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum+=mat[i][j]*x[j];
        x[i]=(mat[i][n]-sum)/mat[i][i];
        printf("\nx[%d] = %.2f",i+1,x[i]);
    }

    getch();
    return 0;
}
