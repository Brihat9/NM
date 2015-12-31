/** LU Decomposition Method **/

#include<stdio.h>
#include<conio.h>

#define N 100

int main(void)
{
    int i,j,k,n,m;
    float mat[N][N],LU[N][N],sum;

    printf(" LU DECOMPOSITION METHOD\n\n Splits matrix A into two matrices such that A=LU\n");
    printf(" where L = Lower Triangular Matrix with unit diagonal\n");
    printf("  and  U = Upper Triangular Matrix\n");

    printf("\n Enter order of square matrix : ");
    scanf("%d",&n);

    //reads elements of matrix A
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("  Enter element %d.%d : ",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }

    for(m=0;m<n;m++)
    {
        //calculates elements of rows of LU matrix
        i=m;
        for(j=0;j<n;j++)
            if(i<j || i==j)
            {
                sum=0.0;
                for(k=0;k<i;k++)
                    sum+=(LU[i][k]*LU[k][j]);
                LU[i][j]=(mat[i][j]-sum);
                //printf("\nLU[%d][%d] = %.2f\n",i+1,j+1,LU[i][j]);
            }

        //calculates elements of columns of LU matrix
        j=m;
        for(i=0;i<n;i++)
            if(i>j)
            {
                sum=0.0;
                for(k=0;k<j;k++)
                    sum+=(LU[i][k]*LU[k][j]);
                LU[i][j]=((mat[i][j]-sum)/LU[j][j]);
                //printf("\nLU[%d][%d] = %.2f\n",i+1,j+1,LU[i][j]);
            }
    }

    //Displays original matrix A ( equals to (matrix L) *(matrix U) )
    printf("\n The given matrix A = \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%10.2f",mat[i][j]);
        printf("\n");
    }

    //Displays matrix L ( Lower Triangular Matrix )
    printf("\n is equal to product of the matrix L = \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(i>j)
                printf("%10.2f",LU[i][j]);
            else if(i==j)
                printf("%10.2f",1.0);
            else
                printf("%10.2f",0.0);
        printf("\n");
    }

    //Displays matrix U ( Upper Triangular Matrix )
    printf("\n with the matrix U = \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(i<j || i==j)
                printf("%10.2f",LU[i][j]);
            else
                printf("%10.2f",0.0);
        printf("\n");
    }

    getch();
    return 0;
}
