/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cleaner.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:46:22 by tdechand          #+#    #+#             */
/*   Updated: 2023/02/17 12:56:04 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_CLEANER_H
# define STRING_CLEANER_H

char	*string_cleaner(char *dirty, t_data data);

typedef struct s_char
{
	char			c;
	struct s_char	*next;
	struct s_char	*prev;
}				t_char;

#endif
