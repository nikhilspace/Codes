#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct date {
    int day,month,year;
};

struct 
{
    char book[30];
    char genre[10];
    int book_id;
    char borrower_name[30];
    char status[10];
    struct date last_update;
} add,update,remov,check;

int delay(int input) 
{
    int ms = 800 * input;

    clock_t start_time = clock();

    while (clock()<start_time + ms);
}

void ad() {
    system("cls");
    FILE *old;
    old=fopen("data.dat","a+");

    printf("Enter today's date (mm/dd/yy)\n:");
    scanf("%d/%d/%d",&add.last_update.day,&add.last_update.month,&add.last_update.year);
    printf("Book name \n:");
    scanf("%s",&add.book);
    printf("Genre \n:");
    scanf("%s",add.genre);
    printf("ISBN no. \n:");
    scanf("%d",&add.book_id);
    printf("Book status (Added/Borrowed/Returned) \n:");
    scanf("%s",&add.status);

    fprintf(old,"%s %s %d %s %s %d/%d/%d \n",add.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
    printf("Book added to the database!");
    delay(2);
    fclose(old);
}

void up () {
    system("cls");
    int count=0;
    FILE *old,*new;
    old=fopen("data.dat","r+");
    new=fopen("newdata.dat","w+");

    printf("Enter today's date (mm/dd/yy)\n:");
    scanf("%d/%d/%d",&check.last_update.day,&check.last_update.month,&check.last_update.year);
    printf("ISBN no. \n:");
    scanf("%d",&check.book_id);

    while(fscanf(old,"%s %s %d %s %s %d/%d/%d \n",add.book,add.genre,&add.book_id,add.status,add.borrower_name,&add.last_update.day,&add.last_update.month,&add.last_update.year)!=EOF) 
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
            
            fprintf(new,"%s %s %d %s %s %d/%d/%d \n",add.book,add.genre,add.book_id,check.status,check.borrower_name,check.last_update.day,check.last_update.month,check.last_update.year);  
        }        
        else {
            fprintf(new,"%s %s %d %s %s %d/%d/%d \n",add.book,add.genre,add.book_id,add.status,add.borrower_name,add.last_update.day,add.last_update.month,add.last_update.year);
        }
    }

    if (count!=1) 
    {   
        int choice;
        printf("book not found \n");
        printf("enter 1 to try again or 0 to exit");
        scanf("%d",&choice);

        if (choice==1) {
            up();
        }
        else 
        goto exit;

    }
    exit:
    fclose(old);
    fclose(new);
    remove("data.dat");
    rename("newdata.dat","data.dat");
}
int main_menu() {
    int choice;
    system("cls");
    printf("\t\t\t:::MAIN MENU:::\n\n\n");
    
    printf("1.Add new book to library \n2.Change book status\n\n\nENTER:");
    scanf("%d",&choice);

    switch (choice) {
    case 1:ad();break;
    case 2:up();break;
    default:break;
    }
}

void main() {
    system("cls");
    printf("\t\tCOLLEGE LIBRARY MANAGEMENT PROGRAM \n");
    printf("\t\tby Nikhil Mahar \n");
    for (int i=0;i<=3;i++) {
        delay(1);
        printf(".");
    }
    
    main_menu();
}
