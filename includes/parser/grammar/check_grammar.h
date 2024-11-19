/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:31 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/17 17:18:04 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_GRAMMAR_H
# define CHECK_GRAMMAR_H

# include "libft.h"

# define OK_GRAMMAR 0
# define ERR_GRAMAR 1

int	check_list_line_grammar(t_list *list_line);

#endif