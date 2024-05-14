#include "world_test.h"
#include "world.h"

#include "assertz.h"
#include <string.h>

#include "dworld.h"

void 	create_world_test()
{
	t_world *world = dcreate_world();
	destroy_world(&world);
}

void	world_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "world_test") != 0)
		return ;
	create_title("world_test");

	create_world_test();
}