#include <math.h>
#include "convert.h"

#define WEEK_DAYS_QUANTITY 7


const char WEEK_DATES[] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
int DAYS_PER_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void get_day(char now[], char p_day[3])
{
  p_day[0] = now[0];
  p_day[1] = now[1];
  p_day[2] = now[2];
}

void get_month(char now[], char p_month[3])
{
  p_month[0] = now[4];
  p_month[1] = now[5];
  p_month[2] = now[6];
}

int get_date(char now[])
{
  int current_day;
  char stringfy_number[2] = {0, 0};

  stringfy_number[0] = ascii_to_int((int)now[8]);
  stringfy_number[1] = ascii_to_int((int)now[9]);

  if (now[9] == ' ')
    return ascii_to_int((int)now[8]);

  stringfy_number[0] = stringfy_number[0] * 10;
  current_day = stringfy_number[0] + stringfy_number[1];

  return current_day;
}

int get_year(char now[])
{
  int result, i, pot;

  result = pot = i = 0;

  for (i = 0; i < 4; i++)
  {
    pot = ((int)pow((double)10, (double)3 - i));

    result += ascii_to_int((int)now[20 + i]) * pot;
  }

  return result;
}

int is_leap_year(int year)
{

  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    return 1;
  else
    return 0;
}

int jan_first_date_start(int year)
{
  int example_year = 2023;
  int example_date = 0; // representa segunda
  int date, year_diff;
  int initial_value = 0;
  date = 0;

  year_diff = year - example_year;

  if (year < example_year)
  {
    for (int new_year = example_year; new_year >= year; new_year--)
    {
      if ((new_year - 1) < year)
        break;

      if (is_leap_year(new_year - 1))
      {
        if (date == 1)
          date = 6;
        else if ((date - 2) < 0)
          date = 5;
        else
          date -= 2;
      }
      else
      {
        if ((date - 1) < 0)
          date = 6;
        else
          date--;
      }
    }
  }
  else
  {
    for (int i = 0; i < year_diff; i++)
    {
      int new_year = example_year + i;

      if (is_leap_year(new_year))
      {
        if (date == 5)
          date = 0;
        else if ((date + 2) > 6)
          date = 1;
        else
          date += 2;
      }
      else
      {
        if ((date + 1) > 6)
          date = 0;
        else
          date++;
      }
    }
  }

  return date;
}

int round_week_date(int week_date, int days_quantity)
{
  int days_quantity_week_date = days_quantity - 28;

  if (days_quantity == 28)
  {
    return week_date;
  }

  if (days_quantity == 29)
  {
    return week_date + 1;
  }

  if (week_date + days_quantity_week_date > 6)
  {
    return days_quantity + week_date - 35;
  }

  return week_date + days_quantity_week_date;
}

int first_day_of_month(int first_day_of_jan, int numeric_month, int year)
{
  int start_week_day = first_day_of_jan;

  if (is_leap_year(year))
  {
    DAYS_PER_MONTH[1] = 29;
  }

  for (int i = 0; i <= numeric_month; i++)
  {
    if (i >= numeric_month)
      break;

    int days_quantity = DAYS_PER_MONTH[i];

    start_week_day = round_week_date(start_week_day, days_quantity);
  }

  return start_week_day;
}

void print_month(int numeric_month)
{
  switch (numeric_month)
  {
  case 0:
    printf("       January");
    break;
  case 1:
    printf("       February");
    break;
  case 2:
    printf("        March");
    break;
  case 3:
    printf("        April");
    break;
  case 4:
    printf("         May");
    break;
  case 5:
    printf("        June");
    break;
  case 6:
    printf("        July");
    break;
  case 7:
    printf("       August");
    break;
  case 8:
    printf("      September");
    break;
  case 9:
    printf("       October");
    break;
  case 10:
    printf("      November");
    break;
  case 11:
    printf("      December");
    break;
  }
}