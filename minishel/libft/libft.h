/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:33:07 by horandri          #+#    #+#             */
/*   Updated: 2024/12/20 14:02:37 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_lst
{
	char				c;
	struct s_lst		*next;
}	t_lst;

typedef unsigned long	t_size;
char				*ft_strjoin_char(char *s1);
char				*ft_strjoin2(char *s1, char const *s2);
char	*ft_strdup_free(char *str);
int					ft_atoi(const char *str);
int					ft_isalpha(int e);
int					ft_tolower(int e);
int					ft_toupper(int e);
int					ft_isalnum(char e);
int					ft_isascii(char e);
int					ft_isalnum_char(char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isdigit(char e);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isprint(char e);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t n, size_t e);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *find, size_t n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *str);

#endif
