#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int orderr(int[]);
void menu(void);
void printtoorder(int[], int);

struct fororder
{
    int itemno;
    float price;
    char itmname[100];
};

FILE *menuee, *orderf, *idfile, *record;

void main()
{
    int vorder[20], i, n, checker = 1, slength;

    // printf("%d\n", n);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d", vorder[i]);
    // }
    char fID[20], ID[20];

    idfile = fopen("ID.txt", "r");
    // check if id exists or not
    printf("ENTER USER ID: ");
    scanf("%s", &ID);
    slength = 12;
    while ((fscanf(idfile, "%s", fID)) != EOF)
    {
        checker = strcmp(ID, fID);
        if (checker == 0)
            break;
    }
    // printf("%s",ID);

    // printf("%d",checker);
    if (checker == 0)
    {

        menu();
        n = orderr(vorder);
    }
    else
    {
        printf("Invalid ID\n");
        printf("please enter valid id or consult the admin");
        exit(1);
    }
    printf("The order is been noted.");
    printtoorder(vorder, n);

    // display menu

    // print the order in the file

    fclose(idfile);
}

int orderr(int vorder[])
{
    int i = 0;
    while (1)
    {
        printf("\nInput item number to order , type 999 to exit ");
        scanf("%d", &vorder[i]);
        if (vorder[i] == 999)
        {
            break;
        }
        i++;
    }
    return i;
}

void menu(void)
{
    menuee = fopen("menu.txt", "r");
    struct fororder s[100];
    char menudata;
    int i = 0;
    while ((fscanf(menuee, "%d%f%[^\n]%*c", &s[i].itemno, &s[i].price, &s[i].itmname)) != EOF)
    {
        printf("%d     %s   %f\n", s[i].itemno, s[i].itmname, s[i].price);
        i++;
    }
    fclose(menuee);
}

void printtoorder(int theorder[], int n)
{
    orderf = fopen("orderfile.txt", "w+");
    menuee = fopen("menu.txt", "r");
    record = fopen("record.txt", "w+");

    int i, j, dat, nn = 0;
    // printf("%d\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", theorder[i]);
    }
    struct fororder s[100];
    i = 0;
    while ((fscanf(menuee, "%d%f%[^\n]%*c", &s[i].itemno, &s[i].price, &s[i].itmname)) != EOF)
    {
        i++;
    }
    dat = i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < dat; j++)
        {
            if (theorder[i] == j)
            {
                nn++;
                fprintf(orderf, "%d     %s   %f\n", nn, s[i].itmname, s[i].price);
                fprintf(record, "%d %f%s\n", nn, s[i].price, s[i].itmname);
            }
        }
    }
    fclose(menuee);
    fclose(orderf);
    fclose(record);
}