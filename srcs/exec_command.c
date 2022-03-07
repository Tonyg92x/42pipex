/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 10:58:04 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'h')
		{
			path = strdup(envp[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

//	Execute the command entered. If there is a problem,
//	do nothing and return.
void	execute_command(t_command *command, char **envp)
{
	char	*path;

	if (command->cmd == NULL)
		return;
	path = get_path(envp);
	if (path != NULL)
	{
		ft_printf("%s\n", path);
		free(path);
	}
}

// void	execute_command(char **argv, char *cmd)
// {
// 	if (execve(cmd, argv, NULL) == -1)
// 		perror("Could not execute the command.\n");
// }