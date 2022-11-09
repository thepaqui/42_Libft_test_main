/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thepaqui <thepaqui@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:05 by thepaqui          #+#    #+#             */
/*   Updated: 2022/11/09 11:41:35 by thepaqui         ###   ########.fr       */
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
#define NB_TESTS 16
#define ISALPHA ft_check_isalpha()
#define ISDIGIT ft_check_isdigit()
#define ISALNUM ft_check_isalnum()
#define ISASCII ft_check_isascii()
#define ISPRINT ft_check_isprint()
#define STRLEN ft_check_strlen()
#define MEMSET ft_check_memset()
#define BZERO ft_check_bzero()
#define MEMCPY ft_check_memcpy()
#define MEMMOV ft_check_memmove()

#define TOUPPER ft_check_toupper()
#define TOLOWER ft_check_tolower()

#define PUTCHAR_FD ft_check_putchar_fd()
#define PUTSTR_FD ft_check_putstr_fd()
#define PUTENDL_FD ft_check_putendl_fd()
#define PUTNBR_FD ft_check_putnbr_fd()

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
	printf("\"%s\" has a length of %lu.\n", str1, res);
	res = ft_strlen(str2);
	if (res == 1)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %lu.\n", str2, res);
	res = ft_strlen(str3);
	if (res == 7)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %lu.\n", str3, res);
	res = ft_strlen(str4);
	if (res == 42)
		SET_STYLE(REGULAR, GREEN);
	else
	{
		SET_STYLE(REGULAR, RED);
		err++;
	}
	printf("\"%s\" has a length of %lu.\n", str4, res);
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	nb_succ;

	nb_succ = 0;
	SET_STYLE(REGULAR, CYAN);
	printf("There are %d tests.\n", NB_TESTS);
	ft_print_title("ISALPHA");
	nb_succ += ft_print_check_result(ISALPHA);
	ft_print_title("ISDIGIT");
	nb_succ += ft_print_check_result(ISDIGIT);
	ft_print_title("ISALNUM");
	nb_succ += ft_print_check_result(ISALNUM);
	ft_print_title("ISASCII");
	nb_succ += ft_print_check_result(ISASCII);
	ft_print_title("ISPRINT");
	nb_succ += ft_print_check_result(ISPRINT);
	ft_print_title("STRLEN");
	nb_succ += ft_print_check_result(STRLEN);
	ft_print_title("MEMSET");
	nb_succ += ft_print_check_result(MEMSET);
	ft_print_title("BZERO");
	nb_succ += ft_print_check_result(BZERO);
	ft_print_title("MEMCPY");
	nb_succ += ft_print_check_result(MEMCPY);
	ft_print_title("MEMMOV");
	nb_succ += ft_print_check_result(MEMMOV);
	//strlcpy
	//strlcat
	ft_print_title("TOUPPER");
	nb_succ += ft_print_check_result(TOUPPER);
	ft_print_title("TOLOWER");
	nb_succ += ft_print_check_result(TOLOWER);

	ft_print_title("PUTCHAR_FD");
	nb_succ += ft_print_check_result(PUTCHAR_FD);
	ft_print_title("PUTSTR_FD");
	nb_succ += ft_print_check_result(PUTSTR_FD);
	ft_print_title("PUTENDL_FD");
	nb_succ += ft_print_check_result(PUTENDL_FD);
	ft_print_title("PUTNBR_FD");
	nb_succ += ft_print_check_result(PUTNBR_FD);
	ft_print_final_result(nb_succ);
	return (0);
}
