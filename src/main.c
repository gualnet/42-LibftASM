#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "libfts.h"

int	test_ft_strcat()
{
	char	*str1;
	char	*str2;
	char	*base = "salut, je suis moi !";
	size_t	size1;
	size_t	size2;

	str1 = strdup(base);
	str2 = malloc(strlen(str1) + 1);
	bzero(str2, strlen(str1) + 1);
	printf("str1[%s]\n", str1);
	printf("str2[%s]\n", str2);
	
	strcat(str2, str1);
	
	printf("str1[%s]\n", str1);
	printf("str2[%s]\n", str2);

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
	printf("\n\tFT_strcat:\n");
	if (test_ft_strcat() == -1)
		printf("strcat : err\n");
	
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