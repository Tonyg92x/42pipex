/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 10:56:55 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	print_commands(t_command_list *l)
{
	t_command	*temp;

	temp = l->start;
	while (temp != NULL)
	{
		ft_printf("CMD = %s\n", temp->cmd);
		if (temp->arg[0] != '\0')
			ft_printf("ARG = %s\n", temp->arg);
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
