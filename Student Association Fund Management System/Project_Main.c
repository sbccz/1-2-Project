/*header file including:*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

/*Sub Structure*/
struct date
{
    int day, month, year;
};

/*Main Structure*/
struct
{
    char name[60];
    char id_no[20];
    char department[15];
    char address[60];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add,upd,check,rem,transaction;

/*Globally Declaration*/
int i,j,main_exit;
void menu();

/*It's for delay a window*/
void fordelay(int z)
{
    int i,j;
    for(i=0; i<z; i++)
    {
        j=i;
    }
}


/*for creating new id*/
void new_Id()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(dd/mm/yy): ");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the student ID number: ");
    scanf("%s",&check.id_no);
    while(fscanf(ptr,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (strcmp(check.id_no, add.id_no)==0)
        {
            system("cls");
            system("color 4");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThis ID number already in use!\n");
            fordelay(1000000000);
            system("color 9");
            goto account_no;
        }
    }
    strcpy(add.id_no, check.id_no);
    //add.id_no=check.id_no;
    printf("\nEnter the name: ");
    scanf("%s",&add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter The Department name: ");
    scanf("%s",&add.department);
    printf("\nEnter the address(district): ");
    scanf("%s",add.address);
    printf("\nEnter the phone number(01.....): 01");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: ");
    scanf("%f",&add.amt);

    fprintf(ptr,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);

    fclose(ptr);

    printf("\nAccount created successfully!");

add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    {
        menu();
    }

    else if(main_exit==0)
    {
        close();
    }

    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}


/*for editing existing account*/
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\nEnter the ID No of the student whose info you want to change: ");
    scanf("%s",&upd.id_no);
    while(fscanf(old,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (strcmp(add.id_no, upd.id_no)==0)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n");
            printf("1.Address\n");
            printf("2.Phone\n\n");
            printf("Enter your choice(1 for address and 2 for phone): ");
            scanf("%d",&choice);
            system("cls");

            if(choice==1)
            {
                printf("Enter the new address: ");
                scanf("%s",upd.address);
                fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,upd.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Changes Saved!!");
            }
            else if(choice==2)
            {
                printf("Enter the new phone number(01....): 01");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,upd.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }

        }
        else
        {
            fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
edit_invalid:
        printf("\n\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }
}


/*For Transaction*/
void transact(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("Enter the ID No. of the Student: ");
    scanf("%s",&transaction.id_no);

    while(fscanf(old,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (strcmp(add.id_no, transaction.id_no)==0)
        {
            test = 1;
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw): ");
            scanf("%d",&choice);

            if (choice==1)
            {
                printf("Enter the amount you want to deposit: ");
                scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw: ");
                scanf("%f",&transaction.amt);
                add.amt-=transaction.amt;
                fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
            fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
    {
        printf("\n\nRecord not found!!");
transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==0)
            transact();
        else if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }

    }
    else
    {
        printf("\n\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }
}

/*For See Account Details*/
void see(void)
{
    FILE *ptr;
    int test = 0,choice;

    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.ID No\n2.Name\nEnter your choice: ");
    scanf("%d",&choice);

    if (choice==1)
    {
        printf("\nEnter the ID number: ");
        scanf("%s",&check.id_no);
        while(fscanf(ptr,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if (strcmp(add.id_no, check.id_no)==0)
            {
                system("cls");
                test=1;

                printf("\nDepartment: %s",add.department);
                printf("\nID No: %s",add.id_no);
                printf("\nStudent Name: %s",add.name);
                printf("\nDate Of Birth: %d/%d/%d",add.dob.day,add.dob.month,add.dob.year);
                printf("\nAddress: %s",add.address);
                printf("\nPhone Number: 01%0.0lf",add.phone);
                printf("\nTotal Amount: %0.2f",add.amt);
                printf("\nDate Of Deposit: %d/%d/%d",add.deposit.day,add.deposit.month,add.deposit.year);
            }
        }
    }
    else if(choice==2)
    {
        printf("\nEnter the name: ");
        scanf("%s",&check.name);

        while(fscanf(ptr,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if (strcmp(add.name, check.name)==0)
            {
                system("cls");
                test=1;

                printf("\nDepartment: %s",add.department);
                printf("\nID No: %s",add.id_no);
                printf("\nStudent Name: %s",add.name);
                printf("\nDate Of Birth: %d/%d/%d",add.dob.day,add.dob.month,add.dob.year);
                printf("\nAddress: %s",add.address);
                printf("\nPhone Number: 01%0.0lf",add.phone);
                printf("\nTotal Amount: %0.2f",add.amt);
                printf("\nDate Of Deposit: %d/%d/%d",add.deposit.day,add.deposit.month,add.deposit.year);
            }
        }
    }

    fclose(ptr);
    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
see_invalid:
        printf("\n\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
        {
            menu();
        }
        else if (main_exit==2)
        {
            close();
        }
        else if(main_exit==0)
        {
            see();
        }
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\n\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
    }
    if (main_exit==1)
    {
        system("cls");
        menu();
    }
    else
    {
        system("cls");
        close();
    }
}


void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the ID No. of the Student you want to delete: ");
    scanf("%s",&rem.id_no);

    while(fscanf(old,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if(strcmp(add.id_no,rem.id_no)!=0)
        {
            fprintf(newrec,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.address,add.phone,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
        }
        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
erase_invalid:
        printf("\n\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d",&main_exit);

        if (main_exit==1)
        {
            menu();
        }
        else if(main_exit==2)
        {
            close();
        }
        else if(main_exit==0)
        {
            erase();
        }
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\n\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}




void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\n\t   ID NO\t\tNAME\t\t\tADDRESS(district)\t\tPHONE\n");

    while(fscanf(view,"%s %s %s %d/%d/%d %s %lf %f %d/%d/%d\n",add.department,add.id_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,add.address,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        printf("\n\t%10s\t %10s\t\t\t%10s\t\t\t01%.0lf",add.id_no,add.name,add.address,add.phone);
        test++;
    }
    fclose(view);
    if (test==0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\n\n\n\n\n\n\n\n\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    {
        menu();
    }

    else if(main_exit==0)
    {
        close();
    }

    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}



/*Close function(When you close your project then it will be displayed)*/
void close(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t This Project Is Developed By Mehedi Hassan Joy");
    getch();
}

/*Menu function controled all of my project functionality*/
void menu(void)
{
    int choyce;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tSTUDENT ASSOCIATION FUND MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Add New ID");
    printf("\n\t\t2.Update Information of Existing ID");
    printf("\n\t\t3.For Transactions");
    printf("\n\t\t4.Check the Details of Existing ID");
    printf("\n\t\t5.Removing Existing ID");
    printf("\n\t\t6.View Student's List");
    printf("\n\t\t7.Exit");
    printf("\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choyce);

    system("cls");
    switch(choyce)
    {
    case 1:
        new_Id();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    }


}

int main()
{
    char password[10]="cvbnm";
    char pass[10] = {0,0,0,0,0,0,0,0,0,0};
    int i=0;

    char ch;
    printf("\n\n\n\n\n\t\t\t Enter the password to login: ");
    //scanf("%s",pass);
    int j=0;
    while((ch = getch()) != '\r')
    {

        pass[j] = ch;
        j++;
        printf("*");
    }
    //printf("\n%s",pass);
    if(strcmp(pass, password)==0)
    {
        printf("\n\n\n\n\n\n\t\t\t\t Password Match!");
        printf("\n\t\t\t\t\t\t Loading");
        for(i=0; i<7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
        system("color 4");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Wrong Password!!\a\a\a");

login_try:
        printf("\n\n\n\n\n\n\n\n\n\n\t\tEnter 1 to try again and 0 to exit: ");
        scanf("%d",&main_exit);
        system("color 9");
        if(main_exit == 1)
        {
            system("cls");
            main();
        }
        else if(main_exit ==0)
        {
            system("cls");
            close();
        }
        else
        {
            system("cls");
            printf("\a\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Invalid!! ");
            for(int i=0; i<7; i++)
            {
                fordelay(100000000);
                printf(".");
            }

            system("cls");
            goto login_try;
        }
    }
    return 0;
}
