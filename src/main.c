/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:32:39 by galy              #+#    #+#             */
/*   Updated: 2018/06/07 17:21:27 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"

int test_ft_memchr()
{
	char	*str;
	size_t	size;
	void	*ret1;
	void	*ret2;


	str = "Non! Rien de rien, Non! Je ne regrette rien, Ni le bien qu'on m'a fait, Ni le mal tout ca m'est bien egal! +";
	size = ft_strlen(str);
	
	ret1 = memchr(str, 'd', size);
	ret2 = ft_memchr(str, 'd', size);
	printf("str[%p] ->[%p][%p]\n", str, ret1, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 1: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 1: OK\033[0m\n");

	ret1 = memchr(str, 0, size);
	ret2 = ft_memchr(str, 0, size);
	printf("str[%p] ->[%p][%p]\n", str, ret1, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 2: OK\033[0m\n");

	ret1 = memchr(str, '+', size);
	ret2 = ft_memchr(str, '+', size);
	printf("str[%p] ->[%p][%p]\n", str, ret1, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 3: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 3: OK\033[0m\n");

	/*
	**	EMPTY STRING
	*/
	str = "";
	
	ret1 = memchr(str, 'd', size);
	ret2 = ft_memchr(str, 'd', size);
	printf("->[%p][%p][%d]\n", ret1, ret2, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 4: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 4: OK\033[0m\n");

	ret1 = memchr(str, 0, size);
	ret2 = ft_memchr(str, 0, size);
	printf("str[%p] ->[%p][%p]\n", str, ret1, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 5: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 5: OK\033[0m\n");
	
	ret1 = memchr(str, '0', 0);
	ret2 = ft_memchr(str, '0', 0);
	printf("str[%p] ->[%p][%p]\n", str, ret1, ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 6: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 6: OK\033[0m\n");

	/*
	**	SEGFAULT
	** str = NULL;
	** ret1 = memchr(str, 0, size);
	** ret2 = ft_memchr(str, 0, size);
	*/

	return (1);
}

int test_ft_putstr_fd()
{
	int fd;
	char *str = "truc";
	
	// Test fd = std out
	str = "\nft_putstr_fd sur stdout (if you see me it's ok)\n\n";
	ft_putstr_fd(str, 1);

	//test fd -> in a filemake fc
	str = "Direct dans un fichier... WAOUU!";
	fd = open("putstr_fd_test", O_CREAT | O_RDWR | O_NONBLOCK, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		printf("Attention fd = %d\n", fd);
		return (-1);
	}
	printf("fd = %d -> writing in \"putstr_fd_test\"\n", fd);
	ft_putstr_fd(str, fd);
	close(fd);
	return (1);
}

int	test_ft_cat()
{
// 	int		fd;
// 	char	*path1;
// 	char	*path2;
// 	char	*path3;
	
// 	path2 = "inc/libfts.h";
// 	path3 = "Makefile";
	
// 	fd = open(path2, O_RDONLY | O_NONBLOCK);
// 	if (fd < 0)
// 		printf("Attention fd = %d\n", fd);
// 	ft_cat(fd);
// 	close(fd);
	
// 	fd = open(path3, O_RDONLY | O_NONBLOCK);
// 	if (fd < 0)
// 		printf("Attention fd = %d\n", fd);
// 	ft_cat(fd);
// 	close(fd);

// 	// printf("\nFT_CAT END\n");
	return (1);
}

int	test_ft_strdup()
{
	char	*base = "Le mot aviation";
	char	*str1 = NULL;
	char	*str2 = NULL;

	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("BASE		[%p][%s]\n", base, base);
		printf("strdup		[%p][%s]\n", str1, str1);
		printf("ft_strdup	[%p][%s]\n", str2, str2);
		printf("\033[31mTEST 1: NOK\033[0m\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("\033[32mTEST 1: OK\033[0m\n");

	base = "Le mot « aviation » (du latin « avis », qui signifie « oiseau »2, et du suffixe « atio ») a été employé pour la première fois par Gabriel de La Landelle, en 1863,\ndans le livre Aviation ou navigation aérienne sans ballon, un ouvrage rendant compte des tentatives d'envol de Jean-Marie Le Bris dans un appareil plus lourd que l'air.";
	str1 = NULL;
	str2 = NULL;
	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("strdup     [%p][%s]\n", str1, str1);
		printf("strdup     [%p][%d]\n", str2, str2);
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("\033[32mTEST 2: OK\033[0m\n");

	base = "";
	str1 = strdup(base);
	str2 = ft_strdup(base);
	if (strcmp(str1, str2) != 0)
	{
		printf("strdup     [%p][%s]\n", str1, str1);
		printf("strdup     [%p][%s]\n", str2, str2);
		printf("\033[31mTEST 3: NOK\033[0m\n");
		return (-1);
	}
	free(str1);
	free(str2);
	printf("\033[32mTEST 3: OK\033[0m\n");

	// // CRASH TEST
	// base = NULL;
	// str1 = strdup(base);
	// str2 = ft_strdup(base);

	return (1);
}

int	test_ft_memcpy()
{
	size_t	size = 200;
	char	*base = "Le loup gris est l'un des animaux les plus connus et les plus étudiés au monde, avec probablement plus de livres écrits à son sujet que toute autre espèce sauvage3.";
	char	*str1;
	char	*str2;
	char	*ret1;

	str1 = (char*)malloc(size);
	str2 = (char*)malloc(size);
	bzero(str1, size);
	bzero(str2, size);
	ret1 = NULL;
	ret1 = (char*)memcpy(str1, base, strlen(base));
	printf("memcpy    [%p - %p][%s]\n", str1, ret1, str1);

	ret1 = NULL;
	ret1 = (char*)ft_memcpy(str2, base, strlen(base));
	printf("ft_memcpy [%p - %p][%s]\n", str2, ret1, str2);
	if (strcmp(str1, str2) != 0)
	{
		printf("\033[31mTEST 1: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 1: OK\033[0m\n\n");

	/*
	**	EMPTY STRING
	*/
	char	*base2 = "";
	bzero(str1, size);
	bzero(str2, size);
	ret1 = (char*)memcpy(str1, base2, 0);
	printf("memcpy    [%p - %p][%s]\n", str1, ret1, str1);

	ret1 = (char*)ft_memcpy(str2, base2, 0);
	printf("ft_memcpy [%p - %p][%s]\n", str2, ret1, str2);
	if (strcmp(str1, str2) != 0)
	{
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 2: OK\033[0m\n");
	free(str1);
	free(str2);
	return (1);
}

int	test_ft_memset()
{
	size_t	size = 80;
	char	*str1;
	char	*ret1;
	char	*str2;
	char	*ret2;

	str1 = (char*)malloc(size);
	bzero(str1, size);
	str2 = (char*)malloc(size);
	bzero(str2, size);

	ret1 = (char*)memset(str1, '$', 12);
	printf("memset [%p - %p][%s]\n", str1, ret1, str1);
	ret2 = (char*)ft_memset(str2, '$', 12);
	printf("memset [%p - %p][%s]\n", str2, ret2, str2);
	if (str2 != ret2 || strcmp(str1, str2) != 0)
	{
		printf("\033[31mTEST 1: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 1: OK\033[0m\n");

	bzero(str1, size);
	bzero(str2, size);
	ret1 = (char*)memset(str1, '@', 0);
	printf("memset [%p - %p][%s]\n", str1, ret1, str1);
	ret2 = (char*)ft_memset(str2, '@', 0);
	printf("memset [%p - %p][%s]\n", str2, ret2, str2);
	if (str2 != ret2 || strcmp(str1, str2) != 0)
	{
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 2: OK\033[0m\n");

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
	ret2 = ft_puts(str);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("\033[31mTEST 1: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 1: OK\033[0m\n");

	str = "";
	ret1 = puts(str);
	ret2 = ft_puts(str);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 2: OK\033[0m\n");

	str = NULL;
	ret1 = puts(str);
	ret2 = ft_puts(str);
	if (ret1 > 0 && ret2 <= 0)
	{
		printf("\033[31mTEST 3: NOK\033[0m\n");
		return (-1);
	}
	printf("\033[32mTEST 3: OK\033[0m\n");

	return (1);
}

int	test_ft_strlen()
{
	int		ret1 = 0;
	int		ret2 = 0;
	char	*str = "8c1eIUGF6b57cad4F 4a6ca18cc08*UI6dfa;'c72d";
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("ret ft [%d]\n", ret1);
	printf("ret    [%d]\n", ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 1: NOK\033[0m\n");
		printf("ret ft [%d]\n", ret1);
		printf("ret    [%d]\n", ret2);
		return (-1);
	}
	else
		printf("\033[32mTEST 1: OK\033[0m\n");
	str = "";
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("ret ft [%d]\n", ret1);
	printf("ret    [%d]\n", ret2);
	if (ret1 != ret2)
	{
		printf("\033[31mTEST 2: NOK\033[0m\n");
		return (-1);
	}
	else
		printf("\033[32mTEST 2: OK\033[0m\n");


	
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
	printf("\033[32mTEST 1: OK\033[0m\n");
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
	printf("\033[32mTEST 1: OK\033[0m\n");
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
	printf("\033[32mTEST 1: OK\033[0m\n");
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
	printf("\033[32mTEST 1: OK\033[0m\n");
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
	printf("\033[32mTEST 1: OK\033[0m\n");
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
		printf("\033[32mTEST 1: OK\033[0m\n");
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
		printf("\033[32mTEST 1: OK\033[0m\n");
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
		printf("\033[32mTEST 1: OK\033[0m\n");
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
		printf("\033[32mTEST 2: OK\033[0m\n");
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
		printf("\033[32mTEST 1: OK\033[0m\n");
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
		printf("\033[32mTEST 2: OK\033[0m\n");
	return (1);
}

int	main()
{
	printf("\n\tFT_memchr:\n");
	if (test_ft_memchr() == -1)
		printf("memchr : err\n");

		printf("\n\tFT_putstr_fd:\n");
	if (test_ft_putstr_fd() == -1)
		printf("putstr_fd : err\n");

	printf("\n\tFT_cat:\n");
	if (test_ft_cat() == -1)
		printf("cat : err\n");

	printf("\n\tFT_strdup:\n");
	if (test_ft_strdup() == -1)
		printf("strdup : err\n");

	printf("\n\tFT_memcpy:\n");
	if (test_ft_memcpy() == -1)
		printf("memcpy : err\n");

	printf("\n\tFT_memset:\n");
	if (test_ft_memset() == -1)
		printf("memset : err\n");

	printf("\n\tFT_puts:\n");
	if (test_ft_puts() == -1)
		printf("puts : err\n");

	printf("\n\tFT_strlen:\n");
	if (test_ft_strlen() == -1)
		printf("strlen : err\n");

	printf("\n\tFT_isprint:\n");
	if (test_ft_isprint() == -1)
		printf("isprint : err\n");

	printf("\n\tFT_isascii:\n");
	if (test_ft_isascii() == -1)
		printf("isascii : err\n");

	printf("\n\tFT_isalnum:\n");
	if (test_ft_isalnum() == -1)
		printf("isalnum : err\n");

	printf("\n\tFT_isdigit:\n");
	if (test_ft_isdigit() == -1)
		printf("isdigit : err\n");

	printf("\n\tFT_isalpha:\n");
	if (test_ft_isalpha() == -1)
		printf("isalpha : err\n");

	printf("\n\tFT_strcat:\n");
	if (test_ft_strcat() == -1)
		printf("strcat : err\n");
	
	printf("\n\tFT_bzero:\n");
	if (test_ft_bzero() == -1)
		printf("bzero : err\n");

	printf("\n\tFT_TOLOWER:\n");
	if (test_ft_tolower() == -1)
		printf("tolower : err\n");

	printf("\n\tFT_TOUPPER:\n\n");
	if (test_ft_toupper() == -1)
		printf("toupper : err\n");
	
	printf("\nEND\n");
	return (0);
}

/*
** int main(int ac, const char **av)
** {
** 	printf("Test00\n");
** 	ft_cat(0);
** 	printf("Test00 end\n");
**	
** 	printf("Test01 file:[%s]\n", __FILE__);
** 	ft_cat(open(__FILE__, O_RDONLY));
** 	printf("Test01 end\n");
**	
** 	printf("Test02 file:[%s]\n", av[0]);
** 	ft_cat(open(av[0], O_RDONLY));
** 	printf("Test02 end\n");
**	
** 	printf("Test03\n");
** 	ft_cat(-42);
** 	printf("Test03 end\n");
**	
** 	printf("Test04\n");
** 	(void)ac;
** 	printf("Test04 end\n");
**
** 	return (0);
** }
*/