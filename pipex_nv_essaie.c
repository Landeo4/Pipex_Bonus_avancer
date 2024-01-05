/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_nv_essaie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:54:16 by tpotillion        #+#    #+#             */
/*   Updated: 2024/01/05 20:06:18 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// int	ft_pipex_nv(char *argv[], char *env[], char *new_argv[])
// {
// 	pid_t	pid[2];
// 	int		status;
// 	int		i;
// 	int		nb;
// 	t_pipes	*pipes;
// 	pid_t	pid_child;
// 	// (void)pid_child;
// 	// (void)i;
// 	(void)status;
// 	// (void)env;
// 	// (void)new_argv;
// 	// (void)nb;
// 	// (void)pid;
// 	nb = get_nb_pipes(argv);
// 	pipes = NULL;
// 	pipes = init_struct(argv);
// 	if (!pipes)
// 		return (-1);
// 	printf("nb %i\n", nb);
// 	i = 0;
// 	printf("verification des argument==========\n");
// 	while (new_argv[i])
// 	{
// 		printf("%s\n", new_argv[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("verif terminer=======\n");
// 	nb++;
// 	while (i < nb)
// 	{
// 		pid[i] = fork();
// 		if (pid[i] < 0)	
// 			return (printf("erreur de fork\n"), 1);
// 		if (pid[i] == 0)
// 		{
// 			fprintf(stderr, "boucle numero %d et nb %d\n", i, nb);
// 			// fprintf(stderr, "LE PID DE %d EST DE %d\n", i, pid[i]);
// 			if (i == 0)
// 			{
// 				fprintf(stderr, "========JE SUIS DANS IN========\n");
// 				if (child_process_in(pipes, i, env, new_argv) == -1)
// 					return (-1);
// 				fprintf(stderr, "========JE SORS DE IN========\n");
// 			}
// 			else if (i == nb - 1)
// 			{
// 				fprintf(stderr, "///JE SUIS DANS OUT ET VOICI I = %d///\n", i);
// 				if (child_process_out(pipes, i, env, new_argv) == -1)
// 					return (-1);
// 				fprintf(stderr, "///JE SORS DE OUT ET VOICI I = %d///\n", i);
// 				exit(0);
// 			}
// 			else
// 			{
// 				fprintf(stderr, "--------JE SUIS DANS MIDDLE--------\n");
// 				if (child_process_middle(pipes, i, env, new_argv) == -1)
// 					return (-1);
// 				fprintf(stderr, "--------JE SORS DE MIDDLE--------");
// 				printf("truc de ouf\n");
// 			}
// 		}
// 		// else
// 		// {
// 		// 	fprintf(stderr, "je suis dans waitpid, go voir si ca stuck\n");
// 		// 	pid_child = waitpid(pid[i], &status, 0);
// 		// 	if (pid_child == -1)
// 		// 		return (printf("problem pid\n"), free(pipes), -1);
// 		// 	fprintf(stderr, "pid dans  mon if = %d et je sors\n", pid[i]);
// 		// }
// 		i++;
// 	}
// 	fprintf(stderr, "JE SUIS SORTIS DE MA BOUCLE voici mon pid %d\n", pid[i]);
// 	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
// 	// while (i < 2)
// 	// {
// 	// 	close(pipes[i].pipes[0]);
// 	// 	close(pipes[i].pipes[1]);
// 	// 	i++;
// 	// }
// 	close(pipes[0].pipes[0]);
// 	close(pipes[0].pipes[1]);
// 	i = 0;
// 	if (pid[i] > 0)
// 		parent_process(pipes, i, env, new_argv);
// 	close(pipes->pipes[1]);
// 	close(pipes->pipes[0]);
// 	// close(pipes[0].pipes[0]);
// 	// close(pipes[0].pipes[1]);
// 	// close(pipes[1].pipes[1]);
// 	// close(pipes[1].pipes[0]);
// 	// close(pipes[2].pipes[1]);
// 	// close(pipes[2].pipes[0]);
// 	while (i < nb)
// 	{
// 		pid_child = waitpid(pid[i], &status, 0);
// 		if (pid_child == -1)
// 			return (printf("problem pid\n"), free(pipes), -1);
// 		fprintf(stderr, "pid dans boucle = %d\n", pid[i]);
// 		fprintf(stderr, "i dans ma boucle de pid %d\n", i);
// 		i++;
// 	}
// 	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
// 	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
// 	fprintf(stderr, "=====WAH WAH WAH TU VA SORTIR LA=====\n");
// 	free(pipes);
// 	return (0);
// }
