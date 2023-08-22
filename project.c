#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define MAX_BNAME 60
#define MAX_SNAME 60
#define MAX_ANAME 60
typedef struct
{
    char Books_id[20];
    char BookName[MAX_BNAME];
    char AuthorName[MAX_ANAME];
    char StudentName[MAX_SNAME];
} BooksInfo;

typedef struct login
{
   char userid[20];
   char passw[15];
}login;

/*void signup()
{
    login credential;
    char temp[20];
    FILE *fp=NULL;
    label:
    printf("\n\t\tENTER NEW USER ID   :");
    scanf("%s",credential.userid);
    printf("\n\t\tENTER NEW PASSWORD  :");
    scanf("%s",credential.passw);
    printf("\n\t\tCONFIRM NEW PASSWORD:");
    scanf("%s",temp);
    getchar();
    if(strcmp(temp,credential.passw)==0)
    {
       printf("\n\t\tYour User Id created successfully...\n\n");
    }
    else
    {
        printf("\n\t\tPassword doesn't matched please try again...");
        goto label;
    }
    printf("\n\t\tPress any key to continue...");
    getchar();
    fp=fopen("pass.txt","w");
    isfileopen(fp);
    fwrite(&credential,sizeof(credential),1,fp);
    fclose(fp);
}
void loginid()
{
  FILE *fp=NULL;
  login credential;
  char id[20],pass[20];
  label:
  printf("\n\t\tENTER USER ID   :");
  scanf("%s",id);
  printf("\n\t\tENTER PASSWORD  :");
  scanf("%s",pass);
  fp=fopen("pass.txt","r");
  isfileopen(fp);
  getchar();
  while(fread(&credential,sizeof(credential),1,fp))
  {
      if(strcmp(id,credential.userid)==0&&strcmp(pass,credential.passw)==0)
      {
          printf("\n\t\tLogged in successfully...");
      }
      else{
          printf("\n\t\tUser id or Password are wrong please enter correct login credential...");
          goto label;
      }
  }
  fclose(fp);
  printf("\n\t\tPress any key to continue...");
  getchar();
    
}
void changepass()
{
    login credential;
    FILE *fp=NULL;
    char temp[20];
    label:
    printf("\n\t\tENTER NEW USER ID   :");
    scanf("%s",credential.userid);
    printf("\n\t\tENTER NEW PASSWORD  :");
    scanf("%s",credential.passw);
    printf("\n\t\tCONFIRM NEW PASSWORD:");
    scanf("%s",temp);
    getchar();
    if(strcmp(temp,credential.passw)==0)
    {
       printf("Your Login Id and Password updated successfully...");
    }
    else
    {
        printf("Password doesn't matched please try again...");
        goto label;
    }
    printf("\n\t\tPress any key to continue...");
    getchar();
    remove("pass.txt");
    fp=fopen("pass.txt","w");
    isfileopen(fp);
    fwrite(&credential,sizeof(credential),1,fp);
    fclose(fp);


}
*/

void headMessage(char message[])
{
   system("clear");
    //regex "\e[1;1H\e[2J";
    printf("\n\n\t\t################################################################################");
    printf("\n\t\t################################################################################");
    printf("\n\t\t################                                                ################");
    printf("\n\t\t################      Library management System Project in C    ################");
    printf("\n\t\t################                                                ################");
    printf("\n\t\t################################################################################");
    printf("\n\t\t################################################################################");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n                        \t \t\t  %s\t\n",message);
    printf("------------------------------------------------------------------------------------------------------------");
}
void welcomeMessage()
{
    printf("\n");
    printf("\n*************************************************************************************************************\n");
    printf("\t\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t            =                 WELCOME                   =");
    printf("\n\t\t\t            =                   TO                      =");
    printf("\n\t\t\t            =                 LIBRARY                   =");
    printf("\n\t\t\t            =               MANAGEMENT                  =");
    printf("\n\t\t\t            =                 SYSTEM                    =");
    printf("\n\t\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n*************************************************************************************************************\n");
    printf("\n\n\t\tEnter any key to continue.....");
    getchar();
}
int isnamevalid(char name[])
{
    int valid=1;
    int length=strlen(name);
    for(int i=0; i<length; i++)
    {
        //if(!(isalpha(name[i]))&&(name[i]!='\n')&&(name[i]!=' '))
        if((name[i]==' '&&name[i+1]=='\n')||(i==0&&name[i]=='\n'))
        {
            valid=0;
            break;
        }
    }
    return valid;
}
void isfileopen(FILE *fp)
{
    if(fp==NULL)
    {
        printf("\n\t\tFacing some issues try again.. \n");
        exit(1);
    }

}
void addbookInDataBase()
{   
    
    int z,valid=0,i=0;
    char ch,temp[20];
    FILE *fp=NULL;
    BooksInfo addbook;
    label:
    printf("\n\t\tPlease Select Department : ");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t1. B.TECH\t\t2. B.PHARMA\t\t3. BBA   \t\t4. BCA\n");
    printf("\t\t5. M.TECH\t\t6. M.PHARMA\t\t7. MBA   \t\t8. MCA\n");
    
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t:->");
    scanf("%d",&z);
    do
    {
        
        switch(z)
        {
            case 1:fp=fopen("B_TECH.txt","ab+");break;
            case 2:fp=fopen("B_PHARMA.txt","ab+");break;
            case 3:fp=fopen("BBA.txt","ab+");break;
            case 4:fp=fopen("BCA.txt","ab+");break;
            case 5:fp=fopen("M_TECH.txt","ab+");break;
            case 6:fp=fopen("M_PHARMA.txt","ab+");break;
            case 7:fp=fopen("MBA.txt","ab+");break;
            case 8:fp=fopen("MCA.txt","ab+");break;
            default : printf("Invalid Input...Please Try again");
        }
    }
    while(z>8&&z<1);
    
    isfileopen(fp);
    headMessage("ADDING NEW BOOKS");
    printf("\n \n\t\tENTER THE DETAILS : ");
    printf("\n------------------------------------------------------------------------------------------------------------");
    do
    {
        printf("\n\n\t\tBook ID     : ");
        fflush(stdin);
        scanf("%s",addbook.Books_id);
        z=strlen(addbook.Books_id);
        memcpy(temp,addbook.Books_id,z);
        temp[z]='\0';
        for(i=0;i<z;i++)
        {
            if((temp[i]>='0')&&(temp[i]<='9'))
            continue;
            else
            break;
        }
        //z=strlen(addbook.Books_id);
        if(z==i)
        valid=1;
        else
        valid=0;
        
        if(!valid)
        printf("\n\t\tBook ID is Invalid...Please Enter an Integer Number only... ");
    }while(!valid);
    
    
    do
    {
        printf("\n\t\tBook Name   : ");
        fflush(stdin);
        getchar();
        scanf("%[^\n]s",addbook.BookName);
        //fgets(addbook.BookName,MAX_BNAME,stdin); 
        valid=isnamevalid(addbook.BookName);
        if(!valid)
        printf("\n\t\tBook Name is invalid...Please Re-enter : ");

    }
    while(!valid);

    do
    {
        printf("\n\t\tAuthor Name : ");
        fflush(stdin);
        getchar();
        scanf("%[^\n]s",addbook.AuthorName);
       // fgets(addbook.AuthorName,MAX_BNAME,stdin);
        valid=isnamevalid(addbook.AuthorName);
        if(!valid)
        printf("\nAuthor Name is invalid...Please Re-enter : ");
    }
    while(!valid);

    do
    {
        printf("\n\t\tStudent Name: ");
        fflush(stdin);
        getchar();
        scanf("%[^\n]s",addbook.StudentName);
       // fgets(addbook.StudentName,MAX_BNAME,stdin);
        valid=isnamevalid(addbook.StudentName);
        if(!valid)
        printf("\nStudent Name is invalid....Please Re-enter : ");
    }
    while(!valid);

    fwrite(&addbook,sizeof(addbook),1,fp);
    fclose(fp);
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    getchar();
    printf("\nThe Details are saved successfully\n\n");
    printf("Press 1 For PREVIOUS MENU and Press any key For MAIN MENU : ");
    scanf("%c",&ch);
    if(ch=='1')
    goto label;
}

void searchBooks()
{
    int z,count=1;
    FILE *fp=NULL;
    int found=0;
    char ch, enterbookname[MAX_BNAME];
    
    BooksInfo search;
    printf("\n\t\tPlease Select Department : ");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t1. B.TECH\t\t2. B.PHARMA\t\t3. BBA   \t\t4. BCA\n");
    printf("\t\t5. M.TECH\t\t6. M.PHARMA\t\t7. MBA   \t\t8. MCA\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t:->");
    scanf("%d",&z);
    do
    {
        
        switch(z)
        {
            case 1:fp=fopen("B_TECH.txt","rb");break;
            case 2:fp=fopen("B_PHARMA.txt","rb");break;
            case 3:fp=fopen("BBA.txt","rb");break;
            case 4:fp=fopen("BCA.txt","rb");break;
            case 5:fp=fopen("M_TECH.txt","rb");break;
            case 6:fp=fopen("M_PHARMA.txt","rb");break;
            case 7:fp=fopen("MBA.txt","rb");break;
            case 8:fp=fopen("MCA.txt","rb");break;
            default : printf("\t\tInvalid Input...Please Try again");
        }
    }
    while(z>8&&z<1);
    isfileopen(fp);
    headMessage("Searching Books...");
    LABEL :
    printf("\n\n\t\t1. Search by Book ID\t\t2. Search by Book Name\t\t3. Search by Author Name\n\t\t:-> ");
    scanf("%d",&z);
    if(z==1)
  {
    printf("\n\t\tEnter Book ID to search...You can also Enter Sub-Set of Book ID... \n\t\t:->");
    fflush(stdin);
    getchar();
    scanf("%[^\n]s",enterbookname);
    getchar();
    printf("\n\t\tThe Matched Details are ......");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\nBOOK COUNT\t\tBOOK ID\t\tBOOK NAME\t\tAUTHOR NAME\t\tSTUDENT NAME");
    printf("\n------------------------------------------------------------------------------------------------------------");
    while(fread(&search,sizeof(search),1,fp))
    {
        if(strstr(search.Books_id,enterbookname)!=NULL)
        {
           printf("\n%02d.\t\t\t%-5.20s\t\t%-10.30s\t\t%-10.20s\t\t%s\n",count,search.Books_id,
           search.BookName,search.AuthorName,search.StudentName);   
           count++;
        }

    }
    count=1;
  }
  else if(z==2)
  {
    printf("\n\t\tEnter Book Name to search...You can also Enter Sub-string of Name... \n\t\t:->");
    fflush(stdin);
    getchar();
    scanf("%[^\n]s",enterbookname);
    getchar();
    printf("\n\t\tThe Matched Details are ......");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\nBOOK COUNT\t\tBOOK ID\t\tBOOK NAME\t\tAUTHOR NAME\tSTUDENT NAME");
    printf("\n------------------------------------------------------------------------------------------------------------");
    while(fread(&search,sizeof(search),1,fp))
    {
        if(strstr(search.BookName,enterbookname)!=NULL)
        {
        printf("\n%02d.\t\t\t%-5.20s\t\t%-10.30s\t\t%-10.20s\t\t%s\n",count,search.Books_id,
        search.BookName,search.AuthorName,search.StudentName);   
        count++;
        }

    }
    count=1;
  }
  else if(z==3)
  {
    printf("\n\t\tEnter Author Name to search...You can also Enter Sub-Name of Author... \n\t\t:->");
    fflush(stdin);
    getchar();
    scanf("%[^\n]s",enterbookname);
    getchar();
    printf("\n\t\tThe Matched Details are ......");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\nBOOK COUNT\t\tBOOK ID\t\tBOOK NAME\t\tAUTHOR NAME\t\tSTUDENT NAME");
    printf("\n------------------------------------------------------------------------------------------------------------");
    while(fread(&search,sizeof(search),1,fp))
    {
        if(strstr(search.AuthorName,enterbookname)!=NULL)
        {
        printf("\n%02d.\t\t\t%-5.20s\t\t%-10.30s\t\t%-10.20s\t\t%s\n",count,search.Books_id,
        search.BookName,search.AuthorName,search.StudentName);   
        count++;
        }

    }
  }
  else
  {
     printf("\n\n\t\tEnter Valid Option..");
     goto LABEL;
  }
    fclose(fp);
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tPress any key for MAIN MENU...");
    getchar();
}

void viewDatabase()
{
    int z;
    int doubt=0;
    int count =1;
    BooksInfo s;
    printf("\n\t\tPlease Select Department : ");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t1. B.TECH\t\t2. B.PHARMA\t\t3. BBA   \t\t4. BCA\n");
    printf("\t\t5. M.TECH\t\t6. M.PHARMA\t\t7. MBA   \t\t8. MCA\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t:->");
    scanf("%d",&z);
   
    FILE *fp=NULL;
    do
    {
        
        switch(z)
        {
            case 1:fp=fopen("B_TECH.txt","rb");break;
            case 2:fp=fopen("B_PHARMA.txt","rb");break;
            case 3:fp=fopen("BBA.txt","rb");break;
            case 4:fp=fopen("BCA.txt","rb");break;
            case 5:fp=fopen("M_TECH.txt","rb");break;
            case 6:fp=fopen("M_PHARMA.txt","rb");break;
            case 7:fp=fopen("MBA.txt","rb");break;
            case 8:fp=fopen("MCA.txt","rb");break;
            default : printf("\t\tInvalid Input...Please Try again");
        }
    }
    while(z>8&&z<1);

    isfileopen(fp);
    headMessage("Showing Database...");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\nBOOK COUNT\t\tBOOK ID\t\tBOOK NAME\t\tAUTHOR NAME\t\tSTUDENT NAME");
    printf("\n------------------------------------------------------------------------------------------------------------");
    getchar();
    while(fread(&s,sizeof(s),1,fp))
    {
        printf("\n%02d.\t\t\t%-5.20s\t\t%-10.30s\t\t%-10.20s\t\t%s\n",count,s.Books_id,s.BookName,s.AuthorName,s.StudentName);
        count++;
        doubt=1;
    }
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    fclose(fp);
   // printf("\n\n\n\t\t\t\t\t\t\t\t\t\tNO MORE RECORDS...\n\n");
    printf("\t\tPress any key for MAIN MENU...");
    getchar();
    if(!doubt)
    {
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t NO RECORD ... \n\n");
    }
}

void deleteBooks()
{
    char bdelete[20];
    int found=0,z;
    BooksInfo s;
    FILE *fp=NULL;
    printf("\n\t\tPlease Select Department : ");
    printf("\n------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t1. B.TECH\t\t2. B.PHARMA\t\t3. BBA   \t\t4. BCA\n");
    printf("\t\t5. M.TECH\t\t6. M.PHARMA\t\t7. MBA   \t\t8. MCA\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t:->");
    scanf("%d",&z);

   do
    {
        
        switch(z)
        {
            case 1:fp=fopen("B_TECH.txt","rb");break;
            case 2:fp=fopen("B_PHARMA.txt","rb");break;
            case 3:fp=fopen("BBA.txt","rb");break;
            case 4:fp=fopen("BCA.txt","rb");break;
            case 5:fp=fopen("M_TECH.txt","rb");break;
            case 6:fp=fopen("M_PHARMA.txt","rb");break;
            case 7:fp=fopen("MBA.txt","rb");break;
            case 8:fp=fopen("MCA.txt","rb");break;
            default : printf("\t\tInvalid Input...Please Try again");
        }
    }
    while(z>8&&z<1);
    isfileopen(fp);
    FILE *tem=NULL;
    tem=fopen("temp.bin","wb");
    isfileopen(tem);
    printf("\n\t\tEnter Book ID NO. for delete : ");
    scanf("%s",bdelete);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.Books_id,bdelete)!=0)
            fwrite(&s,sizeof(s),1,tem);
        else
            found=1;
    }
    if(found)
    {
        printf("\n\n\t\tRecord Deleted Successfully... \n\n\n");
        getchar();
    }
    else
      { 
        printf("\n\n\t\tRecord not found\n");
        getchar();
      }
    fclose(fp);
    fclose(tem);
       switch(z)
        {
            case 1:{remove("B_TECH.txt");rename("temp.bin","B_TECH.txt");break;}
            case 2:{remove("B_PHARMA.txt");rename("temp.bin","B_PHARMA.txt");break;}
            case 3:{remove("BBA.txt");rename("temp.bin","BBA.txt");break;}
            case 4:{remove("BCA.txt");rename("temp.bin","BCA.txt");break;}
            case 5:{remove("M_TECH.txt");rename("temp.bin","M_TECH.txt");break;}
            case 6:{remove("M_PHARMA.txt");rename("temp.bin","M_PHARMA.txt");break;}
            case 7:{remove("MBA.txt");rename("temp.bin","MBA.txt");break;}
            case 8:{remove("MCA.txt");rename("temp.bin","MCA.txt");break;}
        }
    
}

int main()
{
    char choice;
   /* sachin:
    headMessage("Login");
    printf("\n\t\tIF YOU WANT ACCESS LIBRARY MANAGEMENT SYSTEM PLEASE LOGIN AND IF YOU ARE NEW USER PLEASE SIGN UP...");
    printf("\n\n\t\t1. LOGIN\t\t\t\t\t\t2. SIGN UP\n\t\t:->");
    scanf("%c",&choice);
    if(choice=='1')
    {
       loginid();
    }
    else if(choice=='2')
    {
      signup();
    }
    else
    {
        printf("\n\t\tChoose valid choise...");
        goto sachin;
    }   */
    
        label :
        headMessage("__In Proccess__");
        headMessage("MAIN MENU");
        printf("\n\t\tPlease Select your desired Function : ");
        printf("\n------------------------------------------------------------------------------------------------------------");
        printf("\n\t\t1. Add Books Details");
        printf("\t2. Search Books");
        printf("\t\t3. View Database");
        printf("\t4. Delete Book");
       // printf("\n\t\t5. Change Id-Password\t6. Student Record");
        printf("\n\t\t0. Exit\n");
        printf("------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t:->");
        scanf("%c",&choice);
        switch(choice)
        {
        case '1':addbookInDataBase();break;
        case '2':searchBooks();break;
        case '3':viewDatabase();break;
        case '4':deleteBooks();break;
       // case '5':changepass();break;
       // case '6':studentrec();
        case '0':
        {
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\tThank you!!!\n");
            printf("------------------------------------------------------------------------------------------------------------\n");
            exit(1);
        }

        }
        if(choice>'4'||choice<'0')
        {
            getchar();
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\tInvalid Input !!!...Try again...");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            
            printf("\n\n\t\tEnter any key to continue.....");
            getchar();
       }
        goto label;
        
}

