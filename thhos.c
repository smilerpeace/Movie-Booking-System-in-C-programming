#include<stdio.h>
#include<stdlib.h>
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
}s;
int main()
{
  FILE *f;
  f=fopen("movie.txt","ab+");
  fflush(stdin);
  for(int k=0;k<3;k++)
  {
    fflush(stdin);
    printf("\n Enter area pincode: ");
    scanf("%d",&s.pincode);
    fflush(stdin);
    printf("enter mall names");
    for(int i=0; i<3; i++)
    gets(s.mall[i].mallname);
  for(int i=0;i<3;i++)
  {
  printf("\n Enter mall %d movienames: ", i+1);
  for(int j=0;j<3;j++)
  {
  fflush(stdin);
  gets(s.mall[i].m[j].moviename);
  for(int k=0;k<10;k++)
  {
    for(int l=0;l<8;l++)
    {
      s.mall[i].m[j].movie[k][l]=0;
    }
  }
}
}
for(int i=0;i<3;i++)
{
printf("\n Enter mall %d times: ", i+1);
for(int j=0;j<3;j++)
{
fflush(stdin);
gets(s.mall[i].m[j].time);
}
}
fwrite(&s,sizeof(s),1,f);
fflush(stdin);
fclose(f);
}
}
