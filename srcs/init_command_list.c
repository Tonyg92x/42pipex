/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 08:57:19 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

//	Get the command in the string entered.
char	*get_cmd(char *string)
{
	char	*cmd;
	char	*temp;
	int		size;

	size = 0;
	while (string[size] != ' ')
		size++;
	temp = ft_substr(string, 0, size);
	cmd = ft_strdup(temp);
	free(temp);
	return (cmd);
}

//	Get the argument next to the command in the string entered.
//	If there is none, return an empty string.
char	*get_arg(char *string)
{
	char	*arg;
	char	*temp;
	int		start;

	start = 0;
	while (string[start] != ' ')
		start++;
	start++;
	temp = ft_substr(string, start, 1000);
	arg = ft_strdup(temp);
	free(temp);
	return (arg);
}

//	For every string entered as arguments, fill a linked list of 
//	it's command and arguments if there is some.
void	initialise_command_list(t_command_list *l, int argc, char **argv)
{
	int			i;
	t_command	*temp;

	l->start = malloc(sizeof(t_command));
	l->start->prev = NULL;
	l->start->cmd = get_cmd(argv[1]);
	l->start->arg = get_arg(argv[1]);
	temp = l->start;
	i = 2;
	ft_printf("argc = %d\n", argc);
	while (i < argc)
	{
		temp->next = malloc(sizeof(t_command));
		temp->next->prev = temp;
		temp = temp->next;
		temp->cmd = get_cmd(argv[i]);
		temp->arg = get_arg(argv[i]);
		i++;
	}
}

//	Free all memory allocated in the command list.
void	free_command_list(t_command_list *l)
{
	t_command	*temp;
	t_command	*temp2;

	if (l->start != NULL)
	{
		temp = l->start;
		while (temp != NULL)
		{
			if (temp->cmd != NULL)
				free(temp->cmd);
			if (temp->arg != NULL)
				free(temp->arg);
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
	free(l);
}
