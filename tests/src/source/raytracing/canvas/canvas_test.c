#include "canvas_test.h"
#include "canvas.h"
#include "color.h"

//test
#include "assertz.h"

#include "string.h"

void	set_pixel_test()
{
	create_subtitle("set_pixel_test");

	//test1 endian == 1
	t_color colort; colort.red=1; colort.green = 0.5; colort.blue = 0.1;
	t_canvas *canvas = create_canvas(1);

	set_pixel(canvas, 0, 9, &colort);
	int color = canvas->pixels[9];
	int test1ColorExpected = 0b00000000111111110111111100011001;
	assert_svalue(test1ColorExpected, color, "test1 0-255-127-25");

	//test2 endian == 0
	t_color test2Colort; test2Colort.red=1; test2Colort.green = 0.5; test2Colort.blue = 0.1;
	t_canvas *test2Canvas = create_canvas(0);
	test2Canvas->pixels[9] = 0;
	set_pixel(test2Canvas, 0, 9, &test2Colort);
	int test2color = test2Canvas->pixels[9];
	int test2ColorExpected = 0b00011001011111111111111100000000;
	assert_svalue(test2ColorExpected, test2color, "test2 0-255-127-25  25-127-255-0");

	destroy_canvas(&canvas);
	destroy_canvas(&test2Canvas);
}

void canvas_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "canvas_test") != 0)
		return ;
	create_title("canvas_test");

	set_pixel_test();
}