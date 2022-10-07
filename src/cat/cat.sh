
printf "test 1 without any flag\n" >> std_cat_result.txt
printf "test 1 without any flag\n" >> s21_cat_result.txt
cat test1.txt >> std_cat_result.txt
./s21_cat test1.txt >> s21_cat_result.txt

printf "\ntest 2 -e flag\n" >> std_cat_result.txt
printf "\ntest 2 -e flag\n" >> s21_cat_result.txt
cat -e test1.txt >> std_cat_result.txt
./s21_cat -e test1.txt >> s21_cat_result.txt

printf "\ntest 3 -b flag\n" >> std_cat_result.txt
printf "\ntest 3 -b flag\n" >> s21_cat_result.txt
cat -b test1.txt >> std_cat_result.txt
./s21_cat -b test1.txt >> s21_cat_result.txt

printf "\ntest 4 -n flag\n" >> std_cat_result.txt
printf "\ntest 4 -n flag\n" >> s21_cat_result.txt
cat -n test1.txt >> std_cat_result.txt
./s21_cat -n test1.txt >> s21_cat_result.txt

printf "\ntest 5 -s flag\n" >> std_cat_result.txt
printf "\ntest 5 -s flag\n" >> s21_cat_result.txt
cat -s test1.txt >> std_cat_result.txt
./s21_cat -s test1.txt >> s21_cat_result.txt

printf "\ntest 6 -t flag\n" >> std_cat_result.txt
printf "\ntest 6 -t flag\n" >> s21_cat_result.txt
cat -t test1.txt >> std_cat_result.txt
./s21_cat -t test1.txt >> s21_cat_result.txt

printf "\ntest 7 -E flag\n" >> std_cat_result.txt
printf "\ntest 7 -E flag\n" >> s21_cat_result.txt
cat -E test1.txt >> std_cat_result.txt
./s21_cat -E test1.txt >> s21_cat_result.txt

printf "\ntest 8 -T flag\n" >> std_cat_result.txt
printf "\ntest 8 -T flag\n" >> s21_cat_result.txt
cat -T test1.txt >> std_cat_result.txt
./s21_cat -T test1.txt >> s21_cat_result.txt

printf "\ntest 9 -v flag\n" >> std_cat_result.txt
printf "\ntest 9 -v flag\n" >> s21_cat_result.txt
cat -v test1.txt >> std_cat_result.txt
./s21_cat -v test1.txt >> s21_cat_result.txt

printf "\ntest 10 all flags\n" >> std_cat_result.txt
printf "\ntest 10 all flags\n" >> s21_cat_result.txt
cat -seTnb test1.txt >> std_cat_result.txt
./s21_cat -seTnb test1.txt >> s21_cat_result.txt

printf "\ntest 11 several files without any flag\n" >> std_cat_result.txt
printf "\ntest 11 several files without any flag\n" >> s21_cat_result.txt
cat test4.txt test1.txt >> std_cat_result.txt
./s21_cat test4.txt test1.txt >> s21_cat_result.txt


printf "\ntest 12 several files -e flag\n" >> std_cat_result.txt
printf "\ntest 12 several files -e flag\n" >> s21_cat_result.txt
cat -e test4.txt test1.txt >> std_cat_result.txt
./s21_cat -e test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 13 several files -b flag\n" >> std_cat_result.txt
printf "\ntest 13 several files -b flag\n" >> s21_cat_result.txt
cat -b test4.txt test1.txt >> std_cat_result.txt
./s21_cat -b test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 14 several files -n flag\n" >> std_cat_result.txt
printf "\ntest 14 several files -n flag\n" >> s21_cat_result.txt
cat -n test0.txt test1.txt >> std_cat_result.txt
./s21_cat -n test0.txt test1.txt >> s21_cat_result.txt

printf "\ntest 15 several files -s flag\n" >> std_cat_result.txt
printf "\ntest 15 several files -s flag\n" >> s21_cat_result.txt
cat -s test4.txt test1.txt >> std_cat_result.txt
./s21_cat -s test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 16 several files -t flag\n" >> std_cat_result.txt
printf "\ntest 16 several files -t flag\n" >> s21_cat_result.txt
cat -t test4.txt test1.txt >> std_cat_result.txt
./s21_cat -t test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 17 several files -E flag\n" >> std_cat_result.txt
printf "\ntest 17 several files -E flag\n" >> s21_cat_result.txt
cat -E test4.txt test1.txt >> std_cat_result.txt
./s21_cat -E test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 18 several files -T flag\n" >> std_cat_result.txt
printf "\ntest 18 several files -T flag\n" >> s21_cat_result.txt
cat -T test4.txt test1.txt >> std_cat_result.txt
./s21_cat -T test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 19 several files -v flag\n" >> std_cat_result.txt
printf "\ntest 19 several files -v flag\n" >> s21_cat_result.txt
cat -v test4.txt test1.txt >> std_cat_result.txt
./s21_cat -v test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 20 several files all flags\n" >> std_cat_result.txt
printf "\ntest 20 several files all flags\n" >> s21_cat_result.txt
cat -setnbTEv test4.txt test1.txt >> std_cat_result.txt
./s21_cat -setnbTEv test4.txt test1.txt >> s21_cat_result.txt

printf "\ntest 21 unprintable signs with -v\n" >> std_cat_result.txt
printf "\ntest 21 unprintable signs with -v\n" >> s21_cat_result.txt
cat -v invisible.txt  >> std_cat_result.txt
./s21_cat -v invisible.txt >> s21_cat_result.txt

