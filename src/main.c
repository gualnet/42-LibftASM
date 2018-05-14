#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	test_ft_tolower()
{
	char str[5];
	char *str2;
	
	str[0] = 'A';
	str[1] = 'z';
	str[2] = 'C';
	str[3] = 'D';
	str[4] = '\0';
	if ((str2 = strdup(str)) == NULL)
		exit(-1);
	// -------
	printf("exec|");
	str2[1] = ft_tolower(str2[1]);
	printf("|endexec\n");
	str[1] = tolower(str[1]);
	// -------
	printf("REAL [%s]\n", str);
	printf("ft_  [%s]\n", str2);
	// if (strcmp(str, str2) != 0)
	// {
	// 	printf("REAL [%s]\n", str);
	// 	printf("ft_  [%s]\n", str2);
	// 	return(-1);
	// }
	return (1);
}

int	main()
{
	printf("\nTEST FT_TOLOWER:\n\n");
	if (test_ft_tolower() == -1)
		printf("tolower : err\n");

	// printf("\nTEST FT_TOUPPER:\n\n");
	// if (test_ft_toupper() == -1)
	// 	printf("toupper : err\n");
	
	printf("\nEND\n");
	return (0);
}