#include "Types.h"
#include "Bank_Database.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void createnode(Point_t *pl)
{
  pl->head = NULL;
  pl->size = 0;
}

void addaccount(Point_t *pl,char name[50],float balances,char account_number[50])
{
    Node *check = pl->head;  // this node to check account_number that enter is exist or not
    bool flag = false;      // used as pointer that account_number is exist or not

  /*while loop to check the account_number which enter is exist or not*/
  while (check)
  {
    if (strcmp(check->Cust.account_number,account_number)==0)
    {
      flag = true;
      break;
    } else {
      check = check->next;
    }
  }

  /*if flag still false this mean that there is no account_number such user entered*/
  if (flag == false)
    {
    Node *newnode = (Node*)malloc(sizeof(Node));  // make New node to store account in the list
    if (newnode != NULL)    // check for successfully booked memory space
    {
      printf("Account Booked Successfully!!\n");
      strcpy(newnode->Cust.name, name);
      strcpy(newnode->Cust.account_number, account_number);
      newnode->Cust.balances = balances;
      newnode->next = NULL;
      if (pl->head == NULL) /*if New node is the first node in the linked list*/
      {
        pl->head = newnode;
      }
      else
      {
        Node *q = pl->head; /*if linked list already have elements push the New node in rear*/
        while (q->next != NULL)
        {
          q = q->next;
        }
        q->next = newnode;
      }
      pl->size++;
    } else {
      printf("Account NOT BOOKED\n"); /*if space in memory do not booked for New node */
    }

    /*File Handling*/

    FILE *pf = NULL;
    pf = fopen("Customer_Info.txt", "aw");

    if (pf != NULL)
    {
      fprintf(pf, "%s,%s,%0.3f\n", name, account_number,balances);
    }
    else
    {
      printf("NOT OPENED!!\n");
    }
    fclose(pf);
  }
  else
  {
    printf("This Is Account Is Already Existes...\n");
  }
}


void removeAccountInfo(Point_t *pl, char Account_Number[50])
{
  bool flag = false; /*check Account if it exist or not*/
  Node *q = pl->head;
  if (q == NULL)
  {
    printf("There Is No Account!!\n");
    return;
  } /*pointer to move on nodes*/
  Node *temp = NULL;

  /*if Account which i search is exist in first node */
  if (strcmp(q->Cust.account_number,Account_Number)==0)
  {
    pl->head = q->next;
    free(q);
    q = NULL;
    pl->size--;
    UpdateAccountInfo(pl);
    return;
  }

  while (q) /*to reach the node which have the Account which i search*/
  {
    if (((q->next != NULL) && (strcmp(q->Cust.account_number,Account_Number)==0) ))
    {
      flag = true; // this mean that Account is founded
      break;
    }
    else
    {
      q = q->next;
    }
  }

  if (flag) //flag is true this mean we find Account which we searched */
  {
    temp = q->next;
    free(temp);
    temp = NULL;
    q->next = q->next->next;
    UpdateAccountInfo(pl);
    pl->size--;
  }
  else
  {
    printf("No Account Such as You Entered!!\n");
    printf("-------------------------\n");
  }
}


void display(Point_t *pl)
{
    Node *q = pl->head;
    if (q == NULL)
    {
      printf("There Are No Accounts!!\n");
      return;
    }

    while (q)
    {
      printf("Name               : %s\n", q->Cust.name);
      printf("Account Number is  : %s\n", q->Cust.account_number);
      printf("balances           : %0.3f \n", q->Cust.balances);
      printf("-------------------------------------\n");
      q = q->next;
    }
}

void UpdateAccountInfo(Point_t *pl)
{

  FILE *pf = NULL;

  pf = fopen("Customer_Info.txt", "w");

  if (pf != NULL)
    {
    Node *current = pl->head;
    while (current != NULL)
    {
      fprintf(pf, "%s,%s,%0.3f\n", current->Cust.name,
                                      current->Cust.account_number,
                                      current->Cust.balances);
      current = current->next;
    }

  } else {
    printf("NOT OPENED!!\n");
  }
  fclose(pf);
  printf("File updated successfully.\n");
}


customer *get_data_customer()
{

  static customer cus;

  printf("Enter Name: ");
  gets(cus.name);

  printf("Enter Account Number: ");
  gets(cus.account_number);

  printf("Enter Balance you want to add: ");
  scanf("%f", &cus.balances);
  fflush(stdin);

  return &cus;
}

void Save_File_customer(Point_t *pl)
{
    char name[50];
    char account_number[50];
    float balance;

    FILE *pf = fopen("Customer_Info.txt", "r");
    if (pf != NULL)
    {
        while (fscanf(pf, "%49[^,],%49[^,],%f", name, account_number, &balance) == 3)
        {
            int c;
            while ((c = fgetc(pf)) != EOF && c != '\n');

            Node *newnode = (Node *)malloc(sizeof(Node));
            if (newnode != NULL)
            {
                strcpy(newnode->Cust.name, name);
                newnode->Cust.balances = balance;
                strcpy(newnode->Cust.account_number, account_number);
                newnode->next = NULL;

                if (pl->head == NULL)
                {
                    pl->head = newnode;
                }
                else
                {
                    Node *q = pl->head;
                    while (q->next != NULL)
                    {
                        q = q->next;
                    }
                    q->next = newnode;
                }
                pl->size++;
            }
            else
            {
                printf("Memory allocation failed for new node\n");
            }
        }
        fclose(pf);
    }
}

void handle_transaction(Point_t *pl, const char account_number[50], float amount, int transaction_type)
{
    if (pl->head == NULL)
    {
        printf("There are no accounts.\n");
        return;
    }

    Node *current = pl->head;
    bool account_found = false;

    while (current != NULL)
    {
        if (strcmp(current->Cust.account_number, account_number) == 0)
        {
            account_found = true;
            switch (transaction_type)
            {
                case 1: // Deposit
                    current->Cust.balances += amount;
                    printf("Deposit successful. New balance: %0.3f\n", current->Cust.balances);
                    break;
                case 2: // Withdrawal
                    if (current->Cust.balances - amount < 0)
                    {
                        printf("Insufficient funds for withdrawal.\n");
                        return;
                    }
                    current->Cust.balances -= amount;
                    printf("Withdrawal successful. New balance: %0.3f\n", current->Cust.balances);
                    break;
                default:
                    printf("Invalid transaction type.\n");
                    return;
            }

            UpdateAccountInfo(pl);
            return;
        }
        current = current->next;
    }

    if (!account_found)
    {
        printf("Account not found.\n");
    }
}

void handle_transfer(Point_t *pl, const char source_account[50], const char destination_account[50], float amount)
{
    if (pl->head == NULL)
    {
        printf("There are no accounts.\n");
        return;
    }

    Node *source = pl->head;
    Node *destination = pl->head;
    bool source_found = false;
    bool destination_found = false;

    while (source != NULL)
    {
        if (strcmp(source->Cust.account_number, source_account) == 0)
        {
            source_found = true;
            break;
        }
        source = source->next;
    }

    while (destination != NULL)
    {
        if (strcmp(destination->Cust.account_number, destination_account) == 0)
        {
            destination_found = true;
            break;
        }
        destination = destination->next;
    }

    if (!source_found)
    {
        printf("Source account not found.\n");
        return;
    }

    if (!destination_found)
    {
        printf("Destination account not found.\n");
        return;
    }

    if (source->Cust.balances - amount < 0)
    {
        printf("Insufficient funds in source account for transfer.\n");
        return;
    }

    source->Cust.balances -= amount;
    destination->Cust.balances += amount;

    printf("Transfer successful.\n");
    printf("Source account new balance: %0.3f\n", source->Cust.balances);
    printf("Destination account new balance: %0.3f\n", destination->Cust.balances);

    UpdateAccountInfo(pl);
}
