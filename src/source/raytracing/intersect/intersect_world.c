#include "intersect_world.h"

#include "libft.h"
#include "shape.h"
#include "types.h"
#include "array.h"
#include "intersect.h"
#include "intersect_utils.h"

t_list	*intersect_world(t_world *world, t_ray *ray)
{
	t_list	*all_inter;
	t_list	*tmp_inter;
	t_shape *shape;
	t_uint	count;
	t_uint	size;

	all_inter = NULL;
	count = 0;
	size = ft_lstsize(world->shapes);
	while(count < size)
	{
		shape = (t_shape *)ft_lstget(world->shapes, count)->content;
		tmp_inter = intersect(shape, ray);
		if (ft_lstsize(tmp_inter))
			ft_lstadd_back(&all_inter, tmp_inter);
		count++;
	}
	ft_lstsort(all_inter, sort_intersection);
	return (all_inter);
}