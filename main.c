#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char street[30];
    char flat[20];
    char city[20];


} address;

typedef struct
{

    char firstName[15];
    char lastName[15];
    char phoneNumber[20];
    char email[20];
    address address1;

} contact;

contact contacts[100];
int numberOfStudents=0;
contact temp;


void load()
{
    int i=0;
    FILE* f1=fopen("contacts.txt","r");
    if(f1!=NULL)
    {
        while(!feof(f1))           //%4[^,] means read at most four characters or until a comma is encountered.
        {
            fscanf(f1,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",contacts[i].firstName,contacts[i].lastName,contacts[i].address1.street,contacts[i].address1.flat,contacts[i].address1.city,contacts[i].phoneNumber,contacts[i].email);
            i++;
        }
        printf("LOAD SUCCESSFUL!\n\n");
    }
    else printf("File Not Found!\n\n");
    fclose(f1);
    numberOfStudents=i;
}


void search()
{
    char target[15];
    printf("Enter First Name to search for it: ");
    scanf("%s",target);
    int i=0,found=0;
    while(i<numberOfStudents)
    {
        if(strcmp(target,contacts[i].firstName)==0)
        {
            printf("Name: %s %s\nAddress: %s, %s, %s\nPhone Number: %s \n\n",contacts[i].firstName,contacts[i].lastName,contacts[i].address1.street,contacts[i].address1.flat,contacts[i].address1.city,contacts[i].phoneNumber);
            found=1;
        }
        i++;
    }
    if(found==0)
        printf("NOT FOUND!\n\n");
}

void checkForDash(int index)
{

    if(!strcmp(contacts[index].firstName,"-"))
        strcpy(contacts[index].firstName,temp.firstName);

    if(!strcmp(contacts[index].lastName,"-"))
        strcpy(contacts[index].lastName,temp.lastName);

    if(!strcmp(contacts[index].address1.street,"-"))
        strcpy(contacts[index].address1.street,temp.address1.street);

    if(!strcmp(contacts[index].address1.flat,"-"))
        strcpy(contacts[index].address1.flat,temp.address1.flat);

    if(!strcmp(contacts[index].address1.city,"-"))
        strcpy(contacts[index].address1.city,temp.address1.city);

    if(!strcmp(contacts[index].phoneNumber,"-"))
        strcpy(contacts[index].phoneNumber,temp.phoneNumber);

    if(!strcmp(contacts[index].email,"-"))
        strcpy(contacts[index].email,temp.email);
}


void fillTemp(int index)
{
    strcpy(temp.firstName,contacts[index].firstName);
    strcpy(temp.lastName,contacts[index].lastName);
    strcpy(temp.address1.street,contacts[index].address1.street);
    strcpy(temp.address1.flat,contacts[index].address1.flat);
    strcpy(temp.address1.city,contacts[index].address1.city);
    strcpy(temp.phoneNumber,contacts[index].phoneNumber);
    strcpy(temp.email,contacts[index].email);
}


void takeInput(int index,int modify)
{
    int foundNumber=0,foundLetter=0,i=0,found1=0,found2=0;

    do
    {
        int j=0;
        printf("Enter First Name: ");
        scanf("%s",contacts[index].firstName);
        if(!strcmp(contacts[index].firstName,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].firstName))
        {
            if(contacts[index].firstName[j]>='0' && contacts[index].firstName[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;

        }
    }
    while(foundNumber==1);
    do
    {
        foundNumber=0;
        int j=0;
        printf("Enter Last Name: ");
        scanf("%s",contacts[index].lastName);
        if(!strcmp(contacts[index].lastName,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].lastName))
        {
            if(contacts[index].lastName[j]>='0' && contacts[index].lastName[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;

        }
    }
    while(foundNumber==1);
    do
    {
        foundNumber=0;
        int j=0;
        printf("Enter Street: ");
        getchar();
        gets(contacts[index].address1.street);
        //scanf("%s",contacts[index].address1.street);
        if(!strcmp(contacts[index].address1.street,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].address1.street))
        {
            if(contacts[index].address1.street[j]>='0' && contacts[index].address1.street[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;

        }
    }
    while(foundNumber==1);

    do
    {
        foundLetter=0;
        int j=0;
        printf("Enter Flat: ");
        scanf("%s",contacts[index].address1.flat);
        if(!strcmp(contacts[index].address1.flat,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].address1.flat))
        {
            if(isdigit(contacts[index].address1.flat[j])==0)
            {
                foundLetter=1;
                break;
            }
            j++;

        }
    }
    while(foundLetter==1);

    do
    {
        foundNumber=0;
        int j=0;
        printf("Enter City: ");
        scanf("%s",contacts[index].address1.city);
        if(!strcmp(contacts[index].address1.city,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].address1.city))
        {
            if(contacts[index].address1.city[j]>='0' && contacts[index].address1.city[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;

        }
    }
    while(foundNumber==1);

    do
    {
        foundLetter=0;
        int j=0;
        printf("Enter Phone Number: ");
        scanf("%s",contacts[index].phoneNumber);
        if(!strcmp(contacts[index].phoneNumber,"-")&&modify==1)
            break;

        while(j<strlen(contacts[index].phoneNumber))
        {
            if(isdigit(contacts[index].phoneNumber[j])==0)
            {
                foundLetter=1;
                break;
            }
            j++;

        }
    }
    while(foundLetter==1);

    do
    {
        i=1;
        found1=0;
        found2=0;
        printf("Enter email (example@domain.com): ");
        scanf("%s",contacts[index].email);
        int numberOfCharOfemail = strlen(contacts[index].email);
        if(!strcmp(contacts[index].email,"-")&&modify==1)
            break;

        while(i<numberOfCharOfemail)
        {
            if(contacts[index].email[i]=='@')
            {
                found1=1;
                break;
            }
            i++;

        }
        if(contacts[index].email[numberOfCharOfemail-4]=='.'&&contacts[index].email[numberOfCharOfemail-3]=='c'&&contacts[index].email[numberOfCharOfemail-2]=='o'&&contacts[index].email[numberOfCharOfemail-1]=='m')
        {
            found2=1;
        }

    }
    while(found1==0||found2==0);

}


void add()
{
    takeInput(numberOfStudents,0);
    numberOfStudents++;
    printf("ADDED SUCCESSFULLY!\n\n");


}


void modify()
{
    int foundNumber;
    char firstNameTarget[15];

    do
    {
        foundNumber=0;
        int j=0;
        printf("Enter First Name Of contact you want to edit: ");
        scanf("%s",firstNameTarget);
        while(j<strlen(firstNameTarget))
        {
            if(firstNameTarget[j]>='0' && firstNameTarget[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;
        }
    }
    while(foundNumber==1);

    int menu=1;
    int pick;
    int i=0,k=0;
    int options[10];
    while(i<numberOfStudents)
    {
        if(strcmp(firstNameTarget,contacts[i].firstName)==0)
        {
            options[k]=i;
            k++;
        }
        i++;
    }
    if(k>1)
    {

        int r=0;
        while(r<k)
        {

            printf("%d- %s %s\n",menu,contacts[options[r]].firstName,contacts[options[r]].lastName);
            r++;
            menu++;

        }
        printf("Please choose a contact to edit by typing it's number: ");
        scanf("%d",&pick);
        int index;
        index=options[pick-1];


        fillTemp(index);
        printf("You can skip an entry by typing '-' : \n");
        takeInput(index,1);
        checkForDash(index);



        printf("SUCCESSFULLY EDITED!\n\n");




    }
    else if(k==1)
    {
        int index = options[0];

        fillTemp(index);

        printf("You can skip an entry by typing '-' : \n");

        takeInput(index,1);

        checkForDash(index);


        printf("SUCCESSFULLY EDITED!\n\n");


    }
    else printf("NOT FOUND!\n\n");

}


void deleteContact()
{
    char firstNameTarget[15];
int foundNumber;
    do
    {
        foundNumber=0;
        int j=0;
        printf("Enter First Name Of contact you want to delete: ");
        scanf("%s",firstNameTarget);
        while(j<strlen(firstNameTarget))
        {
            if(firstNameTarget[j]>='0' && firstNameTarget[j]<='9')
            {
                foundNumber=1;
                break;
            }
            j++;
        }
    }
    while(foundNumber==1);

    int menu=1,r;
    int pick;
    int i,k=0;
    int options[15];
    for(i=0; i<numberOfStudents; i++)
    {
        if(!strcmp(firstNameTarget,contacts[i].firstName))
        {
            options[k]=i;
            k++;
        }
    }
    if(k>1)
    {

        for(r=0; r<k; r++)
        {

            printf("%d- %s %s\n",menu,contacts[options[r]].firstName,contacts[options[r]].lastName);
            menu++;

        }
        printf("Please choose a contact to delete by typing it's number: ");
        scanf("%d",&pick);

        int index = options[pick-1];
        int m;

        for(m=index; m<numberOfStudents; m++)
        {
            contacts[m]=contacts[m+1];
        }

        numberOfStudents--;


    }
    if(k==1)
    {

        int index = options[0];
        int m;

        for(m=index; m<numberOfStudents; m++)
        {
            contacts[m]=contacts[m+1];
        }

        numberOfStudents--;



    }
    if(k==0) printf("NOT FOUND!\n\n");
    else printf("SUCCESSFULLY DELETED\n\n");

}

void displaySorted()
{
    contact *temp =(contact*)malloc(sizeof(contact));
    int i,j;
    for(j=0; j<numberOfStudents-1; j++)
    {
        for(i=0; i<numberOfStudents-1; i++)
        {
            if(strcmp(contacts[i].firstName,contacts[i+1].firstName)>0)
            {
                *temp=contacts[i+1];
                contacts[i+1]=contacts[i];
                contacts[i]=*temp;
            }

            else if(strcmp(contacts[i].firstName,contacts[i+1].firstName)==0)
            {
                if(strcmp(contacts[i].lastName,contacts[i+1].lastName)>0)
                {
                    *temp=contacts[i+1];
                    contacts[i+1]=contacts[i];
                    contacts[i]=*temp;
                }
            }
        }
    }

    for(i=0; i<numberOfStudents; i++)
    {
        printf("\n%s %s  %s, %s, %s  %s %s\n\n",contacts[i].firstName,contacts[i].lastName,contacts[i].address1.street,contacts[i].address1.flat,contacts[i].address1.city,contacts[i].phoneNumber,contacts[i].email);
    }
}

void save()
{

    int i=0;

    FILE* f1=fopen("contacts.txt","w");
    if(f1!=NULL)
    {
        while(i<numberOfStudents)
        {
            fprintf(f1,"%s,%s,%s,%s,%s,%s,%s\n",contacts[i].firstName,contacts[i].lastName,contacts[i].address1.street,contacts[i].address1.flat,contacts[i].address1.city,contacts[i].phoneNumber,contacts[i].email);
            i++;
        }

        printf("SAVE SUCCESSFUL\n\n");
    }
    else printf("File Not Found!\n\n");
    fclose(f1);
}

int quit()
{
    char answer;
    printf("Are you sure you want to quit? Any unsaved data will be lost.\nType 'Y' or 'N': ");
    scanf(" %c",&answer);
    if(answer=='y'||answer=='Y')
        return 1;

    else return 0;
}


int main()
{
    printf("Phone Book\n\n");
    load();
    while(1)
    {

        int pick;
        printf("1-Load from file\n2-Search for a contact\n3-Add a contact\n4-Edit a contact\n5-Delete a contact\n6-Display contacts\n7-Save changes\n8-Quit\n");

        printf("Type the number of the operation you wish to execute: ");

        do
        {
            scanf("%d",&pick);
        }
        while(pick>8||pick<0);

        switch(pick)
        {
        case 1:
            system("cls");
            load();

            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            system("cls");
            add();
            break;
        case 4:
            system("cls");
            modify();
            break;
        case 5:
            system("cls");
            deleteContact();
            break;
        case 6:
            system("cls");
            displaySorted();
            break;
        case 7:
            system("cls");
            save();
            break;
        case 8:
            if(quit()==1)
            {
                printf("BYE LOSER!!");
                exit(0);
            }

            break;
        }
    }

    return 0;
}
