#include <stdio.h>
#include <string.h>

int main(void)
{
  int ret;
  char  mdp[14];
  char in[100];
  
  mdp[0] = '_';
  mdp[1] = '_';
  mdp[2] = 's';
  mdp[3] = 't';
  mdp[4] = 'a';
  mdp[5] = 'c';
  mdp[6] = 'k';
  mdp[7] = '_';
  mdp[8] = 'c';
  mdp[9] = 'h';
  mdp[10] = 'e';
  mdp[11] = 'c';
  mdp[12] = 'k';
  mdp[13] = '\0';
  printf("Please enter key: ");
  scanf("%s",in);
  ret = strcmp(in,(char *)mdp);
  if (ret == 0) {
    printf("Good job.\n");
  }
  else {
    printf("Nope.\n");
  }
  return 0;
}
