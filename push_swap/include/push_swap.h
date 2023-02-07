/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:58 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/07 13:02:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	**chunk;
	int	chunk_len;
	int	nb_chunk;
}		t_stack;

// free :
// free le tableau d'argument
void	*free_strs(char ***strs);
// free les chunks
void	*free_chunk(t_stack *stack);
// free stack et tmp puis retourne null
void	*set_stack_free(char *tmp, int *stack);
// free la structure principale
int		free_all(t_stack *stack, int mod);

// check si les argument sont valide et renvoi un tableau d'entier
void	*check_error(char **argv, int argc, t_stack *stack);

// utils :
// converti les arguments en tableau d'entier
int		*set_stack(char ***strs, t_stack *stack);
// compte les nombre qu'il y a dans strs
int		count_nbr(char ***strs);
// renvoi la taille de stack
int		stack_len(int *stack);
// affiche la liste de nombre
void	display_stack(int *stack);
// set up les chunk
void	set_chunk(t_stack *stack);
void	set_chunk_max(t_stack *stack);

// cost
// apllique ra ou rra selon is_ra
void	loop_sort(int *stack, int is_ra, int nb);
void	loop_sort_b(int *stack, int is_rb, int nb);
// calcule s'il vaut mieux aplliquer ra ou rra renvoi 1 pour ra
int		is_ra(int index, int *stack);
// calule le cout de deplacement de index et le renvoi
// le retour de cette fonction est le nombre d'action 
// a aplliquer pour que le nombre a l'index donné soit en tete de list
int		cost(int index, int *stack);

// math

int		is_upper(int *stack, int j);
int		is_lower_of(int *stack, int of);
int		is_pair(int nb);
int		f_upper(int *stack);
int		f_lower(int *stack);

// sort :

void	sort_three(int *stack_a);
void	sort_five(int *stack_a, int *stack_b);
void	chunk_sort(t_stack *stack);

// action :
//Intervertit les 2 premiers éléments au sommet de la pile a.
void	sa(int *stack_a, int display);
//Intervertit les 2 premiers éléments au sommet de la pile b.
void	sb(int *stack_b, int display);
//sa et sb
void	ss(int	*stack_a, int *stack_b, int display);
//Décale d’une position vers le haut tous les élements de la pile a
//Le premier élément devient le dernier.
void	ra(int	*stack_a, int display);
//Décale d’une position vers le haut tous les élements de la pile b
//Le premier élément devient le dernier.
void	rb(int	*stack_b, int display);
//ra et rb
void	rr(int *stack_a, int *stack_b, int display);
// Décale d’une position vers le bas tous les élements de
//la pile a. Le dernier élément devient le premier.
void	rra(int *stack_a, int display);
// Décale d’une position vers le bas tous les élements de
//la pile b. Le dernier élément devient le premier.
void	rrb(int *stack_b, int display);
// rra et rrb
void	rrr(int	*stack_a, int *stack_b, int display);
// Prend le premier élément au sommet de b et le met sur a.
void	pa(int *stack_a, int *stack_b, int display);
// Prend le premier élément au sommet de a et le met sur b.
void	pb(int *stack_a, int *stack_b, int display);

#endif