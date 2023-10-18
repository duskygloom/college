// bank customer account management

#include <stdio.h>
#include <stdlib.h>

#define DATAFILE "customer_records_data.txt"
#define CANNOT_WRITE_STATUS 1

typedef struct {
    int account_number;
    double balance;
    int account_active;
} CustomerRecord;

typedef struct Node {
    CustomerRecord *record;
    struct Node *next;
} Node;

// general functions
int get_response();
Node *load_records_list();
void store_records_list(Node *records_list);

// record functions
CustomerRecord *get_record(int account_number);
void print_record(CustomerRecord *record);

// list functions
Node *init_list();
void delete_list(Node *head);
void append_to_list(Node *head, CustomerRecord *record);
int list_length(Node *head);
void print_list(Node *head);
CustomerRecord *find_record_with_number(Node *head, int account_number);

int main()
{
    CustomerRecord *record;
    int number;
    Node *list = load_records_list();
    while (1) {
        switch (get_response()) {
            case 0:
                store_records_list(list);
                return 0;
            case 1:
                store_records_list(list);
                printf("Stored customer records in %s\n", DATAFILE);
                break;
            case 2:
                printf("Account number: ");
                scanf("%d", &number);
                getchar();
                record = find_record_with_number(list, number);
                if (record) {
                    print_record(record);
                    printf("Do you want to change the record? (y/n) ");
                    number = getchar();
                    if (number == 'y' || number == 'Y') {
                        printf("New balance: ");
                        scanf("%lf", &(record->balance));
                        getchar();
                        printf("Is the account active? (y/n) ");
                        number = getchar();
                        if (number == 'y' || number == 'Y')
                            record->account_active = 1;
                        // if not y, then account will be inactive
                        else record->account_active = 0;
                        store_records_list(list);
                        printf("Record changed and saved.\n");
                    }
                }
                else printf("Account number doesn't exist.\n");
                break;
            case 3:
                record = get_record(list_length(list) + 1);
                append_to_list(list, record);
                store_records_list(list);
                printf("Added customer record %d.\n", record->account_number);
                break;
        }
        putchar('\n');
    }
    return 0;
}

int get_response()
{
    int response;
    printf("1. Store customer records in file.\n");
    printf("2. Retrieve the record of a customer with account number and update if required.\n");
    printf("3. Append a new customer to the file.\n");
    printf("0. Quit.\n");
    printf("Response: ");
    scanf("%d", &response);
    return response;
}

Node *load_records_list()
{
    Node *records_list = init_list();
    FILE *file;
    if ((file=fopen(DATAFILE, "r")) == NULL) {
        printf("Data file not found. Creating new file.\n");
        // creating new data file if data doesn't exist
        if ((file = fopen(DATAFILE, "w")) == NULL) {
            printf("Cannot write into datafile.\n");
            exit(CANNOT_WRITE_STATUS);
        }
        else {
            // the first line contains the number of records
            fprintf(file, "0\n");
            fflush(file);
            fclose(file);
        };
    }
    else {
        int length, account_number, account_active;
        double balance;
        CustomerRecord *record;
        fscanf(file, "%d", &length);
        for (; length>0; --length) {
            fscanf(file, "%d %lf %d", &account_number, &balance, 
                &account_active);
            record = malloc(sizeof(CustomerRecord));
            record->account_number = account_number;
            record->balance = balance;
            record->account_active = account_active;
            append_to_list(records_list, record);
        }
        fclose(file);
    }
    return records_list;
}

void store_records_list(Node *records_list)
{
    FILE *file;
    int length = (int)(records_list->record);
    if ((file = fopen(DATAFILE, "w")) == NULL) {
        printf("Cannot write into datafile.\n");
        exit(CANNOT_WRITE_STATUS);
    }
    else {
        fprintf(file, "%d\n", length);
        records_list = records_list->next;
        for (; length>0; --length) {
            fprintf(file, "%d %.2lf %d\n", 
                records_list->record->account_number,
                records_list->record->balance,
                records_list->record->account_active);
            records_list = records_list->next;
        }
        fflush(file);
        fclose(file);
    }
}

CustomerRecord *get_record(int account_number)
{
    // takes input and returns a new CustomerRecord object
    char ch;
    CustomerRecord *record = malloc(sizeof(CustomerRecord));
    record->account_number = account_number;
    printf("Balance: ");
    scanf("%lf", &(record->balance));
    getchar();
    printf("Is the account active? (y/n) ");
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
        record->account_active = 1;
    // if not y, then account will be inactive
    else record->account_active = 0;
    return record;
}

void print_record(CustomerRecord *record)
{
    printf("Account number: %d\n", record->account_number);
    printf("Balance: %.2lf\n", record->balance);
    printf("Account active: ");
    if (record->account_active) printf("Yes\n");
    else printf("No\n");
}

Node *init_list()
{
    // the 0th record stores the length
    Node *newnode = malloc(sizeof(Node));
    newnode->record = 0;
    newnode->next = NULL;
    return newnode;
}

void delete_list(Node *head)
{
    // frees the head too
    Node *prev;
    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

void append_to_list(Node *head, CustomerRecord *record)
{
    Node *current, *newnode;
    // moving to the last element
    for (current=head; current->next; current=current->next);
    // appending record
    newnode = malloc(sizeof(Node));
    newnode->record = record;
    newnode->next = NULL;
    current->next = newnode;
    head->record = (CustomerRecord *)((int)(head->record) + 1);
}

int list_length(Node *head)
{
    int length = 0;
    for (head=head->next; head; head=head->next)
        ++length;
    return length;
}

void print_list(Node *head)
{
    for (head=head->next; head; head=head->next)
        print_record(head->record);
}

CustomerRecord *find_record_with_number(Node *head, int account_number)
{
    for (head=head->next; head; head=head->next) {
        if (head->record->account_number == account_number)
            return head->record;
    }
    return NULL;
}

