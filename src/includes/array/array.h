/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:13:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/30 17:24:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "libft.h"
# include "types.h"

t_list	*ft_lstget(t_list *head, t_uint index);
void	ft_lstsort(t_list *head, void sort_function(void *a, void *b));

#endif