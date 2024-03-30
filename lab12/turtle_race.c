#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void position_of_turtle(int);
void position_of_hare(int);

int turtle = 1;
int hare = 1;

void main()
{
  srand(time(NULL));

  printf("BANG !!!!\nAND THEY'RE OFF !!!!\n");

  while (1)
  {
    int h = rand() % 10 + 1;
    position_of_hare(h);
    int t = rand() % 10 + 1;
    position_of_turtle(t);
   
   //update position on each line
    for(int i = 1; i <= 70; i++)
    {
      if (i == 1) printf("|");
      if (i == 70 && i != hare && i != turtle) printf("|");
      else if (i == hare && i == turtle)
      {
        printf("OUCH!!!");
        i += 6;
      }
      else if (i == hare) printf("H");
      else if (i == turtle) printf("T");
      else printf(" ");
    }
    printf("\n");
    if (hare >= 70 && turtle >= 70)
    { 
      printf("Game Tied!!");
      break; 
    }
    else if (hare >= 70 )
    { 
      printf("Hare wins. Yuch!");
      break; 
    }
    else if (turtle >= 70)
    { 
      printf("TORTOISE WINS!!! YAY!!!");
      break; 
    }
    
  }
}

// Position of turtle control
void position_of_turtle(int t)
{
  if (t >= 1 && t <= 5) turtle += 3;
  else if (t == 6 || t == 7)
  { 
    turtle -= 6;
    if (turtle < 1) turtle = 1; 
  }
  else turtle += 1;
}

// Position of hare control.
void position_of_hare(int h)
{
  if (h == 1 || h == 2) hare += 0;
  else if (h == 3|| h == 4) hare += 9;
  else if (h == 5)
  {
    hare -= 12;
    if(hare < 1) hare=1; 
  }
  else if (h >= 6 && h <= 8) hare += 1;
  else
  { 
    hare -= 2;
    if(hare < 1) hare=1; 
  }
}