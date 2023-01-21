#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct user
{
    char phone[50];
    char acountNumber[50];
    char password[50];
    float balance;
};

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{

    gotoxy(25, 8);
    printf("===== HI! WELCOME ===== ");
    gotoxy(25, 10);
    printf("++++++++++ BANKING MANAGEMENT SYSTEM ++++++++++ \n\n");

    gotoxy(25, 12);
    printf("Group's member:");

    gotoxy(25, 14);
    printf("Monika\n");

    gotoxy(25, 15);
    printf("Amit\n");

    gotoxy(25, 16);
    printf("Kashish\n");

    gotoxy(25, 17);
    printf("Utpal\n\n");

    gotoxy(25, 19);
    printf("Press ENTER to start with us");
    getch();

    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int option, choice;
    char cont = 'y';
    float amount;
main:
    system("cls");
    printf("\nHi! Costumer you're welcome!");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");
    printf("\n3. Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &option);

    if (option == 3)
    {
        for (int i = 0; i < 150000; i++)
        {
            i++;
            i--;
            break;
        }
    }

    if (option > 3)
    {
        printf("\nInvalid choice.");
        printf("\nPress any key to continue...");
        getch();
        goto main;
    }

    if (option == 1)
    {
        system("cls");
        printf("Enter your account number:\t");
        scanf("%s", usr.acountNumber);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount succesfully registered");
            printf("\nPress any key to continue...");
            getch();
            goto main;
        }
        else
        {
            printf("\n\nSomething went wrong please try again");
            printf("\nPress any key to continue...");
            getch();
            goto main;
        }
        fclose(fp);
    }
    if (option == 2)
    {
    main2:
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nAccount number not registered");
            printf("\nTo register an account number");
            printf("\nPress any key to continue...");
            getch();
            goto main;
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {
                printf("\n\t\tWelcome %s", usr.phone);
                ;
                while (cont == 'y')
                {
                    system("cls");
                    printf("\n\n   \xB2\xB2 Main Menu \xB2\xB2");
                    printf("\n\nPress 1 for balance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdrawl");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for password change");
                    printf("\npress 6 for exit");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current balance is Rs.%.2f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nSuccesfully deposited.");
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        if (amount > usr.balance)
                        {
                            printf("Insufficent balance");
                        }
                        else
                        {
                            usr.balance -= amount;
                            printf("\nYou have withdrawn Rs.%.2f", amount);
                        }
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);

                        fclose(fp);
                        break;

                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s", phone);

                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f", &amount);

                        strcpy(filename, phone);
                        fp = fopen(strcat(filename, ".dat"), "r");

                        if (fp == NULL)
                            printf("\nAccount number not registered");
                        else
                        {
                        fread(&usr1, sizeof(struct user), 1, fp);

                        fclose(fp);
                        if (amount > usr.balance)
                            printf("\nInsufficient balance");
                        else
                        {

                            fp = fopen(filename, "w");
                            usr1.balance += amount;
                            fwrite(&usr1, sizeof(struct user), 1, fp);

                            fclose(fp);
                            if (fwrite != NULL)
                            {
                            printf("\nYou have succesfully transfered Rs.%.2f to %s", amount, phone);
                            strcpy(filename, usr.phone);

                            fp = fopen(strcat(filename, ".dat"), "w");
                            usr.balance -= amount;

                            fwrite(&usr, sizeof(struct user), 1, fp);
                            fclose(fp);
                            }
                        }
                            break;
                        case 5:
                            printf("\nPlease enter your new password:\t");
                            scanf("%s", pword);
                            
                            fp = fopen(filename, "w");
                            strcpy(usr.password, pword);
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if (fwrite != NULL)
                                printf("\nPassword succesfully changed");
                        }
                        break;

                    case 6:
                        for (int i = 0; i < 10000; i++)
                        {
                            i++;
                            i--;
                        }
                        break;

                    default:
                        printf("\nInvalid option");
                    }

                    printf("\nDo you want to continue the transaction [y/n]\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\nInvalid password\n");
                // printf("Enter the account details one more time\n");
                printf("\n\nPress any key to continue....");
                getch();
                goto main;
            }
        }
    }

    return 0;
}