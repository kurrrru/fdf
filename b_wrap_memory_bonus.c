/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_wrap_memory_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:51:18 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_wrap_bonus.h"

void	*malloc_wrap(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ptr, size);
	return (ptr);
}

void	*realloc_wrap(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (old_size > new_size)
	{
		ft_putendl_fd(MSG_REALLOC_SIZE_ERROR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_ptr = malloc_wrap(new_size);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

char	**ft_split_wrap(char const *s, char c)
{
	char	**splited;

	splited = ft_split(s, c);
	if (splited == NULL)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	return (splited);
}
