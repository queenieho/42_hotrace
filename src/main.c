/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:34:11 by qho               #+#    #+#             */
/*   Updated: 2017/05/13 15:50:42 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

int		ft_hashkey_gen(char *str)
{
	int		key;

	key = 0;
	
	return (key);
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
				input.key = ft_hashkey_gen(line);
				// ft_putstr("KEY:  ");
				// ft_putendl(line);
			}
			else if (idx % 2 && !flag)
			{
				input.value = ft_strdup(line);
				ft_insert_value
				// ft_putstr("VAL:  ");
				// ft_putendl(line);
			}
			else if (flag == 1)
			{
				ft_putstr("TO SEARCH:  ");
				ft_putendl(line);
			}
			free(line);
			idx++;
		}
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
		printf("%lu\n", idx);
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