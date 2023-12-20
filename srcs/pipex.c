/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/12/20 16:43:12 by tpotilli         ###   ########.fr       */
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

int	ft_pipex(char *argv[], char *env[])
{
	pid_t	pid[2];
	int		status;
	int		i;
	int		nb;
	t_pipes	*pipes;

	nb = get_nb_pipes(argv);
	pipes = NULL;
	pipes = init_struct(argv);
	if (!pipes)
		return (printf("problem with pipe\n"), -1);
	printf("nb %i\n", nb);
	i = 0;
	while (i < nb)
	{
		pid[i] = fork();
		if (pid[i] < 0)	
			return (1);
		fprintf(stderr, "boucle %d\n", i);
		if (pid[i] == 0)
		{
			fprintf(stderr, "dans mon pid = 0 i = %d nb = %d\n", i, nb);
			if (i == 0)
			{
				fprintf(stderr, "je rentre dans child_process_in\n");
				child_process_in(pipes, env, argv);
				fprintf(stderr, "je sors de child_process_in\n");
			}
			else if (i == nb)
			{
				printf("je passe par out\n");
				child_process_out(pipes, i, env, argv);
				exit(0);
			}
			else
			{
				printf("je passe par middle\n");
				child_process_middle(pipes, i, env, argv);
			}
		}
		i++;
	}
	printf("mon i a la sortie de la boucle %i\n", i);
	i = 0;
	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
	while (i < nb)
	{
		printf("je suis dans la boucle waitpid\n");
		waitpid(pid[i], &status, 0);
		i++;
	}
	free(pipes);
	fprintf(stderr, "donc la finis????\n");
	return (0);
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