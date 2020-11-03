/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:50:31 by lspiess           #+#    #+#             */
/*   Updated: 2020/01/15 21:04:04 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_H
# define STRINGFT_H
# include <unistd.h>

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

size_t			ft_strlen(const char *s);
int				ft_istrlen(const char *s);
int				ft_nblen(int n);

char			*ft_strtrim(char const *s, char const *set);
char			**ft_split_whitespace(char const *s);
void			*ft_free_tokens(char ***tokp);

char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strcpy(char *dst, const char *src);

char			*ft_strjoin(char const *s1, char const *s2);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void(*f)(unsigned int, char *));

int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strcapitalize(char *s);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strchr_idx(const char *s, int c);
int				ft_strnchr_idx(const char *s, int c, size_t n);

char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *src, size_t len);

char			*ft_strrev(char *s);

void			ft_strdel(char **as);
char			*ft_strnew(size_t size);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
