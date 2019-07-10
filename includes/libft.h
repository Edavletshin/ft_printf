/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:28:42 by galiza            #+#    #+#             */
/*   Updated: 2019/06/20 14:32:00 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // Удалить!!!
# define ABS(Value)	((Value < 0) ? (-Value) : (Value))

# define HH			1
# define H			2
# define L			4
# define LL			8

typedef	struct		s_flags
{
	int				minus;
	int				plus;
	int				dot;
	int				zero;
	int				len;
	int				blank;
	int				h_tag;
	int				l_int;
	int				padding;
	long long int	total;
	unsigned long
	long int		un_tot;
	double			flt;
	int				t_dot;
	int				flags;
	int				base;
}					t_flags;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *destination, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *d, const void *r, size_t n);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memmove(void *d, const void *s, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, int n);
void				ft_putendl(char const *s);
int					ft_putnbr_base(long long int n, int base,
					const char *digits);
int					ft_putun_nbr_base_not_print(unsigned long long int n, unsigned int base,
					const char *digits);
int					ft_putun_nbr_base(unsigned long long int n,
					unsigned int base, const char *digits);
int					ft_putun_nbr(unsigned long long int n);
int					ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
int					ft_pow(int nb, int power);
int					ft_count_if(char **tab, int (*f) (char*));
int					ft_printf(const char *fmt, ...);
/*
** ----------------------------- Printf utils----------------------------------
*/
int					ft_print_percent(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_c(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_s(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_p(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_f(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_d(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_o(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_u(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_x(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_bigx(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_printf_aux(const char *fmt, va_list ap,
					int curr_chr, int len);
int					ft_print_spaces(t_flags flags, int size_int);
int					ft_print_accur(t_flags flags, int accur);
void				ft_get_int(const char *fmt, int len, t_flags *flags);
void				ft_get_keys(const char *fmt, int len, t_flags *flags);
int					ft_print_keys(t_flags flags, int size_int);
int					ft_get_len(t_flags flags);
int					size(long long int i, int base);
int					un_size(unsigned long long int i, int base);

/*
** ----------------------------- Printf norminette------------------------------
*/
int					print_fract(long double n, int len, int accur);
int					if_long(const char *fmt, int curr_chr, t_flags flags);
int					space_nan(int len, t_flags flags);
#endif
