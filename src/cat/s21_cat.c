#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int str_counter = 1;
  int previous = 0;

  flague cat_flague;
  flague_init(&cat_flague);
  int ret = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      ret = flague_id(argv[i], &cat_flague);
    }
  }
  if (ret == 0) {
    char *filename;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        filename = argv[i];
        file_output(filename, &cat_flague, &str_counter, &previous);
      }
    }
  }
  return 0;
}

int flague_init(flague *cat_flague) {
  cat_flague->s = 0;
  cat_flague->b = 0;
  cat_flague->e = 0;
  cat_flague->t = 0;
  cat_flague->n = 0;
  cat_flague->v = 0;
}

int flague_id(char *argv, flague *cat_flague) {
  int ret = 0;
  if (argv[1] == '-') {
    if (!strcmp(argv, "--number")) {
      cat_flague->n = 1;
    } else if (!strcmp(argv, "--number-nonblank")) {
      cat_flague->n = 0, cat_flague->b = 1;
    } else if (!strcmp(argv, "--squeeze-blank")) {
      cat_flague->s = 1;
    } else if (strcmp(argv, "--number") && strcmp(argv, "--number-nonblank") &&
               strcmp(argv, "--squeeze-blank")) {
      ret = -1;
      printf("invalid option: %s\n", argv);
    }
  } else if (argv[0] == '-') {
    for (int i = 1; i <= strlen(argv); i++) {
      if (argv[i] != '-') {
        if (argv[i] == 'b') {
          cat_flague->n = 0, cat_flague->b = 1;
        } else if (argv[i] == 's') {
          cat_flague->s = 1;
        } else if (argv[i] == 'e') {
          cat_flague->e = 1, cat_flague->v = 1;
        } else if (argv[i] == 't') {
          cat_flague->t = 1, cat_flague->v = 1;
        } else if (argv[i] == 'E') {
          cat_flague->e = 1;
        } else if (argv[i] == 'T') {
          cat_flague->t = 1;
        } else if (argv[i] == 'v') {
          cat_flague->v = 1;
        } else if (argv[i] == 'n') {
          if (cat_flague->b == 0) {
            cat_flague->n = 1;
          } else {
            cat_flague->n = 0;
          }
        } else if (argv[i]) {
          ret = -1;
          printf("invalid option: %c\n", argv[i]);
        }
      }
    }
  }
  return ret;
}

int file_output(char *filename, flague *cat_flague, int *str_counter,
                int *previous) {
  int null_str_counter = 0;

  for (int i = 0; i < 1; i++) {
    FILE *mf;
    mf = fopen(filename, "r");
    if (mf == NULL) {
      break;
    } else {
      char cur_str[100];
      while (1) {
        char *str_pointer;
        str_pointer = fgets(cur_str, sizeof(cur_str), mf);
        if (str_pointer == NULL) {
          if (feof(mf) != 0) {
            break;
          } else {
            printf("\nF_READ ERROR\n");
            break;
          }
        }

        string_editor(cat_flague, cur_str, str_counter, &null_str_counter,
                      previous);
        if (cur_str[strlen(cur_str) - 1] != 10)
          *previous = 1;
        else
          *previous = 0;
      }
    }
    if (fclose(mf) == EOF) printf("F_CLOSE ERROR\n");
  }

  return 0;
}

void string_editor(flague *cat_flague, char *cur_str, int *str_counter,
                   int *null_str_counter, int *previous) {
  char final_str[200] = {0};
  char add_flags_temp[150] = {0};

  if (cat_flague->s) {
    if (cur_str[0] != '\n') {
      snprintf(final_str, BUFSIZE, "%s", cur_str);
      *null_str_counter = 0;
      flague_switcher(cat_flague, final_str, add_flags_temp, str_counter,
                      previous);

    } else {
      if (*null_str_counter == 0) {
        snprintf(final_str, BUFSIZE, "%s", cur_str);
        flague_switcher(cat_flague, final_str, add_flags_temp, str_counter,
                        previous);
      }

      *null_str_counter = 1;
    }

  } else {  // if !-s
    snprintf(final_str, BUFSIZE, "%s", cur_str);
    flague_switcher(cat_flague, final_str, add_flags_temp, str_counter,
                    previous);
  }

  printf("%s", final_str);
}

char *flague_switcher(flague *cat_flague, char *final_str, char *add_flags_temp,
                      int *str_counter, int *previous) {
  if (cat_flague->v) {
    flag_v(final_str, add_flags_temp);
  }

  if (cat_flague->t) {
    flag_t(final_str, add_flags_temp);
  }

  if (cat_flague->b) {
    flag_b(final_str, add_flags_temp, str_counter, previous);
  }
  if (cat_flague->n) {
    flag_n(final_str, add_flags_temp, str_counter, previous);
  }
  if (cat_flague->e) {
    flag_e(final_str, add_flags_temp);
  }

  return final_str;
}

void flag_b(char *cur_str, char *add_flags_temp, int *str_counter,
            int *previous) {
  for (int i = 0; add_flags_temp[i] != '\0'; i++) {
    add_flags_temp[i] = '\0';
  }
  if (*previous == 1) {
    snprintf(add_flags_temp, BUFSIZE, "%s", cur_str);

  } else {
    if (cur_str[0] != '\n') {
      if (*str_counter > 9) {
        snprintf(add_flags_temp, BUFSIZE, "    %d%c%s", *str_counter, 9,
                 cur_str);
      } else if (*str_counter > 99) {
        snprintf(add_flags_temp, BUFSIZE, "   %d%c%s", *str_counter, 9,
                 cur_str);
      } else {
        snprintf(add_flags_temp, BUFSIZE, "     %d%c%s", *str_counter, 9,
                 cur_str);
      }
      *str_counter = *str_counter + 1;
    } else {
      snprintf(add_flags_temp, BUFSIZE, "%s", cur_str);
    }
  }
  snprintf(cur_str, BUFSIZE, "%s", add_flags_temp);
}

void flag_e(char *cur_str, char *add_flags_temp) {
  for (int i = 0; add_flags_temp[i] != '\0'; i++) {
    add_flags_temp[i] = '\0';
  }

  for (int i = 0; i < strlen(cur_str); i++) {
    add_flags_temp[i] = cur_str[i];
  }

  if (add_flags_temp[strlen(add_flags_temp) - 1] == 10) {
    add_flags_temp[strlen(add_flags_temp) - 1] = '$';
    add_flags_temp[strlen(add_flags_temp)] = 10;
  }
  snprintf(cur_str, BUFSIZE, "%s", add_flags_temp);
}

void flag_t(char *cur_str, char *add_flags_temp) {
  int increaser = 0;

  for (int i = 0, j = 0; i < strlen(cur_str) + increaser; i++, j++) {
    add_flags_temp[i] = cur_str[j];

    if (cur_str[j] == '\t') {
      add_flags_temp[i] = '^';
      add_flags_temp[i + 1] = 'I';
      i = i + 1;
      increaser++;
    }
  }

  snprintf(cur_str, BUFSIZE, "%s", add_flags_temp);
}

void flag_n(char *cur_str, char *add_flags_temp, int *str_counter,
            int *previous) {
  if (*previous == 1) {
    snprintf(add_flags_temp, BUFSIZE, "%s", cur_str);

  } else {
    if (*str_counter > 9) {
      snprintf(add_flags_temp, BUFSIZE, "    %d%c%s", *str_counter, 9, cur_str);
    } else if (*str_counter > 99) {
      snprintf(add_flags_temp, BUFSIZE, "   %d%c%s", *str_counter, 9, cur_str);
    } else {
      snprintf(add_flags_temp, BUFSIZE, "     %d%c%s", *str_counter, 9,
               cur_str);
    }
    *str_counter = *str_counter + 1;
  }
  snprintf(cur_str, BUFSIZE, "%s", add_flags_temp);
}

void flag_v(char *cur_str, char *add_flags_temp) {
  int n_position = -1;
  int zero_position = 0;
  int last_line = 0;

  for (int i = 0; i < BUFSIZE; i++) {
    if (cur_str[i] == '\n') {
      n_position = i;
      break;
    }
    if (cur_str[i] == '\0') {
      zero_position = i;
      if (n_position < 0) {
        last_line = 1;
      }
      break;
    }
  }
  for (int i = 0; i < BUFSIZE; i++) {
    int ch = cur_str[i];
    int length = strlen(add_flags_temp);
    if (ch == 0 && n_position < 0) {
      zero_position = i;
    }

    if (ch == 9 || ch == 10) {
      snprintf(add_flags_temp + length, BUFSIZE - length, "%c", ch);
    } else if (ch > 0) {
      if (ch == 127) {
        snprintf(add_flags_temp + length, BUFSIZE - length, "^?");
      } else if (ch < 32) {
        snprintf(add_flags_temp + length, BUFSIZE - length, "^%c", ch + 64);
      } else {
        snprintf(add_flags_temp + length, BUFSIZE - length, "%c", ch);
      }

    } else if (ch < 0) {
      snprintf(add_flags_temp + length, BUFSIZE - length, "M-");

      if (ch < -96) {
        snprintf(add_flags_temp + length + 2, BUFSIZE - length - 2, "^%c",
                 ch + 192);

      } else if (ch == -1) {
        snprintf(add_flags_temp + length + 2, BUFSIZE - length - 2, "^%c",
                 ch + 64);

      } else {
        snprintf(add_flags_temp + length + 2, BUFSIZE - length - 2, "%c",
                 ch + 128);
      }
    } else {
      snprintf(add_flags_temp + length + 2, BUFSIZE - length - 2, "%c", ch);
    }
  }
  if (zero_position != 0 && last_line) {
    snprintf(add_flags_temp + strlen(add_flags_temp),
             BUFSIZE - strlen(add_flags_temp), "^%c", 64);
    snprintf(add_flags_temp + strlen(add_flags_temp),
             BUFSIZE - strlen(add_flags_temp), "%c", 10);
  }

  snprintf(cur_str, BUFSIZE, "%s", add_flags_temp);
}
