#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>



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
    int choice;
    char product1[30];
    char product2[30];
    char product3[30];
    system("cls");
    FILE *old,*new,*bill;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    bill=fopen("sales_report.dat","a+");

    printf("Date (mm/dd/yy): ");
    scanf("%d/%d/%d",&check.update.month,&check.update.day,&check.update.year);
    printf("Customer Name: ");
    scanf("%s",&check.customer);
    printf("Phone: ");
    scanf("%lld",&check.phone);
    try_again:
    printf("Product code: ");
    scanf("%d",&check.item_code);
    printf("Quantity: ");
    scanf("%d",&check.quantity);
    
    check.invoice=check.update.month+check.update.day+check.update.year*check.phone;

    printf("Enter 1 to add more product or 0 to continue: ");
    scanf("%d",&choice);
    if (choice==1) 
    {   
        printf("Product code: ");
        scanf("%d",&edit.item_code);
        printf("Quantity: ");
        scanf("%d",&edit.quantity);

        printf("Enter 1 to add more product or 0 to continue: ");
        scanf("%d",&choice);


        if (choice==1) 
        {   
        printf("Product code: ");
        scanf("%d",&remov.item_code);
        printf("Quantity: ");
        scanf("%d",&remov.quantity);
        }
    }


    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if(check.item_code==add.item_code) 
        {   
            strcpy(product1,add.item_name);
            add.total=add.price*check.quantity;
            fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity-check.quantity,check.update.month,check.update.day,check.update.year);
        }    

        if (edit.item_code==add.item_code) 
        {   
            strcpy(product2,add.item_name);
            add.total=add.total+add.price*edit.quantity;
            fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity-edit.quantity,check.update.month,check.update.day,check.update.year);
        }
      
        if (remov.item_code==add.item_code) 
        {   
            strcpy(product3,add.item_name);
            add.total=add.total+add.price*remov.quantity;
            fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity-remov.quantity,check.update.month,check.update.day,check.update.year);         
        } 

        if (check.item_code!=add.item_code&&edit.item_code!=add.item_code&&remov.item_code!=add.item_code)
        {
            fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity,add.update.month,add.update.day,add.update.year);      
        }                   
    }

    system("cls");
    printf("\t\t\tBILL\n\n\n");
    printf("Name:%s\n",check.customer);
    printf("Phone:%lld\n",check.phone);
    printf("Date:%d/%d/%d\t\tInvoice:%lld\n\n",check.update.month,check.update.day,check.update.year,check.invoice);
    printf("ITEM DESCRIPTION\t\tQUANTITY\n");
    printf("%s\t\t%d\n%s\t\t%d\n%s\t\t%d\n\n",product1,check.quantity,product2,edit.quantity,product3,remov.quantity);
    printf("TOTAL:%drs",add.total);

    fprintf(bill,"%s %lld %lld %d %s %d %d %s %d %d %s %d %d %d/%d/%d",check.customer,check.phone,check.invoice,add.total,product1,check.item_code,check.quantity,product2,edit.item_code,edit.quantity,product3,remov.item_code,remov.quantity,check.update.month,check.update.day,check.update.year);
    
    fclose(old);
    fclose(new);
    fclose(bill);
    remove("inventory.dat");
    rename("newinventory.dat","inventory.dat");
}


void remove_product()
{   int choice;
    system("cls");
    FILE *old,*new;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    printf("Enter Product code:");
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
        printf("\n\nEnter 1 to delete another Product or 0 to Exit:");
        scanf("%d",&try);
    
    if (try==1) {
        remove_product();
    }
    else
        return;
    }

    else if (choice!=1);
    {
        printf("Product not in inventory\n\n");
        int try;
        printf("Enter 1 Try again or 0 for Main Menu\n:");
        scanf("%d",&try);
    
        if (try==1) 
        {
        remove_product();
        }
        else
        main_menu();
    }
}


void edit_product() 
{   int count;
    system("cls");
    FILE *old,*new;
    old=fopen("inventory.dat","r");
    new=fopen("newinventory.dat","w");
    printf("Today's Date (mm/dd/yy): ");
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
            printf("1.Change Name\n2.Change Price\n3.Change Quantity\n4.Main Menu\n\n:");
            scanf("%d",&choice);

            if (choice==1) 
            {
                printf("Enter new name:");
                scanf("%s",edit.item_name);

                fprintf(new,"%s %d %d %d %d/%d/%d\n",edit.item_name,add.item_code,add.price,add.quantity,edit.update.month,edit.update.day,edit.update.year);
                printf("Edited succesfully.\n");

            }

            else if (choice==2) 
            {
                printf("Enter new price:");
                scanf("%d",&edit.price);

                fprintf(new,"%s %d %d %d %d/%d/%d\n",add.item_name,add.item_code,edit.price,add.quantity,edit.update.month,edit.update.day,edit.update.year);
                printf("Edited succesfully.\n");

            }

            else if (choice==3) 
            {
                printf("Enter quantity:");
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
            printf("Enter 1 to try again or 2 for Main menu.:");
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

void check_inventory() 
{
    system("cls");
    FILE *old;
    old=fopen("inventory.dat","r");
    
    printf("PRODUCT\t\tPRODUCT CODE\tPRICE\tQUANTITY\tLAST UPDATED\n\n\n");
    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        printf("%s\t%d\t%drs\t%d\t\t%d/%d/%d\n",add.item_name,add.item_code,add.price,add.quantity,add.update.month,add.update.day,add.update.year);
    }
    int choice;
    printf("\n\n1.Edit Product\n2.Main Menu\n\n: ");
    scanf("%d",&choice);
    if (choice)
    edit_product();
    else
    main_menu();
}

void add_product() 
{   
    try_again:
    system("cls");
    FILE *old;
    old=fopen("inventory.dat","a+");
    
    printf("Product Name: \n");
    scanf("%s",check.item_name);
    printf("Product Code: \n");
    scanf("%d",&check.item_code);

    while (fscanf(old,"%s %d %d %d %d/%d/%d\n",&add.item_name,&add.item_code,&add.price,&add.quantity,&add.update.month,&add.update.day,&add.update.year)!=EOF)
    {
        if (check.item_code==add.item_code) 
        {
            printf("Product already in inventory.\n");
            printf("1.To add new product\n2.To edit existing product\n0.Main menu.\n\n:");
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
    
    int choice;
    printf("Product added.\n");
    printf("Enter 1 To add more products or 0 to Exit:");
    scanf("%d",&choice);
    if (choice==1)
    {add_product();}

    fclose(old);
}


void main_menu () 
{
    int choice;
    system("cls");
    printf("\t\t\t---MAIN MENU---\n\n\n");
    printf("\n\n1.Print bill\n2.Add Product\n3.Edit Product\n4.Check Inventory\n5.Remove Product\n0.Exit\n\nNote:Use '_' instead of space.\n\n:");
    scanf("%d",&choice);

    switch (choice) {
        case 1:bill();break;
        case 2:add_product();break;
        case 3:edit_product();break;
        case 4:check_inventory();break;
        case 5:remove_product();break;
        default:return;
    }
}

void main () 
{
    system("cls");
    printf("\t\t\t---FASHION STORE MANAGEMENT PROGRAM---\n");
    printf("\n\n\n\n\n\nMade by Nikhil Mahar\n");
    printf("LOADING");
for(int i=0;i<4;i++) 
{  
    delay(1);
    printf(".");
}
    main_menu();
}


