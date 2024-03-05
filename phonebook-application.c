#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[35];
    char address[50];
     char father_name[35];
    long int mble_no;
    char mail[100];

    };
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
int main()
{
    system("color 5f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\n\t\t  MENU \t\n");
printf("\n\t1.Add New   \t2.List   \t3.Exit  ");

switch(getch())
{
    case '1':

                addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;

    default:
                system("cls");
                printf("\nEnter 1 to 3 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter name: ");
        got(p.name);
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter father name: ");
        got(p.father_name);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("\nEnter e-mail:");
         got(p.mail);
        fwrite(&p,sizeof(p),1,f);

        printf("\nrecord saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n YOUR RECORD IS\n ");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.father_name,p.mble_no,p.mail);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}

void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=5&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==5)
                {
                    if(i>0)
                    {
                        i--;
                    }

                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
