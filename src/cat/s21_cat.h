#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#define BUFSIZE 150
#define BUFSIZE2 300

#include <stdio.h>
#include <string.h>

typedef struct flague {
  int b;
  int n;
  int s;
  int e;
  int t;
  int v;
} flague;

int flague_init(flague *cat_flague);
int flague_id(char *argv, flague *cat_flague);
int file_output(char *filename, flague *cat_flague, int *str_counter, int *previous);

void string_editor(flague *cat_flague, char *cur_str, int *str_counter,
                   int *null_str_counter, int *previous);
char *flague_switcher(flague *cat_flague, char *final_str, char *add_flags_temp,
                      int *str_counter, int *previous);
void flag_b(char *cur_str, char *add_flags_temp, int *str_counter, int *previous);
void flag_e(char *cur_str, char *add_flags_temp);
void flag_t(char *cur_str, char *add_flags_temp);
void flag_v(char *cur_str, char *add_flags_temp);
void flag_n(char *cur_str, char *add_flags_temp, int *str_counter, int *previous);


#endif  // SRC_CAT_S21_CAT_H_
