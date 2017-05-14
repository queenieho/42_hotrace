/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:33:27 by qho               #+#    #+#             */
/*   Updated: 2017/05/13 20:03:48 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 32
# define TABLE_SIZE 31121
// # define TABLE_SIZE 3000017
/*
** first prime number over 3 million to fit the largest file. 
** Prime number for better hash key
*/

# ifndef ERRORS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
# endif

# ifndef W_ERRORS
#  define WERR1(a, b, c) if(a){ft_putendl(b);return(c);}
#  define WERR2(a, b, c, d) if(a){b;ft_putendl(c);return(d);}
# endif

typedef struct			s_input
{
	char				*key;
	char				*value;
}						t_input;

typedef struct			s_content
{
	char				*key;
	char				*value;
	struct s_content	*next;
}						t_content;

typedef struct			s_table		
{
	unsigned long		size;
	t_content			**record;
}						t_table;

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);

void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);


static int	ft_get_line(char **line, char **hold, char *buf);
int			get_next_line(const int fd, char **line);

#endif