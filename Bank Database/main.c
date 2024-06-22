#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "Types.h"
#include "Bank_Database.h"


Point_t P;

int main()
{
    createnode(&P);
    Save_File_customer(&P);
    char OP = 0;
    printf("*******Notes*******\
            \n 1 for Add Account \
            \n 2 for Delete Account\
            \n 3 for Transaction\
            \n 4 for displaying all accounts\
            \n 5 for exit \n");
    while(1)
    {
    printf("Enter The Opreation\n");
    scanf("%d",&OP);
    fflush(stdin);
    switch(OP)
    {
        case 1 :
            {
                customer *ptr = get_data_customer();
                addaccount(&P,ptr->name,ptr->balances,ptr->account_number);
                break;
            }
        case 2 :
            {
                printf("Enter Account Number: ");
                char account_number [50] = {0} ;
                scanf("%s",account_number);
                fflush(stdin);
                removeAccountInfo(&P,account_number);
                break;
            }
        case 3 :
            {
                int transaction_type;
                printf("Enter Transaction Type (1 for Deposit, 2 for Withdrawal, 3 for Transfer): ");
                scanf("%d", &transaction_type);
                getchar();

                if (transaction_type == 1 || transaction_type == 2)
                {
                    printf("Enter Account Number: ");
                    char account_number[50] = {0};
                    scanf("%s", account_number);
                    getchar();
                    printf("Enter Amount: ");
                    float amount = 0;
                    scanf("%f", &amount);
                    getchar();
                    handle_transaction(&P, account_number, amount, transaction_type);
                }
                else if (transaction_type == 3)
                {
                    printf("Enter Source Account Number: ");
                    char source_account[50] = {0};
                    scanf("%s", source_account);
                    getchar();
                    printf("Enter Destination Account Number: ");
                    char destination_account[50] = {0};
                    scanf("%s", destination_account);
                    getchar();
                    printf("Enter Amount: ");
                    float amount = 0;
                    scanf("%f", &amount);
                    getchar();
                    handle_transfer(&P, source_account, destination_account, amount);
                }
                break;
            }
        case 4 :
            {
              display(&P);
              break;
            }
        case 5 :
            {
                return 0 ;
            }
    }
    }
    return 0;
}







