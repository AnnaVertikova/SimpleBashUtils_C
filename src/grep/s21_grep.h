#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#define BUFSIZE 1000

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flague {
  int e;  // ищет шаблон с учётом региста
  int i;  // игнорирует различия регистра
  int v;  // выводит строчки, где нет совпадений
  int c;  // выводит только количество совпадающих строк
  int l;  // выводит только совпадающие файлы
  int n;  // предваряет каждую строку вывода номером строки из файла ввода
  int h;  // выводит совпадающие строки, не предваряя их именами файлов
  int s;  // подавляет сообщения об ошибках
  int f;  // -f file Получает регулярные выражения из файла. bonus part!
  int o;  // печатает только совпадающие (непустые) части совпавшей строки.
          // bonus part!
  int eof;
} flague;

int starter(int argc, char *argv[], flague grep_flague);
int flague_init(flague *grep_flague);
int flague_id(char *argv, flague *grep_flague);
int file_output(char *filename, char *pattern_file_name, flague *grep_flague,
                char *pattern, int *files_counter);

void string_editor(flague *grep_flague, char *cur_str, int *str_counter,
                   char *pattern, char *filename, char *pattern_file_name,
                   int *match_counter, int *files_counter);
void *flague_switcher(flague *grep_flague, char *cur_str, char *final_str, int *str_counter,
                      char *pattern, char *file_name, char *pattern_file_name,
                      int *match_counter, int *file_counter);
void flag_e(char *cur_str, char* final_str, char *pattern);
void flag_i(char *cur_str, char* final_str, char *pattern);
void flag_v(char *cur_str, char* final_str, char *pattern);
void flag_c(char *cur_str, char* final_str, char *pattern, int *match_counter);
void flag_l(char *cur_str, char *final_str, char *pattern, char *filename, int *match_counter);
void flag_n(char *cur_str, char* final_str, char *pattern, int *str_counter);
void flag_f(char *cur_str, char* final_str, char *pattern_file_name);
void flag_o(char *cur_str, char *pattern, char *filename, int *file_counter);
int match_search(char *cur_str, char *pattern, int reg_flague);
int o_match_search(char *cur_str, char *pattern, int reg_flague, int *file_counter, char* filename);
int zero_identifier(char *cur_str, int *n_position);
#endif  // SRC_GREP_S21_GREP_H_
