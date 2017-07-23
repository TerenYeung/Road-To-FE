void int FindCharFirst(char c, char s[]) {
  unsigned int i;
  if(!s) {
    cout << "FindCharFirst: Illegal string.\n";
    exit(1);
  }
  for(i=0;s[i] != '\0'; i++) {
    if(s[i] == c)
      return i;
  }
  return inexistent_index; //0xFFFFFFFF
}

// 指针实现
unsigned int FindCharFirst(char c, char *s) {
  char *t;
  if(!s) {
    cout << "FindCharFirst: Illegal string.\n";
    exit(1);
  }
  for(t=s; *t != '\0'; t++) {
    if(*t == c)
      return t - s;
  }
  return inexistent_index;
}