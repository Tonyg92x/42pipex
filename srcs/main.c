/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/10 15:22:01 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

//	Print out the command entered, usage for verification.
static void	print_commands(t_command_list *l)
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

//	Fonction to validate if the file is openable.
static bool	validate_file(char	*input, char *output)
{
	int	fd;

	fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_printf("Can't open or create the output file.");
		return (false);
	}
	else
		close(fd);
	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Error on opening the file to read");
		return (false);
	}
	else
		close(fd);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_command_list	*list;
	t_command		*temp;
	int				fd[2];

	if (argc < 4)
		return (0);
	if (validate_file(argv[1], argv[argc - 1]) == false)
		return (1);
	if (pipe(fd) == -1)
	{
		ft_printf("An error occured whith openning the pipe.\n");
		return (2);
	}
	list = malloc(sizeof(t_command_list));
	initialise_command_list(list, argc, argv);
	print_commands(list);
	temp = list->start;
	dup2(open(argv[1], O_RDONLY), 0);
	while (list->len > 1)
	{
		dup2(fd[1], 1);
		execute_command(temp, envp, fd);
		dup2(fd[0], 0);
		temp = temp->next;
		list->len--;
	}
	if (list->len == 1)
	{
		dup2(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777), 1);
		execute_command(temp, envp, fd);
	}
	free_command_list(list);
}
