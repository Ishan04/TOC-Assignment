#include<stdio.h>
#include<string.h> 
#define NO_OF_CHARS 256

void createTransFunc(char *pattern, int x, int TransFunc[][NO_OF_CHARS])  //function to create transition function
{
  int q, j;
  for (q = 0; q <= x; q++){
  for (j = 0; j < NO_OF_CHARS; j++)
  TransFunc[q][j] = nextState(pattern, x, q, j);
} 
}
 
void find(char *pattern, char *input) //function to search for a pattern in a text string
{ 
  int y = strlen(input);
  int x = strlen(pattern);
  int z=x+1;
  int cnt=0;
  int TransFunc[z][NO_OF_CHARS];  // creating a transition function
  createTransFunc(pattern, x, TransFunc);
  int i, q=0;
  for (i = 0; i < y; i++){
  q = TransFunc[q][input[i]];
  if (q == x){
				cnt++;
				printf ("\n Pattern found!");
				printf("\nNo of occurences are: %d",cnt);}
  }
}
 
int nextState(char *pattern, int x, int q, int j)
{
  if (q < j && j == pattern[q])
  return q+1;

  int next, i;
  for (next = q; next > 0; next--)
  {
  if(pattern[next-1] == j)
  {
  for(i = 0; i < next-1; i++)
  {
  if (pattern[i] != pattern[q-next+1+i])
  break;
  }
  if (i == next-1)
  return next;
  }
  }
  return 0;
}

int main()
{
  char pattern[50],input[100];
  printf("\n Enter the input String: ");
  scanf("%s",&input);
  printf("\n Enter the Pattern: ");
  scanf("%s",&pattern);
  find(pattern, input);
  return 0;
}