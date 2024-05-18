#include "canvas.h"

#include <stdio.h>
#include <stdlib.h>


static void    save_one_color(FILE *file_ppm, t_canvas *canvas, int color)
{
	int r;
	int g;
	int b;
	if (canvas->is_endian)
	{
		r = ((color >> 16) & 0xFF); //r
		g = ((color >>  8) & 0xFF); //g
		b = (color & 0xFF); //b
	}
	else
	{
		b = ((color >>  24) & 0xFF);
		g = ((color >>  16) & 0xFF);
		r = ((color >>  8) & 0xFF);
	}
	fprintf(file_ppm, "%d %d %d ", r, g, b);
}

void    save_ppm(t_canvas *canvas)
{
	FILE *file_ppm;
	file_ppm = fopen("image_debug.ppm", "w+");
	if(!file_ppm)
		printf("error when open image_debug.ppm");

	size_t count = 0;
	size_t  colum_size = canvas->width - 1;
	unsigned int canvas_size = canvas->height * canvas->width;
	fprintf(file_ppm, "P3\n%d %d\n255\n", canvas->width, canvas->width);

	for(unsigned int count = 0; count < canvas_size; count++)
	{
		save_one_color(file_ppm, canvas, canvas->pixels[count]);
		if (count % canvas->width == colum_size)
           fprintf(file_ppm, "\n");
        else
            fprintf(file_ppm, " ");
	}

	fclose(file_ppm);
}