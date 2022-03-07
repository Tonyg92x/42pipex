/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 14:29:37 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	print_commands(t_command_list *l)
{
	t_command	*temp;
	int			i;

	temp = l->start;
	while (temp != NULL)
	{
		i = 1;
		ft_printf("CMD = %s", temp->cmd[0]);
		while (temp->cmd[i] != NULL)
			ft_printf(" %s", temp->cmd[i++]);
		ft_printf("\n");
		temp = temp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_command_list	*list;

	if (argc < 2)
		return (0);
	list = malloc(sizeof(t_command_list));
	initialise_command_list(list, argc, argv);
	execute_command(list->start, envp);
	print_commands(list);
	free_command_list(list);
}
