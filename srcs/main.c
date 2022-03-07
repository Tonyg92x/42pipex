/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 08:57:49 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_command_list	*list;

	if (argc < 2)
		return (0);
	list = malloc(sizeof(t_command_list));
	initialise_command_list(list, argc, argv);	
	execute_command(list->start, envp);
	free_command_list(list);
}
