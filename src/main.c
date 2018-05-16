#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "libfts.h"

void	test_buff()
{
	char test[100];
}

void	*ft_cat(int fd);

int	test_ft_cat()
{
	int		fd;
	char	*path;
	path = "test_cat_00";
	path = "inc/libfts.h";
	path = "Makefile";
	// printf("file path: ");
	// scanf("%s", path);
	
	fd = open(path, O_RDONLY | O_NONBLOCK);
	// if (fd < 0)
	printf("Attention fd = %d\n", fd);
	
	void *x = ft_cat(fd);
	// printf("RSP [%p]\n", x);
	// printf("\nRET [%d]\n", (int)x);
	// printf("RSP [%d]\n", *(int*)x);
	// printf("RSP [%s]\n", (char*)x);
	// printf("FD  [%p]\n", &fd);
	// printf("FD  [%d]\n", fd);

	close(fd);
	printf("\nFT_CAT END\n");
	return (1);
}

int	test_ft_strdup()
{
	char	*base = "Le mot « aviation »";
	char	*str1 = NULL;
	char	*str2 = NULL;

	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("strdup     [%p][%s]\n", str1, str1);
		printf("strdup     [%p][%s]\n", str2, str2);
		printf("TEST 1: NOK\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("TEST 1: OK\n");

	base = "Le mot « aviation » (du latin « avis », qui signifie « oiseau »2, et du suffixe « atio ») a été employé pour la première fois par Gabriel de La Landelle, en 1863,\ndans le livre Aviation ou navigation aérienne sans ballon, un ouvrage rendant compte des tentatives d'envol de Jean-Marie Le Bris dans un appareil plus lourd que l'air.";
	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("strdup     [%p][%s]\n", str1, str1);
		printf("strdup     [%p][%s]\n", str2, str2);
		printf("TEST 2: NOK\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("TEST 2: OK\n");

	base = "";
	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("strdup     [%p][%s]\n", str1, str1);
		printf("strdup     [%p][%s]\n", str2, str2);
		printf("TEST 3: NOK\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("TEST 3: OK\n");

	// // CRASH TEST
	// base = NULL;
	// str1 = strdup(base);
	// str2 = ft_strdup(base);
	// // if (strcmp(str1, str2) == 0)
	// // {
	// // 	printf("strdup     [%p][%s]\n", str1, str1);
	// // 	printf("strdup     [%p][%s]\n", str2, str2);
	// // 	printf("TEST 4: NOK\n");
	// // 	return (-1);
	// // }
	// // free(str1);
	// // free(str2);
	// // printf("TEST 4: OK\n");
	return (1);
}

int	test_ft_memcpy()
{
	size_t	size = 80;
	char	*base = "Le loup gris est l'un des animaux les plus connus et les plus étudiés au monde, avec probablement plus de livres écrits à son sujet que toute autre espèce sauvage3.";
	char	*str1;
	char	*ret1;

	str1 = malloc(size);
	bzero(str1, size);
	ret1 = NULL;
	ret1 = memcpy(str1, base, strlen(base));
	printf("memcpy    [%p - %p][%s]\n", str1, ret1, str1);

	bzero(str1, size);
	ret1 = NULL;
	ret1 = ft_memcpy(str1, base, strlen(base));
	printf("ft_memcpy [%p - %p][%s]\n", str1, ret1, str1);

	free(str1);
	return (1);
}

int	test_ft_memset()
{
	size_t	size = 80;
	char	*str1;
	char	*ret1;
	char	*str2;
	char	*ret2;

	str1 = malloc(size);
	bzero(str1, size);
	str2 = malloc(size);
	bzero(str2, size);

	ret1 = memset(str1, '$', 12);
	printf("memset [%p - %p][%s]\n", str1, ret1, str1);
	ret2 = ft_memset(str2, '$', 12);
	printf("memset [%p - %p][%s]\n", str2, ret2, str2);
	if (str2 != ret2 || strcmp(str1, str2) != 0)
	{
		printf("TEST 1: NOK\n");
		return (-1);
	}
	printf("TEST 1: OK\n");

	bzero(str1, size);
	bzero(str2, size);
	ret1 = memset(str1, '@', 0);
	printf("memset [%p - %p][%s]\n", str1, ret1, str1);
	ret2 = ft_memset(str2, '@', 0);
	printf("memset [%p - %p][%s]\n", str2, ret2, str2);
	if (str2 != ret2 || strcmp(str1, str2) != 0)
	{
		printf("TEST 2: NOK\n");
		return (-1);
	}
	printf("TEST 2: OK\n");

	free(str1);
	free(str2);
	return (1);
}

int	test_ft_puts()
{
	char *str = "coucou je suis moi !";
	int ret1 = 0;
	int ret2 = 0;

	ret1 = puts(str);
	// printf("ret puts   : %d\n", ret1);
	ret2 = ft_puts(str);
	// printf("ret ft_puts: %d\n", ret2);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("TEST 1: NOK\n");
		return (-1);
	}
	printf("TEST 1: OK\n");

	str = "";
	ret1 = puts(str);
	// printf("ret puts   : %d\n", ret1);
	ret2 = ft_puts(str);
	// printf("ret ft_puts: %d\n", ret2);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("TEST 2: NOK\n");
		return (-1);
	}
	printf("TEST 2: OK\n");

	str = NULL;
	ret1 = puts(str);
	// printf("ret puts   : %d\n", ret1);
	ret2 = ft_puts(str);
	// printf("ret ft_puts: %d\n", ret2);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("TEST 3: NOK\n");
		return (-1);
	}
	printf("TEST 3: OK\n");

	return (1);
}

int	test_ft_strlen()
{
	int		ret1 = 0;
	int		ret2 = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	if (ret1 != ret2)
	{
		printf("TEST 1: NOK\n");
		return (-1);
	}
	else
		printf("TEST 1: OK\n");
	str = "";
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	if (ret1 != ret2)
	{
		printf("TEST 2: NOK\n");
		return (-1);
	}
	else
		printf("TEST 2: OK\n");


	
	return (1);
}

int	test_ft_isprint()
{
	int		ret1 = 0;
	int		ret2 = 0;
	int		i = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";

	while (str[i] != '\0')
	{
		ret1 = isprint(str[i]);
		ret2 = ft_isprint(str[i]);
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

int	test_ft_isascii()
{
	int		ret1 = 0;
	int		ret2 = 0;
	int		i = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";

	while (str[i] != '\0')
	{
		ret1 = isascii(str[i]);
		ret2 = ft_isascii(str[i]);
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
	size_t	i = 0;
	
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
	size_t	i = 0;
	
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

	printf("\n\tFT_cat:\n");
	if (test_ft_cat() == -1)
		printf("cat : err\n");

	// printf("\n\tFT_strdup:\n");
	// if (test_ft_strdup() == -1)
	// 	printf("strdup : err\n");

	// printf("\n\tFT_memcpy:\n");
	// if (test_ft_memcpy() == -1)
	// 	printf("memcpy : err\n");

	// printf("\n\tFT_memset:\n");
	// if (test_ft_memset() == -1)
	// 	printf("memset : err\n");

	// printf("\n\tFT_puts:\n");
	// if (test_ft_puts() == -1)
	// 	printf("puts : err\n");

	// printf("\n\tFT_strlen:\n");
	// if (test_ft_strlen() == -1)
	// 	printf("strlen : err\n");

	// printf("\n\tFT_isprint:\n");
	// if (test_ft_isprint() == -1)
	// 	printf("isprint : err\n");

	// printf("\n\tFT_isascii:\n");
	// if (test_ft_isascii() == -1)
	// 	printf("isascii : err\n");

	// printf("\n\tFT_isalnum:\n");
	// if (test_ft_isalnum() == -1)
	// 	printf("isalnum : err\n");

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