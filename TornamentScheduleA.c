#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 1000


int validate(int schedule[MAX][MAX], int n);
int schedule[MAX][MAX];
void tournament(int schedule[MAX][MAX], int n);


int main(void)
{

int matches;
int n, r, i;
int temp;
printf("Enter the number of competitor for Tournament: \n");
scanf("%d", &n);
printf("\n");

/* If the number of teams is even, requires n-1 matches; if odd, requires n. */

temp = isPowerOfTwo(n);


if(temp)
{
matches = n-1;  // for Even number of competitors.
tournament(schedule, n);


printf("\n    Competitor\n     \ ");
for (i = 0; i < n; i++)
  printf("%5d", i+1);
printf("\n");
printf("Day \\");
for (i = 0; i < 5 * n; i++)
   printf(".");
printf("\n");
for (r = 0; r < matches; r++)
  {
    printf("%5d:", r+1);
    for (i = 0; i < n; i++)
      printf("%5d", schedule[r][i] + 1);
    printf("\n");
  }
printf("\n");
 }// IF(temp END)
 else{
	printf("\n Number entered is not a power of 2 \n");
 }
  return 0;
}

int isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}


// Calculate tournament scheduling 
void tournament(int s[MAX][MAX], int n)
{
int matches, m, r, i;

if (n % 2)
  m = n + 1;
else
  m = n;


if (n % 2)
  matches = n;	// for Odd number of competitors..
else
  matches = n-1; // for Even number of competitors..


for (r = 0; r < matches; r++)
  {
    for (i = 0; i < r; i++)
      s[r][i] = ((matches+r-i+1) + m) % m;
    for (i = r; i < n; i++)
      s[r][i] = ((matches+r-i) + m) % m;
  }

  // make diagonal value 0 of each row.
r = 0;
for (i = m-2; i > 0; i--)
  {
    r = ((r - 2) + matches) % matches;
    s[r][0] = s[r][i];
    s[r][i] = 0;
  }


if (m != n)
{
   for (i = 0; i < matches; i++)
	{
		s[i][i] = -1;
	}
}

}

