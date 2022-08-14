#include <stdio.h>
#include <conio.h>
#include <string.h>

int orderr(int[]);
void menu(void);
void rec(void);
void billing(void);

FILE *menuee, *orderf, *idfile, *record, *bill, *allrecord;

struct fororder
{
    int itemno;
    float price;
    char itmname[100], name[100];
};

void main()
{
    int answer;
    printf("1. View order\n");
    printf("2. Bill\n");
    printf("3. Total sale.\n");
    printf("4. View all record\n");
    printf("5. Change menu.\n");
    printf("Your choice: ");
    scanf("%d",&answer);
    rec();
}

void rec(void)
{
    record = fopen("record.txt", "r");
    struct fororder s[100];
    //printf("HELLO");
    int i =0, nn=0;
    while ((fscanf(record, "%d%f%[^\n]%*c", &s[i].itemno, &s[i].price, &s[i].itmname)) != EOF)
    {
        nn++;
        printf("%d     %s\n", nn, s[i].itmname);
        i++;
    }
    fclose(record);
}

void billing()
{

}

// void rec()
// {
//     record = fopen("record.txt", "r");
//     if (record == NULL)
//         printf("ERROR !!");

//     int i, j, dat, nn = 0;
//     // // printf("%d\n", n);
//     // for (i = 0; i < n; i++)
//     // {
//     //     printf("%d ", theorder[i]);
//     // }
//     struct fororder s[100];
//     i = 0;
//     while ((fscanf(record, "%d%f%[^\n]%*c", &s[i].itemno, &s[i].price, &s[i].itmname)) != EOF)
//     {
//         printf("%d %s\n", nn + 1, s[i].itmname);
//         i++;
//     }
//     //dat = i;
//     //for (i = 0; i < dat; i++)
//     //{
//         // for (j = 0; j < dat; j++)
//         //{
//         // if (theorder[i] == j)
//         //{

//         // fprintf(record, "%d %f%s\n", nn + 1, s[i].price, s[i].itmname);
        //}
 //   }
//}
//fclose(menuee);
//fclose(orderf);
// fclose(record);
// }


// void rec(){
// struct fororder s[100];
//     menuee = fopen("menu copy.txt", "r");
//     float price;
//     char name[100];
//     int i = 1, n;
//     while (i != 7)
//     {
//         fscanf(menuee, "%d%s%c", &s[i].itemno, &s[i].itmname,&s[i].nnn);

//         fscanf(menuee, "%.2f", &s[i].price);

//         i++;
//     }
//     i = 1;
//     while (i != 7)
//     {
//         printf("%d  %s", s[i].itemno, s[i].itmname);
//         printf("    %.2f\n", s[i].price);
//         i++;
//     }

//     fclose(menuee);
// }
