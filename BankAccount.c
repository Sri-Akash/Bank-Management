#include<stdio.h>
#include<conio.h>
int balanceChecking(int,int);
/*void displayUserAccount();
void amountDeposit();
void amountWithdrawal();
void accountCreation();
void accountLogin();*/
long acc_no=0;
char name[20];
char gender[10];
int balance,withdraw,deposit;
int num1,num2,age,pin;
int main()
{
    printf("\nEnter the any one of the option :");
    printf("\n1.Account Login\n2.Create an Account\n3.Exit\n");
    scanf("%d",&num1);
    switch(num1)
    {
        case 1:
            accountLogin();
            break;
        case 2:
            accountCreation();
            break;
        case 3:
            exit(0);
        default:
            printf("\nEnter the correct option.\n");
    }
    return 0;
}
void bank()
{

    printf("\n\n----------Welcome to Our Bank----------\n");
    printf("\nEnter the any one of the option :\n");
    printf("\n1.Account Details \n2.Remaining Balance \n3.Deposit Amount \n4.Withdraw Amount \n5.exit\n");
    scanf("%d",&num2);
    switch(num2)
    {
        case 1:
            displayUserAccount();
            break;
        case 2:
            balance=balanceChecking(withdraw,deposit);
            break;
        case 3:
            amountDeposit();
            break;
        case 4:
            amountWithdrawal();
            break;
        case 5:
            exit(0);
        default:
            printf("\nEnter the correct option.\n");
    }
}
void displayUserAccount()
{
    char yorn;
    printf("\nName : %s",name);
    printf("\nAge : %d",age);
    printf("\nGender : %s",gender);
    printf("\nAccount Number : %ld\n",acc_no);
    printf("\nDo you want to continue (y:yes or n:no) :\n");
    scanf(" %c",&yorn);
    if(yorn=='y')
        bank();
    else
    {
        printf("\nThank you Come Again.\n");
        main();
    }
}
int balanceChecking(int w,int d)
{
    char yorn;
    int bal;
    bal=d-w;
    printf("\nBank Balance : %d\n",bal);
    printf("\nDo you want to continue (y:yes or n:no) :\n");
    scanf(" %c",&yorn);
    if(yorn=='y')
        bank();
    else
    {
        printf("\nThank you Come Again.\n");
        main();
    }
    return bal;
}
void amountDeposit()
{
    char yorn;
    printf("\nEnter the Deposit amount :\n");
    scanf("%d",&deposit);
    balance=balance+deposit;
    printf("\nDo you want to continue (y:yes or n:no) :\n");
    scanf(" %c",&yorn);
    if(yorn=='y')
        bank();
    else
    {
        printf("\nThank you Come Again.\n");
        main();
    }
}
void amountWithdrawal()
{
    char yorn;
    printf("\nEnter the withdrawal amount :\n ");
    scanf("%d",&withdraw);
    balance=balance-withdraw;
    printf("\nDo you want to continue (y:yes or n:no) :\n");
    scanf(" %c",&yorn);
    if(yorn=='y')
        bank();
    else
    {
        printf("\nThank you Come Again.\n");
        main();
    }
}
void accountCreation()
{
    char press;
    int check=1,count;
    printf("\n-----------Account Creation Section-----------\n ");
    printf("\nEnter your Name :\n");
    scanf("%s",name);
    do
    {
        if(check>1)
        {
            printf("\This Bank must allows only 18+ Customers.\n");
        }
        printf("\nEnter your Age : \n");
        scanf("%d",&age);
        check++;
    }while(age<18);
    printf("\nEnter your Gender : \n");
    scanf("%s",gender);
    printf("\nEnter a four digit Pin : \n");
    scanf("%d",&pin);
    acc_no=acc_no+1;
    printf("\nYour Account is Successfully Created.\n");
    printf("\nYour Account Number is %ld.\n",acc_no);
    printf("\nAre you want to login into our Bank.Press (y:yes or n:no) :\n");
    scanf(" %c",&press);
    if(press=='y')
        accountLogin();
    else
    {
        printf("\nThankyou\n");
    }
}
void accountLogin()
{
    int log_id,log_pin,check;
    printf("\-----------Account Login Section-----------\n");
    printf("\nEnter your Account Number :\n");
    scanf("%d",&log_id);
    printf("Enter your Pin : \n");
    scanf("%d",&log_pin);
    if(log_id==acc_no)
    {
        if(log_pin==pin)
            bank();
        else
        {
            printf("\nIncorrect Pin Number.Try again later.\n");
            accountLogin();
        }

    }
    else
    {
        printf("\nYou have not account in our Bank.\nPress 1 to create an account.\n");
        scanf("%d",&check);
        if(check==1)
            accountCreation();
        else
        {
             printf("\nThankyou\n");
             main();
        }
    }
}
