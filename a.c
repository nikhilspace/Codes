#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void main_menu();

struct date
{
    int month,day,year;   
};

struct
{
    char item_name[30];
    int item_code;
    int price;
    int quantity;
    struct date update;
    char customer[30];
    long long int phone;
    int total;
    long long int invoice;
}add,remov,edit,check;


void delay (int n) 
{
    int millisecond = 800*n;

    time_t start = clock();

    while (clock() < start + millisecond) {}
}


void bill() 
{
    system("cls");
    FILE *old,*new,*bill;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    bill=fopen("Sales_report.dat","a+");

    printf("Date (mm/dd/yy): ");
    scanf("%d/%d/%d",&check.update.month,&check.update.day,&check.update.year);
    printf("Customer Name: ");
    scanf("%s",&check.customer);
    printf("Phone: ");
    scanf("%lld",&check.phone);
    printf("Product code: ");
    scanf("%d",&check.item_code);
    printf("Quantity: ");
    scanf("%d",&check.quantity);
    int choice;
    int rem=0;
    printf("Enter 1 to add more product or 0 to continue: ");
    scanf("%d",&choice);
    if (choice==1) 
    {   rem=1;
        printf("Product code: ");
        scanf("%d",&edit.item_code);
            printf("Quantity: ");
            scanf("%d",&edit.quantity);
    }
    printf("Enter 1 to add more product or 0 to continue: ");
    scanf("%d",&choice);
    if (choice==1) 
    {   rem=2;
        printf("Product code: ");
        scanf("%d",&remov.item_code);
            printf("Quantity: ");
            scanf("%d",&remov.quantity);
    }

    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if(check.item_code==add.item_code) 
        {
            add.total=add.price;
            while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
                {
                    if (edit.item_code==add.item_code) 
                    {    
                        add.total=add.total+add.price;
                        while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
                            {
                                if (remov.item_code==add.item_code) 
                                {    
                                 add.total=add.total+add.price;

                                }
                            }
                    }
                }
        }   
    }
    printf("%d",add.total);
}


int remove_product()
{   int choice;
    system("cls");
    FILE *old,*new;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    printf("Enter product code which you want to remove: ");
    scanf("%d",&remov.item_code);

    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if (remov.item_code==add.item_code)
        {   
            choice=1;
            printf("\n\n\nProduct Deleted!\n");
        }
        else
        fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity,add.update.month,add.update.day,add.update.year);
    }

    fclose(old);
    fclose(new);
    remove("inventory.dat");
    rename("newinventory.dat","inventory.dat");

    if (choice==1)
    {
        int try;
        printf("\n\nEnter 1 to delete another product or 0 to exit:\n");
        scanf("%d",&try);
    
    if (try==1) {
        remove_product();
    }
    else
        return 0;
    }

    if (choice!=1);
    {
        printf("Product not in inventory\n\n");
        int try;
        printf("Enter 1 to try again or 0 to exit\n:");
        scanf("%d",&try);
    
        if (try==1) 
        {
        remove_product();
        }
        else
        return 0;
    }

}

void check_inventory() 
{
    system("cls");
    FILE *old;
    old=fopen("inventory.dat","r");
    
    printf("PRODUCT|PRODUCT CODE|PRICE|QUANTITY|LAST UPDATED\n\n");
    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        printf("%s  %d  %drs  %d  %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity,add.update.month,add.update.day,add.update.year);
    }
}


void edit_product() 
{   int count;
    system("cls");
    FILE *old,*new;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    printf("Today's Date (mm/dd/yy): \n");
    scanf("%d/%d/%d",&edit.update.day,&edit.update.month,&edit.update.year);
    printf("Enter Product code: ");
    scanf("%d",&check.item_code);

    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if (check.item_code==add.item_code) {
            try_again:
            count=1;
            int choice;
            system("cls");
            printf("1.Change Name\n2.Change Price\n3.Change Quantity\n4.Main Menu\n");
            scanf("%d",&choice);

            if (choice==1) 
            {
                printf("Enter new name: ");
                scanf("%s",edit.item_name);

                fprintf(new,"%s %d %d %d %d/%d/%d\n",edit.item_name,add.item_code,add.price,add.quantity,edit.update.month,edit.update.day,edit.update.year);
                printf("Edited succesfully.\n");

            }

            else if (choice==2) 
            {
                printf("Enter new price: ");
                scanf("%d",&edit.price);

                fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,edit.price,add.quantity,edit.update.month,edit.update.day,edit.update.year);
                printf("Edited succesfully.\n");

            }

            else if (choice==3) 
            {
                printf("Enter quantity: ");
                scanf("%d",&edit.quantity);

                fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,edit.quantity,edit.update.month,edit.update.day,edit.update.year);
                printf("Edited succesfully.\n");

            }
            else if (choice!=1||choice!=2||choice!=3)
            {
                printf("Wrong Input!\n");
                delay(3);
                goto try_again;
            }
        }
        else
        fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity,add.update.month,add.update.day,add.update.year);
    }
        if (count!=1) 
        {
            int n;
            printf("Product not in database.\n");
            printf("Enter 1 to try again or 2 for Main menu.\n\n:");
                scanf("%d",&n);
                if (n==1)
                edit_product();

                else
                main_menu();
        }
        fclose(old);
        fclose(new);
        remove("inventory.dat");
        rename("newinventory.dat","inventory.dat");
}


void add_product() 
{
    system("cls");
    FILE *old;
    old=fopen("inventory.dat","a+");
    try_again:

    printf("Product Name: \n");
    scanf("%s",check.item_name);
    printf("Product Code: \n");
    scanf("%d",&check.item_code);

    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",&add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if (check.item_code==add.item_code) 
        {
            printf("Product already in inventory.\n");
            printf("Enter 1 to input another product, 2 to edit existing product details or 0 for Main menu.\n\n:");
            int choice;
            scanf("%d",&choice);

            if (choice==1)
            goto try_again;

            else if (choice==2)
            edit_product();

            else
            main_menu();
        }
    }
    
    printf("Product MRP: \n");
    scanf("%d",&add.price);
    printf("Product Quantity: \n");
    scanf("%d",&add.quantity);
    printf("Today's Date (mm/dd/yy): \n");
    scanf("%d/%d/%d",&add.update.day,&add.update.month,&add.update.year);

    fprintf(old,"%s %d %d %d %d/%d/%d\n",check.item_name,check.item_code,add.price,add.quantity,add.update.day,add.update.month,add.update.year);

    fclose(old);
}


void main_menu () 
{
    int choice;
    system("cls");
    printf("\t\t\t---MAIN MENU---");
    printf("\n\n1.Print bill\n2.Add Product\n3.Edit Product\n4.Check Inventory\n5.Remove Product\n\n\n:");
    scanf("%d",&choice);

    switch (choice) {
        case 1:bill();break;
        case 2:add_product();break;
        case 3:edit_product();break;
        case 4:check_inventory();break;
        case 5:remove_product();break;
    }
}

void main () 
{
    system("cls");
    printf("\t\t\tFASHION STORE MANAGEMENT PROGRAM\n");
    printf("\t\t\tby Nikhil Mahar");

for(int i=0;i<3;i++) 
{
    //delay(1);
    printf(".");
}
    main_menu();
}


