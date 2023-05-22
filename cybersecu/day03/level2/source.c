#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void no(void)
{
  printf("Nope.\n");
}

void ok(void)
{
  printf("Good job.\n");
}

int main(void)
{
  int i;
  size_t len;
  int resultat;
  bool bVar4;
  char toto[4];
  char d;
  char c;
  char b;
  char local_39[24];
  char local_21[9];
  int local_18;
  int local_14;
  int local_10;
  char local_c;
  
  local_c = 0;
  printf("Please enter key: ");
  local_10 = scanf("%23s",local_39);
  if (local_10 != 1) {
    no();
  }
  if (local_39[1] != '0') {
    no();
  }
  if (local_39[0] != '0') {
    no();
  }
  fflush(stdin);
  memset(local_21,0,9);
  local_21[0] = 'd';
  toto[3] = 0;
  local_18 = 2;
  local_14 = 1;
  while( true ) {
    len = strlen(local_21);
    i = local_18;
    bVar4 = false;
    if (len < 8) {
      len = strlen(local_39);
      bVar4 = i < len;
    }
    if (!bVar4) break;
    toto[0] = local_39[local_18];
    toto[1] = local_39[local_18 + 1];
    toto[2] = local_39[local_18 + 2];
    resultat = atoi(toto);
    local_21[local_14] = (char)resultat;
    local_18 = local_18 + 3;
    local_14 = local_14 + 1;
  }
  local_21[local_14] = '\0';
  resultat = strcmp((char *)local_21,"delabere");
  if (resultat == 0) {
    ok();
  }
  else {
    no();
  }
  return 0;
}