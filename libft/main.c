/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shadya <shadya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:57:22 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/19 13:36:17 by shadya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Command line to link with libft.a :
	cc -Wall -Wextra -Werror main.c libft.a -lbsd -o test
*/

#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

char	alpha_or_dash(unsigned int i, char c)
{
	(void)	i;

	if (ft_isalpha(c))
		return (c);
	return ('-');
}

void	make_even_uppercase(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	del(void *content)
{
	(void)content;
}

void	print_node(void *content)
{
	printf("- %s\n", (char *)content);
}

void *lsttoupper(void *content)
{
	char *s = strdup((char *)content);
	if (!s) return NULL;
	for (int i = 0; s[i]; i++)
		s[i] = toupper(s[i]);
	return s;
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (strcmp(av[1], "ft_isalpha.c") == 0)
		{
			printf("og: %d\n", isalpha(av[2][0]));
			printf("ft: %d\n", ft_isalpha(av[2][0]));
		}
		else if (strcmp(av[1], "ft_isdigit.c") == 0)
		{
			printf("og: %d\n", isdigit(av[2][0]));
			printf("ft: %d\n", ft_isdigit(av[2][0]));
		}
		else if (strcmp(av[1], "ft_isalnum.c") == 0)
		{
			printf("og: %d\n", isalnum(av[2][0]));
			printf("ft: %d\n", ft_isalnum(av[2][0]));
		}
		else if (strcmp(av[1], "ft_isascii.c") == 0)
		{
			printf("og: %d\n", isascii(av[2][0]));
			printf("ft: %d\n", ft_isascii(av[2][0]));
		}
		else if (strcmp(av[1], "ft_isprint.c") == 0)
		{
			printf("printable (og): %d\n", isprint(' '));
			printf("printable (ft): %d\n", ft_isprint(' '));
			printf("not printable (og): %d\n", isprint('\n'));
			printf("not printable (ft): %d\n", ft_isprint('\n'));
		}
		else if (strcmp(av[1], "ft_strlen.c") == 0)
		{
			printf("og: %zu\n", strlen(av[2]));
			printf("ft: %zu\n", ft_strlen(av[2]));
		}
		else if (strcmp(av[1], "ft_memset.c") == 0)
		{
			char buffer[25] = "Hello";
			char buffer2[25] = "Hello";
			memset(buffer + 2, '*', 5);
			ft_memset(buffer2 + 2, '*', 5);
			printf("Result (og): %s\n", buffer);
			printf("Result (ft): %s\n", buffer2);
		}
		else if (strcmp(av[1], "ft_bzero.c") == 0)
		{
			char buffer[25] = "Hello, how are you today?";
			char buffer2[25] = "Hello, how are you today?";
			bzero(buffer + 19, 5);
			ft_bzero(buffer2 + 19, 5);
			printf("Result (og): %s\n", buffer);
			printf("Result (ft): %s\n", buffer2);
		}
		else if (strcmp(av[1], "ft_memcpy.c") == 0)
		{
			// Handling overlap (undefined behavior):
			char str[10] = "0123456789";
			char str2[10] = "0123456789";
			memcpy(str + 3, str, 5);
			ft_memcpy(str2 + 3, str2, 5);
			printf("str after : %s\n", str);
			printf("str after : %s\n", str2);
			// Normal behavior :
			char src[] = "copy this";
			char dest[100];
			char dest2[100];
			memcpy(dest, src, ft_strlen(src) + 1);
			ft_memcpy(dest2, src, ft_strlen(src) + 1);
			printf("Result (og) -> src: %s, dest: %s\n", src, dest);
			printf("Result (ft) -> src: %s, dest: %s\n", src, dest2);
		}
		else if (strcmp(av[1], "ft_memmove.c") == 0)
		{
			// Handling overlap (should be able to handle it):
			char str[10] = "0123456789";
			memmove(str + 3, str, 5);
			printf("str after : %s\n", str);
			char str2[10] = "0123456789";
			ft_memmove(str2 + 3, str2, 5);
			printf("str after : %s\n", str2);
			// Normal behavior :
			char src[] = "copy this";
			char dest[100];
			char dest2[100];
			memmove(dest, src, ft_strlen(src) + 1);
			ft_memmove(dest2, src, ft_strlen(src) + 1);
			printf("Result (og) -> src: %s, dest: %s\n", src, dest);
			printf("Result (ft) -> src: %s, dest: %s\n", src, dest2);
		}
		else if (strcmp(av[1], "ft_strlcpy.c") == 0)
		{
			char src[] = "Hello, world!";
			size_t size = 10;
			char dst[100] = "A very long string where i need to copy";
			//char *dst = NULL;
			size_t buffer = strlcpy(dst, src, size);
			printf("Result (og) -> dst: %s, buffer: %zu\n", dst, buffer);
			char dst2[100] = "A very long string where i need to copy";
			//char *dst2 = NULL;
			size_t buffer2 = ft_strlcpy(dst2, src, size);
			printf("Result (ft) -> dst: %s, buffer: %zu\n", dst2, buffer2);
		}
		else if (strcmp(av[1], "ft_strlcat.c") == 0)
		{
			char src[] = " world!";
			//char *src = NULL;
			size_t size = 12;
			char dst[100] = "Hello";
			//char *dst = NULL;
			size_t buffer = strlcat(dst, src, size);
			printf("Result (og) -> dst: %s, buffer: %zu\n", dst, buffer);
			char dst2[100] = "Hello";
			//char *dst2 = NULL;
			size_t buffer2 = ft_strlcat(dst2, src, size);
			printf("Result (ft) -> dst: %s, buffer: %zu\n", dst2, buffer2);
		}
		else if (strcmp(av[1], "ft_toupper.c") == 0)
		{
			printf("og: %c\n", toupper(av[2][0]));
			printf("ft: %c\n", ft_toupper(av[2][0]));
		}
		else if (strcmp(av[1], "ft_tolower.c") == 0)
		{
			printf("og: %c\n", tolower(av[2][0]));
			printf("ft: %c\n", ft_tolower(av[2][0]));
		}
		else if (strcmp(av[1], "ft_strchr.c") == 0)
		{
			char str[] = "salut les amis";
			//char str[] = NULL;
			int c = 't' + 256;
			printf("Char found (og): %s\n", strchr(str, c));
			printf("Char found (ft): %s\n", ft_strchr(str, c));
		}
		else if (strcmp(av[1], "ft_strrchr.c") == 0)
		{
			char str[] = "hello";
			//char *str = NULL;
			int c = 'x';
			printf("Char found (og): %s\n", strrchr(str, c));
			printf("Char found (ft): %s\n", ft_strrchr(str, c));
		}
		else if (strcmp(av[1], "ft_strncmp.c") == 0)
		{
			char str1[] = "test\200";
			char str2[] = "test\0";
			//char *str1 = NULL;
			//char *str2 = NULL;
			size_t size = 6;
			printf("Result (og): %d\n", strncmp(str1, str2, size));
			printf("Result (ft): %d\n", ft_strncmp(str1, str2, size));
		}
		else if (strcmp(av[1], "ft_memchr.c") == 0)
		{
			//char s[] = "hello";
			char *s = NULL;
			int c = 'l' + 256;
			size_t n = 4;
			printf("Result (og): %p\n", memchr(s, c, n));
			printf("Result (ft): %p\n", ft_memchr(s, c, n));
		}
		else if (strcmp(av[1], "ft_memcmp.c") == 0)
		{
			char s1[] = "abcdefghij";
			char s2[] = "abcdefgxyz";
			//char *s1 = NULL;
			//char *s2 = NULL;
			size_t size = 10;
			printf("Result with char (og): %d\n", memcmp(s1, s2, size));
			printf("Result with char (ft): %d\n", ft_memcmp(s1, s2, size));
			int tab1[] = {1, 2, 3};
			int tab2[] = {-1, 2, 3};
			size_t size_tab = 2;
			printf("Result with int (og): %d\n", memcmp(tab1, tab2, size_tab));
			printf("Result with int (ft): %d\n", ft_memcmp(tab1, tab2, size_tab));
		}
		else if (strcmp(av[1], "ft_strnstr.c") == 0)
		{
			char big[] = "Hello, tu vas bien?";
			char little[] = "tu vas";
			//char *big = NULL;
			//char *little = NULL;
			size_t len = 13;
			printf("Found or null (og): %s\n", strnstr(big, little, len));
			printf("Found or null (ft): %s\n", ft_strnstr(big, little, len));
		}
		else if (strcmp(av[1], "ft_atoi.c") == 0)
		{
			char *str = "\t 10";
			//char *str = NULL;
			printf("Result (og): %d\n", atoi(str));
			printf("Result (ft): %d\n", ft_atoi(str));
		}
		else if (strcmp(av[1], "ft_calloc.c") == 0)
		{
			size_t nmemb = 10;
			size_t size = sizeof(int);
			int *arr = calloc(nmemb, size);
			if (!arr)
			{
				printf("(og) calloc failed: overflow or out of memory\n");
				return 1;
			}
			printf("arr (og): [");
			for (size_t i = 0; i < nmemb; i++)
			{
				printf(" %d ", arr[i]);
			}
			printf("]\n");
			free(arr);
			int *arr2 = ft_calloc(nmemb, size);
			if (!arr2)
			{
				printf("(ft) calloc failed: overflow or out of memory\n");
				return 1;
			}
			printf("arr (ft): [");
			for (size_t i = 0; i < nmemb; i++)
			{
				printf(" %d ", arr2[i]);
			}
			printf("]\n");
			free(arr2);
		}
		else if (strcmp(av[1], "ft_strdup.c") == 0)
		{
			char s[] = "string to duplicate";
			//char *s = NULL;
			char *dup = strdup(s);
			char *dup2 = ft_strdup(s);
			printf("Result (og): %s\n", dup);
			printf("Result (ft): %s\n", dup2);
			free(dup);
			free(dup2);
		}
		else if (strcmp(av[1], "ft_substr.c") == 0)
		{
			char s[] = "long string to copy";
			//char *s = NULL;
			unsigned int start = 2;
			size_t len = 100;
			char *substr = ft_substr(s, start, len);
			printf("Result: %s\n", substr);
			free(substr);
		}
		else if (strcmp(av[1], "ft_strjoin.c") == 0)
		{
			char *s1 = "Hello";
			char *s2 = ", world!";
			//char *s1 = NULL;
			//char *s2 = NULL;
			char *str = ft_strjoin(s1, s2);
			printf("Result: %s\n", str);
			free(str);
		}
		else if (strcmp(av[1], "ft_strtrim.c") == 0)
		{
			char set[] = "av";
			char s1[] = "avavavavava";
			//char *set = NULL;
			//char *s1 = NULL;
			char *str = ft_strtrim(s1, set);
			printf("Result: %s\n", str);
			free(str);
		}
		else if (strcmp(av[1], "ft_split.c") == 0)
		{
			char *s = "hello ca va";
			//char *s = NULL;
			char c	= 'c';
			char **strings = ft_split(s, c);
			if (! strings)
				printf("ft_split returned NULL!\n");
			else
			{
				int i = 0;
				while (strings[i])
				{
					printf("[%d] = %s\n", i, strings[i]);
					i++;
				}
				printf("[%d] = %s\n", i, strings[i]);
				i = 0;
				while (strings[i])
				{
					free(strings[i]);
					i++;
				}
				free(strings[i]);
			}
			free(strings);
		}
		else if (strcmp(av[1], "ft_itoa.c") == 0)
		{
			int n = 0;
			printf("Result: %s\n", ft_itoa(n));
		}
		else if (strcmp(av[1], "ft_strmapi.c") == 0)
		{
			char *s = "Hello, World!";
			//char *s = NULL;
			char *new_str = ft_strmapi(s, alpha_or_dash);
			printf("Result: %s\n", new_str);
			free(new_str);
		}
		else if (strcmp(av[1], "ft_striteri.c") == 0)
		{
			char s[] = "Hello, World!";
			//char *s = NULL;
			ft_striteri(s, make_even_uppercase);
			printf("Result: %s\n", s);
		}
		else if (strcmp(av[1], "ft_putchar_fd.c") == 0)
		{
			char c = 'S';
			int fd = 1;
			ft_putchar_fd(c, fd);
			write(fd, "\n", 1);
		}
		else if (strcmp(av[1], "ft_putstr_fd.c") == 0)
		{
			char *s = "Hello, World!";
			//char *s = NULL;
			int fd = 1;
			ft_putstr_fd(s, fd);
			write(fd, "\n", 1);
		}
		else if (strcmp(av[1], "ft_putendl_fd.c") == 0)
		{
			char *s = "Hello, World!";
			//char *s = NULL;
			int fd = 1;
			ft_putendl_fd(s, fd);
		}
		else if (strcmp(av[1], "ft_putnbr_fd.c") == 0)
		{
			int n = -2147483648;
			int fd = 1;
			ft_putnbr_fd(n, fd);
			write(fd, "\n", 1);
		}
		else if (strcmp(av[1], "ft_lstnew.c") == 0)
		{
			char *str = "Hello, World!";
			//char *str = NULL;
			t_list *node = ft_lstnew(str);
			printf("Result: %s\n", (char *)node->content);
			printf("Next is %s\n", node->next == NULL ? "NULL" : "not NULL");
			free(node);
		}
		else if (strcmp(av[1], "ft_lstadd_front.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			ft_lstadd_front(&list, new);
			printf("list->content = %s\n", (char *)list->content);
			printf("list->next->content = %s\n", (char *)list->next->content);
			printf("list->next->next = %s\n", list->next->next == NULL ? "NULL" : "not NULL");
			ft_lstclear(&list, del);
		}
		else if (strcmp(av[1], "ft_lstsize.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			//t_list *list = NULL;
			t_list *new = ft_lstnew("New");
			t_list *new2 = ft_lstnew("New2");
			ft_lstadd_front(&list, new);
			ft_lstadd_front(&list, new2);
			printf("Count: %d\n", ft_lstsize(list));
			ft_lstclear(&list, del);
		}
		else if (strcmp(av[1], "ft_lstlast.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			t_list *new2 = ft_lstnew("New2");
			ft_lstadd_front(&list, new);
			ft_lstadd_front(&list, new2);
			printf("Count: %d\n", ft_lstsize(list));
			printf("Last node content: %s\n", (char *)ft_lstlast(list)->content);
			ft_lstclear(&list, del);
		}
		else if (strcmp(av[1], "ft_lstadd_back.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			ft_lstadd_back(&list, new);
			printf("list->content = %s\n", (char *)list->content);
			printf("list->next->content = %s\n", (char *)list->next->content);
			printf("list->next->next = %s\n", list->next->next == NULL ? "NULL" : "not NULL");
			ft_lstclear(&list, del);
		}
		else if (strcmp(av[1], "ft_lstdelone.c") == 0)
		{
			t_list *node = ft_lstnew("First");
			printf("Before deletion: %s\n", (char *)node->content);
			ft_lstdelone(node, del);
			printf("Deleted (check valgrind)\n");
		}
		else if (strcmp(av[1], "ft_lstclear.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			t_list *new2 = ft_lstnew("New2");
			ft_lstadd_front(&list, new);
			ft_lstadd_front(&list, new2);
			printf("Count before deletion: %d\n", ft_lstsize(list));
			ft_lstclear(&list, del);
			printf("Count after deletion: %d\n", ft_lstsize(list));
			printf("Deleted (check valgrind)\n");
		}
		else if (strcmp(av[1], "ft_lstiter.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			t_list *new2 = ft_lstnew("New2");
			ft_lstadd_front(&list, new);
			ft_lstadd_front(&list, new2);
			ft_lstiter(list, print_node);
			ft_lstclear(&list, del);
		}
		else if (strcmp(av[1], "ft_lstmap.c") == 0)
		{
			t_list *list = ft_lstnew("First");
			t_list *new = ft_lstnew("New");
			t_list *new2 = ft_lstnew("New2");
			ft_lstadd_back(&list, new);
			ft_lstadd_back(&list, new2);
			printf("List: \n");
			ft_lstiter(list, print_node);
			t_list *new_list = ft_lstmap(list, lsttoupper, del);
			printf("Mapped list: \n");
			ft_lstiter(new_list, print_node);
			ft_lstclear(&list, del);
			ft_lstclear(&new_list, del);
		}
		else
		{
			printf("No function found.\n");
		}
	}
	return (0);
}
