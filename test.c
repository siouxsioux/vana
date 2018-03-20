#include <stdio.h>
#include <time.h>

//Vana'diel starts 886 Jan 1 0:00:00
// VDAYS(sec) ((long )((long )((long )(sec) / (long )(60 * 60 * 24))))  * 25
#define VDAYS(sec) ((long )((long )(sec) / 3456L))
#define VYEAR(day) ((long )((long )day / 360L))
#define VMON(day) ((long )(((long )day % 360L) / 30L))
#define VDAY(day) ((long )(((long )day % 360L) % 30L))

int main(void)
{
   time_t start, timer;
   struct tm t, *t_st;
   long   eTimer_s, vTimer_s;
   long vdays, vy, vmon, vd, vh, vmin, vs;

	// Earth 2002 Jan 1 0:00:00 Tue [Vana'diel starts]
   t.tm_year = 102; // 2002
   t.tm_mon  = 0;   // Jan
   t.tm_mday = 1;  // 1
   t.tm_wday = 2;   // Tue
   t.tm_hour = 0;   // 0:00:00
   t.tm_min  = 0;
   t.tm_sec  = 0;

   start = mktime(&t);

   time(&timer);

   printf("[Erath]Start time(%ld)%s", start, ctime(&start));
   printf("[Erath]Now time  (%ld)%s", timer, ctime(&timer));
  
   eTimer_s = (long )(timer - start);
   vdays = VDAYS(eTimer_s);
   vy = VYEAR(vdays) + 886L;
   vmon = VMON(vdays) + 1L;
   vd = VDAY(vdays);
//   printf("%ld %ld %ld\n", vdays, vdays % 360L, vdays % 360L % 30L);
   vh = (eTimer_s / 360L) * 25L - ((long )(vdays * 24L));
   vmin = vTimer_s / 60L - ((long )(vdays * 24L * 60));
   vs = vTimer_s % 60L;
  printf("diff sec=%ld day=%ld year=%ld\n", eTimer_s, vdays, vy);
 
   printf("%ld/%02ld/%02ld %02ld:%02ld:%02ld\n", vy, vmon, vd, vh, vmin, vs);   

   return 0;
}


