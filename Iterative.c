#include<stdio.h>
#include<conio.h>

int main(void)
{
    //float a,b,c;
    int i=0;
    char cc;
    float x1=0,x2=0,x3=0;
    do{
            i++;
        x1=(22+x2-2*x3)/9;
        x2=(11-5*x1+3*x3)/10;
        x3=(22-2*x1+3*x2)/7;
        printf("%d\t%.5f\t%.5f\t%.5f\t\n",i,x1,x2,x3);
        //x1=a;x2=b;x3=c;
        printf("next ? : ");
        scanf("%s",&cc);
    }while(cc=='y');
    return 0;

}
