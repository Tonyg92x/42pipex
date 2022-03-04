/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/03 11:46:37 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

// void	execute_command(char **argv, char *cmd)
// {
// 	if (execve(cmd, argv, NULL) == -1)
// 		perror("Could not execute the command.\n");
// }

char	*get_cmd(char *string)
{
	char	*cmd;
	int		size;

	size = 0;
	while (string[size] != ' ')
		size++;
	cmd = ft_substr(string, 0, size);
	return (cmd);
}

char	*get_arg(char *string)
{
	char	*arg;
	int		start;

	start = 0;
	while (string[start] != ' ')
		start++;
	start++;
	arg = ft_substr(string, start, 1000);
	return (arg);
}

void	initialise_command_list(t_command_list *l, int argc, char **argv)
{
	l->start = malloc(sizeof(t_command));
	l->start->cmd = get_cmd(argv[1]);
	l->start->arg = get_arg(argv[1]);
	argc--;
}

void	free_command_list(t_command_list *l)
{
	t_command	*temp;

	while (l->start != NULL)
	{
		if (l->start->cmd != NULL)
			free(l->start->cmd);
		if (l->start->arg != NULL)
			free(l->start->arg);
		temp = l->start;
		if (l->start->next != NULL)
			l->start = l->start->next;
		free(temp);
	}
	free(l);
}

//	, char **envp
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_command_list	*list;

	list = malloc(sizeof(t_command_list));
	initialise_command_list(list, argc, argv);
	ft_printf("CMD = %s\nArgs = %s", list->start->cmd, list->start->arg);
	// free_command_list(list);
}
