/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:34:11 by qho               #+#    #+#             */
/*   Updated: 2017/05/14 03:41:00 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

int		ft_hashkey_gen(char *str)
{
	unsigned long		key;
	int					c;

	key = 5381;
	while ((c = *str++))
		key = ((key << 5) + key) + c;
	key = key % TABLE_SIZE;	
	// printf("key: %lu\n", key);
	return (key);
}

void	ft_replace_node(char **node_val, char *value, char *key)
{
	free(*node_val);
	*node_val = ft_strdup(value);
	free(value);
	free(key);
}

t_content	*ft_new_node(char *key, char *value)
{
	t_content *new;

	if ((new = (t_content *)malloc(sizeof(t_content))) == NULL)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	free(key);
	free(value);
	return (new);
}

void	ft_insert_value(t_table *table, char *key, char *value)
{
	int			bin;
	t_content	*next;
	t_content	*new;

	bin = ft_hashkey_gen(key);
	new = ft_new_node(key, value);
	if (table->record[bin] == NULL)
	{
		table->record[bin] = new;
		// ft_putendl("copied?");
		// ft_putendl(table->record[bin]->key);
		// ft_putendl(table->record[bin]->value);
	}
	// else
	// {
	// 	ft_putendl("occupied");
	// 	// ft_putendl(table->record[bin]->value);
	// 	// ft_putendl(table->record[bin]->key);
	// 	next = table->record[bin];
	// 	while (next != NULL && next->key != NULL && (ft_strcmp(key, next->key) != 0))
	// 	{
	// 		ft_putendl(next->key);
	// 		ft_putendl(next->value);
	// 		next = next->next;
	// 	}
	// 	if (next != NULL && next->key != NULL && (ft_strcmp(key, next->key) == 0))
	// 	{
	// 		ft_putendl("duplicate key node");
	// 		ft_replace_node(&next->value, value, key);
	// 		ft_putendl(next->value);
	// 	}
	// 	else
	// 	{
	// 		ft_putendl("inserting new node");
	// 		next = new;
	// 		ft_putendl(next->key);
	// 		ft_putendl(next->value);
	// 	}
	// }
}

void	ft_find_value(t_table *table, char *key)
{
	int			bin;
	t_content	*curr;

	bin = ft_hashkey_gen(key);
	curr = table->record[bin];
	// while (curr != NULL && curr->key != NULL && (ft_strcmp(key, curr->key) != 0))
	// 	curr = curr->next;

	if (curr == NULL || curr->key == NULL || (ft_strcmp(key, curr->key) != 0))
	{
		ft_putstr(key);
//		ft_putstr("-search ");
		ft_putendl(": Not found.");
	}
	else
	{
//		ft_putstr(key);
//		ft_putstr("-search ");
		ft_putendl(curr->value);
	}
}

void	ft_get_input(t_table *table)
{
	char	*line;
	int		idx;
	int		flag;
	t_input	input;

	idx = 0;
	flag = 0;
	while (1)
	{
		if (get_next_line(0, &line) == 1)
		{
			if (*line == '\0')
				flag = 1;
			else if (!(idx % 2) && !flag)
			{
				input.key = ft_strdup(line);
				// ft_putstr("KEY:  ");
				// ft_putendl(line);
			}
			else if (idx % 2 && !flag)
			{
				// ft_putstr("VAL:  ");
				// ft_putendl(line);
				input.value = ft_strdup(line);
				ft_insert_value(table, input.key, input.value);	
			}
			else if (flag == 1)
			{
				ft_find_value(table, line);
				// ft_putstr("TO SEARCH:  ");
				// ft_putendl(line);
			}
			free(line);
			idx++;
		}
		else
			break ;
	}
}

int		ft_table_init(t_table *table, unsigned long size)
{
	unsigned long		idx;

	idx = -1;
	table->size = size;
	if ((table->record = (t_content **)malloc(sizeof(t_content *) * size)) == NULL)
		return (-1);
	while (++idx < size)
	{
		table->record[idx] = NULL;
		// printf("%lu\n", idx);
	}
	return (0);
}

int		main(void)
{
	t_table table;

	if ((ft_table_init(&table, TABLE_SIZE)) == -1)
		return (-1);
	ft_get_input(&table);
	
	return (0);
}
