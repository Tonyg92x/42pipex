/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 08:57:58 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

//	Execute the command entered. If there is a problem,
//	do nothing and return.
void	execute_command(t_command *command, char **envp)
{
	int	i;

	i = 0;
	if (command->cmd == NULL)
		return;
	ft_printf("Command = %s\n", command->cmd);
	if (command->arg != NULL)
		ft_printf("Arguments = %s\n", command->arg);
	ft_printf("Environnement parameters : \n");
	while (envp[i])
		ft_printf("%s\n", envp[i++]);
}

// void	execute_command(char **argv, char *cmd)
// {
// 	if (execve(cmd, argv, NULL) == -1)
// 		perror("Could not execute the command.\n");
// }