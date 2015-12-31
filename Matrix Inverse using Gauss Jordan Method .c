/** Matrix Inverse using Gauss Jordan Method **/

#include<stdio.h>
#include<conio.h>
//#include<math.h>
#include<stdlib.h>

#define N 10

int main(void)
{
    int i,j,k,n;
    float ratio,mat[N][2*N],temp;
    printf(" Enter order of square matrix : ");
    scanf("%d",&n);

    // read matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("  Enter element %d.%d : ",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }

    // fill remaining elements of augmented matrix by identity matrix
    for(i=0;i<n;i++)
        for(j=n;j<2*n;j++)
            if(j==i+n)
                mat[i][j]=1;
            else
                mat[i][j]=0;
/**
    //display augmented matrix
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n;j++)
            printf("%10.2f",mat[i][j]);
        printf("\n");
    }
**/
    //Gauss Jordan Method
    for(j=0;j<n;j++)
    {
        if(mat[j][j]==0)
        {
            printf("\n Error in calculation.\n");
            getch();
            exit(1);
        }
        for(i=0;i<n;i++)
            if(i!=j)
            {
                ratio=mat[i][j]/mat[j][j];
                for(k=0;k<2*n;k++)
                    mat[i][k]-=ratio*mat[j][k];
            }
    }

    //transforms diagonal matrix to identity matrix
    for(i=0;i<n;i++)
    {
        temp=mat[i][i];
        for(j=0;j<2*n;j++)
            mat[i][j]*=1.0/temp;
    }
/**
    //display augmented matrix
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n;j++)
            printf("%10.2f",mat[i][j]);
        printf("\n");
    }
**/
    //display inverse of given matrix
    printf("\n Inverse of given matrix is \n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%10.2f",mat[i][j+n]);
        printf("\n");
    }
    getch();
    return 0;
}
