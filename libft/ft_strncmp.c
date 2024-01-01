/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:13:44 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/01 18:44:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	printf("%s\n%s\n%ld\n", s1, s2, n);
	i = 0;
	if ((!(s1) && !(s2)) || n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*int main()
{
	printf("%d\n",ft_strncmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("%d\n",strncmp("atoms\0\0\0\0", "atoms\0abc", 8));

}*/