#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "libfts.h"

int	test_ft_isalnum()
{
	int		ret1 = 0;
	int		ret2 = 0;
	int		i = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";

	while (str[i] != '\0')
	{
		ret1 = isalnum(str[i]);
		ret2 = ft_isalnum(str[i]);
		if (ret1 != ret2)
		{
			printf("Err i = %d | c = %c\n", i, str[i]);
			return (-1);
		}
		i++;
	}
	printf("TEST 1: OK\n");
	return (1);
}

int	test_ft_isdigit()
{
	int		ret1 = 0;
	int		ret2 = 0;
	int		i = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";

	while (str[i] != '\0')
	{
		ret1 = isdigit(str[i]);
		ret2 = ft_isdigit(str[i]);
		if (ret1 != ret2)
		{
			printf("Err i = %d | c = %c\n", i, str[i]);
			return (-1);
		}
		i++;
	}
	printf("TEST 1: OK\n");
	return (1);
}

int	test_ft_isalpha()
{
	int		ret1 = 0;
	int		ret2 = 0;
	int		i = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";

	while (str[i] != '\0')
	{
		ret1 = isalpha(str[i]);
		ret2 = ft_isalpha(str[i]);
		if (ret1 != ret2)
		{
			printf("Err i = %d | c = %c\n", i, str[i]);
			return (-1);
		}
		i++;
	}
	printf("TEST 1: OK\n");
	return (1);
}

int	test_ft_strcat()
{
	char	str1[30];
	char	str2[30];
	char	*res1;
	char	*res2;
	char	*base = "salut, je suis moi !";
	size_t	size1;
	size_t	size2;

	bzero(str1, 30);
	str1[0] = 'X';
	str1[1] = 'y';
	str1[2] = 'Z';
	str1[3] = '-';
	str1[4] = '>';
	bzero(str2, 30);
	str2[0] = 'X';
	str2[1] = 'y';
	str2[2] = 'Z';
	str2[3] = '-';
	str2[4] = '>';

	res1 = ft_strcat(str1, base);
	res2 = strcat(str2, base);
	if (strcmp(res1, res2) != 0)
	{
		printf("str1[%s]\n", str1);
		printf("str2[%s]\n", str2);
		printf("ft_strcat: [%s]\n", res1);
		printf("strcat:    [%s]\n", res2);
	}
	else
		printf("TEST 1: OK\n");
	return (1);
}

int test_ft_bzero()
{
	int		i = 0;
	int		len;
	char	str[5];
	str[0] = 'A';
	str[1] = 'z';
	str[2] = '(';
	str[3] = 'Z';
	str[4] = '\0';

	len = strlen(str);
	ft_bzero(str, len);
	// bzero(str, len);
	if (strlen(str) != 0)
	{
		while (i < len - 1)
		{
			printf("[%c ", str[i]);
			printf("%d]-", str[i]);
			i++;
		}
		printf("[%c", str[i]);
		printf("%d]|", str[i]);
		return (-1);
	}
	else
		printf("TEST 1: OK\n");
	return (1);
}

int	test_ft_toupper()
{
	char	str[5];
	char	*str2;
	char	*str3 = "_()*OUGI897fiyvhb)[t97rf8yit97r8fYIV6t97rfiy98t7iu";
	int		i = 0;
	
	str[0] = 'A';
	str[1] = 'z';
	str[2] = '(';
	str[3] = 'Z';
	str[4] = '\0';
	if ((str2 = strdup(str)) == NULL)
		exit(-1);
	// -------
	str2[0] = ft_toupper(str2[0]);
	str2[1] = ft_toupper(str2[1]);
	str2[2] = ft_toupper(str2[2]);
	str2[3] = ft_toupper(str2[3]);
	str[0] = toupper(str2[0]);
	str[1] = toupper(str2[1]);
	str[2] = toupper(str2[2]);
	str[3] = toupper(str2[3]);
	// -------
	if (strcmp(str, str2) != 0)
	{
		printf("REAL [%s]\n", str);
		printf("ft_  [%s]\n", str2);
		return(-1);
	}
	else
		printf("TEST 1: OK\n");
	free(str2);
	// -------
	if ((str3 = strdup(str3)) == NULL)
		exit(-1);
	if ((str2 = strdup(str3)) == NULL)
		exit(-1);
	while (i < strlen(str3))
	{
		str3[i] = toupper(str3[i]);
		str2[i] = ft_toupper(str3[i]);
		i++;
	}
	if (strcmp(str2, str3) != 0)
	{
		printf("STR  [_()*OUGI897fiyvhb)[t97rf8yit97r8fYIV6t97rfiy98t7iu]\n");
		printf("REAL [%s]\n", str3);
		printf("ft_  [%s]\n", str2);
		return(-1);
	}
	else
		printf("TEST 2: OK\n");
	return (1);
}

int	test_ft_tolower()
{
	char	str[5];
	char	*str2;
	char	*str3 = "_()*OUGI897fiyvhb)[t97rf8yit97r8fYIV6t97rfiy98t7iu";
	int		i = 0;
	
	str[0] = 'A';
	str[1] = 'z';
	str[2] = '(';
	str[3] = 'Z';
	str[4] = '\0';
	if ((str2 = strdup(str)) == NULL)
		exit(-1);
	// -------
	str2[0] = ft_tolower(str2[0]);
	str2[1] = ft_tolower(str2[1]);
	str2[2] = ft_tolower(str2[2]);
	str2[3] = ft_tolower(str2[3]);
	str[0] = tolower(str2[0]);
	str[1] = tolower(str2[1]);
	str[2] = tolower(str2[2]);
	str[3] = tolower(str2[3]);
	// -------
	if (strcmp(str, str2) != 0)
	{
		printf("REAL [%s]\n", str);
		printf("ft_  [%s]\n", str2);
		return(-1);
	}
	else
		printf("TEST 1: OK\n");
	free(str2);
	// -------
	if ((str3 = strdup(str3)) == NULL)
		exit(-1);
	if ((str2 = strdup(str3)) == NULL)
		exit(-1);
	while (i < strlen(str3))
	{
		str3[i] = tolower(str3[i]);
		str2[i] = ft_tolower(str3[i]);
		i++;
	}
	if (strcmp(str2, str3) != 0)
	{
		printf("STR  [_()*OUGI897fiyvhb)[t97rf8yit97r8fYIV6t97rfiy98t7iu]\n");
		printf("REAL [%s]\n", str3);
		printf("ft_  [%s]\n", str2);
		return(-1);
	}
	else
		printf("TEST 2: OK\n");
	return (1);
}

int	main()
{
	printf("\n\tFT_isalnum:\n");
	if (test_ft_isalnum() == -1)
		printf("isalnum : err\n");

	// printf("\n\tFT_isdigit:\n");
	// if (test_ft_isdigit() == -1)
	// 	printf("isdigit : err\n");

	// printf("\n\tFT_isalpha:\n");
	// if (test_ft_isalpha() == -1)
	// 	printf("isalpha : err\n");

	// printf("\n\tFT_strcat:\n");
	// if (test_ft_strcat() == -1)
	// 	printf("strcat : err\n");
	
	// printf("\n\tFT_bzero:\n");
	// if (test_ft_bzero() == -1)
	// 	printf("bzero : err\n");

	// printf("\n\tFT_TOLOWER:\n");
	// if (test_ft_tolower() == -1)
	// 	printf("tolower : err\n");

	// printf("\n\tFT_TOUPPER:\n\n");
	// if (test_ft_toupper() == -1)
	// 	printf("toupper : err\n");
	
	printf("\nEND\n");
	return (0);
}