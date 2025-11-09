#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    struct Medicine{
        int ID;
        char name[100];
        char company[100];
        int quantity;
        float price;
        char expiry[100];
    };
    // Functions for all condtions
    void addMedicine();
    void displayMedicine();
    void searchMedicine();
    void updateMedicine();
    void deletMedicine();

int main(){
    int choice;
    while(1){
        printf(" This is choices\n");
        printf("1. Adding a Medicines\n");
        printf("2. Dispalying a Medicines\n ");
        printf("3. Serach a Medicines by ID\n");
        printf("4. Upadte a Medicines\n ");
        printf("5. Deleting a Medicines\n");
        printf("6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            addMedicine();
            break;

            case 2:
            displayMedicine();
            break;

            case 3:
            searchMedicine();
            break;

            case 4:
            updateMedicine();
            break;

            case 5:
            deletMedicine();
            break;

            case 6:
            printf("Exiting a program.\n");
            exit(0);

            default:
            printf("Invalid choice \n please try again");
        }
    }
    return 0;
}
//user-defined function for adding a medicine
void addMedicine(){
    FILE *fp;
    fp=fopen("Medicine.txt","a+");
    struct Medicine m;
    if(fp==NULL){
        printf("Error opening file");
    }
    else{
        printf("Enter the medicine ID : ");
        scanf("%d",&m.ID);
        printf("Enter the name of the medicine : ");
        scanf("%s",m.name);
        printf("Enter the company name : ");
        scanf("%s",m.company);
        printf("Enter the price of the medicine : ");
        scanf("%f",&m.price);
        printf("Enter the quantity of the medicine : ");
        scanf("%d",&m.quantity);
        printf("Enter the expiry date (dd-mm-yy) : ");
        scanf("%s",m.expiry);
    }
    fprintf(fp, "%d\t %s\t %s\t %.2f\t %d\t %s\n", 
        m.ID, m.name, m.company, m.price, m.quantity, m.expiry);
    fclose(fp);
    printf("Data added succesfully....");
}

// user-defined function fo displaying a medicines
void displayMedicine() {
    FILE *fp;
    struct Medicine m;

    fp = fopen("Medicine.txt", "r");
    if (fp == NULL) {
        printf("No data found!\n");
        return;
    }
    printf("\nAll Medicines:\n");
    printf("-----------------------------------------------------------\n");
    printf("ID\tName\t\tCompany\t\tPrice\tQty\tExpiry\n");
    printf("-----------------------------------------------------------\n");

    // Loop until end of file
    while (fscanf(fp, "%d %s %s %f %d %s", 
                  &m.ID, m.name, m.company, &m.price, &m.quantity, m.expiry) == 6) {
        printf("%d\t%-10s\t%-10s\t%.2f\t%d\t%s\n",
               m.ID, m.name, m.company, m.price, m.quantity, m.expiry);
    }
    printf("-----------------------------------------------------------\n");
    fclose(fp);
}

//user-define function for search medice by ID
void searchMedicine(){
    FILE *fp;
    fp=fopen("Medicine.txt","r");
    struct Medicine m;
    int id,found=0;
    if(fp==NULL){
        printf("No data found");
    }
    else{
        printf("\n Enter medicine id to search \n");
        scanf("%d",&id);
         while (fscanf(fp, "%d %s %s %f %d %s", 
                  &m.ID, m.name, m.company, &m.price, &m.quantity, m.expiry) == 6) {
        if(m.ID==id){
            found=1;
            printf("ID\tName\t\tCompany\t\tPrice\tQty\tExpiry\n");
            printf("%d\t%-10s\t%-10s\t%.2f\t%d\t%s\n",
               m.ID, m.name, m.company, m.price, m.quantity, m.expiry);
            break;
        }
    }
    if(!found){
        printf("\nno medicine found with id %d\n",id);
    }
    }
    fclose(fp);
}

// user-define function for updating a medicine
void updateMedicine(){
    FILE *fp;
    fp=fopen("Medicine.txt","r");
    struct Medicine m[100];
    int c=0,found=0,id,choice,running;
    char searchName[50];
    if(fp==NULL){
        printf("No data found");
    }
    else{
         while(fscanf(fp,"%d %s %s %f %d %s",
    &m[c].ID,m[c].name,m[c].company,&m[c].price,&m[c].quantity,m[c].expiry)==6){
        c++;
    }
    fclose(fp);
    printf("\n Enter the name of the medicine to update\n");
    scanf("%s",searchName);
    printf("enter the ID of the medicine : ");
    scanf("%d",&id);
    for(int i=0;i<c;i++){
        if(strcmp(m[i].name,searchName)==0 || id==m[i].ID){
            printf("\nID %d Medicine %s  found\n",m[i].ID,m[i].name);
            while(running){
            printf(" This is choices\n");
            printf("1. change all choices\n");
            printf("2. Only medicine ID\n");
            printf("3. Only Medicine name\n ");
            printf("4. Only medicine company\n");
            printf("5. only price of the medicine\n ");
            printf("6. only quantity of medicine \n");
            printf("7. only expiry date of the medicine \n");
            printf("8.  exit the updation mode\n");
            printf("Enter the choice  : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
        printf("Enter the id of the medicine : ");
        scanf("%d",&m[i].ID);
        printf("Enter the name of the medicine : ");
        scanf("%s",m[i].name);
        printf("Enter the company name : ");
        scanf("%s",m[i].company);
        printf("Enter the price of the medicine : ");
        scanf("%f",&m[i].price);
        printf("Enter the quantity of the medicine : ");
        scanf("%d",&m[i].quantity);
        printf("Enter the expiry date (dd-mm-yy) : ");
        scanf("%s",m[i].expiry);
        found=1;
        break;
         case 2:
         printf("Enter the id of the medicine : ");
         scanf("%d",&m[i].ID);
        found=1;
            break;
            case 3:
        printf("Enter the name of the medicine : ");
        scanf("%s",m[i].name);
        found=1;
            break;
            case 4:
        printf("Enter the company name : ");
        scanf("%s",m[i].company);
        found=1;
            break;
            case 5:
        printf("Enter the price of the medicine : ");
        scanf("%f",&m[i].price);
        found=1;
            break;
            case 6:
        printf("Enter the quantity of the medicine : ");
        scanf("%d",&m[i].quantity);
        found=1;
            break;
            case 7:
        printf("Enter the expiry date (dd-mm-yy) : ");
        scanf("%s",m[i].expiry);
        found=1;
        break;
            case 8:
            printf("Exiting from upation mode...\n ");
            running=0;
            break;
        default:
                printf("Invalid choice..\ntry again");
            }
        }
        }
    }
}
    if(!found){
        printf("\n No medicine found with thet name\n");
    }

    // rewriting the entire file with updated array
    fp=fopen("Medicine.txt","w");
    for(int i=0;i<c;i++){
        fprintf(fp,"%d %s %s %f %d %s",
            m[i].ID,m[i].name,m[i].company,m[i].price,m[i].quantity,m[i].expiry);
    }
    fclose(fp);
    printf("Record updated successfully \n");
}

// user-define function for deleting a medicine 
void deletMedicine() {
    FILE *fp = fopen("medicine.txt", "r");
    struct Medicine m[100];
    int count=0,i,j,found = 0,id;
    char searchName[50];

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read all records into array
    while (fscanf(fp, "%d %s %s %d %f %s",
                  &m[count].ID, m[count].name, m[count].company,
                  &m[count].quantity, &m[count].price, m[count].expiry) == 6) {
        count++;
    }
    fclose(fp);

    printf("Enter Medicine Name to delete : ");
    scanf("%s", searchName);
    printf("Enter the id of the medicine : ");
    scanf("%d",&id);

    // Search and delete using loop
    for (i = 0; i < count; i++) {
        if(strcmp(m[i].name, searchName) == 0 || id==m[i].ID) {
            found = 1;
            // Shift remaining elements left
            for (j = i; j < count - 1; j++) {
                m[j] = m[j + 1];
            }
            count--; // Decrease total count
            break;
        }
    }
    if (!found) {
        printf("No medicine found with that name!\n");
        return;
    }

    // Rewrite file with remaining records
    fp = fopen("medicine.txt", "w");
    for (i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %d %.2f %s\n",
                m[i].ID, m[i].name, m[i].company,
                m[i].quantity, m[i].price, m[i].expiry);
    }
    fclose(fp);
    printf("id %d Medicine %s deleted successfully!\n",id, searchName);
}







