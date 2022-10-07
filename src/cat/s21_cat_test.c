#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *mf, *nf;
  char std_str[50] = {0};
  char s21_str[50] = {0};
  int correct = 0;
  int incorrect = 0;

  int i = 0;
  mf = fopen("std_cat_result.txt", "r");
  nf = fopen("s21_cat_result.txt", "r");

  while (1) {
    char *mstr = fgets(std_str, sizeof(std_str), mf);
    char *nstr = fgets(s21_str, sizeof(s21_str), nf);
    i++;
    if (mstr == NULL || nstr == NULL) {
      if (feof(mf) != 0 || feof(nf) != 0) {
        break;
      } else {
        printf("\nF_READ ERROR\n");
        break;
      }
    }
    if (!strcmp(std_str, s21_str)) {
      printf("line %4d correct\n", i);
      correct++;
    } else {
      incorrect++;
      printf("line %4d incorrect\n", i);
    }
  }
  printf("Correct %d\n", correct);
  printf("Incorrect %d\n", incorrect);

  fclose(mf);
  fclose(nf);

  return 0;
}
