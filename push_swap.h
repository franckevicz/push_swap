/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:05:52 by mfrankev          #+#    #+#             */
/*   Updated: 2017/03/05 13:12:18 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 11
# define SS 12

# define PA 2
# define PB 22

# define RA 3
# define RB 33
# define RR 36

# define RRA 4
# define RRB 44
# define RRR 48

# define PIVOT_RANGE (size / 2)
# define PIVOT1_RANGE ((size) / 3)
# define PIVOT2_RANGE ((size) * 2 / 3)
# define VALID_C ft_strstr("ra\brra\bsa\bpa\brb\brrb\bsb\bpb\brrr\bss" ,line)

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_lst
{
	int				val;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct	s_flags
{
	int	v;
	int c;
	int	fd_output;
	int	fd_input;
	int	n;

}				t_flags;

void			lst_add_elem(t_lst **head, int data);
void			lst_del_elem(t_lst **elem);
void			lst_rotate(t_lst **head);
void			lst_rev_rotate(t_lst **head);
void			lst_swap_first(t_lst *head);
void			print_stacks(t_lst *stack_a, t_lst *stack_b);
void			print_arrays(int *stack_a, int size_a, int *stack_b, \
				int size_b);
void			lst_push_from_stack(t_lst **donor, t_lst **patient);
void			lst_swap_both(t_lst **stack_a, t_lst **stack_b);
void			lst_rotate_both(t_lst **stack_a, t_lst **stack_b);
void			lst_rev_rotate_both(t_lst **stack_a, t_lst **stack_b);
int				lst_is_sorted(t_lst *head);
int				lst_is_rev_sorted(t_lst *head);
int				lst_is_nsorted(t_lst *head, int n);
int				lst_is_nrev_sorted(t_lst *head, int n);
void			lst_push_back(t_lst **head, int data);
t_flags			*parsing_flags(int *argc, char ***argv);
void			skip_argc_argv(int *argc, char ***argv, int times);
void			parce_flags_v_c_i_o(char **argv, t_flags *flags);
long long		ft_atoll(const char *str);
int				pushing_numbers(int argc, char **argv, t_lst **stack);
int				lst_search_val(t_lst *head, int value);
int				check_val(char *num, t_lst *stack);
int				lst_size(t_lst *head);
int				*lst_to_array(t_lst *head);
int				sort(t_lst **stack_a, t_lst **stack_b);
void			pivoting_3way(t_lst **stack_a, t_lst **stack_b);
void			pivoting(t_lst **stack_a, t_lst **stack_b);
void			get_pivot2(t_lst *stack_a, int *pivot1, int *pivot2);
int				get_pivot1(t_lst *stack_a);
void			haljava_sort(t_lst **stack_a, t_lst **stack_b);
void			poor_sort(t_lst **stack_a, t_lst **stack_b, int size);
void			rev_poor_sort(t_lst **stack_a, t_lst **stack_b, int size);
int				lst_is_num_bigger(t_lst *head, int i);
int				lst_is_num_smaller(t_lst *head, int i);
int				lst_is_num_smaller_in_n(t_lst *head, int i, int size);
int				lst_is_num_bigger_in_n(t_lst *head, int i, int size);
int				average_of_n_next(t_lst *head, int i);
void			gnome_sort(int *array, int size);
int				get_n_pivot1(t_lst *stack_a, int n);
void			rev_quicksort_stack(t_lst **stack_a, t_lst **stack_b, \
				int sort_len);
t_lst			*quicksort_stack(t_lst **stack_a, t_lst **stack_b, \
				int sort_len);
int				number_of_smaller_n_next(t_lst *head, int i, int size);
int				number_of_bigger_n_next(t_lst *head, int i, int size);
void			sort_three(t_lst **stack_a, t_lst **stack_b);
t_lst			*stack_operation(char *oper, t_lst **stack_a, t_lst **stack_b);
void			rev_sort_three(t_lst **stack_a, t_lst **stack_b);
void			short_sort_3(t_lst **stack_a);
void			short_rev_sort_3(t_lst **stack_b);
void			remove_rr_r(t_lst **commands);
void			optimize(t_lst **commands);
int				do_oper(char *oper, t_lst **stack_a, t_lst **stack_b);
void			print_operations(t_lst **operations);
void			double_opers(t_lst **commands);
void			del_list(t_lst **head);
void			push_operation(char *oper, t_lst **commands);
int				do_sorting(int *argc, char **argv, t_lst **stack_a,\
				t_flags *flags);
void			print_stacks_color(t_lst *stack_a, t_lst *stack_b);
void			print_arrays_color(int *stack_a, int size_a, int *stack_b, \
				int size_b);
int				short_sort(t_lst **stack_a, t_lst **stack_b, int sort_len);

#endif
