/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:37 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/27 20:29:28 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Func/push_swap.h"

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char	*empty_str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
#endif