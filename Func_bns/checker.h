/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:37 by sgmih             #+#    #+#             */
/*   Updated: 2025/01/31 19:28:29 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				content;
	int				index;
	int				position;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char	*empty_str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	parse(char **av, t_list **stack_a);
void	check_exist(t_list **stack, int res, char **str);
void	check_empty(char *av, t_list **stack);
void	check_valid(char *av, t_list **stack);
char	**ft_split(char *s, char c);
void	fun_index(t_list **str, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_error(t_list **stack);
void	push(t_list **src, t_list **dst);
void	reverse_rotate(t_list **stack);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	ft_lstclear(t_list **lst);
void	free_leaks(t_list **stack);
t_list	*ft_lstmin(t_list *lst);
t_list	*ft_lstmax(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(t_list **stack_a, int content);
size_t	ft_strlen(const char *str);
int		ft_lstsize(t_list *lst);
int		ft_atoi(char *str, t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif