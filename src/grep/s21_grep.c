#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flague grep_flague;
  flague_init(&grep_flague);
  starter(argc, argv, grep_flague);
  return 0;
}

int starter(int argc, char *argv[], flague grep_flague) {
  int file_counter = 0;
  char *pattern = NULL;
  int ret = 0;
  int j = 0;
  char *filename = NULL;
  char *pattern_file_name = NULL;

  if (argv[1][0] != '-') {
    pattern = argv[1];
    grep_flague.e = 1;
    j = 2;
  } else {
    j = 3;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        ret = flague_id(argv[i], &grep_flague);
      }
    }
    if (grep_flague.f) {
      pattern_file_name = argv[2];
      filename = argv[3];
      file_counter = 1;
      file_output(filename, pattern_file_name, &grep_flague, pattern,
                  &file_counter);
    }

    if (!grep_flague.f && argv[2][0] != '-') {
      pattern = argv[2];
    }
  }
  if (!grep_flague.f && ret == 0) {
    for (int i = j; i < argc; i++) {
      if (argv[i][0] != '-') {
        file_counter++;
      }
    }

    for (int i = j; i < argc; i++) {
      if (argv[i][0] != '-') {
        filename = argv[i];
        file_output(filename, pattern_file_name, &grep_flague, pattern,
                    &file_counter);
      }
    }
  }
  return 0;
}

int flague_init(flague *grep_flague) {
  grep_flague->e = 0;
  grep_flague->i = 0;
  grep_flague->v = 0;
  grep_flague->c = 0;
  grep_flague->l = 0;
  grep_flague->n = 0;
  grep_flague->h = 0;
  grep_flague->s = 0;
  grep_flague->f = 0;
  grep_flague->o = 0;
  grep_flague->eof = 0;
  return 0;
}

int flague_id(char *argv, flague *grep_flague) {
  int ret = 0;
  if (argv[0] == '-') {
    for (int i = 1; i <= (int)strlen(argv); i++) {
      if (argv[i] != '-') {
        if (argv[i] == 'e') {
          grep_flague->e = 1;
        } else if (argv[i] == 'i') {
          grep_flague->i = 1;
        } else if (argv[i] == 'v') {
          grep_flague->v = 1;
        } else if (argv[i] == 'c') {
          grep_flague->c = 1;
        } else if (argv[i] == 'l') {
          grep_flague->l = 1;
        } else if (argv[i] == 'n') {
          grep_flague->n = 1;
        } else if (argv[i] == 'h') {
          grep_flague->h = 1;
        } else if (argv[i] == 's') {
          grep_flague->s = 1;
        } else if (argv[i] == 'f') {
          grep_flague->f = 1;
        } else if (argv[i] == 'o') {
          grep_flague->o = 1;
        } else if (argv[i]) {
          ret = -1;
          printf("invalid option: %c\n", argv[i]);
        }
      }
    }
  }

  return ret;
}

int file_output(char *filename, char *pattern_file_name, flague *grep_flague,
                char *pattern, int *file_counter) {
  int match_counter = 0;
  int str_counter = 1;
  for (int i = 0; i < *file_counter; i++) {
    FILE *mf;
    mf = fopen(filename, "r");
    if (mf == NULL) {
      break;
    } else {
      char cur_str[BUFSIZE];
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
        if (!i) {
          string_editor(grep_flague, cur_str, &str_counter, pattern, filename,
                        pattern_file_name, &match_counter, file_counter);
        }
      }
    }
    if (fclose(mf) == EOF) printf("F_CLOSE ERROR\n");
  }
  if (grep_flague->c) {
    if (*file_counter < 2) {
      printf("%d\n", match_counter);
    } else {
      printf("%s:%d\n", filename, match_counter);
    }
  }

  return 0;
}

void string_editor(flague *grep_flague, char *cur_str, int *str_counter,
                   char *pattern, char *filename, char *pattern_file_name,
                   int *match_counter, int *file_counter) {
  int n_position = -1;
  char final_str[BUFSIZE] = {0};

  if (grep_flague->h || *file_counter <= 1) {
    if (grep_flague->n) {
      snprintf(final_str, BUFSIZE, "%d:%s", *str_counter, cur_str);
    } else {
      snprintf(final_str, BUFSIZE, "%s", cur_str);
    }

  } else if (*file_counter > 1 || !grep_flague->h) {
    if (grep_flague->n) {
      snprintf(final_str, BUFSIZE, "%s:%d:%s", filename, *str_counter, cur_str);
    } else {
      snprintf(final_str, BUFSIZE, "%s:%s", filename, cur_str);
    }
  }
  int length = strlen(final_str);
  if (zero_identifier(final_str, &n_position) < 0 && length > 0) {
    snprintf(final_str + length, BUFSIZE - length, "%c", 10);
  }

  flague_switcher(grep_flague, cur_str, final_str, str_counter, pattern,
                  filename, pattern_file_name, match_counter, file_counter);
}

void *flague_switcher(flague *grep_flague, char *cur_str, char *final_str,
                      int *str_counter, char *pattern, char *filename,
                      char *pattern_file_name, int *match_counter,
                      int *file_counter) {
  if (grep_flague->i) {
    flag_i(cur_str, final_str, pattern);
  }
  if (grep_flague->v) {
    flag_v(cur_str, final_str, pattern);
  }
  if (grep_flague->c) {
    flag_c(cur_str, final_str, pattern, match_counter);
  }
  if (grep_flague->l) {
    flag_l(cur_str, final_str, pattern, filename, match_counter);
  }
  if (grep_flague->n) {
    flag_n(cur_str, final_str, pattern, str_counter);
  }
  if (grep_flague->f) {
    flag_f(cur_str, final_str, pattern_file_name);
  }
  if (grep_flague->o) {
    flag_o(cur_str, pattern, filename, file_counter);
  }
  if (grep_flague->e || grep_flague->h || grep_flague->s) {
    flag_e(cur_str, final_str, pattern);
  }
}

void flag_e(char *cur_str, char *final_str, char *pattern) {
  if (match_search(cur_str, pattern, 0)) {
    printf("%s", final_str);
  }
}

void flag_i(char *cur_str, char *final_str, char *pattern) {
  if (match_search(cur_str, pattern, REG_ICASE)) {
    printf("%s", final_str);
  }
}

void flag_v(char *cur_str, char *final_str, char *pattern) {
  if (!(match_search(cur_str, pattern, 0))) {
    printf("%s", final_str);
  }
}

void flag_c(char *cur_str, char *final_str, char *pattern, int *match_counter) {
  if (match_search(cur_str, pattern, 0)) {
    *match_counter = *match_counter + 1;
  }
}

void flag_l(char *cur_str, char *final_str, char *pattern, char *filename,
            int *match_counter) {
  if (match_search(cur_str, pattern, 0)) {
    *match_counter = *match_counter + 1;
    if (*match_counter == 1) {
      printf("%s\n", filename);
    }
  }
}

void flag_n(char *cur_str, char *final_str, char *pattern, int *str_counter) {
  if (match_search(cur_str, pattern, REG_NOSUB)) {
    printf("%s", final_str);
  }
  *str_counter = *str_counter + 1;
}

void flag_f(char *cur_str, char *final_str, char *pattern_file_name) {
  for (int i = 0; i < 1; i++) {
    FILE *mf;
    mf = fopen(pattern_file_name, "r");
    if (mf == NULL) {
      break;
    } else {
      char pattern[BUFSIZE];
      while (1) {
        char *str_pointer;
        str_pointer = fgets(pattern, sizeof(pattern), mf);
        pattern[strlen(pattern) - 1] = '\0';
        if (str_pointer == NULL) {
          if (feof(mf) != 0) {
            break;
          } else {
            printf("\nF_READ ERROR\n");
            break;
          }
        }

        if (match_search(cur_str, pattern, REG_EXTENDED)) {
          printf("%s", final_str);
          break;
        }
      }
    }
    if (fclose(mf) == EOF) printf("F_CLOSE ERROR\n");
  }
}

void flag_o(char *cur_str, char *pattern, char *filename, int *file_counter) {
  o_match_search(cur_str, pattern, REG_EXTENDED, file_counter, filename);
}

int match_search(char *cur_str, char *pattern, int reg_flague) {
  regex_t regex;
  regmatch_t matches[BUFSIZE];
  regcomp(&regex, pattern, reg_flague);
  int match = regexec(&regex, cur_str, 0, matches, 0);
  regfree(&regex);

  return !match;
}

int o_match_search(char *cur_str, char *pattern, int reg_flague,
                   int *file_counter, char *filename) {
  char final_str[BUFSIZE] = {0};
  regex_t regex;
  regmatch_t matches[1];
  regcomp(&regex, pattern, reg_flague);
  int match = 0;

  while (1) {
    if (*file_counter != 1) {
      snprintf(final_str, BUFSIZE, "%s:", filename);
    } else {
      snprintf(final_str, BUFSIZE, "%s", "");
    }
    if (regexec(&regex, cur_str, 1, matches, 0) == 0) {
      match = 1;
      for (int i = matches[0].rm_so; i < matches[0].rm_eo; i++) {
        snprintf(final_str + strlen(final_str), BUFSIZE - strlen(final_str),
                 "%c", cur_str[i]);
      }
      printf("%s\n", final_str);

      cur_str = cur_str + matches[0].rm_eo;
    } else {
      break;
    }
  }

  regfree(&regex);
  return !match;
}

int zero_identifier(char *cur_str, int *n_position) {
  for (int i = 0; i < BUFSIZE; i++) {
    if (cur_str[i] == '\n') {
      *n_position = i;
      break;
    }
  }
  return *n_position;
}
