#ifndef BANK_DATABASE
#define BANK_DATABASE

void createnode(Point_t *pl);

void addaccount(Point_t *pl, char name[50],float balances,char account_number[50]);

void display(Point_t *pl);

void UpdateAccountInfo(Point_t *pl);

void removeAccountInfo(Point_t *pl, char Account_Number[50]);

customer *get_data_customer();

void Save_File_customer(Point_t *pl);

void handle_transaction(Point_t *pl, const char account_number[50], float amount, int transaction_type);

void handle_transfer(Point_t *pl, const char source_account[50], const char destination_account[50], float amount);


#endif // BANK_DATABASE

