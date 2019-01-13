#include <stdio.h>
#include <string.h>
int main()
{
	// FILE *fp = fopen("test.txt", "w");
	// fprintf(fp, "hello world");
	// fclose(fp);
	int x[5] = { 2, 4, 6, 8, 10 }, *p, **pp;

      p = x;
      pp = &p;
      printf("%d ", *(p++));
      printf("%d\n", **pp);

	return 0;
}
