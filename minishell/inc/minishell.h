/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft/mylibft.h"

//# include "../libft/inc/libft.h"
//# include "colors.h"
//# include "get_next_line.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

//data structures
//
typedef struct s_cmds
{
	void		*word;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_prompt
{
	t_cmds	*cmds;
	//my own command. Just a string array from ft_split " " readline result.
	char	**command;
	char	**envp;
	//probably don't use envp, but just declare str and fill each with ft_strdup.
	char	*env_pwd;
	char	*env_shlvl;
	char	*env_path;
	char	*env__;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

//functions
void				dosomething(void);


#endif
