int ascii_to_int(int ascii_digit) {
  // 48 representes ascii digit 0, 49 -> 1...
  int result = ascii_digit - 48;

  if (result >= 0) return result;

  return 0;
}

int map_month_to_int(char month[]) {
  int result, month_digit_1, month_digit_2, month_digit_3;

  month_digit_1 = (int)month[0];
  month_digit_2 = (int)month[1];
  month_digit_3 = (int)month[2];

  switch (month_digit_1) {
    case 74:                    // J
      if (month_digit_2 == 97)  // a
        result = 0;
      else if (month_digit_2 != 97 && month_digit_3 == 110)  // n
        result = 5;
      else
        result = 6;
      break;
    case 70:  // F
      result = 1;
      break;
    case 77:                     // M
      if (month_digit_3 == 114)  // r
        result = 2;
      else
        result = 4;
      break;
    case 65:                     // A
      if (month_digit_2 == 112)  // p
        result = 3;
      else
        result = 7;
      break;
    case 83:  // S
      result = 8;
      break;
    case 79:  // O
      result = 9;
      break;
    case 78:  // N
      result = 10;
      break;
    case 68:  // D
      result = 11;
      break;
    default:
      result = 0;
  }
  return result;
}
