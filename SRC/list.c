/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:54:54 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/05 18:15:40 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*creat_node(char	*line)
{
	t_map	*node;

	node = malloc(sizeof(node));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	node->next = NULL;
	return (node);
}

void	add_back(t_map **head, t_map *node)
{
	t_map	*curr;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
}

int	list_size(t_map *head)
{
	int		i;
	t_map	*curr;

	i = 0;
	curr = head;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	ft_clean(t_map **head)
{
	t_map	*curr;
	t_map	*temp;

	curr = *head;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp->line);
		free(temp);
	}
	head = NULL;
}
