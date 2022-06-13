#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 1000
#define PI 3.14159
#define RD 57.2957795
#define RG 63.6619772

int main()
{
    system("@cls||clear");
    printf("\t\t\t\tWELCOME TO SCIENTIFIC CALCULATOR\n\n\n");
    printf("\t\t\t\tPlease choose an option:\n");
    printf("\t\t\t\tPress 1. For Calculate\n");
    printf("\t\t\t\tPress 2. For Result\n");
    printf("\t\t\t\tPress 3. For Exit\n\n");
    int a;
    FILE *pt1, *pt2;
    printf("Enter Your Choice: ");
    scanf("%d", &a);
    if(a == 1)
    {
        calculate();
    }
    else if(a == 2)
    {
        pt2=fopen("results.txt","r");
        char res[5000];
        while(fgets(res, 5000, (FILE *)pt2))
        {
            // fgets(res, 50, (FILE *)pt2);
            printf("%s\n", res);
//            fscanf(pt2,"%s\n",res);
//            printf("%s\n",res);
            //i++;
//            if(feof(pt2))
//                break;
        }
        fclose(pt2);
        int c;
        printf("Do you wish to make more calculation? 1.YES 2.NO\n");
        printf("Press 1 or 2: ");
        scanf("%d", &c);
        if(c == 1) main();
        else printf("\nThank you for using the calculator\n\n\n");
    }
    else if(a==3)
    {
        printf("\nThank you for using the calculator\n\n\n");
        getchar();
        exit(0);
    }

    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
        int c;
        printf("\nDo you wish to make more calculation? 1.YES 2.NO\n");
        printf("Press 1 or 2: ");
        scanf("%d", &c);
        if(c == 1) main();
        else printf("\nThank you for using the calculator\n\n\n");
    }
    return 0;
}
void calculate()
{
    system("@cls||clear");
    printf("\t\t\tChoose any calculating option\n\n\t\t\tPress 1. For Numeric conversions\n\t\t\tPress 2. For Trigonometric function\n\t\t\tPress 3. For Factorial\n\t\t\tPress 4. For Permutation & Combination\n\t\t\tPress 5. For Polynomial Equation\n\t\t\tPress 6. For Simple operations\n\t\t\tPress 7. For Simple scientific operations\n");
    printf("\t\t\tPress 8. For Matrix Operations\n\t\t\tPress 9. For Vector Operations\n\t\t\tPress 10.For Solving Equations\n\t\t\tPress 11.For Main Menu\n");
    int a;
    printf("Enter Your Choice: ");
    scanf("%d", &a);
    // calling all functions
    if(a == 1)
    {
        Numeric();
    }
    else if(a == 2)
    {
        Trigono();
    }
    else if(a == 3)
    {
        Factorial();
    }
    else if(a == 4)
    {
        pandc();
    }
    else if(a == 5)
    {
        poly();
    }
    else if(a == 6)
    {
        samop(); //simple operation
    }
    else if(a == 7)
    {
        ssmo();//  simple scientific operations
    }
    else if(a == 8)
    {
        matrix();
    }
    else if(a == 9)
    {
        vectors();
    }
    else if(a == 10)
    {
        equations();
    }
    else if(a == 11)
    {
        main();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    int b;
    printf("Do you wish to make more calculation? 1.YES 2.NO\n");
    printf("Press 1 or 2: ");
    scanf("%d", &b);
    if(b == 1) calculate();
    else main();
}
// for numeric calculation
void Numeric()
{
    system("@cls||clear");
    printf("\n\t\t\tPress 1.  For Binary to decimal\n\t\t\tPress 2.  for Binary to octal\n\t\t\tPress 3.  For Binary to hexadecimal\n\t\t\tPress 4.  For Decimal to binary\n\t\t\tPress 5.  For Decimal to octal\n\t\t\tPress 6.  For Decimal to hexadecimal\n\t\t\tPress 7.  For Octal to binary\n\t\t\tPress 8.  For Octal to decimal\n\t\t\tPress 9.  For Octal to hexadecimal\n\t\t\tPress 10. For Hexadecimal to binary\n\t\t\tPress 11. For Hexadecimal to octal\n\t\t\tPress 12. For Hexadecimal to decimal\n\t\t\tPress 13. For Previous Menu \n\n");
    int a;
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    printf("Enter Your Choice: ");
    scanf("%d", &a);
    if(a == 1) // binary to decimal
    {
        int  num, binary_val, decimal_val = 0, base = 1, rem;
        printf("Enter a binary number(1 and 0): \n");
        scanf("%d", &num); /* maximum five digits */
        binary_val = num;
        while (num > 0)
        {
            rem = num % 10;
            decimal_val = decimal_val + rem * base;
            num = num / 10 ;
            base = base * 2;
        }
        fprintf(pt1,"\nBinary to Decimal conversion result:\n");
        printf("Its decimal equivalent is = %d \n\n", decimal_val);
        fprintf(pt1,"Its decimal equivalent is = %d \n\n", decimal_val);
    }
    else if(a == 2) // binary to octal
    {
        long int binarynum, octalnum = 0, j = 1, remainder;
        printf("Enter the value for  binary number(1 and 0): \n");
        scanf("%ld", &binarynum);
        while (binarynum != 0)
        {
            remainder = binarynum % 10;
            octalnum = octalnum + remainder * j;
            j = j * 2;
            binarynum = binarynum / 10;
        }
        fprintf(pt1,"\nBinary to Octal conversion result:\n");
        printf("Equivalent octal value: %lo\n\n", octalnum);
        fprintf(pt1,"Equivalent octal value: %lo\n\n", octalnum);
    }
    else if(a == 3) // binary to hexadecimal
    {
        long int binaryval, hexadecimalval = 0, i = 1, remainder;
        printf("Enter the binary number: ");
        scanf("%ld", &binaryval);
        while (binaryval != 0)
        {
            remainder = binaryval % 10;
            hexadecimalval = hexadecimalval + remainder * i;
            i = i * 2;
            binaryval = binaryval / 10;
        }
        fprintf(pt1,"\nBinary to Hexadecimal conversion result:\n");
        printf("Equivalent hexadecimal value: %lX\n\n", hexadecimalval);
        fprintf(pt1,"Equivalent hexadecimal value: %lX\n\n", hexadecimalval);
    }
    else if(a == 4) //decimal to binary
    {
        int number,cnt,i;
        int bin[32];
        printf("Enter decimal number: ");
        scanf("%d",&number);
        cnt=0;              /*initialize index to zero*/
        while(number>0)
        {
            bin[cnt]=number%2;
            number=number/2;
            cnt++;
        }
        fprintf(pt1,"\nDecimal to Binary conversion result:\n");
        /*print value in reverse order*/
        printf("Binary value is: ");
        for(i=(cnt-1); i>=0; i--)
        {
            printf("%d",bin[i]);
            fprintf(pt1, "%d",bin[i]);
        }
        printf("\n\n");
    }
    else if(a == 5) //decimal to octal
    {
        int number,cnt,i;
        int oct[32];
        printf("Enter decimal number: ");
        scanf("%d",&number);
        cnt=0;              /*initialize index to zero*/
        while(number>0)
        {
            oct[cnt]=number%8;
            number=number/8;
            cnt++;
        }
        /*print value in reverse order*/
        fprintf(pt1,"\nDecimal to Octal conversion result:\n");
        printf("Octal value is: ");
        for(i=(cnt-1); i>=0; i--)
        {
            printf("%d",oct[i]);
            fprintf(pt1,"%d",oct[i]);
        }
        printf("\n\n");
    }
    else if(a == 6) // decimal to hexa
    {
        long int decimalNumber,remainder,quotient;
        int i=1,j,temp;
        char hexadecimalNumber[100];
        printf("Enter any decimal number: ");
        scanf("%ld",&decimalNumber);
        quotient = decimalNumber;
        while(quotient!=0)
        {
            temp = quotient % 16;
            //To convert integer into character
            if( temp < 10)
                temp =temp + 48;
            else
                temp = temp + 55;
            hexadecimalNumber[i++]= temp;
            quotient = quotient / 16;
        }
        fprintf(pt1,"\nDecimal to Hexadecimal conversion result:\n");
        printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
        for (j = i -1 ; j> 0; j--)
        {
            printf("%c",hexadecimalNumber[j]);
            fprintf(pt1,"%c",hexadecimalNumber[j]);
        }
        printf("\n\n");
    }
    else if(a == 7) // octal to binary
    {
        char octalnum[MAX];
        long i = 0;
        printf("Enter any octal number: ");
        scanf("%s", octalnum);
        fprintf(pt1,"\nOctal to Binary conversion result:\n");
        printf("Equivalent binary value: ");
        fprintf(pt1,"Equivalent binary value: ");
        while (octalnum[i])
        {
            switch (octalnum[i])
            {
            case '0':
                printf("000");
                fprintf(pt1, "000");
                break;
            case '1':
                printf("001");
                fprintf(pt1, "001");
                break;
            case '2':
                printf("010");
                fprintf(pt1, "010");
                break;
            case '3':
                printf("011");
                fprintf(pt1, "011");
                break;
            case '4':
                printf("100");
                fprintf(pt1, "100");
                break;
            case '5':
                printf("101");
                fprintf(pt1, "101");
                break;
            case '6':
                printf("110");
                fprintf(pt1, "110");
                break;
            case '7':
                printf("111");
                fprintf(pt1, "111");
                break;
            default:
                printf("\n Invalid octal digit %c ", octalnum[i]);
            }
            i++;
        }
        printf("\n\n");
    }
    else if(a == 8) //octal decimal
    {
        long int octal, decimal = 0;
        int i = 0;
        printf("Enter any octal number: ");
        scanf("%ld", &octal);
        while (octal != 0)
        {
            decimal =  decimal +(octal % 10)* pow(8, i++);
            octal = octal / 10;
        }
        fprintf(pt1,"\nOctal to Deciaml conversion result:\n");
        printf("Equivalent decimal value: %ld\n\n",decimal);
        fprintf(pt1,"Equivalent decimal value: %ld\n\n",decimal);
    }
    else if(a == 9) //octal to hexa
    {
        int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};
        long long octal, tempOctal, binary, place;
        char hex[65] = "";
        int rem;
        place = 1;
        binary = 0;
        /* Input octal number from user */
        printf("Enter any octal number: ");
        scanf("%lld", &octal);
        tempOctal = octal;
        //Octal to binary conversion
        while(tempOctal > 0)
        {
            rem = tempOctal % 10;
            binary = (OCTALVALUES[rem] * place) + binary;
            tempOctal /= 10;
            place *= 1000;
        }
        //Binary to hexadecimal conversion
        while(binary > 0)
        {
            rem = binary % 10000;
            switch(rem)
            {
            case 0:
                strcat(hex, "0");
                break;
            case 1:
                strcat(hex, "1");
                break;
            case 10:
                strcat(hex, "2");
                break;
            case 11:
                strcat(hex, "3");
                break;
            case 100:
                strcat(hex, "4");
                break;
            case 101:
                strcat(hex, "5");
                break;
            case 110:
                strcat(hex, "6");
                break;
            case 111:
                strcat(hex, "7");
                break;
            case 1000:
                strcat(hex, "8");
                break;
            case 1001:
                strcat(hex, "9");
                break;
            case 1010:
                strcat(hex, "A");
                break;
            case 1011:
                strcat(hex, "B");
                break;
            case 1100:
                strcat(hex, "C");
                break;
            case 1101:
                strcat(hex, "D");
                break;
            case 1110:
                strcat(hex, "E");
                break;
            case 1111:
                strcat(hex, "F");
                break;
            }
            binary /= 10000;
        }
        strrev(hex);
        fprintf(pt1,"\nOctal to Hexadecimal conversion result:\n");
        printf("Hexadecimal number: %s\n\n", hex);
        fprintf(pt1,"Hexadecimal number: %s\n\n", hex);
    }
    else if(a == 10) //hexa to binary
    {
        char binarynum[MAX], hexa[MAX];
        long int i = 0;
        printf("Enter the value for hexadecimal: ");
        scanf("%s", hexa);
        fprintf(pt1,"\nHexadecimal to Binary conversion result:\n");
        printf("\nEquivalent binary value: ");
        fprintf(pt1,"\nEquivalent binary value: ");
        while (hexa[i])
        {
            switch (hexa[i])
            {
            case '0':
                printf("0000");
                fprintf(pt1, "0000");
                break;
            case '1':
                printf("0001");
                fprintf(pt1, "0001");
                break;
            case '2':
                printf("0010");
                fprintf(pt1, "0010");
                break;
            case '3':
                printf("0011");
                fprintf(pt1, "0011");
                break;
            case '4':
                printf("0100");
                fprintf(pt1, "0100");
                break;
            case '5':
                printf("0101");
                fprintf(pt1, "0101");
                break;
            case '6':
                printf("0110");
                fprintf(pt1, "0110");
                break;
            case '7':
                printf("0111");
                fprintf(pt1, "0111");
                break;
            case '8':
                printf("1000");
                fprintf(pt1, "1000");
                break;
            case '9':
                printf("1001");
                fprintf(pt1, "1001");
                break;
            case 'A':
                printf("1010");
                fprintf(pt1, "1010");
                break;
            case 'B':
                printf("1011");
                fprintf(pt1, "1011");
                break;
            case 'C':
                printf("1100");
                fprintf(pt1, "1100");
                break;
            case 'D':
                printf("1101");
                fprintf(pt1, "1101");
                break;
            case 'E':
                printf("1110");
                fprintf(pt1,"1110");
                break;
            case 'F':
                printf("1111");
                fprintf(pt1, "1111");
                break;
            case 'a':
                printf("1010");
                fprintf(pt1, "1010");
                break;
            case 'b':
                printf("1011");
                fprintf(pt1, "1011");
                break;
            case 'c':
                printf("1100");
                fprintf(pt1,"1100");
                break;
            case 'd':
                printf("1101");
                fprintf(pt1,"1101");
                break;
            case 'e':
                printf("1110");
                fprintf(pt1,"1110");
                break;
            case 'f':
                printf("1111");
                fprintf(pt1, "1111");
                break;
            default:
                printf("\n Invalid hexadecimal digit %c ", hexa[i]);
            }
            i++;
        }
        printf("\n\n");
    }
    else if(a == 11) //hexa to octal
    {
        char hex[20];
        printf("Enter Hexadecimal Number : ");
        scanf("%s",hex);
        fprintf(pt1,"\n Hexadecimal to Octal conversion result:\n");
        printf("Equivalent Octal Value = %d\n\n",h2o(hex));
        fprintf(pt1,"Equivalent Octal Value = %d\n\n",h2o(hex));
    }
    else if(a==12) // hexa to decimal
    {
        long long decimalNumber=0;
        char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char hexadecimal[30];
        int i, j, power=0, digit;
        printf("Enter a Hexadecimal Number\n");
        scanf("%s", hexadecimal);
        /* Converting hexadecimal number to decimal number */
        for(i=strlen(hexadecimal)-1; i >= 0; i--)
        {
            /*search currect character in hexDigits array */
            for(j=0; j<16; j++)
            {
                if(hexadecimal[i] == hexDigits[j])
                {
                    decimalNumber += j*pow(16, power);
                }
            }
            power++;
        }
        fprintf(pt1,"\nHexadecimal to decimal conversion result:\n");
        printf("Decimal Number : %ld\n\n", decimalNumber);
        fprintf(pt1,"Decimal Number : %ld\n\n", decimalNumber);
    }
    else if(a == 13)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
int h2o(char hex[])
{
    int i,len, dec=0, oct=0;
    for(len=0; hex[len]!='\0'; len++);
    for(i=0; hex[i]!='\0'; i++,len--)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            dec= dec + (hex[i]-'0')*pow(16,len-1);
        }
        if(hex[i]>='A' && hex[i]<='F')
        {
            dec = dec + (hex[i]-55)*pow(16,len-1);
        }
        if(hex[i]>='a' && hex[i]<='f')
        {
            dec = dec + (hex[i]-87)*pow(16,len-1);
        }
    } /* Now dec contains the decimal value of given hexadecimal number. */
    i=1;
    while(dec!=0)
    {
        oct = oct + (dec%8)*i;
        dec = dec/8;
        i = i*10;
    }
    return oct;
}
void Trigono()
{
    system("@cls||clear");
    printf("\n\t\t\tPress 1. For Sin\n\t\t\tPress 2. For Cos\n\t\t\tPress 3. For Tan\n\t\t\tPress 4. For Sin Inverse\n\t\t\tPress 5. For Cos Inverse\n\t\t\tPress 6. For Tan Inverse\n\t\t\tPress 7. For Previous Menu\n\n");
    int a;
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    printf("Enter Your Choice :  ");
    scanf("%d", &a);
    if(a==1)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=x*PI/180;
        x=sin(x);
        fprintf(pt1,"\nSin(x) result:\n");
        printf("%2.4f\n\n",x);
        fprintf(pt1,"%2.4f\n\n",x);
    }
    else if(a==2)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=x*PI/180;
        x=cos(x);
        fprintf(pt1,"\nCos(x) result:\n");
        printf("%2.4f\n\n",x);
        fprintf(pt1,"%2.4f\n\n",x);
    }
    else if(a==3)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=x*PI/180;
        x=tan(x);
        fprintf(pt1,"\nTan(x) result:\n");
        printf("%2.4f\n",x);
        fprintf(pt1,"%2.4f\n",x);
    }
    else if(a==4)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=asin(x);
        x=x*(180/PI);
        fprintf(pt1,"\nSin Inverse(x) result:\n");
        printf("%2.2f\n",x);
        fprintf(pt1,"%2.2f\n",x);
    }
    else if(a==5)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=acos(x);
        x=x*180/PI;
        fprintf(pt1,"\nCos Inverse(x) result:\n");
        printf("%2.2f\n",x);
        fprintf(pt1,"%2.2f\n",x);
    }
    else if(a==6)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        x=atan(x);
        x=x*180/PI;
        fprintf(pt1,"\nTan Inverse(x) result:\n");
        printf("%2.2f\n",x);
        fprintf(pt1,"%2.2f\n",x);
    }
    else if(a == 7)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
void Factorial()
{
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    int i,n;
    int fact=1;
    printf("Input n : ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        fact=fact*i;

    fprintf(pt1,"\nFaction result:\n");
    printf("Factorial of this number is: %d\n\n",fact);
    fprintf(pt1,"Factorial of this number is: %d\n\n",fact);
    fclose(pt1);
}
void pandc()
{
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    int n, r, ncr( int, int);
    long npr( int, int);
    long double fact( int);

    fprintf(pt1,"\n Permutation and Combination result:\n");
    printf("Enter value of n & r (n>r):\n");
    scanf("%d %d",&n, &r);
    if( n>= r)
    {
        printf("%dC%d is %d\n", n,r,ncr(n,r));
        fprintf(pt1,"%dC%d is %d\n", n,r,ncr(n,r));

        printf("%dP%d is %ld\n\n", n,r,npr(n,r));
        fprintf(pt1,"%dP%d is %ld\n\n", n,r,npr(n,r));
    }
    else
    {
        printf("WRONG INPUT. Enter the correct input.\n\n");
    }
    fclose(pt1);
}
long double fact( int p)
{
    long double facts = 1;
    int i;
    for ( i = 1; i<= p; i++)
        facts = facts * i;
    return( facts);
}
int ncr ( int n, int r)
{
    return( fact( n) / (fact( r) * fact(n- r) ) ) ;
}
long npr( int n, int r)
{
    return( fact( n) / fact( n- r));
}
void poly()
{
    system("@cls||clear");
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    printf("\n\t\t\tPress 1. For Polynomial Addition \n\t\t\tPress 2. For Polynomial Subtraction\n\t\t\tPress 3. For Polynomial Multiplication\n\t\t\tPress 4. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        int a[100], b[100], c[100],m,n,k,k1,i,j,x;
        system("@cls||clear");
        fprintf(pt1, "\nPolynomial addition result:\n");
        printf("\n\tEnter the no. of terms of the polynomial:");
        scanf("%d", &m);
        printf("\n\tEnter the degrees and coefficients (pair input):");
        for (i=0; i<2*m; i++)
            scanf("%d", &a[i]);
        printf("\n\tFirst polynomial is:");
        fprintf(pt1, "\nFirst polynomial is:");
        k1=0;
        if(a[k1+1]==1)
        {
            printf("x^%d", a[k1]);
            fprintf(pt1, "x^%d", a[k1]);
        }
        else
        {
            printf("%dx^%d", a[k1+1],a[k1]);
            fprintf(pt1, "%dx^%d", a[k1+1],a[k1]);
        }
        k1+=2;
        while (k1<i)
        {
            printf("+%dx^%d", a[k1+1],a[k1]);
            fprintf(pt1, "+%dx^%d", a[k1+1],a[k1]);
            k1+=2;
        }
        printf("\n\n\n\tEnter the no. of terms of 2nd polynomial:");
        scanf("%d", &n);
        printf("\n\tEnter the degrees and co-efficients:");
        for(j=0; j<2*n; j++)
            scanf("%d", &b[j]);
        printf("\n\tSecond polynomial is:");
        fprintf(pt1, "\nSecond polynomial is:");
        k1=0;
        if(b[k1+1]==1)
        {
            printf("x^%d", b[k1]);
            fprintf(pt1, "x^%d", b[k1]);
        }
        else
        {
            printf("%dx^%d",b[k1+1],b[k1]);
            fprintf(pt1, "%dx^%d",b[k1+1],b[k1]);
        }
        k1+=2;
        while (k1<2*n)
        {
            printf("+%dx^%d", b[k1+1],b[k1]);
            fprintf(pt1,"+%dx^%d", b[k1+1],b[k1]);
            k1+=2;
        }
        i=0;
        j=0;
        k=0;
        while (m>0 && n>0)
        {
            if (a[i]==b[j])
            {
                c[k+1]=a[i+1]+b[j+1];
                c[k]=a[i];
                m--;
                n--;
                i+=2;
                j+=2;
            }
            else if (a[i]>b[j])
            {
                c[k+1]=a[i+1];
                c[k]=a[i];
                m--;
                i+=2;
            }
            else
            {
                c[k+1]=b[j+1];
                c[k]=b[j];
                n--;
                j+=2;
            }
            k+=2;
        }
        while (m>0)
        {
            c[k+1]=a[i+1];
            c[k]=a[i];
            k+=2;
            i+=2;
            m--;
        }
        while (n>0)
        {
            c[k+1]=b[j+1];
            c[k]=b[j];
            k+=2;
            j+=2;
            n--;
        }
        printf("\n\n\tSum of the two polynomials is: ");
        fprintf(pt1, "\nSum of the two polynomials is: ");
        k1=0;
        if (c[k1+1]==1)
        {
            printf("x^%d", c[k1]);
            fprintf(pt1, "x^%d", c[k1]);
        }
        else
        {
            printf("%dx^%d", c[k1+1],c[k1]);
            fprintf(pt1, "%dx^%d", c[k1+1],c[k1]);
        }
        k1+=2;
        while (k1<k)
        {
            if (c[k1+1]==1)
            {
                printf("+x^%d", c[k1]);
                fprintf(pt1, "+x^%d", c[k1]);
            }
            else
            {
                printf("+%dx^%d", c[k1+1], c[k1]);
                fprintf(pt1, "+%dx^%d", c[k1+1], c[k1]);
            }
            k1+=2;
        }
        printf("\n\n");
    }
    else if(a==2)
    {
        int a[100], b[100], c[100],m,n,k,k1,i,j,x;
        system("@cls||clear");
        fprintf(pt1, "\nPolynomial subtraction result:\n");
        printf("\n\tEnter the no. of terms of the polynomial:");
        scanf("%d", &m);
        printf("\n\tEnter the degrees and coefficients(pair input):");
        for (i=0; i<2*m; i++)
            scanf("%d", &a[i]);
        printf("\n\tFirst polynomial is:");
        fprintf(pt1, "\nFirst polynomial is:");
        k1=0;
        if(a[k1+1]==1)
        {
            printf("x^%d", a[k1]);
            fprintf(pt1, "x^%d", a[k1]);
        }
        else
        {
            printf("%dx^%d", a[k1+1],a[k1]);
            fprintf(pt1, "%dx^%d", a[k1+1],a[k1]);
        }
        k1+=2;
        while (k1<i)
        {
            printf("+%dx^%d", a[k1+1],a[k1]);
            fprintf(pt1, "+%dx^%d", a[k1+1],a[k1]);
            k1+=2;
        }
        printf("\n\n\n\tEnter the no. of terms of 2nd polynomial:");
        scanf("%d", &n);
        printf("\n\tEnter the degrees and co-efficients:");
        for(j=0; j<2*n; j++)
            scanf("%d", &b[j]);
        printf("\n\tSecond polynomial is:");
        fprintf(pt1, "\nSecond polynomial is:");
        k1=0;
        if(b[k1+1]==1)
        {
            printf("x^%d", b[k1]);
            fprintf(pt1, "x^%d", b[k1]);
        }
        else
        {
            printf("%dx^%d",b[k1+1],b[k1]);
            fprintf(pt1, "%dx^%d",b[k1+1],b[k1]);
        }
        k1+=2;
        while (k1<2*n)
        {
            printf("+%dx^%d", b[k1+1],b[k1]);
            fprintf(pt1,"+%dx^%d", b[k1+1],b[k1]);
            k1+=2;
        }
        i=0;
        j=0;
        k=0;
        while (m>0 && n>0)
        {
            if (a[i]==b[j])
            {
                c[k+1]=a[i+1] - b[j+1];
                c[k]=a[i];
                m--;
                n--;
                i+=2;
                j+=2;
            }
            else if (a[i]>b[j])
            {
                c[k+1]=a[i+1];
                c[k]=a[i];
                m--;
                i+=2;
            }
            else
            {
                c[k+1]=b[j+1];
                c[k]=b[j];
                n--;
                j+=2;
            }
            k+=2;
        }
        while (m>0)
        {
            c[k+1]=a[i+1];
            c[k]=a[i];
            k+=2;
            i+=2;
            m--;
        }
        while (n>0)
        {
            c[k+1]=b[j+1];
            c[k]=b[j];
            k+=2;
            j+=2;
            n--;
        }
        printf("\n\n\tDifference of the two polynomials is: ");
        fprintf(pt1, "\nDifference of the two polynomials is: ");
        k1=0;
        if (c[k1+1]==1)
        {
            printf("x^%d", c[k1]);
            fprintf(pt1, "x^%d", c[k1]);
        }
        else
        {
            printf("%dx^%d", c[k1+1],c[k1]);
            fprintf(pt1, "%dx^%d", c[k1+1],c[k1]);
        }
        k1+=2;
        while (k1<k)
        {
            if (c[k1+1]==1)
            {
                printf("+x^%d", c[k1]);
                fprintf(pt1, "+x^%d", c[k1]);
            }
            else
            {
                printf("+%dx^%d", c[k1+1], c[k1]);
                fprintf(pt1, "+%dx^%d", c[k1+1], c[k1]);
            }
            k1+=2;
        }
        printf("\n\n");
    }
    else if(a==3)
    {
        struct poly
        {
            int degree;
            int coeff;
        };/*End of structure definition*/
        struct poly poly1[10],poly2[10],product[100];
        int noOfTerms1,noOfTerms2,count=-1;
        int i,j;
        system("@cls||clear");
        fprintf(pt1, "\nPolynomial multiplication result:\n");
        printf("\nEnter Number Of Terms Of 1st Polynomial: ");
        scanf("%d",&noOfTerms1);
        for(i=0; i< noOfTerms1; i++)
        {
            printf("\nEnter Degree: ");
            scanf("%d",&poly1[i].degree);
            printf("\nEnter Coefficient: ");
            scanf("%d",&poly1[i].coeff);
        }/*End of i for loop*/
        printf("\n First Polynomial: ");
        fprintf(pt1, "\n First Polynomial: ");
        for(i=0; i< noOfTerms1; i++)
        {
            if(poly1[i].degree==0)
            {
                printf("%d ",poly1[i].coeff);
                fprintf(pt1,"%d ",poly1[i].coeff);
            }
            else if(poly1[i].degree==1)
            {
                printf("%dx ",poly1[i].coeff);
                fprintf(pt1,"%dx ",poly1[i].coeff);
            }
            else
            {
                printf("%dx^%d ",poly1[i].coeff,poly1[i].degree);
                fprintf(pt1, "%dx^%d ",poly1[i].coeff,poly1[i].degree);
            }
            if(i!=noOfTerms1-1)
            {
                printf("+ ");
                fprintf(pt1, "+ ");
            }
        }/*End of i for loop*/
        printf("\nEnter Number Of Terms Of 2nd Polynomial: ");
        scanf("%d",&noOfTerms2);
        for(i=0; i< noOfTerms2; i++)
        {
            printf("\nEnter Degree: ");
            scanf("%d",&poly2[i].degree);
            printf("\nEnter Coefficient: ");
            scanf("%d",&poly2[i].coeff);
        }/*End of i for loop*/

        printf("\n Second Polynomial: ");
        fprintf(pt1, "\n Second Polynomial: ");
        for(i=0; i< noOfTerms2; i++)
        {
            if(poly2[i].degree==0)
            {
                printf("%d ",poly2[i].coeff);
                fprintf(pt1, "%d ",poly2[i].coeff);
            }
            else if(poly2[i].degree==1)
            {
                printf("%dx ",poly2[i].coeff);
                fprintf(pt1, "%dx ",poly2[i].coeff);
            }

            else
            {
                printf("%dx^%d ",poly2[i].coeff,poly2[i].degree);
                fprintf(pt1, "%dx^%d ",poly2[i].coeff,poly2[i].degree);
            }
            if(i!=noOfTerms2-1)
            {
                printf("+ ");
                fprintf(pt1, "+ ");
            }
        }
        for(i=0; i< noOfTerms1; i++)
        {
            for (j=0; j< noOfTerms2; j++)
            {
                product[++count].degree=poly1[i].degree+poly2[j].degree;
                product[count].coeff=poly1[i].coeff*poly2[j].coeff;
            }/*End of j for loop*/
        }/*End of i for loop*/
        printf("\nThe Product Of Two Polynomials Is: ");
        fprintf(pt1, "\nThe Product Of Two Polynomials Is: ");
        for(i=0; i<=count; i++)
        {
            if(product[i].degree==0)
            {
                printf("%d ",product[i].coeff);
                fprintf(pt1, "%d ",product[i].coeff);
            }
            else if(product[i].degree==1)
            {
                printf("%dx ",product[i].coeff);
                fprintf(pt1, "%dx ",product[i].coeff);
            }
            else
            {
                printf("%dx^%d ",product[i].coeff,product[i].degree);
                fprintf(pt1, "%dx^%d ",product[i].coeff,product[i].degree);
            }
            if(i!=count)
            {
                printf("+ ");
                fprintf(pt1, "+ ");
            }
        }
        printf("\n\n");
    }
    else if(a == 4)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
void samop()
{
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    system("@cls||clear");
    printf("\n\t\t\tPress 1. For Addition\n\t\t\tPress 2. For Subtraction\n\t\t\tPress 3. For Multiply\n\t\t\tPress 4. For Division\n\t\t\tPress 5. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        int i,e;
        float f,sum=0;
        printf("Enter the no you want to add\n");
        scanf("%d",&e);
        printf("Enter the no:\n");
        for(i=0; i<e; i++)
        {
            scanf("%f",&f);
            sum=sum+f;
        }
        fprintf(pt1, "\nAddition result:\n");
        printf("The sum is %f\n\n",sum);
        fprintf(pt1,"The sum is %f\n\n",sum);
    }
    else if(a==2)
    {
        float sub,g,h;
        printf("Enter two no you want sub\n");
        scanf("%f %f",&g,&h);
        sub=g-h;
        fprintf(pt1, "\nSubtraction result:\n");
        printf("sub=%f-%f=%f\n\n",g,h,sub);
        fprintf(pt1,"sub=%f-%f=%f\n\n",g,h,sub);
    }
    else if(a==3)
    {
        int e,i;
        float f,mul=1;
        printf("Enter the no you want to multiply\n");
        scanf("%d",&e);
        printf("Enter the numbers:\n");
        for(i=1; i<=e; i++)
        {
            scanf("%f",&f);
            mul=mul*f;
        }
        fprintf(pt1, "\nMultiplication result:\n");
        printf("The multiple is: %f\n\n",mul);
        fprintf(pt1,"The multiple is: %f\n\n",mul);
    }
    else if(a==4)
    {
        float div,g,h;
        printf("Enter two no you want Division:\n");
        scanf("%f %f",&g,&h);
        div=g/h;
        fprintf(pt1, "\nDivison result:\n");
        printf("Division is=%f/%f=%f\n\n",g,h,div);
        fprintf(pt1,"Division is=%f/%f=%f\n\n",g,h,div);
    }
    else if(a == 5)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
void ssmo()
{
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    system("@cls||clear");
    printf("\n\t\t\tPress 1. For log\n\t\t\tPress 2. For ln\n\t\t\tPress 3. For x to the power n\n\t\t\tPress 4. For e to the power x\n\t\t\tPress 5. For Square root\n\t\t\tPress 6. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        fprintf(pt1, "\nLog(n) result:\n");
        printf("%f\n\n",log10(x));
        fprintf(pt1,"%f\n\n",log10(x));
    }
    else if(a==2)
    {
        float x;
        printf("Input x : ");
        scanf("%f",&x);
        fprintf(pt1, "\nln(n) result:\n");
        printf("%f\n\n",log(x));
        fprintf(pt1,"%f\n\n",log(x));
    }
    else if(a==3)
    {
        int a,n,result=1;
        printf("Enter base:\n");
        scanf("%d",&a);
        printf("Enter power:\n");
        scanf("%d",&n);
        result=a*pow(a,n-1);
        fprintf(pt1, "\nX^n function result:\n");
        printf("%d^%d = %d\n\n", a,n, result);
        fprintf(pt1,"%d^%d = %d\n\n", a,n, result);
    }
    else if(a==4)
    {
        int i;
        float x,sum,T1,T2;
        printf("Input x: ");
        scanf("%f",&x);
        sum=T1=T2=1;
        for(i=1; i<=100; i=i+1)
        {
            T1=T1*x;
            T2=T2*i;
            sum=sum+T1/T2;
        }
        fprintf(pt1, "\ne^x function result:\n");
        printf("%f",sum);
        fprintf(pt1,"%f",sum);
    }
    else if(a==5)
    {
        float x, squareRoot;
        printf("Input x: ");
        scanf("%f",&x);
        squareRoot =  sqrt(x);
        fprintf(pt1, "\nSquare root result:\n");
        printf("Square root of %f =  %f\n\n", x, squareRoot);
        fprintf(pt1,"Square root of %f =  %f\n\n", x, squareRoot);
    }
    else if(a == 6)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
void matrix()
{
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    system("@cls||clear");
    printf("\n\t\t\tPress 1. For Matrix Addition\n\t\t\tPress 2. For Matrix Subtraction\n\t\t\tPress 3. For Matrix Multiplication\n\t\t\tPress 4. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        int m, n, c, d, first[10][10], second[10][10], sum[10][10];
        printf("Enter the number of rows and columns of matrix\n");
        printf("Enter Row: ");
        scanf("%d", &m);
        printf("Enter Column: ");
        scanf("%d",&n);
        printf("Enter the elements of first matrix\n");
        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);

        printf("First matrix is\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < n; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }
        printf("Enter the elements of second matrix\n");
        for (c = 0; c < m; c++)
            for (d = 0 ; d < n; d++)
                scanf("%d", &second[c][d]);

        printf("Second matrixis\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < n; d++)
            {
                printf("%d\t", second[c][d]);
            }
            printf("\n");
        }
        fprintf(pt1, "\nMatrix addition result:\n");
        printf("Sum of entered matrices:-\n");
        fprintf(pt1,"Sum of entered matrices:-\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0 ; d < n; d++)
            {
                sum[c][d] = first[c][d] + second[c][d];
                printf("%d\t", sum[c][d]);
                fprintf(pt1,"%d\t", sum[c][d]);
            }
            printf("\n");
            fprintf(pt1,"\n");
        }
    }
    else if(a==2)
    {
        int m, n, c, d, first[10][10], second[10][10], difference[10][10];
        printf("Enter the number of rows and columns of matrix\n");
        printf("Enter Row: ");
        scanf("%d", &m);
        printf("Enter Column: ");
        scanf("%d",&n);
        printf("Enter the elements of first matrix\n");

        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);

        printf("First matrix is\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < n; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }
        printf("Enter the elements of second matrix\n");
        for (c = 0; c < m; c++)
            for (d = 0 ; d < n; d++)
                scanf("%d", &second[c][d]);

        printf("Second matrixis\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < n; d++)
            {
                printf("%d\t", second[c][d]);
            }
            printf("\n");
        }
        fprintf(pt1, "\nMatrix subtraction result:\n");
        printf("Difference of entered matrices:-\n");
        fprintf(pt1,"Difference  of entered matrices:-\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0 ; d < n; d++)
            {
                difference[c][d] = first[c][d] - second[c][d];
                printf("%d\t", difference[c][d]);
                fprintf(pt1,"%d\t", difference[c][d]);
            }
            printf("\n");
            fprintf(pt1,"\n");
        }
    }
    else if(a==3)
    {
        int m, n, p, q, c, d, k, sum = 0;
        int first[10][10], second[10][10], multiply[10][10];

        printf("Enter number of rows and columns of first matrix\n");
        printf("Enter Row: ");
        scanf("%d", &m);
        printf("Enter Column: ");
        scanf("%d",&n);
        printf("Enter elements of first matrix\n");

        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);
        printf("First matrix is\n");
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < n; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }

        printf("Enter number of rows and columns of second matrix\n");
        scanf("%d%d", &p, &q);

        if (n != p)
            printf("The matrices can't be multiplied with each other.\n");
        else
        {
            printf("Enter elements of second matrix\n");

            for (c = 0; c < p; c++)
                for (d = 0; d < q; d++)
                    scanf("%d", &second[c][d]);

            printf("Second matrix is\n");
            for (c = 0; c < p; c++)
            {
                for (d = 0; d < q; d++)
                {
                    printf("%d\t", second[c][d]);
                }
                printf("\n");
            }

            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                {
                    for (k = 0; k < p; k++)
                    {
                        sum = sum + first[c][k]*second[k][d];
                    }
                    multiply[c][d] = sum;
                    sum = 0;
                }
            }
            fprintf(pt1, "\nMatrix multiplication result:\n");
            printf("Product of the matrices:\n");
            fprintf(pt1, "Product of the matrices:\n");
            for (c = 0; c < m; c++)
            {
                for (d = 0; d < q; d++)
                {
                    printf("%d\t", multiply[c][d]);
                    fprintf(pt1,"%d\t", multiply[c][d]);
                }
                printf("\n");
                fprintf(pt1,"\n");
            }
        }
    }
    else if(a == 4)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
//using for vector function
typedef double val;
void anglemid_vector(val a,val b,val c,val d,val e,val f,val g,val *h)
{
    val i;
    i=acos((a*d+b*e+c*f)/(sqrt(a*a+b*b+c*c)*sqrt(d*d+e*e+f*f)));
    if(g!=1&&g!=2&&g!=3)
        printf("\n SYNTAX ERROR:TRY AGAIN \n ");
    else
        *h=(g==1)?(i*RD):((g==2)?(i):(i*RG));
}
void vectors()
{


    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    system("@cls||clear");
    printf("\n\t\t\tPress 1. To find Magnitude(A) \n\t\t\tPress 2. To find Direction(A) \n\t\t\tPress 3. To find Angle(A,B) \n\t\t\tPress 4. To find (A)+(B)\n\t\t\tPress 5. To find (A)-(B)\n\t\t\tPress 6. To find [a]*(A)\n\t\t\tPress 7. To find Scalar product(A,B)\n\t\t\tPress 8. To find Vector product(A,B)\n\t\t\tPress 9. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("Enter {I,J,K components} of vector (A):\n");
        printf("Enter I: ");
        scanf("%lf",&a);
        printf("Enter J: ");
        scanf("%lf",&b);
        printf("Enter K: ");
        scanf("%lf",&c);
        d=sqrt(a*a+b*b+c*c);
        fprintf(pt1, "\n Vector magnitude result: \n");
        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        printf("\n Magnitude of Vector (A) is {%.2lf} \n\n",d);
        fprintf(pt1, " Magnitude of Vector (A) is {%.2lf} \n",d);
    }
    else if(a==2)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A): \n");
        printf("Enter I: ");
        scanf("%lf",&a);
        printf("Enter J: ");
        scanf("%lf",&b);
        printf("Enter K: ");
        scanf("%lf",&c);
        fprintf(pt1, "\n Vector direction result: \n");
        if(a==0&&b==0&&c==0)
        {
            printf("\n Vector (A) is (%.2lf)I+(%.2lf)j+(%.2lf)K \n",a,b,c);
            printf("\n Direction of Vector (A) IS UNDEFINED:TRY AGAIN \n\n ");
        }
        else
        {
            anglemid_vector(a,b,c,1,0,0,1,&d);
            anglemid_vector(a,b,c,0,1,0,1,&e);
            anglemid_vector(a,b,c,0,0,1,1,&f);
            printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
            fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

            printf("\n Vector (A) makes with [X axis] an angle of {%.2lf} \n",d);
            fprintf(pt1, " Vector (A) makes with [X axis] an angle of {%.2lf} \n",d);

            printf("\n Vector (A) makes with [Y axis] an angle of {%.2lf} \n",e);
            fprintf(pt1, " Vector (A) makes with [Y axis] an angle of {%.2lf} \n",e);

            printf("\n Vector (A) makes with [Z axis] an angle of {%.2lf} \n\n ",f);
            fprintf(pt1, " Vector (A) makes with [Z axis] an angle of {%.2lf} \n\n ",f);


        }
    }
    else if(a==3)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&a);
        printf("Enter (A)J: ");
        scanf("%lf",&b);
        printf("Enter (A)K: ");
        scanf("%lf",&c);

        printf("\n Enter {I,J,K components} of vector (B):\n");
        printf("Enter (B)I: ");
        scanf("%lf",&d);
        printf("Enter (B)J: ");
        scanf("%lf",&e);
        printf("Enter (B)K: ");
        scanf("%lf",&f);

        fprintf(pt1, "\n Vector angle result: \n");

        if((a*a+b*b+c*c)!=0&&(d*d+e*e+f*f)!=0)
        {
            anglemid_vector(a,b,c,d,e,f,1,&g);
            printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
            fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

            printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
            fprintf(pt1, " Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);

            printf("\n Angle between vectors (A) and (B) is {%.2lf degree} \n\n ",g);
            fprintf(pt1, " Angle between vectors (A) and (B) is {%.2lf degree} \n\n ",g);
        }
        else
        {
            printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
            printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
            printf("\n Angle between vectors (A) and (B) IS UNDEFINED:TRY AGAIN \n\n ");
        }
    }
    else if(a==4)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&a);
        printf("Enter (A)J: ");
        scanf("%lf",&b);
        printf("Enter (A)K: ");
        scanf("%lf",&c);

        printf("\n Enter {I,J,K components} of vector (B):\n");
        printf("Enter (B)I: ");
        scanf("%lf",&d);
        printf("Enter (B)J: ");
        scanf("%lf",&e);
        printf("Enter (B)K: ");
        scanf("%lf",&f);

        g=a+d;
        h=b+e;
        i=c+f;
        fprintf(pt1, "\n Vector A+B result: \n");
        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

        printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
        fprintf(pt1, " Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);

        printf("\n Vector (A)+(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
        fprintf(pt1, " Vector (A)+(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
    }
    else if(a==5)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&a);
        printf("Enter (A)J: ");
        scanf("%lf",&b);
        printf("Enter (A)K: ");
        scanf("%lf",&c);

        printf("\n Enter {I,J,K components} of vector (B):\n");
        printf("Enter (B)I: ");
        scanf("%lf",&d);
        printf("Enter (B)J: ");
        scanf("%lf",&e);
        printf("Enter (B)K: ");
        scanf("%lf",&f);

        g=a-d;
        h=b-e;
        i=c-f;
        fprintf(pt1, "\n Vector A-B result: \n");
        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

        printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
        fprintf(pt1, " Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);

        printf("\n Vector (A)-(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
        fprintf(pt1, " Vector (A)-(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
    }
    else if(a==6)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {a} value:");
        scanf("%lf",&a);
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&b);
        printf("Enter (A)J: ");
        scanf("%lf",&c);
        printf("Enter (A)K: ");
        scanf("%lf",&d);
        e=a*b;
        f=a*c;
        g=a*d;
        fprintf(pt1, "\n Vector [a]*(A) result: \n");
        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",b,c,d);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",b,c,d);

        printf("\n Vector [%.2lf]*(A) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",a,e,f,g);
        fprintf(pt1, " Vector [%.2lf]*(A) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",a,e,f,g);
    }
    else if(a==7)
    {
        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&a);
        printf("Enter (A)J: ");
        scanf("%lf",&b);
        printf("Enter (A)K: ");
        scanf("%lf",&c);
        printf("\n Enter {I,J,K components} of vector (B):\n");
        printf("Enter (B)I: ");
        scanf("%lf",&d);
        printf("Enter (B)J: ");
        scanf("%lf",&e);
        printf("Enter (B)K: ");
        scanf("%lf",&f);

        g=a*d+b*e+c*f;
        fprintf(pt1, "\n Vector scalar product result: \n");

        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

        printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
        fprintf(pt1," Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);

        printf("\n Scalar product OR Dot product of Vectors \n");
        fprintf(pt1, " Scalar product OR Dot product of Vectors \n");

        printf("\n (A) and (B) represented by (A).(B) is {%.2lf} \n\n ",g);
        fprintf(pt1, " (A) and (B) represented by (A).(B) is {%.2lf} \n\n ",g);
    }
    else if(a==8)
    {

        val choice,a,b,c,d,e,f,g,h,i;
        printf("\n Enter {I,J,K components} of vector (A):\n");
        printf("Enter (A)I: ");
        scanf("%lf",&a);
        printf("Enter (A)J: ");
        scanf("%lf",&b);
        printf("Enter (A)K: ");
        scanf("%lf",&c);
        printf("\n Enter {I,J,K components} of vector (B):\n");
        printf("Enter (B)I: ");
        scanf("%lf",&d);
        printf("Enter (B)J: ");
        scanf("%lf",&e);
        printf("Enter (B)K: ");
        scanf("%lf",&f);

        g=b*f-c*e;
        h=c*d-a*f;
        i=a*e-b*d;
        fprintf(pt1, "\n Vector vector product result: \n");

        printf("\n Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);
        fprintf(pt1, " Vector (A) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",a,b,c);

        printf("\n Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);
        fprintf(pt1," Vector (B) is (%.2lf)I+(%.2lf)J+(%.2lf)K \n",d,e,f);

        printf("\n Vector product OR Cross product of Vectors (A) and (B) \n");
        fprintf(pt1, " Vector product OR Cross product of Vectors (A) and (B) \n");

        printf("\n represented by (A)x(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
        fprintf(pt1, " represented by (A)x(B) is {%.2lf}I+{%.2lf}J+{%.2lf}K \n\n ",g,h,i);
    }
    else if(a == 9)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
void equations()
{
    system("@cls||clear");
    FILE *pt1, *pt2;
    pt1=fopen("results.txt","a");
    printf("\n\t\t\tPress 1. ax^2+bx+c=0 \n\t\t\tPress 2. ax^3+bx^2+cx+d=0\n\t\t\tPress 3. ax+by+c=0  dx+ey+f=0 \n\t\t\tPress 4. ax+b=c \n\t\t\tPress 5. (a+b)^2 \n\t\t\tPress 6. For Previous Menu\n\n");
    int a;
    printf("Enter Your Choice : ");
    scanf("%d", &a);
    if(a==1)
    {
        double a, b, c, determinant, root1,root2, realPart, imaginaryPart;
        printf("Enter coefficients a, b and c: \n");
        printf("Enter a: ");
        scanf("%lf",&a);
        printf("Enter b: ");
        scanf("%lf",&b);
        printf("Enter c: ");
        scanf("%lf",&c);
        determinant = b*b-4*a*c;
        // condition for real and different roots
        fprintf(pt1, "\n ax^2+bx+c=0 result:\n");
        printf("\nThe two roots are:\n");
        fprintf(pt1, "\nThe two roots are(ax^2+bx+c=0):\n");
        if (determinant > 0)
        {
            // sqrt() function returns square root
            root1 = (-b+sqrt(determinant))/(2*a);
            root2 = (-b-sqrt(determinant))/(2*a);
            printf("x1 = %.2lf and x2 = %.2lf\n\n",root1, root2);
            fprintf(pt1,"x1 = %.2lf and x2 = %.2lf\n\n",root1, root2);
        }
        //condition for real and equal roots
        else if (determinant == 0)
        {
            root1 = root2 = -b/(2*a);
            printf("x1 = x2 = %.2lf\n\n", root1);
            fprintf(pt1,"x1 = x2 = %.2lf\n\n", root1);
        }
        // if roots are not real
        else
        {
            realPart = -b/(2*a);
            imaginaryPart = sqrt(-determinant)/(2*a);
            printf("x1 = %.2lf+%.2lfi and x2 = %.2f-%.2fi\n\n", realPart, imaginaryPart, realPart, imaginaryPart);
            fprintf(pt1,"x1 = %.2lf+%.2lfi and x2 = %.2f-%.2fi\n\n", realPart, imaginaryPart, realPart, imaginaryPart);
        }

    }
    else if(a==2)
    {
        float a,b,c,d,x1,x2,x3,disc;
        int i;
        float expr;
        printf("Enter coefficients a, b, c and d: \n");
        printf("Enter a: ");
        scanf("%f",&a);
        printf("Enter b: ");
        scanf("%f",&b);
        printf("Enter c: ");
        scanf("%f",&c);
        printf("Enter d: ");
        scanf("%f",&d);

        i = 0;
        while(i<abs(d))
        {
            expr = a*pow(i,3)+b*pow(i,2)+c*i+d;
            if(expr==0)
            {
                x1=i;
                break;
            }
            expr = a*pow(-i,3)+b*pow(-i,2)+c*(-i)+d;
            if(expr==0)
            {
                x1=-i;
                break;
            }
            i++;
        }
        fprintf(pt1, "\n ax^3+bx^2+cx+d=0 result:\n");
        printf("\nThree roots are(ax^3+bx^2+cx+d=0):\n");
        fprintf(pt1, "\nThree roots are(ax^3+bx^2+cx+d=0):\n");
        printf("x1 = %f",x1);
        fprintf(pt1, "x1 = %f",x1);
        b = b + (a*(x1));
        c = c + (b*(x1));
        disc = (b*b)-(4*a*c);
        if(disc>=0)
        {
            x2 = (-b+sqrt(disc))/(2*a);
            x3 = (-b-sqrt(disc))/(2*a);
            printf("\nx2 = %f\nx3 = %f",x2,x3);
            fprintf(pt1, "\nx2 = %f\nx3 = %f",x2,x3);
        }
        else
        {
            disc = ((4*a*c)-pow(b,2))/(2*a);
            printf("\nx2 = %f+%fi",((-b)/(2*a)),disc);
            fprintf(pt1, "\nx2 = %f+%fi",((-b)/(2*a)),disc);

            printf("\nx3 = %f-%fi",((-b)/(2*a)),disc);
            fprintf(pt1, "\nx3 = %f-%fi",((-b)/(2*a)),disc);
        }
    }
    else if(a==3)
    {
        float a,b,c,d,e,f,x,y;
        printf("Enter coefficients a, b, c, d, e and f: \n");
        printf("Enter a: ");
        scanf("%f",&a);
        printf("Enter b: ");
        scanf("%f",&b);
        printf("Enter c: ");
        scanf("%f",&c);
        printf("Enter d: ");
        scanf("%f",&d);
        printf("Enter e: ");
        scanf("%f",&e);
        printf("Enter f: ");
        scanf("%f",&f);
        x = ((f*b)-(c*e))/((a*e)-(d*b));
        y = ((c*d)-(f*a))/((a*e)-(d*b));
        fprintf(pt1, "\n ax+by+c=0  dx+ey+f=0 result:\n");
        printf("\nResult of this format (ax+by+c=0  dx+ey+f=0): ");
        fprintf(pt1, "\nResult of this format (ax+by+c=0  dx+ey+f=0): ");
        printf("\n x = %f\n y = %f",x,y);
        fprintf(pt1, "\n x = %f\n y = %f",x,y);
        printf("\n\n");
    }
    else if(a==4)
    {
        float a,b,c,x;
        printf("Enter coefficients a, b and c: \n");
        printf("Enter a: ");
        scanf("%f",&a);
        printf("Enter b: ");
        scanf("%f",&b);
        printf("Enter c: ");
        scanf("%f",&c);
        fprintf(pt1, "\n ax+b=c result:\n");
        printf("\nResult of this format (ax+b=c)\n");
        fprintf(pt1, "\nResult of this format (ax+b=c)");
        x = (c-b)/a;
        printf("\nx = %f",x);
        fprintf(pt1, "\nx = %f",x);
        printf("\n\n");
    }
    else if(a==5)
    {
        struct poly
        {
            int degree;
            int coeff;
        };/*End of structure definition*/

        struct poly poly1[10],poly2[10],product[100];
        int noOfTerms1,count=-1;
        int i,j;
        printf("\nEnter the Degree and Coefficient of a and b: ");
        for(i=0; i< 2; i++)
        {
            printf("\nEnter Degree: ");
            scanf("%d",&poly1[i].degree);
            printf("\nEnter Coefficient: ");
            scanf("%d",&poly1[i].coeff);
        }/*End of i for loop*/
        fprintf(pt1, "\n (a+b)^2 result:\n");
        printf("\n The Equation is: ");
        fprintf(pt1, "\n The Equation is: ");
        printf("(");
        fprintf(pt1, "(");
        for(i=0; i< 2; i++)
        {
            if(poly1[i].degree==0)
            {
                printf("%d ",poly1[i].coeff);
                fprintf(pt1,"%d ",poly1[i].coeff);
            }
            else if(poly1[i].degree==1)
            {
                printf("%dx ",poly1[i].coeff);
                fprintf(pt1,"%dx ",poly1[i].coeff);
            }
            else
            {
                printf("%dx^%d ",poly1[i].coeff,poly1[i].degree);
                fprintf(pt1, "%dx^%d ",poly1[i].coeff,poly1[i].degree);
            }
            if(i!=1)
            {
                printf("+ ");
                fprintf(pt1, "+ ");
            }
        }/*End of i for loop*/
        printf(")^2");
        fprintf(pt1, ")^2");
        for(i=0; i< 2; i++)
        {
            for (j=0; j< 2; j++)
            {
                product[++count].degree=poly1[i].degree+poly1[j].degree;
                product[count].coeff=poly1[i].coeff*poly1[j].coeff;
            }/*End of j for loop*/
        }/*End of i for loop*/
        printf("\nThe Product Of (a+b)^2: ");
        fprintf(pt1,"\nThe Product Of (a+b)^2: ");

        for(i=0; i<=count; i++)
        {
            if(product[i].degree==0)
            {
                printf("%d ",product[i].coeff);
                fprintf(pt1, "%d ",product[i].coeff);
            }
            else if(product[i].degree==1)
            {
                printf("%dx ",product[i].coeff);
                fprintf(pt1, "%dx ",product[i].coeff);
            }
            else
            {
                printf("%dx^%d ",product[i].coeff,product[i].degree);
                fprintf(pt1, "%dx^%d ",product[i].coeff,product[i].degree);
            }
            if(i!=count)
            {
                printf("+ ");
                fprintf(pt1, "+ ");
            }
        }
        printf("\n\n");
    }
    else if(a == 6)
    {
        calculate();
    }
    else
    {
        printf("Wrong Input!..Please Enter a valid Choice..\n");
    }
    fclose(pt1);
}
