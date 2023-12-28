/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:19:16 by tpotilli          #+#    #+#             */
/*   Updated: 2023/12/28 18:38:59 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipes *init_struct(char *argv[])
{
	t_pipes *pipes;
	int		nb;
	int		i;
	int		tmp;

	i = 0;
	nb = get_nb_pipes(argv);
	nb++;
	// printf("mon nb dans init_pipe %i\n", nb);
	pipes = malloc(sizeof(t_pipes) * nb);
	if (!pipes)
		return (printf("problem malloc\n"), NULL);
	while (i < nb)
	{
		if (pipe(pipes[i].pipes) == -1)
			return (printf("pipe problem\n"), free(pipes), NULL);
		i++;
	}
	pipes[0].fd1 = argv[1];
	if (!pipes[0].fd1)
		return (printf("fd1 problem\n"), free(pipes), NULL);
	tmp = found_max(argv) - 1;
	pipes[0].fd2 = argv[tmp];
	if (!pipes[0].fd2)
		return (printf("fd2 problem\n"), free(pipes), NULL);
	// printf("pipes[0].fd2 = %s\n", pipes[0].fd2);
	return (pipes);
}

int	found_max(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		get_nb_pipes(char **argv)
{
	int		i;
	int		cpt;
	int		tmp;

	i = ((cpt = 0));
	tmp = 0;
	while (ft_strncmp(argv[i], "./Pipex", 8) != 0)
		i++;
	i = i + 2;
	while (i < found_max(argv))
	{
		tmp++;
		i++;
	}
	cpt = tmp - 2;
	// fprintf(stderr, "le nombre de pipe est de %d\n", cpt);
	return (cpt);
}
