#define GREEN 0
#define RED 1
#define YELLOW 2
#define BLUE 3

void reset() { 
  printf("\033[0m"); 
}

void paint(int color) {
  
  switch (color) {
    case 1:
      printf("\033[0;31m");
      break;
    case 2:
      printf("\033[0;33m");
      break;
    case 3:
      printf("\033[0;34m");
      break;
    case 0:
    default:
      printf("\033[0;32m"); 
  }
}

