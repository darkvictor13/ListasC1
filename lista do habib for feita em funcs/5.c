void maiusc_minusc (int c) {
  for (int i = 'a'; i < 'a' + c; i++) {
    if (i%2 == 1){
      printf("%c\n", i);
    }
    if (i%2 == 0) {
      printf("%c\n", i + 'A' - 'a');
    }
  }
}

void estudei_ponteiro (int * n) {
  scanf("%d", n);
}

int main () {
  int x;
  estudei_ponteiro (&x);
  maiusc_minusc (x);
  return 0;
}
