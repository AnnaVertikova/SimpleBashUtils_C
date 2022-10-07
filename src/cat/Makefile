s21_cat: 
	gcc s21_cat.c -o s21_cat

test: clean s21_cat
	bash ./cat.sh
	gcc s21_cat_test.c
	./a.out

clean:
	rm -f *.out s21_cat

files:	
	rm std_cat_result.txt s21_cat_result.txt

memcheck: test
	valgrind --tool=memcheck --track-origins=yes ./a.out
