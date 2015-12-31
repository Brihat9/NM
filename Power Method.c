/** Power Method **/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define N 10

float max(float t[N],int n)                     //returns largest element(in magnitude) of vector
{
    int i;
    float m=t[0];
    for(i=1;i<n;i++)
        if(fabs(t[i])>fabs(m))
            m=t[i];
    return m;
}

int main(void)
{
    int i,j,count=0,n;
    float matA[N][N],vecX[N],temp[N],error[N],err,maxelem;
    printf(" Power Method\n");
    printf("  Enter order of square matrix : ");
    scanf("%d",&n);

    //read matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("   Enter element %d.%d : ",i+1,j+1);
            scanf("%f",&matA[i][j]);
        }
/*
    //set initial vector
    for(i=0;i<n;i++)
        vecX[i]=1;
*/
    //takes initial guess vector
    printf("\n  Enter initial guess vector\n");
    for(i=0;i<n;i++)
    {
        printf("   Enter element %d : ",i+1);
        scanf("%f",&vecX[i]);
    }

    system("cls");
    while(1)
    {
        count++;
        printf("\n\t/** Iteration %d **/\n",count);
        printf("------------------------------------\n");

        //multiplies given matrix with vector
        for(i=0;i<n;i++)
        {
            temp[i]=0;
            for(j=0;j<n;j++)
                temp[i]+=matA[i][j]*vecX[j];
        }

        maxelem=max(temp,n);
        printf("    Eigen Value = %.5f\n",maxelem);

        //calculates new approximation of vector
        for(i=0;i<n;i++)
            temp[i]/=maxelem;

        printf("\n    Eigen Vector :\n");

        for(i=0;i<n;i++)
            printf("\t%10.5f\n",temp[i]);

        //calculates error
        for(i=0;i<n;i++)
            error[i]=fabs(temp[i])-fabs(vecX[i]);
        err=max(error,n);
        printf("\n    Error : %.5f\n",fabs(err));

        //sets new vector as approximation for next iteration
        for(i=0;i<n;i++)
            vecX[i]=temp[i];
        printf("------------------------------------\n");

        //exits from loop if error is less than desired
        if(fabs(err)<0.00005)
            break;
        getch();
    }

    getch();
    system("cls");
    printf("\n\n      /** Reqiured Solution **/\n");
    printf("------------------------------------\n");
    printf(" Eigen Vector :\n");
    for(i=0;i<n;i++)
        printf("\t%10.4f\n",vecX[i]);
    printf("\n and Eigen Value = %.4f\n",maxelem);
    printf("------------------------------------\n");

    getch();
    return 0;
}
