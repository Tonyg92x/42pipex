/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/03 11:12:02 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
	#include <sys/wait.h>

typedef struct command
{
	struct command	*next;
	char			*cmd;
	char			*arg;
}								t_command;

typedef struct command_list
{
	struct command	*start;
	int				len;
}								t_command_list;

#endif
