#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "date.h"
#include "color.h"

int main(int argc, char **argv)
{

  char day[3];
  char month[3];
  int date, year, first_day_of_jan, month_in_number, quantity_days_current_month, f_d_month;
  char sun, mon, tue, wed, thu, fri, sat;
 
  time_t now;
  time(&now);

  date = get_date(ctime(&now));
  year = get_year(ctime(&now));
  get_day(ctime(&now), day);
  get_month(ctime(&now), month);
  first_day_of_jan = jan_first_date_start(year);
  month_in_number = map_month_to_int(month);
  quantity_days_current_month = DAYS_PER_MONTH[month_in_number];
  f_d_month = first_day_of_month(first_day_of_jan, month_in_number, year);

  if (is_leap_year(year))
  {
    DAYS_PER_MONTH[1] = 29;
  }

  printf("\n\n");
  paint(GREEN);
  print_month(month_in_number);
  printf(" %d", year);

  printf("\n\n");
  for (int d = 0; d < WEEK_DAYS_QUANTITY; d++)
  {
    paint(YELLOW);
    if (d == 0 || d == 6)
      paint(RED);

    printf("\e[1m %c  \e[m", WEEK_DATES[d]);
    reset();
  }
  printf("\n");

  int break_line = WEEK_DAYS_QUANTITY - f_d_month;

  for (int i = 0; i < f_d_month; i++)
    printf("    ");

  for (int d = 0; d < quantity_days_current_month; d++)
  {
    int altD = d + 1;

    if (date == altD)
    {
      paint(BLUE);
      printf("\e[1m");
    }
    else
    {
      printf("\e[m");
    }

    if ((float)altD / 10 < 1)
      printf(" %d  ", altD);
    else
      printf("%d  ", altD);

    if ((altD) % (break_line) == 0)
      printf("\n");

    if (break_line == 1)
      break_line = WEEK_DAYS_QUANTITY + 1;
    else if (altD > break_line)
    {
      break_line = WEEK_DAYS_QUANTITY + break_line;
    }
    else if (altD >= WEEK_DAYS_QUANTITY + break_line)
      break_line = WEEK_DAYS_QUANTITY;

    reset();
  }

  printf("\n\n");
  return 0;
}
