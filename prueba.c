#include <stdio.h>
#include <string.h>

int main ()
{
	const char *a = "a.ber";
	const char *b = ".ber";

	printf("%d", strncmp(a, b, 4));

	return (0);
}