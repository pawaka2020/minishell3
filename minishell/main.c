/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

char	*ft_getpwd()
{
	char	*cwd;
	char	*res;
	
	cwd = getcwd(0, 0);
	res = ft_strjoin("PWD=", cwd);
	free(cwd);
	return (res);
}

char	*ft_getshlvl()
{
	int	lvl;
	char	*lvlstr;
	char	*res;
	
	lvl = ft_atoi("SHLVL");
	if (lvl < 1)
		lvl = 1;
	else
		lvl++;
	lvlstr = ft_itoa(lvl);
	res = ft_strjoin("SHLVL=", lvlstr);
	free(lvlstr);
	return (res);
}

char	*ft_getpath()
{
	char	*res;
	
	res = getenv("PATH");
	if (res == 0)
		res = "PATH=/usr/local/sbin:/usr/local/bin:/usr/bin:/bin";
	return (ft_strdup(res));
}

char	*ft_get_()
{
	char	*res;
	
	res = getenv("_");
	if (res == 0)
		res = "_minishell";
	return (ft_strdup(res));
}

//perhaps we should include error catching here in case fork() fails.
pid_t	ft_getpid()
{
	pid_t	pid;

	pid = fork();
	waitpid(pid, 0, 0);
	return (pid - 1);
}

void	ft_init(t_prompt *p)
{
	p->cmds = 0;
	g_status = 0;
	p->env_pwd = ft_getpwd();
	p->env_shlvl = ft_getshlvl();
	p->env_path = ft_getpath();
	p->env__ = ft_get_();
	p->pid = ft_getpid();
}

void	ft_free(t_prompt *p)
{
	free(p->env_pwd);
	free(p->env_shlvl);
	free(p->env_path);
	free(p->env__);
}

//apart from changing g_status, I donno what it does yet.
void	ft_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		//rl_replace_line("", 0);
		//rl_on_new_line();
	}
}

void	ft_run(int argc, char **argv, t_prompt prompt)
{
	char	*input; 
	
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (argv && argc)
	{
		input = readline("Put your input here >");
		printf("input is = %s\n", input);
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt			prompt;

	g_status = 0;
	ft_init(&prompt);
	ft_run(argc, argv, prompt);
	ft_free(&prompt);
	return (0);
}
