#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int perm(int n,int r);

int main()
{
    FILE *ptw,*ptr;
    int a,b,n,m,k,r,x,result;
    char file[10];
    while(1)
    {

        printf("\nSelect Input Method: \n\n1)User Input\n2)Read from file\n0)Exit\n\nFunction: ");
        scanf("%d",&a);
        if(a==1)
        {
            printf("\nInput number of tickets : ");
            scanf("%d",&n);
            printf("Input number of prizes : ");
            scanf("%d",&r);
            printf("Tickets surely winning prizes : ");
            scanf("%d",&x);
            printf(" Among winning tickets, number of fixed prize : ");
            scanf("%d",&k);
            printf("Tickets surely not winning prizes : ");
            scanf("%d",&m);
            ptw=fopen("input.txt","w");
            fprintf(ptw,"%d\n%d\n%d\n%d\n%d\n",n,r,x,k,m);
            fclose(ptw);
        }
        else if(a==2)
        {
            printf("\n\nSelect Inputs :\n\n1)Problem a\n2)Problem b\n3)Problem c\n4)Problem d\n5)Problem e\n6)Problem f\n7)Problem g\n8)Problem h\n9)Problem i\n10)Problem j\n0)Last Input\n\n");
            printf("Function: ");
            scanf("%d",&b);
            if(b==0)
                strcpy(file,"input.txt");
            else if(b==1)
                strcpy(file,"a.txt");
            else if(b==2)
                strcpy(file,"b.txt");
            else if(b==3)
                strcpy(file,"c.txt");
            else if(b==4)
                strcpy(file,"d.txt");
            else if(b==5)
                strcpy(file,"e.txt");
            else if(b==6)
                strcpy(file,"f.txt");
            else if(b==7)
                strcpy(file,"g.txt");
            else if(b==8)
                strcpy(file,"h.txt");
            else if(b==9)
                strcpy(file,"i.txt");
            else if(b==10)
                strcpy(file,"j.txt");
            else
            {
                printf("Invalid Input!\n");
                return -3;
            }

            ptr=fopen(file,"r");
            if(ptr==NULL)
            {
                printf("File does not exist");
                return -2;
            }
            else
            {
                fscanf(ptr,"%d\n%d\n%d\n%d\n%d\n",&n,&r,&x,&k,&m);
                printf("\nTickets :\t\t%d\nPrizes :\t\t%d\nWinning tickets :\t%d\nFixed prizes :\t\t%d\nNot winning tickets :   %d\n",n,r,x,k,m);
            }
            fclose(ptr);

        }
        else if(a==0)
        {
            printf("\nProgram exited successfully!\n");
            return 0;
        }
        else
        {
            printf("Invalid function!\n");
            return -1;
        }
        result=(perm(n-m-x,r-x)*perm(r-k,x-k));
        printf("\nWays to win prizes : %d \n\n",result);
    }
    return 0;
}

int perm(int n,int r)
{
    int i,sum;
    sum=1;
    for(i=n;i>n-r;i--)
        sum=sum*i;
    return sum;
}

