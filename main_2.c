/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 13:30:51 by jealonso          #+#    #+#             */
/*   Updated: 2018/08/21 21:17:12 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#define	ALN	ft_isalnum
#define	ALP	ft_isalpha
#define UP	ft_isupper
#define LO	ft_islower
#define DI	ft_isdigit
#define STL	ft_strlen
#define PR	ft_isprint
#define PU	ft_puts
#define AS	ft_isascii
#define TOL	ft_tolower
#define	TOU	ft_toupper
#define BZ	ft_bzero
#define STC	ft_strcat

char	*ft_strcat(char *dest, const char *src);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
// int		ft_isupper(int c);
// int		ft_islower(int c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_isprint(int c);
int 	ft_puts(const char *s);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	ft_memset(char *s, char c, size_t n);
void	ft_memcpy(char *dest, char *src, size_t n);
char	*ft_strdup(char *str);
void	ft_cat(int fd);
// int		ft_strequ(char const *s1, char const *s2);
// int		ft_atoi(char *str);
// int		ft_strcmp(char *s1, char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
// void	*ft_memalloc(size_t size);

void	test_strcat()
{
	const char	str1[] = "pouet";
	char    	str2[20] = "sdfpdbite";
	const char	str3[] = "cacahouette";
	char		str4[12] = "";

	const char	str5[] = "pouet";
	char		str6[20] = "sdfpdbite";
	const char	str7[] = "cacahouette";
	char		str8[12] = "";

	STC(str2, str1);
	STC(str4, str3);
	printf("\n\t\t========  Test ft_strcat.s =======\n\n");
	printf("Ta fonction:\n\ttest1 => \"%s\" test2 => \"%s\"\n\n", str2, str4);
	strcat(str6, str5);
	strcat(str8, str7);
	printf("Valeur envoye: \n\ttest1 => \"%s\" test2 => \"%s\"\n\n", str6, str8);
}

void	test_alnum()
{
	printf("\n\t\t========  Test ft_isalnum.s =======\n\n");
	printf("Ta fonction:\n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n",
			ALN(49), ALN(108), ALN(19), ALN(65), ALN(90));
	printf("Valeur envoye: \n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n", isalnum(49), isalnum(108), isalnum(19), isalnum(65), isalnum(90));

}

void		test_alpha()
{
	printf("\n\t\t========  Test ft_ft_isalpha.s =======\n\n");
	printf("Ta fonction:\n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n",
			ALP(49), ALP(108), ALP(19), ALP(65), ALP(90));
	printf("Valeur envoye: \n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n", isalpha(49), isalpha(108), isalpha(19), isalpha(65), isalpha(90));
}

// void		test_upper()
// {
// 	printf("\n\t\t========  Test ft_isupper.s =======\n\n");
// 	printf("Ta fonction:\n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n",
// 			UP(49), UP(108), UP(19), UP(65), UP(90));
// 	printf("Valeur envoye: \n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n", isupper(49), isupper(108), isupper(19), isupper(65), isupper(90));
// }

// void		test_lower()
// {
// 	printf("\n\t\t========  Test ft_islower.s =======\n\n");
// 	printf("Ta fonction:\n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n",
// 			LO(49), LO(108), LO(19), LO(65), LO(90));
// 	printf("Valeur envoye: \n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n", islower(49), islower(108), islower(19), islower(65), islower(90));

// }

void		test_digit()
{
	printf("\n\t\t========  Test ft_isdigit.s =======\n\n");
	printf("Ta fonction:\n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n",
			DI(49), DI(108), DI(19), DI(65), DI(90));
	printf("Valeur envoye: \n\t1 =>(%d), l =>(%d), dc3 =>(%d), A =>(%d), Z =>(%d)\n\n", isdigit(49), isdigit(108), isdigit(19), isdigit(65), isdigit(90));

}

void		test_strlen()
{
	printf("\n\t\t========  Test ft_strlen.s =======\n\n");
	printf("Ta fonction:\n\t\"AbCdEfGhIjKlMnOpQrStUvWxYz\" =>(%d),\n",
			STL("AbCdEfGhIjKlMnOpQrStUvWxYz"));
	printf("\t\"plop\" =>(%d),\n",
			STL("plop"));
	printf("\t\"bof, bof se test\" =>(%d),\n",
			STL("bof, bof se test"));
	printf("\t\"Combien ca fait ca ?\" =>(%d),\n",
			STL("Combien ca fait ca?"));
	printf("\t\"Pouet\" =>(%d)\n\n",
			STL("pouet"));

	printf("Valeur envoye: \n\t\"AbCdEfGhIjKlMnOpQrStUvWxYz\" =>(%ld),\n\t\"plop\" =>(%ld),\n\t\"bof, bof se test\" =>(%ld),\n\t\"Combien ca fait ca?\" =>(%ld),\n\t\"Pouet\" =>(%ld)\n\n", strlen("AbCdEfGhIjKlMnOpQrStUvWxYz"), strlen("plop"), strlen("bof, bof se test"), strlen("Combien ca fait ca?"), strlen("Pouet"));

}

void		test_print()
{
	printf("\n\t\t========  Test ft_isprint.s =======\n\n");
	printf("Ta fonction:\n\tspace =>(%d), ~ =>(%d), 3 =>(%d), vt =>(%d), del =>(%d)\n\n",
			PR(10), PR(126), PR(51), PR(13), PR(127));
	printf("Valeur envoye: \n\tspace =>(%d), ~ =>(%d), 3 =>(%d), vt =>(%d), del =>(%d)\n\n", isprint(10),isprint(126), isprint(51), isprint(13), isprint(127));
}

void		test_puts()
{
	printf("\n\t\t========  Test ft_puts.s =======\n\n");
	printf("Valeur envoye: \n\t\"asd\"\n\t\(void)\n\t\"12345\"\n\t\"pouet\"\n\t\"couin\"\n\t\"couin\"\n\t\"hippopotomonstrosesquippedaliophobie\"\n\n");
	printf("Ta fonction:\n");
	write(1,"\t",1);
	PU("\"asd\"");
	write(1,"\t",1);
	PU("");
	write(1,"\t",1);
	PU("\"12345\"");
	write(1,"\t",1);
	PU("\"pouet\"");
	write(1,"\t",1);
	PU("\"couin\"");
	write(1,"\t",1);
	PU("\"couin\"");
	write(1,"\t",1);
	PU("\"hippopotomonstrosesquippedaliophobie\"");
	write(1,"\n",1);
}

void		test_ascii()
{
	printf("\n\t\t========  Test ft_isascii.s =======\n\n");
	printf("Ta fonction:\n\tspace =>(%d), ~ =>(%d), 3 =>(%d), vt =>(%d), del =>(%d), (-16) =>(%d), (1337) =>(%d)\n\n",
			AS(32), AS(126), AS(51), AS(13), AS(127), AS(-16), AS(1337));
	printf("Valeur envoye: \n\tspace =>(%d), ~ =>(%d), 3 =>(%d), vt =>(%d), del =>(%d), (-16) =>(%d), (1337) =>(%d)\n\n", isascii(32), isascii(126), isascii(51), isascii(13), isascii(127), isascii(-16), isascii(1337));
}

void		test_tolower()
{
	printf("\n\t\t========  Test ft_tolower.s =======\n\n");
	printf("Ta fonction:\n\t46 =>(%c), 108 =>(%c), 19 =>(%c), 82 =>(%c), 90 =>(%c)\n\n",
			TOL(46), TOL(108), TOL(19), TOL(82), TOL(90));
	printf("Valeur envoye: \n\t46 =>(%c), 108 =>(%c), 19 =>(%c), 82 =>(%c), 90 =>(%c)\n\n", tolower(46), tolower(108), tolower(19), tolower(82), tolower(90));
}

void		test_toupper()
{
	printf("\n\t\t========  Test ft_toupper.s =======\n\n");
	printf("Ta fonction:\n\t49 =>(%c), 108 =>(%c), 19 =>(%c), 82 =>(%c), 122 =>(%c)\n\n",
			TOU(49), TOU(108), TOU(19), TOU(82), TOU(122));
	printf("Valeur envoye: \n\t49 =>(%c), 108 =>(%c), 19 =>(%c), 82 =>(%c), 122 =>(%c)\n\n", toupper(49), toupper(108), toupper(19), toupper(82), toupper(122));
}

void		test_bzero()
{
	char	str1[] = "asd";
	char	str2[] = "";
	char	str3[] = "12345";
	char	str4[] = "pouet";
	char	str5[] = "couin";
	char	str6[] = "couin";
	char	str7[] = "hippopotomonstrosesquippedaliophobie";
	int		i = 0;
	int 	k = strlen(str7);

	printf("\n\t\t========  Test ft_bzero.s =======\n\n");
	printf("Valeur envoye: \n\t\"asd\"(1) =>sd\n\t\(void) (0)=>\n\t\"12345\" (3)=>45\n\t\"pouet\" (2)=>uet\n\t\"couin\"(3) =>in\n\t\"couin\" (5) => \n\t\"hippopotomonstrosesquippedaliophobie\" => potomonstrosesquippedaliophobie\n\n");

	printf("Ta fonction:\n");

	write(1,"\t", 1);
	BZ(str1, 1);
	while(i++ < 3)
		write(1, &str1[i], 1);

	i = 0;
	write(1,"\n\t", 2);
	BZ(str2, 0);
	while(i++ < 0)
		write(1, &str2[i], 1);

	i = 0;
	write(1,"\n\t", 2);
	BZ(str3, 3);
	while(i++ < 5)
		write(1, &str3[i], 1);

	i = 0;
	write(1,"\n\t", 2);
	BZ(str4, 2);
	while(i++ < 5)
		write(1, &str4[i], 1);

	i = 0;
	write(1,"\n\t", 2);
	BZ(str5, 3);
	while(i++ < 5)
		write(1, &str5[i], 1);

	i = 0;
	write(1,"\n\t", 2);
	BZ(str6, 5);
	while(i++ < 5)
		write(1, &str6[i], 1);

	i = 0;
	BZ(str7, 5);
	write(1,"\n\t", 2);
	while(i++ < k)
		write(1, &str7[i], 1);

	write(1,"\n", 1);
}

static void test_ft_memset_sub(char *s1, char *s2, char c, size_t len)
{
	ft_memset(s1, c, len);
	memset(s2, c, len);
	s1[19] = '\0';
	s2[19] = '\0';
	printf("c: %c, len = %lu -> [%s] ([%s])\n", c, len, s1, s2);
}

void    test_memset()
{
	char    s1[20];
	char    s2[20];

	printf("\n\t\t========  Test ft_memset.s =======\n\n");
	test_ft_memset_sub(s1, s2, '\0', 19);
	test_ft_memset_sub(s1, s2, 'c', 3);
	test_ft_memset_sub(s1, s2, 'd', 19);
	test_ft_memset_sub(s1, s2, 'e', 7);
	return ;
}

static void test_ft_memcpy_sub(char *s1, char *s2, char *s3, size_t len)
{
	printf("[%s] {%s} -> ", s1, s3);
	ft_memcpy(s1, s3, len);
	printf("[%s]\n", s1);
	printf("[%s] {%s} -> ", s2, s3);
	ft_memcpy(s2, s3, len);
	printf("[%s]\n", s2);
}

void    test_memcpy()
{
	char	s1[20] = "cacaquipue";
	char	s2[20] = "cacaquipue";

	printf("\n\t\t========  Test ft_memcpy.s =======\n\n");
	test_ft_memcpy_sub(s1, s2, "abcdefghijklmnopqrs", 20);
	test_ft_memcpy_sub(s1, s2, "                   ", 20);
	test_ft_memcpy_sub(s1, s2, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20);
	return ;
}

static void	test_ft_strdup_sub(char *str, char *s1, char *s2)
{
	s1 = NULL;
	s1 = ft_strdup(str);
	s2 = strdup(str);
	printf("[%s] -> [%s] ([%s])\n", str, s1, s2);
	if (s1)
		free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
}

void	test_strdup()
{
	char	str[30] = {"Zaz aime les poneys."};
	char	*s1 = NULL;
	char	*s2 = NULL;

	printf("\n\t\t========  Test ft_strdup.s =======\n\n");
	test_ft_strdup_sub(str, s1, s2);
	strcpy(str, "toto");
	test_ft_strdup_sub(str, s1, s2);
//	strcpy(str, "");
	test_ft_strdup_sub(str, s1, s2);
	return ;
}

#include <fcntl.h>

void	test_cat(void)
{
	int		fd;

	printf("\n\t\t========  Test ft_cat.s =======\n\n");
	fd = open(__FILE__, O_RDONLY);
	if (fd > 0)
	{
		ft_cat(fd);
		close(fd);
	}
	fd = open(".", O_RDONLY);
	if (fd > 0)
	{
		ft_cat(fd);
		close(fd);
	}
	ft_cat(-1);
	ft_cat(6);
//		ft_cat(0);
	return ;
}

// void	test_strequ(void)
// {
// 	char	str[] = "pouet";
// 	char	str1[] = "pouet";
// 	char	str2[] = "marche pas";

// 	printf("\n\t\t========  Test ft_strequ.s =======\n\n");
// 	printf("\t\"pouet/pouet\"     => %d\n",ft_strequ(str,str1));
// 	printf("\t\"pouet/marche pas\" => %d\n",ft_strequ(str,str2));
// }

// void	test_atoi()
// {
// 	char	str1[] = "-27";
// 	char	str2[] = "+27	";
// 	char	str3[] = "	15673433367822684";
// 	char	str4[] = "-L27";

// 	printf("\n\t\t========  Test ft_atoi.s =======\n\n");
// 	printf("\t atoi(%s) => (%d)\n", str1, atoi(str1));
// 	printf("\t ft_ato(%s) => (%d)\n", str1, ft_atoi(str1));
// 	printf("\t atoi(%s) => (%d)\n", str2, atoi(str2));
// 	printf("\t ft_ato(%s) => (%d)\n", str2, ft_atoi(str2));
// 	printf("\t atoi(%s) => (%d)\n", str3, atoi(str3));
// 	printf("\t ft_atoi(%s) => (%d)\n", str3, ft_atoi(str3));
// 	printf("\t atoi(%s) => (%d)\n", str4, atoi(str4));
// 	printf("\t ft_ato(%s) => (%d)\n", str4, ft_atoi(str4));

// }

// void	test_strcmp()
// {
// 	char	str1[] = "pouet";
// 	char	str2[] = "lol";

// 	printf("\n\t\t========  Test ft_strcmp.s =======\n\n");
// 	printf("\t %s/%s => %d\n",str1, str2, ft_strcmp(str1,str2));
// 	printf("\t %s/%s => %d\n",str2, str1, ft_strcmp(str2,str1));
// 	printf("\t %s/%s => %d\n",str1, str1, ft_strcmp(str1,str1));
// }

// void	test_memalloc()
// {

// 	char	*str = ft_memalloc(8);
// 	char	*str1 = ft_memalloc(0);

// 	printf("\n\t\t========  Test ft_memalloc.s =======\n\n");
// 	printf("\t str[8] %d\n", ft_strlen(str));
// 	printf("\t str[NULL] %d\n", ft_strlen(str1));
// }

void	test_memchr()
{
	char	str1[] = "pouet";

	printf("\n\t\t========  Test ft_memchr.s =======\n\n");
	printf("\t %s/o/4 => %s\n", str1,memchr(str1, 'o', 4));
	printf("\t %s/p/18 => %s\n", str1,memchr(str1, 'p', 18));
	printf("\t %s/l/4 => %s\n\n", str1,memchr(str1, 108, 4));

	printf("\t %s/o/4 => %s\n", str1,ft_memchr(str1, 'o', 4));
	printf("\t %s/p/18 => %s\n", str1,ft_memchr(str1, 'p', 18));
	printf("\t %s/p/4 => %s\n", str1,ft_memchr(str1, 108, 4));
}

int		main()
{
	test_print();
	test_strcat();
	test_alnum();
	test_alpha();
	test_ascii();
	test_digit();
	test_strlen();
	test_puts();
	test_tolower();
	test_toupper();
	test_bzero();
	test_memset();
	test_memcpy();
	test_strdup();
	test_memchr();


	// test_upper();
	// test_lower();
	// test_strequ();
	// test_atoi();
	// test_strcmp();
	// test_memalloc();
//	test_cat();
	return (0);
}
