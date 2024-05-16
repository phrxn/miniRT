/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:15:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 11:45:43 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"
# include "matrix.h"
# include "matrix_alloc.h"
# include "matrix_operations.h"
# include "libft.h"

t_transformation	*create_transformation()
{
	t_transformation	*transformation;

	transformation = ft_calloc(1, sizeof(*transformation));
	if (!transformation)
		return (NULL);
	transformation->translation = matrix_create_identity_4x4();
	transformation->rotation = matrix_create_identity_4x4();
	transformation->scale = matrix_create_identity_4x4();
	transformation->transformation = matrix_create_identity_4x4();
	transformation->transformation_inv = matrix_create_identity_4x4();
	transformation->tmp = matrix_create_identity_4x4();
	if (!transformation->translation || !transformation->rotation
		|| !transformation->scale || !transformation->transformation
		|| !transformation->transformation_inv || !transformation->tmp)
	{
		destroy_transformation(&transformation);
		return (NULL);
	}
	return (transformation);
}

void				destroy_transformation(t_transformation	**transf)
{
	t_transformation	*transf_tmp;

	if (!transf || !*transf)
		return ;
	transf_tmp = *transf;
	destroy_matrix(&transf_tmp->translation);
	destroy_matrix(&transf_tmp->rotation);
	destroy_matrix(&transf_tmp->scale);
	destroy_matrix(&transf_tmp->transformation);
	destroy_matrix(&transf_tmp->transformation_inv);
	destroy_matrix(&transf_tmp->tmp);
	free(transf_tmp);
	*transf = NULL;
}

void				fill_transformation_identity(t_transformation	*transf)
{
	matrix_fill_identity(transf->translation);
	matrix_fill_identity(transf->rotation);
	matrix_fill_identity(transf->scale);
	matrix_fill_identity(transf->transformation);
	matrix_fill_identity(transf->transformation_inv);
	matrix_fill_identity(transf->tmp);
}

int					make_transformation(t_transformation *transf)
{
	int	status;

	status = OK_OPERATION;
	status = matrix_mult(transf->translation, transf->rotation, transf->tmp);
	if (status != OK_OPERATION)
		return (status);
	status = matrix_mult(transf->tmp, transf->scale, transf->transformation);
	if (status != OK_OPERATION)
		return (status);
	status = matrix_inverse_4x4(transf->transformation, transf->transformation_inv);
	return (status);
}