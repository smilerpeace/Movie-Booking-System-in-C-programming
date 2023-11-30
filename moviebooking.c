#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define ANSI_RED     "\x1b[31m"
#define ANSI_RESET   "\x1b[0m"
#define ANSI_GREEN   "\x1b[32m"
char a,usname[100],name[100],theatre[100], movie[100],time[100];
int q,mov,seat,sn,bookingno,seatno[100];
void loginsys();
int book();
int main();
void menu2();
int viewticket();//b
int searchticket();//ll
void viewacc();//m
void searchacc();//m
void ticketprint();//m
void cancel();//b
void menu();//ll
int reg();//ll
void changetic();//b
struct movie
{
   int count;
   char moviename[100];
   char time[100];
   int movie[10][8];
};
struct mallname
{
    char mallname[100];
    struct movie m[3];
};
struct area
{
    int pincode;
    struct mallname mall[3];
}p;

struct person
{
    char name[100];
    char username[100];
    char password[100];
}s;
struct movieticket
{
  char nm[100];
  char usernm[100];
  int bookingnum;
  char movie[100];
  char time[100];
  int seatnum,q,mov;
  char theatre[100];
  int seatnos[100];
  int price;
}mo;
int reg()
  {
        system("cls");
        FILE *f;
        char usern[100], nam[100];
        int flag =0;
        f=fopen("project.txt","ab+");
        if(f==NULL)
        {
          printf("\nCannot open the File.");
          return 0;
        }
        fflush(stdin);
        printf("\n Enter your name: ");
        gets(nam);
        printf("\n Enter username: ");
        gets(usern);
        while(fread(&s,sizeof(s),1,f)>0 && flag==0)
        {
          if(strcmp(s.username,usern)==0)
          {
            flag=1;
            printf("username already in use. please type a new username");
            getch();
            reg();
          }
        }
        if(flag==0)
        {
          strcpy(s.username, usern);
          strcpy(s.name, nam);
          printf("\n Enter password: ");
          gets(s.password);
          printf("%s", s.name);
          fwrite(&s,sizeof(s),1,f);
          fflush(stdin);
          printf("\naccount registered");
          fclose(f);
          printf("\n\nEnter any key to proceed to login");
          getch();
          system("cls");
          loginsys();
        }
}
void loginsys()
{
	char pswd[100]="";
  FILE *f;
  int flag=0;
  f=fopen("project.txt","rb+");
  if(f==NULL)
  {
    printf("\nCannot open the File");
    return;
  }
	printf("\n\n  **********************************LOGIN*********************************** \n");
	printf("	Enter	Username: ");
	gets(usname);
  while(fread(&s,sizeof(s),1,f)>0 && flag==0)
  {
    if(strcmp(s.username,usname)==0)
    {
      flag=1;
      printf("		Password: ");
      goto passw;
      passw:
      a=getch();
      switch(a)
      {
        case '\r': break;
        case '\b':
        goto passw;
        default:
        printf("*");
        strncat(pswd,&a,1);
        goto passw;
      }
      if(strcmp(s.password,pswd)==0)
      {
        printf("\nWelcome!!Login Successful!Enter key to continue");
        getch();
        menu();
				break;
      }
      else
      {
        printf("\n\t\twrong password");
        printf("\ntry again");
        getch();
        loginsys();
      }
    }
  }
    if (flag==0)
        {
        printf("\nUnregistered username");
        goto again;
        again:
        printf("\n 1) Register\n 2) Exit");
        switch(getch())
        {
          case '1':
                reg();
                break;
          case '2': exit(0);
                  break;
          default:
            printf("\nEnter 1 and 2 only");
            printf("\nEnter any key to continue");
            getch();
            goto again;
         }
  }
 fclose(f);
}
int viewticket()
{
  char theatrename[100],name[100], moviename[100];
  int i;
  FILE *fp;
  fp=fopen("booked.txt","rb");
  printf("view tickets booked based on\n 1. username of the accounts registered\n 2.name of the movies\n 3. name of the theatre:");
  scanf("%d",&i);
  if(i==1)
  {printf("\n\n");
    printf("enter the username of the account whose booked tickets you wish to view:");
    scanf("%s",&name);
    while(fread(&mo,sizeof(mo),1,fp)>0)
    {
      if(strcmp(mo.usernm,name)==0)
      {
        printf("\nname:%s\nusername of the account:%s\nmovie name:%s\n movie time:%s\ntheatre name:%s\nprice paid:%d\nbooking number:%d\t",mo.nm, mo.usernm, mo.movie, mo.time,mo.theatre, mo.price, mo.bookingnum);
      printf("\n seats booked:");
      for(int i=0;i<mo.seatnum;i++)
      {
        if(i<mo.seatnum-1)
        {
          printf(" %d,",mo.seatnos[i]);
        }
        else
        {
          printf(" %d",mo.seatnos[i]);
        }
      }
     }
   }
  }
  else if(i==2)
  {
    printf("enter the name of the movie for which you wish to view the booked tickets:");
    scanf("%s",&moviename);
    while(fread(&mo,sizeof(mo),1,fp)>0)
    {
      if(strcmp(mo.movie,moviename)==0)
      {printf("\n\n");
        printf("\nname:%s\nusername of the account:%s\nmovie name:%s\n movie time:%s\ntheatre name:%s\nprice paid:%d\nbooking number:%d\t",mo.nm, mo.usernm, mo.movie, mo.time,mo.theatre, mo.price, mo.bookingnum);
      printf("\n seats booked:");
      for(int i=0;i<mo.seatnum;i++)
      {
        if(i<mo.seatnum-1)
        {
          printf(" %d,",mo.seatnos[i]);
        }
        else
        {
          printf(" %d",mo.seatnos[i]);
        }
      }
     }
   }
  }
  else if(i==3)
  {
    printf("enter the name of the theatre for which you wish to view the booked tickets:");
    scanf("%s",&theatrename);
    while(fread(&mo,sizeof(mo),1,fp)>0)
    {
      if(strcmp(mo.theatre,theatrename)==0)
      {
        printf("\n\n");
            printf("\nname:%s\nusername of the account:%s\nmovie name:%s\n movie time:%s\ntheatre name:%s\nprice paid:%d\nbooking number:%d\t",mo.nm, mo.usernm, mo.movie, mo.time,mo.theatre, mo.price, mo.bookingnum);
      printf("\n seats booked:");
      for(int i=0;i<mo.seatnum;i++)
      {
        if(i<mo.seatnum-1)
        {
          printf(" %d,",mo.seatnos[i]);
        }
        else
        {
          printf(" %d",mo.seatnos[i]);
        }
      }
     }
   }
  }
  else
  {printf("invalid option");}
  getch();
  system("cls");
  fclose(fp);
  menu2();
}
int searchticket()
{
  int bokn;
  int flag=0;
  FILE *fp;
  fp=fopen("booked.txt","rb");
    printf("enter the booking number of the ticket you wish to view:");
    scanf("%d",&bokn);
    while(fread(&mo,sizeof(mo),1,fp)>0 && flag==0)
    {
      if(mo.bookingnum==bokn)
      {
      flag=1;
      printf("\nname:%s\nusername of the account:%s\nmovie name:%s\n movie time:%s\ntheatre name:%s\nprice paid:%d\nbooking number:%d\t",mo.nm, mo.usernm, mo.movie, mo.time,mo.theatre, mo.price, mo.bookingnum);
      printf("\n seats booked:");
      for(int i=0;i<mo.seatnum;i++)
      {
        if(i<mo.seatnum-1)
        {
          printf(" %d,",mo.seatnos[i]);
        }
        else
        {
          printf(" %d",mo.seatnos[i]);
        }
      }
     }
  }
  if(flag==0)
  {
    printf("invalid booking number");
  }
  fclose(fp);
  getch();
  menu2();
}
void menu()
{
  system("cls");
	char choice;
  fflush(stdin);
	printf("\n               Simple Movie Ticket Booking System\n");
	printf("             1- Book a ticket                                   \n");
	printf("             2- To cancel a ticket                              \n");
  printf("             3- To print a ticket                               \n");
	printf("             4- Logout                                          \n");
	printf("  Enter your choice: ");
	scanf("%c",&choice);
  goto choic;
  choic:
  switch(choice)
  {
    case '1':
      book();
      break;
    case '2':
    cancel();
    case '3':
    ticketprint();
    break;
    case '4':
      system("cls");
      printf("you have logged out. Press any key to go to homepage");
      getch();
      main();
    default:
      fflush(stdin);
      printf("invalid choice. Enter your choice from 1 - 4 only");
      scanf("%c",&choice);
      goto choic;
  }
}
int main()
{
      FILE *fs;
      char secu[]="team17";
      fs=fopen("bookno.txt","r");
      fscanf(fs,"%d",&bookingno);
      fclose(fs);
      int n;
      printf("\n\n");
      printf("-------------------ONLINE MOVIE BOOKING SYSTEM--------------------\n");
      printf("\n");
      printf("-----If you already have a account login or else register yourself------\nPress :\n 1 to Register\n 2 to Login\n 3 to Admin only options\n 4 to Exit\n");
      scanf("%d", &n);
      if(n==1)
      {
          reg();
          printf("\n");
      }
      if(n==2)
      {
        fflush(stdin);
          loginsys();
      }
      if(n==4)
      exit(0);
      else if(n==3)
      {
        goto security;
        security:
        printf("\t\nEnter security code:");
        char security[100]="";
        goto passd;
        passd:
        a=getch();
        switch(a)
        {
          case '\r': break;
          case '\b':
          goto passd;
          default:
          printf("*");
          strncat(security,&a,1);
          goto passd;
        }
        if(strcmp(security,secu)==0)
        {
          printf("\nWelcome Administrator!!Login Successful!Enter key to continue");
          getch();
          menu2();
        }
        else
        {
          printf("\n\t\twrong password");
          getch();
          goto security;
        }
      }
  }
  void searchacc()
  {
    FILE *fp;
    int flag=0;
    char usnm[100];
    fp=fopen("project.txt","rb");
    if(fp==NULL)
    {
        printf("\nCannot open the File !!!");
        getch();
        menu2();
    }
    printf("\nenter username");
    scanf("%s",&usnm);
    while(fread(&s,sizeof(s),1,fp)==1 &&flag==0)
    {
      if(strcmp(s.username,usnm)==0)
      {
        flag=1;
        printf("\naccount details of the requested username:");
        printf("\nname: %s\nusername: %s\npassword: %s\n\n\n",s.name, s.username,s.password);
      }
    }
    if(flag==0)
    {
      printf("no such account!");
    }
    fclose(fp);
    getch();
    menu2();
  }
  void menu2()
  {
    system("cls");;
    char c;
    goto menu22;
    menu22:
    printf("\nSimple Movie Ticket Booking System Administrator only functions\n");
    printf("             1- View Booked tickets(admin only)                 \n");
    printf("             2- search Booked tickets(admin only)               \n");
    printf("             3- View Accounts Registered(admin only)            \n");
    printf("             4- Search Accounts Registered(admin only)          \n");
    printf("             5- Edit tickets(admin only)                        \n");
    printf("             6- Logout                                          \n");
    c=getch();
    if(c=='1')
    viewticket();
    else if(c=='2')
    searchticket();
    else if(c=='3')
    viewacc();
    else if(c=='4')
    searchacc();
    else if(c=='5')
    changetic();
    else if(c=='6')
    main();
    else
    printf("invalid");
    goto menu22;
  }
  int book()
  {
    system("cls");
    char a;
    int pin,seatavai, flag=0;
    int flag1=0;
    for(int i=0;i<10;i++)
    {
        seatno[i]=0;
    }
    FILE *f,*fp,*fptr,*fs,*fls;
    fp=fopen("project.txt", "rb");
    while(fread(&s,sizeof(s),1,fp)>0)
    {
      if(strcmp(s.username,usname)==0)
      {
        //printf("\n%s\n", s.name);
        strcpy(name,s.name);
      }
    }
    fclose(fp);
    f=fopen("movie.txt", "rb+");
    printf("Enter pincode to view the theatres in the area: ");
    scanf("%d", &pin);
    while(fread(&p,sizeof(p),1,f)>0 && flag==0)
    {
      if(p.pincode == pin)
      {
        flag=1;
        for(int i=0;i<3;i++)
        {
          printf("\n %d - %s ", i+1, p.mall[i].mallname);
        }
        goto goback;
        goback:
        printf("\nEnter your choice of the theatre to view the movies in the theatre: ");
        scanf("%d",&q);
        if(q>3)
        {
          printf("enter proper theatre number from the given theatre numbers");
          goto goback;
        }
        printf("Movies in the theatre you have chosen with the showtimes-");
        for(int i=0;i<3;i++)
        {
          printf("\n %d - %s at time %s ", i+1, p.mall[q-1].m[i].moviename, p.mall[q-1].m[i].time);
        }
        goto goback2;
        goback2:
        printf("\n Enter your choice of movie to book seats");
        scanf("%d", &mov);
        if(mov>3)
        {
          printf("enter proper theatre number from the given theatre numbers");
          goto goback2;
        }
        p.mall[q-1].m[mov-1].count=0;
        strcpy(theatre, p.mall[q-1].mallname);
        strcpy(movie, p.mall[q-1].m[mov-1].moviename);
        strcpy(time, p.mall[q-1].m[mov-1].time);
        printf("\n You wish to book %s %s %s ",theatre, movie, time);
        for(int k=0;k<10;k++)
        {
          for(int l=0;l<8;l++)
          {
            if(p.mall[q-1].m[mov-1].movie[k][l]!=0)
            {
              p.mall[q-1].m[mov-1].count+=1;
            }
          }
        }
        seatavai=80-p.mall[q-1].m[mov-1].count;
        printf("Available seats: %d", seatavai);
        goto seatbooking;
        seatbooking:
        printf("\nEnter the number of seats you want to book");
        scanf("%d", &sn);
        if(sn>seatavai)
        {
          printf("\nNot enough seats.Press 1 to try booking seats lesser than or equal to %d \n Press 2 to go back to menu", seatavai);
          switch(getch())
          {
            case '1': goto seatbooking;
            break;
            case '2':
            fflush(stdin);
            menu();
            break;
            default:
            break;
          }
        }
        else
        {
          printf("\nSeating arrangement in the theatre");
          printf("\nNote:seats in red are occupied");
          for(int k=0;k<10;k++)
          {
            printf("\n");
            for(int l=0;l<8;l++)
            {
              if(p.mall[q-1].m[mov-1].movie[k][l]!=0)
              {
                printf(ANSI_RED);
                printf("   %4d   ",(k*8)+l+1);
                printf(ANSI_RESET);
              }
              else
              {
                printf("   %4d   ",(k*8)+l+1);
              }
            }
          }
          printf("\nIf you want to go back to menu press 'm', else press 'c' ");
          a=getch();
          if(a=='m')
          {
            menu();
          }
          else if(a=='c')
          {
            for(int i=0;i<sn;i++)
            {
              goto seatbook;
              seatbook:
              printf("\nEnter seat choice %d : ", i+1);
              scanf("%d", &seatno[i]);
              for(int j=0;j<i;j++)
              {
                if(seatno[i]==seatno[j])
                {
                  flag1=1;
                  break;
                }
              }
              int k=seatno[i]/8;
              int l=seatno[i]%8-1;
              if(seatno[i]>80 || p.mall[q-1].m[mov-1].movie[k][l]!=0 || seatno[i]<=0||flag1==1)
              {
                printf("enter valid and unoccupied seatnumber");
                flag1=0;
                goto seatbook;
              }
            }
          }
          system("cls");
          for(int i=0;i<sn;i++)
          {
            printf(" %d ", seatno[i]);
          }
          printf("\nYour choices");
          printf("\nNote:seats in red are occupied and seats in green are your choices");
          for(int k=0;k<10;k++)
          {
            printf("\n");
            for(int l=0;l<8;l++)
            {
              if(p.mall[q-1].m[mov-1].movie[k][l]!=0)
              {
                printf(ANSI_RED);
                printf("       %4d",(k*8)+l+1);
                printf(ANSI_RESET);
              }
              else
              {
                flag=0;
                for(int i=0;i<sn;i++)
                {if(seatno[i]==(k*8)+l+1)
                  {flag=1;}
                }
                if(flag==1)
                {
                  printf(ANSI_GREEN);
                  printf("       %4d",(k*8)+l+1);
                  printf(ANSI_RESET);
                }
                else
                {printf("       %4d",(k*8)+l+1);}
               }
              }
            }
            printf("\ncost of one ticket is Rn.70");
            printf("\ncost for %d tickets to the movie %s is Rn.%d ", sn, movie, sn*70);
            printf("\nPress p to pay the fee. Else press q to quit to menu");
            a=getch();
            if(a=='p')
            {
              system("cls");
              for(int i=0;i<sn;i++)
              {
                int k=seatno[i]/8;
                int l=seatno[i]%8-1;
                p.mall[q-1].m[mov-1].movie[k][l]=1;
                fseek(f,-(long)sizeof(p),1);
                fwrite(&p,sizeof(p),1,f);
              }
             fseek(f,-(long)sizeof(p),1);
             fwrite(&p,sizeof(p),1,f);
             system("cls");
             printf("Thank you for choosing %s to view the movie %s at time %s", theatre, movie, time);
             fflush(stdin);
             printf("\npress any key to generate ticket");
             getch();
             bookingno+=1;
             fs=fopen("bookno.txt","w");
             fprintf(fs,"%d", bookingno);
             fclose(fs);
             fptr=fopen("booked.txt", "ab+");
             strcpy(mo.nm,name);
             strcpy(mo.usernm, usname);
             strcpy(mo.theatre, theatre);
             strcpy(mo.movie, movie);
             strcpy(mo.time,time);
             mo.bookingnum=bookingno;
             printf("%d", mo.bookingnum);
             mo.seatnum=sn;
             mo.price=sn*70;
             for(int i=0;i<sn;i++)
             {
               mo.seatnos[i]=seatno[i];
             }
             mo.q=q;
             mo.mov=mov;
             fwrite(&mo,sizeof(mo),1,fptr);
             fclose(fptr);
             fls=fopen("ticket.txt", "w");
             fprintf(fls,"\t-------------------THEATER BOOKING TICKET-------------------\n");
             fprintf(fls,"\t============================================================\n");
             fprintf(fls,"\tThank you for choosing %s \n",mo.theatre);
             fprintf(fls,"\t Customer name     : %s\n",mo.nm);
             fprintf(fls,"\t Booking number    : %d\n",mo.bookingnum);
             fprintf(fls,"\t Movie name        : %s\n",mo.movie);
             fprintf(fls,"\t Movie time        : %s\n",mo.time);
             fprintf(fls,"\t Number of seats   : %d\n",mo.seatnum);
             fprintf(fls,"\t Seats             :");
             for(int i=0;i<mo.seatnum;i++)
             {
               if(i<mo.seatnum-1)
               {
                 fprintf(fls," %d,",mo.seatnos[i]);
               }
               else
               {
                 fprintf(fls," %d",mo.seatnos[i]);
               }
             }
             fprintf(fls,"\n\t price             : %d\n",mo.price);
             fprintf(fls,"\n\t==Thank you. Please Visit us again. Have a wonderful day!===\n");
             fprintf(fls,"\t============================================================\n");
             fclose(fls);
             fls=fopen("bookno.txt", "w");
             fprintf(fls,"%d",bookingno);
             fclose(fls);
             system("notepad ticket.txt");
             menu();
            }
            else if(a=='q')
            {
              menu();
            }
          }
        }
  }
  fclose(f);
}
void viewacc()
{
    FILE *fp;
    fp=fopen("project.txt","rb");
    if(fp==NULL)
    {
        printf("\nCannot open the File !!!");
        return;
    }
    int i=0;
    while(fread(&s,sizeof(s),1,fp)>0)
    {
      printf("\n\n");
      i+=1;
      printf("Account %d info:", i);
        printf("\nname:%s\nusername:%s\npassword:%s\t",s.name, s.username, s.password);
    }
    fclose(fp);
    getch();
    menu2();
}
void cancel()
  {
    int ticketno,nn,flag=0;
    FILE *fp,*ft, *f;
    f=fopen("movie.txt", "rb+");
    fp=fopen("booked.txt","rb");
    ft=fopen("booked1.txt","ab+");
    if(fp==NULL||f==NULL||ft==NULL)
    {
         printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter the booking number of the ticket you want to cancel ");
    scanf("%d",&ticketno);
    while(fread(&mo,sizeof(mo),1,fp)>0)
    {
        if(mo.bookingnum==ticketno && (strcmp(mo.usernm,usname)==0))
        {
        flag=1;
        printf("\nDo you wish to cancel your ticket. Only half of the amount you paid, that is %d will be refunded. Press 1 to continue else press 2 to go back to menu\n",mo.price/2);
        scanf("%d",&nn);
        if(nn==1)
        {
          for(int i=0;i<mo.seatnum;i++)
          {
            int k=mo.seatnos[i]/8;
            int l=mo.seatnos[i]%8-1;
            p.mall[mo.q-1].m[mo.mov-1].movie[k][l]=0;
            fseek(f,-(long)sizeof(p),1);
            fwrite(&p,sizeof(p),1,f);
          }
         fseek(f,-(long)sizeof(p),1);
         fwrite(&p,sizeof(p),1,f);
          printf("\n\t\tTicket cancelled \n");
        }
        else if(nn==2)
        {
          fwrite(&mo,sizeof(mo),1,ft);
        }
        }
        else
        {
          fwrite(&mo,sizeof(mo),1,ft);
        }
    }
    if(flag==0)
    {
    printf("\n\n\t\tNo Such Ticket booked by you!!!");
    }
    fclose(fp);
    fclose(ft);
    fclose(f);
    remove("booked.txt");
    rename("booked1.txt","booked.txt");
    getch();
    menu();
}
void changetic()
{
  int ticketno,nn,flag=0;
  int flag1=0;
  int price,seno,senum;
  FILE *fp,*ft, *f;
  f=fopen("movie.txt", "rb+");
  fp=fopen("booked.txt","rb+");
  ft=fopen("booked1.txt","ab+");
  if(fp==NULL||f==NULL||ft==NULL)
  {
       printf("\n\t\tError: Cannot Open the File!!!");
      return;
  }
  printf("\n\n\tEnter the booking number of the ticket you want to change details ");
  scanf("%d",&ticketno);
  while(fread(&mo,sizeof(mo),1,fp)>0 && flag!=1)
  {
      if(mo.bookingnum==ticketno)
      {
      flag=1;
      printf("\nDo you wish to change this ticket details? Press 1 to continue else press 2 to go back to menu\n");
      scanf("%d",&nn);
      if(nn==1)
      {
        for(int i=0;i<mo.seatnum;i++)
        {
          int k=mo.seatnos[i]/8;
          int l=mo.seatnos[i]%8-1;
          p.mall[mo.q-1].m[mo.mov-1].movie[k][l]=0;
          fseek(f,-(long)sizeof(p),1);
          fwrite(&p,sizeof(p),1,f);
        }
       fseek(f,-(long)sizeof(p),1);
       fwrite(&p,sizeof(p),1,f);
       printf("enter the new cost\n");
       scanf("%d",&price);
       mo.price=price;
       while(mo.seatnos[0]>0)
       {
         for(int i=0;i<mo.seatnum;i++)
         {
           mo.seatnos[i]=mo.seatnos[i+1];
         }
         mo.seatnum--;
       }
       printf("\nenter new number of seats");
       scanf("%d",&seno);
       printf("\nSeating arrangement in the theatre");
       printf("\nNote:seats in red are occupied");
       for(int k=0;k<10;k++)
       {
         printf("\n");
         for(int l=0;l<8;l++)
         {
           if(p.mall[q-1].m[mov-1].movie[k][l]!=0)
           {
             printf(ANSI_RED);
             printf("   %4d   ",(k*8)+l+1);
             printf(ANSI_RESET);
           }
           else
           {
             printf("   %4d   ",(k*8)+l+1);
           }
         }
       }
       printf("\nenter seat numbers");
       for(int i=0;i<seno;i++)
       {
         goto seat;
         seat:
         scanf("%d",&senum);
         for(int j=0;j<i;j++)
         {
           if(senum==mo.seatnos[j])
           {
             flag1=1;
             break;
           }
         }
         int k=senum/8;
         int l=senum%8-1;
         if(senum>80 || p.mall[q-1].m[mov-1].movie[k][l]!=0 || senum<=0||flag1==1)
         {
           printf("enter valid and unoccupied seatnumber");
           flag1=0;
           goto seat;
        }
        mo.seatnos[i]=senum;
       }
       mo.seatnum=seno;
       for(int i=0;i<mo.seatnum;i++)
       {
         int k=mo.seatnos[i]/8;
         int l=mo.seatnos[i]%8-1;
         p.mall[mo.q-1].m[mo.mov-1].movie[k][l]=1;
         fseek(f,-(long)sizeof(p),1);
         fwrite(&p,sizeof(p),1,f);
       }
      fseek(f,-(long)sizeof(p),1);
      fwrite(&p,sizeof(p),1,f);
       fseek(fp,-(long)sizeof(mo),1);
       fwrite(&mo,sizeof(mo),1,fp);
       fwrite(&mo,sizeof(mo),1,ft);
      }
      else if(nn==2)
      {
        fwrite(&mo,sizeof(mo),1,ft);
      }
      }
      else
      {
        fwrite(&mo,sizeof(mo),1,ft);
      }
  }
  if(flag==0)
  {
  printf("\n\n\t\tNo Such Ticket booked!!!");
  }
  fclose(fp);
  fclose(f);
  fclose(ft);
  remove("booked.txt");
  rename("booked1.txt","booked.txt");
  printf("\npress any key to continue\n");
  getch();
  menu2();
}
void ticketprint()
{
  FILE *f, *fp;
  int bokn;
  int flag=0;
  printf("enter booking number: ");
  scanf("%d",&bokn);
  f=fopen("ticket.txt", "w");
  fp=fopen("booked.txt", "rb+");
  while(fread(&mo,sizeof(mo),1,fp)>0 && flag==0)
  {
    if(bokn==mo.bookingnum && (strcmp(mo.usernm,usname)==0))
    {
      flag=1;
      fprintf(f,"\t-------------------THEATER BOOKING TICKET-------------------\n");
      fprintf(f,"\t============================================================\n");
      fprintf(f,"\tThank you for choosing %s \n",mo.theatre);
      fprintf(f,"\t Customer name     : %s\n",mo.nm);
      fprintf(f,"\t Booking number    : %d\n",mo.bookingnum);
      fprintf(f,"\t Movie name        : %s\n",mo.movie);
      fprintf(f,"\t Movie time        : %s\n",mo.time);
      fprintf(f,"\t Number of seats   : %d\n",mo.seatnum);
      fprintf(f,"\t Seats             :");
      for(int i=0;i<mo.seatnum;i++)
      {
        if(i<mo.seatnum-1)
        {
          fprintf(f," %d,",mo.seatnos[i]);
        }
        else
        {
          fprintf(f," %d",mo.seatnos[i]);
        }
      }
      fprintf(f,"\n\t price             : %d\n",mo.price);
      fprintf(f,"\t==Thank you. Please Visit us again. Have a wonderful day!===\n");
      fprintf(f,"\t============================================================\n");
      fclose(f);
      if(flag==1)
      {
        fclose(fp);
      }
      system("notepad ticket.txt");
      menu();
    }
  }
  if(flag==0)
  {
    printf("booking number invalid");
  getch();
  menu();
}
}
