s21_grep: 
	gcc s21_grep.c -o s21_grep

test: clean s21_grep
	bash ./grep.sh
	gcc s21_grep_test.c
	./a.out

clean:
	rm -f *.out s21_grep

files:	
	rm std_grep_result.txt s21_grep_result.txt	

memcheck: test
	valgrind --tool=memcheck --track-origins=yes ./a.out
