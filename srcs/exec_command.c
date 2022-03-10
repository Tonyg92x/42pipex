/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/10 13:06:34 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

//	Add a backslath after every string to test
//	test the path/command with acces funciton.
static char	**add_backslash(char **path)
{
	int		i;
	char	*path_command;

	i = 0;
	while (path[i])
	{
		path_command = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i++] = path_command;
	}
	return (path);
}

static char	*working_path(char **path, int i, t_command *command)
{
	char	*retour;
	char	*path_command;

	while (true)
	{
		if (path[i] == NULL)
			break ;
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
	return (NULL);
}

//	Get the path of the command that
//	I want to run.
static char	*get_path(char **envp, t_command *command)
{
	int		i;
	char	**path;
	char	*retour;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
		{
			path = ft_split(&envp[i][5], ':');
			path = add_backslash(path);
			retour = working_path(path, i, command);
			if (retour == NULL)
			{
				ft_free2d(path);
				return (NULL);
			}
			else
				return (retour);
		}
		i++;
	}
	return (NULL);
}

//	Execute the command entered. If there is a problem,
//	do nothing and return.
void	execute_command(t_command *command, char **envp, int *fd)
{
	char	*path;
	char	*temp;
	int		fd_temp;
	int		id;

	if (command->cmd == NULL)
		return ;
	id = fork();
	if (id == 0)
	{
		fd_temp= dup(fd[0]);
		close(fd[0]);
		dup2(fd_temp, 0);
		path = get_path(envp, command);
		if (path != NULL)
		{
			temp = ft_strjoin(path, command->cmd[0]);
			free(path);
			path = temp;
			if (execve(path, command->cmd, envp) == -1)
			{
				ft_printf("Error : Unable to execute the command.\n");
				exit(0);
			}
			free(path);
		}
		else
		{
			ft_printf("Error while trying to look for a valid path ");
			ft_printf("for the command '%s'.\n", command->cmd[0]);
			exit(0);
		}
	}
	else
		wait(&id);
	path = get_path(envp, command);
}
