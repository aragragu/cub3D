/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:02:48 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/16 17:12:51 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_free_all(t_free *head)
{
	t_free	*current;
	t_free	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->add);
		current->add = NULL;
		free(current);
		current = next;
	}
	head = NULL;
}

t_free	*addnew_free(void *add)
{
	t_free	*new;

	new = malloc(sizeof(t_free));
	if (!new)
		return (NULL);
	new->add = add;
	new->next = NULL;
	return (new);
}

void	addback_free(t_free **head, t_free *new)
{
	t_free	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	*ft_malloc(int size, int status)
{
	static t_free	*head;
	t_free			*tmp;
	void			*rt;

	if (status == ALLOC)
	{
		rt = malloc(size);
		if (!rt)
			my_perror(0, "error:: malloc failed\n");
		tmp = addnew_free(rt);
		if (!tmp)
		{
			ft_free_all(head);
			my_perror(0, "error:: malloc failed\n");
		}
		addback_free(&head, tmp);
		return (rt);
	}
	else
		return (ft_free_all(head), head = NULL);
}
