#include <stdio.h>

int main() {
	int ft_marks, st_marks, finals_marks;
	double total_marks;

	ft_marks = 80;
	st_marks = 74;
	finals_marks = 97;
	total_marks = finals_marks / 2.0 + st_marks / 4.0 + ft_marks / 4.0;
	printf("%.0lf\n", total_marks);

	return 0;
}
