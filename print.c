#include<stdio.h>
struct movie
{
   char moviename[100];
   char time[100];
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
  f=fopen("movie.txt", "rb");
  while(fread(&s,sizeof(s),1,f)>0)
  {
    printf("\n pincode: %d",s.pincode);
    for(int i=0;i<3;i++)
    {
      printf("\n theatre name: %s ", s.mall[i].mallname);
      for(int j=0;j<3;j++)
      {
        printf("\n Movie in mall %d is %s ", i, s.mall[i].m[j].moviename);
        printf("\n time of the movie in mall %d is %s ", i, s.mall[i].m[j].time);
      }
    }
}

}
//strcpy(s.theatre, p.mall[t-1].mallname);
//strcpy(s.movie, p.mall[t-1].m[mov-1].moviename);
//strcpy(s.time, p.mall[t-1].m[mov-1].time);
