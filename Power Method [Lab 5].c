#include<stdio.h>
#include<conio.h>
#include<math.h>

#define N 20                    //maximum order of matrix
#define ERROR .00005            //maximum tolerable error

float max(float a[N],int n)     //return max element
{
    int i;
    float ans=a[0];
    for(i=1;i<n;i++)
        if(fabs(ans)<fabs(a[i]))
            ans=a[i];
    return ans;
}

int main(void)
{
    int i,j,n;
    float mat[N][N],x[N],y[N],z[N];
    float err,maxm;
    printf(" Enter order of square matrix : ");
    scanf("%d",&n);

    //read matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("  Enter element %d.%d : ",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }

    //fill matrix
    printf("\n Enter initial guess vector : \n");
    for(i=0;i<n;i++)
    {
        printf("  Enter element %d : ",i+1);
        scanf("%f",&x[i]);
    }

    //iteration
    do{
        for(i=0;i<n;i++)
        {
            float sum=0;
            for(j=0;j<n;j++)
                sum+=mat[i][j]*x[j];
            y[i]=sum;
        }

        //new vector
        maxm=max(y,n);
        for(i=0;i<n;i++)
            y[i]=y[i]/maxm;

        for(i=0;i<n;i++)
            z[i]=fabs(x[i])-fabs(y[i]);

        //error calculation
        err=max(z,n);
        for(i=0;i<n;i++)
            x[i]=y[i];
    }while(fabs(err)>ERROR);

    //display result

    printf("\n Largest Eigen Value : %.4f\n",maxm);
    printf("\n and corresponding Eigen Vector is \n");
    for(i=0;i<n;i++)
        printf("\t%.4f\n",y[i]);
    getch();
    return 0;
}
