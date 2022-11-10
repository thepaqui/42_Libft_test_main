/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:05 by thepaqui          #+#    #+#             */
/*   Updated: 2022/11/10 18:52:21 by thepaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

//error codes
#define NB_ERR 4
#define NOARG 0
#define EXTRARG 1
#define MALLOCFAIL 2
#define WRONG_FD 3

//text style
#define REGULAR 0
#define BOLD 1
#define GRAY 29
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define PURPLE 35
#define CYAN 36
#define WHITE 37
#define SET_STYLE(eff,col) printf("\033[%d;%dm", eff, col)
#define RESET_STYLE SET_STYLE(REGULAR, GRAY)

//checks
#define OK 0
#define KO 1
#define NB_TESTS 34

//ascii and strlen 6
#define ISALPHA ft_check_isalpha
#define ISDIGIT ft_check_isdigit
#define ISALNUM ft_check_isalnum
#define ISASCII ft_check_isascii
#define ISPRINT ft_check_isprint
#define STRLEN ft_check_strlen

//str and mem basic fts 8
#define MEMSET ft_check_memset
#define BZERO ft_check_bzero
#define MEMCPY ft_check_memcpy
#define MEMMOV ft_check_memmove
#define STRLCPY ft_check_strlcpy
#define STRLCAT ft_check_strlcat
#define CALLOC placeholder
#define STRDUP placeholder

//char case 2
#define TOUPPER ft_check_toupper
#define TOLOWER ft_check_tolower

//str and mem search and comp 6
#define STRCHR ft_check_strchr
#define STRRCHR ft_check_strrchr
#define STRNCMP ft_check_strncmp
#define MEMCHR ft_check_memchr
#define MEMCMP ft_check_memcmp
#define STRNSTR ft_check_strnstr

//str and int manipulation 2
#define ATOI ft_check_atoi
#define ITOA placeholder

//str manipulation 6
#define SUBSTR placeholder
#define STRJOIN placeholder
#define STRTRIM placeholder
#define SPLIT placeholder
#define STRMAPI placeholder
#define STRITERI placeholder

//text display 4
#define PUTCHAR_FD ft_check_putchar_fd
#define PUTSTR_FD ft_check_putstr_fd
#define PUTENDL_FD ft_check_putendl_fd
#define PUTNBR_FD ft_check_putnbr_fd

//list basic fts

int	placeholder(void)
{
	SET_STYLE(BOLD, WHITE);
	printf("This is a placeholder! :P\n");
	return (OK);
}

int	ft_print_error(int code)
{
	char	*err_msgs[NB_ERR];

	err_msgs[NOARG] = "No argument";
	err_msgs[EXTRARG] = "Too many arguments";
	err_msgs[MALLOCFAIL] = "Memory allocation failed";
	err_msgs[WRONG_FD] = "Wrong file descriptor";
	SET_STYLE(BOLD, RED);
	printf("ERROR: %s.\n", err_msgs[code]);
	RESET_STYLE;
	return (code + 1);
}

void	ft_leaks_check(void)
{
	RESET_STYLE;
	printf("\n");
	system("leaks a.out | grep leaks");
}

int	ft_check_isalpha(void)
{
	char	t[8];
	int		i;
	int		err;

	t[0] = 'A';
	t[1] = 'Z';
	t[2] = 'a';
	t[3] = 'z';
	t[4] = '@';
	t[5] = '[';
	t[6] = '`';
	t[7] = '{';
	i = 0;
	err = 0;
	while (i < 4)
	{
		if (ft_isalpha(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is a letter.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is not a letter.\n", t[i]);
			err++;
		}
		i++;
	}
	while (i < 8)
	{
		if (!ft_isalpha(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is not a letter.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is a letter.\n", t[i]);
			err++;
		}
		i++;
	}
	return (err);
}

int	ft_check_isdigit(void)
{
	char	t[4];
	int		i;
	int		err;

	t[0] = '0';
	t[1] = '9';
	t[2] = '/';
	t[3] = ':';
	i = 0;
	err = 0;
	while (i < 2)
	{
		if (ft_isdigit(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is a number.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is not a number.\n", t[i]);
			err++;
		}
		i++;
	}
	while (i < 4)
	{
		if (!ft_isdigit(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is not a number.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is a number.\n", t[i]);
			err++;
		}
		i++;
	}
	return (err);
}

int	ft_check_isalnum(void)
{
	char	t[12];
	int		i;
	int		err;

	t[0] = 'A';
	t[1] = 'Z';
	t[2] = 'a';
	t[3] = 'z';
	t[4] = '@';
	t[5] = '[';
	t[6] = '`';
	t[7] = '{';
	t[8] = '0';
	t[9] = '9';
	t[10] = '/';
	t[11] = ':';
	i = 0;
	err = 0;
	while (i < 4)
	{
		if (ft_isalnum(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is alphanumeric.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is not alphanumeric.\n", t[i]);
			err++;
		}
		i++;
	}
	while (i < 8)
	{
		if (!ft_isalnum(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is not alphanumeric.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is alphanumeric.\n", t[i]);
			err++;
		}
		i++;
	}
	while (i < 10)
	{
		if (ft_isalnum(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is alphanumeric.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is not alphanumeric.\n", t[i]);
			err++;
		}
		i++;
	}
	while (i < 12)
	{
		if (!ft_isalnum(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' is not alphanumeric.\n", t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' is alphanumeric.\n", t[i]);
			err++;
		}
		i++;
	}
	return (err);
}

int	ft_check_isascii(void)
{
	char	t[5];
	int		i;
	int		err;

	t[0] = 0;
	t[1] = 51;
	t[2] = 127;
	t[3] = -1;
	t[4] = -128;
	i = 0;
	err = 0;
	while (i < 3)
	{
		if (ft_isascii(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' (%d) is on the ASCII table.\n", t[i], t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' (%d) is not on the ASCII table.\n", t[i], t[i]);
			err++;
		}
		i++;
	}
	while (i < 5)
	{
		if (!ft_isascii(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' (%d) is not on the ASCII table.\n", t[i], t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' (%d) is on the ASCII table.\n", t[i], t[i]);
			err++;
		}
		i++;
	}
	return (err);
}

int	ft_check_isprint(void)
{
	char	t[8];
	int		i;
	int		err;

	t[0] = ' ';
	t[1] = '~';
	t[2] = '\\';
	t[3] = '|';
	t[4] = 31;
	t[5] = 127;
	t[6] = '	';
	t[7] = -1;
	i = 0;
	err = 0;
	while (i < 4)
	{
		if (ft_isprint(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' (%d) is printable.\n", t[i], t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' (%d) is not printable.\n", t[i], t[i]);
			err++;
		}
		i++;
	}
	while (i < 8)
	{
		if (!ft_isprint(t[i]))
		{
			SET_STYLE(REGULAR, GREEN);
			printf("\'%c\' (%d) is not printable.\n", t[i], t[i]);
		}
		else
		{
			SET_STYLE(REGULAR, RED);
			printf("\'%c\' (%d) is printable.\n", t[i], t[i]);
			err++;
		}
		i++;
	}
	return (err);
}

int	ft_check_strlen(void)
{
	char		str1[1] = "";
	char		str2[2] = " ";
	char		str3[8] = "salut !";
	char		str4[43] = "0123456789`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
	size_t		res;
	int			err;

	err = 0;
	res = ft_strlen(str1);
	if (res == 0)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %zu.\n", str1, res);
	res = ft_strlen(str2);
	if (res == 1)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %zu.\n", str2, res);
	res = ft_strlen(str3);
	if (res == 7)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %zu.\n", str3, res);
	res = ft_strlen(str4);
	if (res == 42)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %zu.\n", str4, res);
	RESET_STYLE;
	return (err);
}

#define MEMSET_STR "1234"
#define MEMSET_BYTES 2
#define MEMSET_OFFSET 1
#define MEMSET_CHAR 'Q'
int	ft_check_memset(void)
{
	char	*str1;
	char	*str2;

	str1 = strdup(MEMSET_STR);
	str2 = strdup(MEMSET_STR);
	if (!str1 || !str2)
		return (ft_print_error(MALLOCFAIL));
	SET_STYLE(REGULAR, CYAN);
	printf("str1: \"%s\"\t\tstr2: \"%s\"\n", str1, str2);
	SET_STYLE(REGULAR, CYAN);
	printf("ft_memset(str1)\t\tmemset(str2)\n");
	ft_memset(str1 + MEMSET_OFFSET, MEMSET_CHAR, MEMSET_BYTES * sizeof(*str1));
	memset(str2 + MEMSET_OFFSET, MEMSET_CHAR, MEMSET_BYTES * sizeof(*str2));
	SET_STYLE(REGULAR, GREEN);
	printf("str1: \"%s\"\t\t", str1);
	printf("str2: \"%s\"\n", str2);
	free(str1);
	free(str2);
	ft_leaks_check();
	return (OK);
}

#define BZERO_STR "12345678"
#define BZERO_BYTES 1
#define BZERO_OFFSET 5
int	ft_check_bzero(void)
{
	char	*str1;
	char	*str2;

	str1 = strdup(BZERO_STR);
	str2 = strdup(BZERO_STR);
	if (!str1 || !str2)
		return (ft_print_error(MALLOCFAIL));
	SET_STYLE(REGULAR, CYAN);
	printf("str1: \"%s\"\tstr2: \"%s\"\n", str1, str2);
	SET_STYLE(REGULAR, CYAN);
	printf("ft_bzero(str1)\t\tbzero(str2)\n");
	SET_STYLE(REGULAR, GREEN);
	ft_bzero(str1 + BZERO_OFFSET, BZERO_BYTES * sizeof(*str1));
	printf("str1: \"%s\"\t\t", str1);
	bzero(str2 + BZERO_OFFSET, BZERO_BYTES * sizeof(*str2));
	printf("str2: \"%s\"\n", str2);
	free(str1);
	free(str2);
	ft_leaks_check();
	return (OK);
}

#define MEMCPY_STR "CECI.EST.UN.TEST.!!"
#define MEMCPY_STRLEN strlen(MEMCPY_STR) + 1
#define MEMCPY_BYTES 20
int	ft_check_memcpy(void)
{
	char	*src;
	char	*src2;
	char	*dst;
	char	*dst2;

	src = strdup(MEMCPY_STR);
	dst = malloc(sizeof(*dst) * MEMCPY_STRLEN);
	if (!src || !dst)
		return (ft_print_error(MALLOCFAIL));
	memcpy(dst, src, MEMCPY_BYTES);
	SET_STYLE(REGULAR, CYAN);
	printf("MEMCPY\n\n");
	SET_STYLE(REGULAR, GREEN);
	printf("src is \"%s\"\ndst is \"%s\"\n\n", src, dst);
	free(src);
	free(dst);
	src2 = strdup(MEMCPY_STR);
	dst2 = malloc(sizeof(*dst2) * MEMCPY_STRLEN);
	if (!src2 || !dst2)
		return (ft_print_error(MALLOCFAIL));
	ft_memcpy(dst2, src2, MEMCPY_BYTES);
	SET_STYLE(REGULAR, CYAN);
	printf("FT_MEMCPY\n\n");
	SET_STYLE(REGULAR, GREEN);
	printf("src2 is \"%s\"\ndst2 is \"%s\"\n", src2, dst2);
	free(src2);
	free(dst2);
	ft_leaks_check();
	return (OK);
}

#define MEMMOV_STR "Bonjour, c'est moi, le TEST. >:]"
#define MEMMOV_STRLEN strlen(MEMMOV_STR) + 1
#define MEMMOV_BYTES 15
#define MEMMOV_OFFSET 5
int	ft_check_memmove(void)
{
	char	*src;
	char	*src2;
	char	*dst;
	char	*dst2;

	src = strdup(MEMMOV_STR);
	dst = src + MEMMOV_OFFSET;
	if (!src || !dst)
		return (ft_print_error(MALLOCFAIL));
	SET_STYLE(REGULAR, CYAN);
	printf("MEMMOV\n\n");
	printf("src is\t\"%s\"\n", src);
	memmove(dst, src, MEMMOV_BYTES);
	SET_STYLE(REGULAR, GREEN);
	printf("dst is\t\"%s\"\n\n", dst);
	free(src);
	src2 = strdup(MEMMOV_STR);
	dst2 = src2 + MEMMOV_OFFSET;
	if (!src2 || !dst2)
		return (ft_print_error(MALLOCFAIL));
	SET_STYLE(REGULAR, CYAN);
	printf("FT_MEMMOV\n\n");
	printf("src2 is\t\"%s\"\n", src2);
	ft_memmove(dst2, src2, MEMMOV_BYTES);
	SET_STYLE(REGULAR, GREEN);
	printf("dst2 is\t\"%s\"\n", dst2);
	free(src2);
	ft_leaks_check();
	return (OK);
}

#define STRLCPY_SRC "abcde"
#define STRLCPY_SRC_LEN strlen(STRLCPY_SRC) + 1
#define STRLCPY_DST "OOOOOOOOO"
#define STRLCPY_DST_LEN 10
#define STRLCPY_BYTES 7
int	ft_check_strlcpy(void)
{
	const char	src[STRLCPY_SRC_LEN] = STRLCPY_SRC;
	char		dest1[STRLCPY_DST_LEN] = STRLCPY_DST;
	char		dest2[STRLCPY_DST_LEN] = STRLCPY_DST;
	size_t		should;
	size_t		is;

	should = strlcpy(dest1, src, STRLCPY_BYTES);
	is = ft_strlcpy(dest2, src, STRLCPY_BYTES);
	SET_STYLE(REGULAR, CYAN);
	printf("strlcpy :\t\t\"%s\"\n", dest1);
	printf("strlcpy returns :	%zu\n\n", should);
	SET_STYLE(REGULAR, GREEN);
	printf("ft_strlcpy :\t\t\"%s\"\n", dest2);
	printf("ft_strlcpy returns :	%zu\n", is);
	return (OK);
}

#define STRLCAT_SRC "123456789"
#define STRLCAT_SRC_LEN strlen(STRLCAT_SRC) + 1
#define STRLCAT_DST "src = "
#define STRLCAT_DST_LEN 20
#define STRLCAT_BYTES 13
int	ft_check_strlcat(void)
{
	char	src[STRLCAT_SRC_LEN] = STRLCAT_SRC;
	char	dest1[STRLCAT_DST_LEN] = STRLCAT_DST;
	char	dest2[STRLCAT_DST_LEN] = STRLCAT_DST;

	SET_STYLE(REGULAR, CYAN);
	printf("src is :\t\"%s\"\n", src);
	printf("dest is :\t\"%s\"\n\n", dest1);
	SET_STYLE(REGULAR, GREEN);
	printf("strlcat returns :\t%zu\t\"%s\"\n", strlcat(dest1, src, STRLCAT_BYTES), dest1);
	printf("ft_strlcat returns :\t%zu\t\"%s\"\n", ft_strlcat(dest2, src, STRLCAT_BYTES), dest2);
	return (OK);
}

#define TOUPPER_STR "Ceci`est@un[PUTAIN{de.TeST!"
#define TOUPPER_STRLEN strlen(TOUPPER_STR) + 1
int	ft_check_toupper(void)
{
	char	str[TOUPPER_STRLEN] = TOUPPER_STR;
	int		i;

	SET_STYLE(REGULAR, CYAN);
	printf("\"%s\"\n\n\tbecame\n\n", str);
	i = -1;
	while (++i < TOUPPER_STRLEN - 1)
		str[i] = ft_toupper(str[i]);
	SET_STYLE(REGULAR, GREEN);
	printf("\"%s\"\n", str);
	return (OK);
}

#define TOLOWER_STR "CECI`esT@un[PUTAIN{De (2) .TeST!"
#define TOLOWER_STRLEN strlen(TOLOWER_STR) + 1
int	ft_check_tolower(void)
{
	char	str[TOLOWER_STRLEN] = TOLOWER_STR;
	int		i;

	SET_STYLE(REGULAR, CYAN);
	printf("\"%s\"\n\n\tbecame\n\n", str);
	i = -1;
	while (++i < TOLOWER_STRLEN - 1)
		str[i] = ft_tolower(str[i]);
	SET_STYLE(REGULAR, GREEN);
	printf("\"%s\"\n", str);
	return (OK);
}

#define STRCHR_STR "I have a bad case of diarrhea."
#define STRCHR_C 'a'
int	ft_check_strchr(void)
{
	char	str[] = STRCHR_STR;
	char	c = STRCHR_C;
	char	*res1;
	char	*res2;

	SET_STYLE(REGULAR, CYAN);
	printf("str is\t\"%s\"\nc is \t\'%c\'\n\n", str, c);
	SET_STYLE(REGULAR, GREEN);
	res1 = strchr(str, (int)c);
	printf("strchr returns\t\t\"%s\" %p\n", res1, res1);
	res2 = ft_strchr(str, (int)c);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_strchr returns\t\"%s\" %p\n", res2, res2);
	if (res1 == res2)
		return (OK);
	else
		return (KO);
}

#define STRRCHR_STR "I have a VERY bad case of diarrhea."
#define STRRCHR_C 'd'
int	ft_check_strrchr(void)
{
	char	str[] = STRRCHR_STR;
	char	c = STRRCHR_C;
	char	*res1;
	char	*res2;

	SET_STYLE(REGULAR, CYAN);
	printf("str is\t\"%s\"\nc is \t\'%c\'\n\n", str, c);
	SET_STYLE(REGULAR, GREEN);
	res1 = strrchr(str, (int)c);
	printf("strrchr returns\t\t\"%s\" %p\n", res1, res1);
	res2 = ft_strrchr(str, (int)c);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_strrchr returns\t\"%s\" %p\n", res2, res2);
	if (res1 == res2)
		return (OK);
	else
		return (KO);
}

#define STRNCMP_STR1 "Music makes you lose control"
#define STRNCMP_STR2 "Music makes OH GOD NO"
#define STRNCMP_BYTES 13
int	ft_check_strncmp(void)
{
	char	s1[] = STRNCMP_STR1;
	char	s2[] = STRNCMP_STR2;
	int		res1;
	int		res2;

	SET_STYLE(REGULAR, CYAN);
	printf("s1 is\t\"%s\"\n", s1);
	printf("s2 is\t\"%s\"\n\n", s2);
	res1 = strncmp(s1, s2, STRNCMP_BYTES);
	res2 = ft_strncmp(s1, s2, STRNCMP_BYTES);
	SET_STYLE(REGULAR, GREEN);
	printf("strncmp returns\t\t%d\n", res1);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_strncmp returns\t%d\n", res2);
	if (res1 != res2)
		return (KO);
	else
		return (OK);
}

#define MEMCHR_STR "Anything for YOU! M. Obama!"
#define MEMCHR_C '!'
#define MEMCHR_BYTES 28
int	ft_check_memchr(void)
{
	char	str[] = MEMCHR_STR;
	char	c = MEMCHR_C;
	char	*res1;
	char	*res2;

	SET_STYLE(REGULAR, CYAN);
	printf("str is\t\"%s\"\nc is \t\'%c\'\n\n", str, c);
	SET_STYLE(REGULAR, GREEN);
	res1 = (char *)memchr((void *)str, (int)c, MEMCHR_BYTES);
	printf("memchr returns\t\t\"%s\" %p\n", res1, res1);
	res2 = (char *)ft_memchr((void *)str, (int)c, MEMCHR_BYTES);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_memchr returns\t\"%s\" %p\n", res2, res2);
	if (res1 == res2)
		return (OK);
	else
		return (KO);
}

#define MEMCMP_STR1 "Music Makes \xccyou lose control"
#define MEMCMP_STR2 "Music Makes \xffOH GOD NO AAAAAA"
#define MEMCMP_BYTES 30
int	ft_check_memcmp(void)
{
	unsigned char	s1[] = MEMCMP_STR1;
	unsigned char	s2[] = MEMCMP_STR2;
	int				res1;
	int				res2;

	SET_STYLE(REGULAR, CYAN);
	printf("s1 is\t\"%s\"\n", s1);
	printf("s2 is\t\"%s\"\n\n", s2);
	res1 = memcmp(s1, s2, MEMCMP_BYTES);
	res2 = ft_memcmp(s1, s2, MEMCMP_BYTES);
	SET_STYLE(REGULAR, GREEN);
	printf("memcmp returns\t\t%d\n", res1);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_memcmp returns\t%d\n", res2);
	if (res1 != res2)
		return (KO);
	else
		return (OK);
}

#define STRNSTR_STR "Fun fact on Vaporeon! >:}"
#define STRNSTR_SUB "on"
#define STRNSTR_BYTES 21
int	ft_check_strnstr(void)
{
	char	str[] = STRNSTR_STR;
	char	to_find[] = STRNSTR_SUB;
	char	*res1;
	char	*res2;

	SET_STYLE(REGULAR, CYAN);
	printf("str is :\t\"%s\"\n", str);
	printf("to_find is :\t\"%s\"\n\n", to_find);
	SET_STYLE(REGULAR, GREEN);
	res1 = strnstr(str, to_find, STRNSTR_BYTES);
	printf("strnstr returns\t\t%p \"%s\"\n", res1, res1);
	res2 = ft_strnstr(str, to_find, STRNSTR_BYTES);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_strnstr returns\t%p \"%s\"\n", res2, res2);
	if (res1 != res2)
		return (KO);
	else
		return (OK);
}

int	ft_check_atoi(void)
{
	char	str[] = "\v \f \r \n \t +00000020150oo0";
	int		res1;
	int		res2;

	SET_STYLE(REGULAR, CYAN);
	printf("str is\t\"%s\"\n\n", str);
	SET_STYLE(REGULAR, GREEN);
	res1 = atoi(str);
	printf("atoi returns\t%d\n", atoi(str));
	res2 = ft_atoi(str);
	if (res2 != res1)
		SET_STYLE(REGULAR, RED);
	printf("ft_atoi returns\t%d\n", ft_atoi(str));
	if (res1 != res2)
		return (KO);
	else
		return (OK);
}

int	ft_check_putchar_fd(void)
{
	char	c;

	c = 'Q';
	SET_STYLE(REGULAR, CYAN);
	printf("Trying to write the letter \'%c\'\n", c);
	SET_STYLE(REGULAR, GREEN);
	printf("\n");
	dprintf(1, "With ft_putchar_fd: \'");
	ft_putchar_fd(c, 1);
	dprintf(1, "\'\n");
	return (OK);
}

#define PUTSTR_FD_STR "The arcana is the means by which all is revealed."
#define PUTSTR_FD_STRLEN strlen(PUTSTR_FD_STR) + 1
int	ft_check_putstr_fd(void)
{
	char	str[PUTSTR_FD_STRLEN] = PUTSTR_FD_STR;

	SET_STYLE(REGULAR, CYAN);
	printf("Trying to write the string:\n\"%s\"\n", str);
	SET_STYLE(REGULAR, GREEN);
	printf("\n");
	dprintf(1, "With ft_putstr_fd:\n\"");
	ft_putstr_fd(str, 1);
	dprintf(1, "\"\n");
	return (OK);
}

#define PUTENDL_FD_STR1 "Pikachu !"
#define PUTENDL_FD_STR1LEN strlen(PUTENDL_FD_STR1) + 1
#define PUTENDL_FD_STR2 "Utilise Tonnerre !"
#define PUTENDL_FD_STR2LEN strlen(PUTENDL_FD_STR2) + 1
int	ft_check_putendl_fd(void)
{
	char	str1[PUTENDL_FD_STR1LEN] = PUTENDL_FD_STR1;
	char	str2[PUTENDL_FD_STR2LEN] = PUTENDL_FD_STR2;

	SET_STYLE(REGULAR, CYAN);
	printf("Trying to write the 2 strings:\n\"%s\" \"%s\"\n", str1, str2);
	SET_STYLE(REGULAR, GREEN);
	printf("\n");
	dprintf(1, "With ft_putendl_fd and ft_putstr_fd:\n\"");
	ft_putendl_fd(str1, 1);
	ft_putstr_fd(str2, 1);
	dprintf(1, "\"\n");
	return (OK);
}

int	ft_check_putnbr_fd(void)
{
	int	tab[8];
	int	i;

	tab[0] = 0;
	tab[1] = 6;
	tab[2] = 13;
	tab[3] = 3147;
	tab[4] = 2147483647;
	tab[5] = -1;
	tab[6] = -333;
	tab[7] = -2147483648;
	SET_STYLE(REGULAR, CYAN);
	printf("Trying to write these numbers:\n");
	i = -1;
	while (++i < 8)
		printf("%d\n", tab[i]);
	SET_STYLE(REGULAR, GREEN);
	printf("\nWith ft_putnbr_fd and ft_putchar_fd:\n");
	i = -1;
	while (++i < 8)
	{
		ft_putnbr_fd(tab[i], 1);
		ft_putchar_fd('\n', 1);
	}
	return (OK);
}

void	ft_print_title(char *str)
{
	SET_STYLE(BOLD, CYAN);

	printf("\nFT_%s:\n", str);
	RESET_STYLE;
	printf("\n");
}

int	ft_print_check_result(int res)
{
	printf("\n");
	if (res == OK)
	{
		SET_STYLE(BOLD, GREEN);
		printf("SUCCESS\n");
	}
	else
	{
		SET_STYLE(BOLD, RED);
		printf("FAILURE\n");
	}
	RESET_STYLE;
	return (res);
}

void	ft_print_final_result(int nb)
{
	printf("\n");
	if (!nb)
	{
		SET_STYLE(BOLD, GREEN);
		printf("     !!!!!     SUCCESS     !!!!!\n");
	}
	else
	{
		SET_STYLE(BOLD, RED);
		printf("     !!!!!     FAILURE     !!!!!\n");
	}
	RESET_STYLE;
}

int	main(void)
{
	int		nb_succ;
	int		(*ft_check[NB_TESTS])(void);
	char	*titles[NB_TESTS];
	int		i;

	ft_check[0] = ISALPHA;
	ft_check[1] = ISDIGIT;
	ft_check[2] = ISALNUM;
	ft_check[3] = ISASCII;
	ft_check[4] = ISPRINT;
	ft_check[5] = STRLEN;
	ft_check[6] = MEMSET;
	ft_check[7] = BZERO;
	ft_check[8] = MEMCPY;
	ft_check[9] = MEMMOV;
	ft_check[10] = STRLCPY;
	ft_check[11] = STRLCAT;
	ft_check[12] = TOUPPER;
	ft_check[13] = TOLOWER;
	ft_check[14] = STRCHR;
	ft_check[15] = STRRCHR;
	ft_check[16] = STRNCMP;
	ft_check[17] = MEMCHR;
	ft_check[18] = MEMCMP;
	ft_check[19] = STRNSTR;
	ft_check[20] = ATOI;
	ft_check[21] = CALLOC;
	ft_check[22] = STRDUP;
	ft_check[23] = SUBSTR;
	ft_check[24] = STRJOIN;
	ft_check[25] = STRTRIM;
	ft_check[26] = SPLIT;
	ft_check[27] = ITOA;
	ft_check[28] = STRMAPI;
	ft_check[29] = STRITERI;
	ft_check[30] = PUTCHAR_FD;
	ft_check[31] = PUTSTR_FD;
	ft_check[32] = PUTENDL_FD;
	ft_check[33] = PUTNBR_FD;
	titles[0] = "ISALPHA";
	titles[1] = "ISDIGIT";
	titles[2] = "ISALNUM";
	titles[3] = "ISASCII";
	titles[4] = "ISPRINT";
	titles[5] = "STRLEN";
	titles[6] = "MEMSET";
	titles[7] = "BZERO";
	titles[8] = "MEMCPY";
	titles[9] = "MEMMOV";
	titles[10] = "STRLCPY";
	titles[11] = "STRLCAT";
	titles[12] = "TOUPPER";
	titles[13] = "TOLOWER";
	titles[14] = "STRCHR";
	titles[15] = "STRRCHR";
	titles[16] = "STRNCMP";
	titles[17] = "MEMCHR";
	titles[18] = "MEMCMP";
	titles[19] = "STRNSTR";
	titles[20] = "ATOI";
	titles[21] = "CALLOC";
	titles[22] = "STRDUP";
	titles[23] = "SUBSTR";
	titles[24] = "STRJOIN";
	titles[25] = "STRTRIM";
	titles[26] = "SPLIT";
	titles[27] = "ITOA";
	titles[28] = "STRMAPI";
	titles[29] = "STRITERI";
	titles[30] = "PUTCHAR_FD";
	titles[31] = "PUTSTR_FD";
	titles[32] = "PUTENDL_FD";
	titles[33] = "PUTNBR_FD";
	nb_succ = 0;
	SET_STYLE(REGULAR, CYAN);
	printf("There are %d tests.\n", NB_TESTS);
	i = -1;
	while (++i < NB_TESTS)
	{
		ft_print_title(titles[i]);
		nb_succ += ft_print_check_result((*ft_check[i])());
	}
	ft_print_final_result(nb_succ);
	return (0);
}
