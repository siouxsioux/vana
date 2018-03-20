#include <stdio.h>
#include <time.h>
#define B_A_DAY (60 * 60 * 24)
#define eSEC_vDAY (B_A_DAY / 25)
#define eSEC_vHOUR (eSEC_vDAY / 24)
#define eSEC_vMIN (eSEC_vHOUR / 60)
#define eSEC_vSEC (eSEC_vMIN / 60)

int main(void)
{
   time_t timer;
   struct tm *t_st;
   int j, h, b;
   int v, vs, vm, vh, vd;

   time(&timer);

   printf("ctime: %s\n", ctime(&timer));

   t_st = localtime(&timer);
   printf("month: %d\n",t_st->tm_mon+1);
   printf("day: %d\n",t_st->tm_mday);
   printf("hour: %d\n",j = t_st->tm_hour);
   printf("min: %d\n",h = t_st->tm_min);
   printf("sec: %d\n", b = t_st->tm_sec);
   v = h * 60 * 60 + h * 60 + b;
   vd = v / eSEC_vDAY;
   vh = v % eSEC_vHOUR;
   vm = v % eSEC_vMIN;
   vs = 0;
   printf("v=%d, vd=%d, vh=%d, vm=%d, vs=%d\n", v, vd, vh, vm, vs);

   return 0;
}

