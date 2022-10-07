rm s21_grep_result.txt
rm std_grep_result.txt

printf "test 1 without any flag\n" >> std_grep_result.txt
printf "test 1 without any flag\n" >> s21_grep_result.txt
grep im test1.txt >> std_grep_result.txt
./s21_grep im test1.txt >> s21_grep_result.txt


printf "\ntest 2 several files without any flag\n" >> std_grep_result.txt
printf "\ntest 2 several files without any flag\n" >> s21_grep_result.txt
grep im test1.txt test2.txt >> std_grep_result.txt
./s21_grep im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 3 -e flag\n" >> std_grep_result.txt
printf "\ntest 3 -e flag\n" >> s21_grep_result.txt
grep -e im test1.txt >> std_grep_result.txt
./s21_grep -e im test1.txt >> s21_grep_result.txt

printf "\ntest 4 several files -e flag\n" >> std_grep_result.txt
printf "\ntest 4 several files -e flag\n" >> s21_grep_result.txt
grep -e im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -e im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 5 -i flag\n" >> std_grep_result.txt
printf "\ntest 5 -i flag\n" >> s21_grep_result.txt
grep -i iM test1.txt >> std_grep_result.txt
./s21_grep -i iM test1.txt >> s21_grep_result.txt

printf "\ntest 5 several files -i flag\n" >> std_grep_result.txt
printf "\ntest 5 several files -i flag\n" >> s21_grep_result.txt
grep -i iM test1.txt test2.txt >> std_grep_result.txt
./s21_grep -i iM test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 6 -v flag\n" >> std_grep_result.txt
printf "\ntest 6 -v flag\n" >> s21_grep_result.txt
grep -v im test1.txt >> std_grep_result.txt
./s21_grep -v im test1.txt >> s21_grep_result.txt

printf "\ntest 7 several files -v flag\n" >> std_grep_result.txt
printf "\ntest 7 several files -v flag\n" >> s21_grep_result.txt
grep -v im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -v im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 8 -c flag\n" >> std_grep_result.txt
printf "\ntest 8 -c flag\n" >> s21_grep_result.txt
grep -c im test1.txt >> std_grep_result.txt
./s21_grep -c im test1.txt >> s21_grep_result.txt

printf "\ntest 9 several files -c flag\n" >> std_grep_result.txt
printf "\ntest 9 several files -c flag\n" >> s21_grep_result.txt
grep -c im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -c im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 10 -l flag\n" >> std_grep_result.txt
printf "\ntest 10 -l flag\n" >> s21_grep_result.txt
grep -l im test1.txt >> std_grep_result.txt
./s21_grep -l im test1.txt >> s21_grep_result.txt

printf "\ntest 10 several files -l flag\n" >> std_grep_result.txt
printf "\ntest 10 several files -l flag\n" >> s21_grep_result.txt
grep -l im test1.txt test2.txt test3.txt >> std_grep_result.txt
./s21_grep -l im test1.txt test2.txt test3.txt >> s21_grep_result.txt

printf "\ntest 11 -n flag\n" >> std_grep_result.txt
printf "\ntest 11 -n flag\n" >> s21_grep_result.txt
grep -n im test1.txt >> std_grep_result.txt
./s21_grep -n im test1.txt >> s21_grep_result.txt

printf "\ntest 12 several files -n flag\n" >> std_grep_result.txt
printf "\ntest 12 several files -n flag\n" >> s21_grep_result.txt
grep -n im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -n im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 13 -h flag\n" >> std_grep_result.txt
printf "\ntest 13 -h flag\n" >> s21_grep_result.txt
grep -h im test1.txt >> std_grep_result.txt
./s21_grep -h im test1.txt >> s21_grep_result.txt

printf "\ntest 14 several files -h flag\n" >> std_grep_result.txt
printf "\ntest 14 several files -h flag\n" >> s21_grep_result.txt
grep -h im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -h im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 15 -s flag\n" >> std_grep_result.txt
printf "\ntest 15 -s flag\n" >> s21_grep_result.txt
grep -s im test18.txt >> std_grep_result.txt
./s21_grep -s im test18.txt >> s21_grep_result.txt

printf "\ntest 16 several files -s flag\n" >> std_grep_result.txt
printf "\ntest 16 several files -s flag\n" >> s21_grep_result.txt
grep -s im test1.txt test28.txt >> std_grep_result.txt
./s21_grep -s im test1.txt test28.txt >> s21_grep_result.txt

printf "\ntest 17 -f flag\n" >> std_grep_result.txt
printf "\ntest 17 -f flag\n" >> s21_grep_result.txt
grep -f regex_search.txt test3.txt >> std_grep_result.txt
./s21_grep -f regex_search.txt test3.txt >> s21_grep_result.txt

printf "\ntest 19 -o flag\n" >> std_grep_result.txt
printf "\ntest 19 -o flag\n" >> s21_grep_result.txt
grep -o im test1.txt >> std_grep_result.txt
./s21_grep -o im test1.txt >> s21_grep_result.txt

printf "\ntest 19 -o flag with RE\n" >> std_grep_result.txt
printf "\ntest 19 -o flag with RE\n" >> s21_grep_result.txt
grep -o [a-e] test1.txt >> std_grep_result.txt
./s21_grep -o [a-e] test1.txt >> s21_grep_result.txt

printf "\ntest 20 several files -o flag\n" >> std_grep_result.txt
printf "\ntest 20 several files -o flag\n" >> s21_grep_result.txt
grep -o im test1.txt test2.txt >> std_grep_result.txt
./s21_grep -o im test1.txt test2.txt >> s21_grep_result.txt

printf "\ntest 20 several files -o flag with RE\n" >> std_grep_result.txt
printf "\ntest 20 several files -o flag with RE\n" >> s21_grep_result.txt
grep -o [a-e] test1.txt test2.txt >> std_grep_result.txt
./s21_grep -o [a-e] test1.txt test2.txt >> s21_grep_result.txt
