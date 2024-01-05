/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/05 19:49:00 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**	Char *argv
**	char *envp
**  int fd1
**  int fd4
**
** =====================================================
** =====================================================
**
** pid_t to stock the identifiers of process
** pipefd[2] tab to stock the identifiers of pid(reading or writing)
** status to verify the status at child
**
** pid1 = fork () call fork to creat a copy of the parent
** if fork work
** -> parent get the child identifiers in pid1
** if doesn't work -> return (1) 
**
** if pid is negative return 1, if pid1 == 0 child process
**
** waitpid() wait the end of parent to wait child
*/

int	ft_pipex(char *argv[], char *env[], char *new_argv[])
{
	pid_t	pid[2];
	int		status;
	int		i;
	int		nb;
	t_pipes	*pipes;
	pid_t	pid_child;
	// (void)pid_child;
	// (void)i;
	// (void)status;
	// (void)env;
	// (void)new_argv;
	// (void)nb;
	// (void)pid;
	nb = get_nb_pipes(argv);
	pipes = NULL;
	pipes = init_struct(argv);
	if (!pipes)
		return (-1);
	printf("nb %i\n", nb);
	i = 0;
	printf("verification des argument==========\n");
	while (new_argv[i])
	{
		printf("%s\n", new_argv[i]);
		i++;
	}
	i = 0;
	printf("verif terminer=======\n");
	nb++;
	while (i < nb)
	{
		pid[i] = fork();
		if (pid[i] < 0)	
			return (printf("erreur de fork\n"), 1);
		if (pid[i] == 0)
		{
			fprintf(stderr, "boucle numero %d et nb %d\n", i, nb);
			// fprintf(stderr, "LE PID DE %d EST DE %d\n", i, pid[i]);
			if (i == 0)
			{
				fprintf(stderr, "========JE SUIS DANS IN========\n");
				if (child_process_in(pipes, i, env, new_argv) == -1)
					return (-1);
				fprintf(stderr, "========JE SORS DE IN========\n");
			}
			else if (i == nb - 1)
			{
				fprintf(stderr, "///JE SUIS DANS OUT ET VOICI I = %d///\n", i);
				if (child_process_out(pipes, i, env, new_argv) == -1)
					return (-1);
				fprintf(stderr, "///JE SORS DE OUT ET VOICI I = %d///\n", i);
				exit(0);
			}
			else
			{
				fprintf(stderr, "--------JE SUIS DANS MIDDLE--------\n");
				if (child_process_middle(pipes, i, env, new_argv) == -1)
					return (-1);
				fprintf(stderr, "--------JE SORS DE MIDDLE--------");
				printf("truc de ouf\n");
			}
		}
		// else
		// {
		// 	fprintf(stderr, "je suis dans waitpid, go voir si ca stuck\n");
		// 	pid_child = waitpid(pid[i], &status, 0);
		// 	if (pid_child == -1)
		// 		return (printf("problem pid\n"), free(pipes), -1);
		// 	fprintf(stderr, "pid dans  mon if = %d et je sors\n", pid[i]);
		// }
		i++;
	}
	fprintf(stderr, "JE SUIS SORTIS DE MA BOUCLE voici mon pid %d\n", pid[i]);
	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
	// while (i < 2)
	// {
	// 	close(pipes[i].pipes[0]);
	// 	close(pipes[i].pipes[1]);
	// 	i++;
	// }
	close(pipes[0].pipes[0]);
	close(pipes[0].pipes[1]);
	i = 0;
	if (pid[i] > 0)
		parent_process(pipes, i, env, new_argv);
	close(pipes->pipes[1]);
	close(pipes->pipes[0]);
	// close(pipes[0].pipes[0]);
	// close(pipes[0].pipes[1]);
	// close(pipes[1].pipes[1]);
	// close(pipes[1].pipes[0]);
	// close(pipes[2].pipes[1]);
	// close(pipes[2].pipes[0]);
	while (i < nb)
	{
		pid_child = waitpid(pid[i], &status, 0);
		if (pid_child == -1)
			return (printf("problem pid\n"), free(pipes), -1);
		fprintf(stderr, "pid dans boucle = %d\n", pid[i]);
		fprintf(stderr, "i dans ma boucle de pid %d\n", i);
		i++;
	}
	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
	free(pipes);
	return (0);
}

void	parent_process(t_pipes *pipes, int i, char *env[], char *argv[])
{
	int j = 0;
	(void)i;
	(void)env;
	(void)argv;

	while (j < 2)
	{
		close(pipes[j].pipes[0]);
		close(pipes[j].pipes[1]);
		j++;
	}
}

// int	ft_pipex(char *argv[], char *envp[])
// {
// 	pid_t	pid[2];
// 	int		end[2];
// 	int		status;
// 	int		i;

// 	i = 0;
// 	if (pipe(end) < 0)
// 		return (perror("pipes"), 1);
// 	printf("je suis dans ft_pipex\n");
// 	while (i < 2)
// 	{
// 		pid[i] = fork();
// 		if (pid[i] < 0)
// 			return (1);
// 		if (pid[i] == 0)
// 		{
// 			if (i == 0)
// 				child_process_start(argv, envp, end);
// 			else
// 				child_process_end(argv, envp, end);
// 		}
// 		i++;
// 	}
// 	close(end[0]);
// 	close(end[1]);
// 	waitpid(pid[1], &status, 0);
// 	waitpid(pid[0], &status, 0);
// 	return (0);
// }

//end[1] == child process ->write
//end[0] == parent process ->read
//cm1 will be executed by child and cm2 by parent