
undefined4 main(void)

{
  int iVar1;
  undefined4 local_7e;
  undefined4 local_7a;
  undefined4 local_76;
  undefined2 local_72;
  char local_70 [100];
  undefined4 local_c;
  
  local_c = 0;
  local_7e._0_1_ = '_';
  local_7e._1_1_ = '_';
  local_7e._2_1_ = 's';
  local_7e._3_1_ = 't';
  local_7a._0_1_ = 'a';
  local_7a._1_1_ = 'c';
  local_7a._2_1_ = 'k';
  local_7a._3_1_ = '_';
  local_76._0_1_ = 'c';
  local_76._1_1_ = 'h';
  local_76._2_1_ = 'e';
  local_76._3_1_ = 'c';
  local_72._0_1_ = 'k';
  local_72._1_1_ = '\0';
  printf("Please enter key: ");
  __isoc99_scanf(&DAT_00012029,local_70);
  iVar1 = strcmp(local_70,(char *)&local_7e);
  if (iVar1 == 0) {
    printf("Good job.\n");
  }
  else {
    printf("Nope.\n");
  }
  return 0;
}
