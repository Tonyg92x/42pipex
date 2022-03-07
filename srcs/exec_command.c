/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 14:17:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

//	Get the path of the command that
//	I want to run.
char	*get_path(char **envp, t_command *command)
{
	int		i;
	char	**path;
	char	*retour;
	char	*path_command;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
		{
			path = ft_split(&envp[i][5], ':');
			i = 0;
			while (path[i])
			{
				path_command = ft_strjoin(path[i], "/");
				free(path[i]);
				path[i++] = path_command;
			}
			i = 0;
			while (true)
			{
				if (path[i] == NULL)
					break;
				path_command = ft_strjoin(path[i], command->cmd[0]);
				if (access(path_command, F_OK) == 0)
				{
					retour = ft_strdup(path[i]);
					ft_free2d(path);
					free(path_command);
					return (retour);
				}
				free(path_command);
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

//	Execute the command entered. If there is a problem,
//	do nothing and return.
void	execute_command(t_command *command, char **envp)
{
	int		id;
	char	*path;
	char	*temp;

	if (command->cmd == NULL)
		return;
	path = get_path(envp, command);
	if (path != NULL)
	{
		temp = ft_strjoin(path, command->cmd[0]);
		free(path);
		path = temp;
		id = fork();
		if (id == 0)
		{
			if (execve(path, command->cmd, envp) == -1)
				ft_printf("Error : Unable to execute the command.\n");
		}
		free(path);
	}
}
