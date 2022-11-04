#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main_menu();
void view();

struct date {
    int day,month,year;
};

struct 
{
    char book[30];
    char genre[10];
    long long int book_id;
    char borrower_name[30];
    char status[10];
    struct date last_update;
} add,update,remov,check;

int delay(int input) 
{
    int ms = 800 * input;

    clock_t start_time = clock();

    while (clock() < start_time + ms);
}

void rem()
{   int choice;
    system("cls");
    FILE *old,*new;
    old=fopen("LMPdata.dat","r");
    new=fopen("newdata.dat","w");
    printf("Enter Book's ISBN no along with order of addition:");
    scanf("%lld",&remov.book_id);

    while(fscanf(old,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,&add.book_id,add.status,add.borrower_name,&add.last_update.day,&add.last_update.month,&add.last_update.year)!=EOF)
    {
        if (remov.book_id==add.book_id)
        {   
            choice=1;
            printf("\nBook removed from database!");
        }
        else
        fprintf(new,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
    }
    
    fclose(old);
    fclose(new);
    remove("LMPdata.dat");
    rename("newdata.dat","LMPdata.dat");

    if (choice!=1)
    {
    printf("Book not in database\n");
    printf("Enter 1 to try again or 0 to Exit:");
    scanf("%d",&choice);
    if (choice==1)
    rem();
    if (choice!=1)
    return;
    }
    
    int try;
    printf("\nEnter 1 to delete another Book or 0 to Exit:");
    scanf("%d",&try);
    
    if (try==1) {
        rem();
    }
    else
    return;
}


void ad() 
{
    system("cls");
    FILE *old;
    old=fopen("LMPdata.dat","a");

    printf("Enter today's date (dd/mm/yy)\n:");
    scanf("%d/%d/%d",&add.last_update.day,&add.last_update.month,&add.last_update.year);
    printf("Note:Name must be 18 character long\n");
    printf("Book name :");
    scanf("%s",&check.book);
    try_again:
    printf("ISBN no. \n:");
    scanf("%llu",&add.book_id);
    while(fscanf(old,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,&add.book_id,add.status,add.borrower_name,&add.last_update.day,&add.last_update.month,&add.last_update.year)!=EOF) 
    {
        if (check.book_id==add.book_id) 
        { 
            printf("Book already in the database.\n");
            printf("Please enter the ISBN number along with its order of submision.\n\n");
            goto try_again;
        }
    }
    printf("Genre \n:");
    scanf("%s",add.genre);
    printf("Book status (Addition/Borrowed/Returned) \n:");
    scanf("%s",&add.status);


    fprintf(old,"%s %s %lld %s %s %d/%d/%d\n",check.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
    printf("\nBook added to the database!");
    fclose(old);

    int choice;
    printf("\nEnter 1 To add another book or 0 for Main Menu:");
    scanf("%d",&choice);
    if (choice==1)
    ad();
    else
    main_menu();
}


void up() 
{
    system("cls");
    int count=0;
    FILE *old,*new;
    old=fopen("LMPdata.dat","r");
    new=fopen("newdata.dat","w");

    printf("Enter today's date (dd/mm/yy)\n:");
    scanf("%d/%d/%d",&check.last_update.day,&check.last_update.month,&check.last_update.year);
    printf("ISBN no. \n:");
    scanf("%llu",&check.book_id);

    while(fscanf(old,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,&add.book_id,add.status,add.borrower_name,&add.last_update.day,&add.last_update.month,&add.last_update.year)!=EOF) 
    {
        if (check.book_id==add.book_id) 
        {   
            count=1;
            system("cls");
            printf("Book:%s\n",add.book);
            printf("Enter status \n:");
            scanf("%s",&check.status);
            printf("Enter borrower name \n:");
            scanf("%s",&check.borrower_name);
            
            fprintf(new,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,add.book_id,check.status,check.borrower_name,check.last_update.day,check.last_update.month,check.last_update.year);  
            printf("Status updated succesfully\n\n");
        }     
        else {
            fprintf(new,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
        }
    }

    if (count!=1) 
    {   
        int choice;
        printf("Book not found \n");
        printf("Enter 1 to try again or 0 for Main Menu");
        scanf("%d",&choice);

        if (choice==1) {
            up();
        }
        else 
        main_menu();

    }
    exit:
    fclose(old);
    fclose(new);
    remove("LMPdata.dat");
    rename("newdata.dat","LMPdata.dat");

    int choice;
    printf("Enter 1 To view library or 0 for Main Menu:");
    scanf("%d",&choice);
    if (choice==1)
    view();
    else
    main_menu();
}


void view() 
{
    system("cls");
    FILE *old;
    old=fopen("LMPdata.dat","r+");
    printf("NAME\t\t\t\tGENRE\t\tISBN No.\t\tSTATUS\t\tBORROWER\t\tLAST UPDATE\t\n");
    
    while(fscanf(old,"%s %s %lld %s %s %d/%d/%d\n",add.book,add.genre,&add.book_id,add.status,add.borrower_name,&add.last_update.day,&add.last_update.month,&add.last_update.year)!=EOF)
    {
        printf("%s\t\t%s\t\t%lld\t\t%s\t%s\t\t\t%d/%d/%d\n",add.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
    }

    int choice;
    printf("\n\nEnter 1 To update book info or 0 to for Main Menu:");
    scanf("%d",&choice);
    if (choice==1)
    up();
    else
    main_menu();
}


void main_menu() 
{
    int choice;
    system("cls");
    printf("\t\t\t:::MAIN MENU:::\n\n\n");
    
    printf("1.Add new book \n2.Change book status\n3.View library\n4.Remove Book\n0.Exit\n\n\nNote:Use '_' instead of space.\n\n:");
    scanf("%d",&choice);

    switch (choice) {
    case 1:ad();break;
    case 2:up();break;
    case 3:view();break;
    case 4:rem();break;
    default:break;
    }
}


void main() 
{
    system("cls");
    printf("\t\t:::SBES College Library Management Program:::\n");
    printf("\n\n\n\n\nNikhil Mahar\nLOADING");
    for (int i=0;i<4;i++) 
    {
        delay(1);
        printf(".");
    }
    main_menu();
}
