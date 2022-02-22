#include "imlib_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static char sprint_buf[1024];
int imlib_printf(int level,char *fmt, ...)
{
va_list args;
int n;
va_start(args, fmt);
n = vsprintf(sprint_buf, fmt, args);
va_end(args);
    switch (level)
    {
    case 0:
        fprintf(stderr,"%s", sprint_buf);
        abort();
        break;
    case 5:
        fprintf(stdout,"%s", sprint_buf);
        break;
    default:
        break;
    }
return n;
}







#include "imlib.h"




void imlib_printf_image_info(void *img)
{
    image_t *imlib_img = (image_t*)img;
    switch (imlib_img->pixfmt)
    {
    case PIXFORMAT_GRAYSCALE:
        printf("imlib image info:\n\t\twidth:%d height:%d mode:PIXFORMAT_GRAYSCALE size:%d pixels:%p is_data_alloc:%d \n",imlib_img->w, imlib_img->h, imlib_img->size, imlib_img->pixels, imlib_img->is_data_alloc);
        break;
    case PIXFORMAT_RGB565:
        printf("imlib image info:\n\t\twidth:%d height:%d mode:PIXFORMAT_RGB565 size:%d pixels:%p is_data_alloc:%d \n",imlib_img->w, imlib_img->h, imlib_img->size, imlib_img->pixels, imlib_img->is_data_alloc);
        break;
    case PIXFORMAT_RGB888:
        printf("imlib image info:\n\t\twidth:%d height:%d mode:PIXFORMAT_RGB888 size:%d pixels:%p is_data_alloc:%d \n",imlib_img->w, imlib_img->h, imlib_img->size, imlib_img->pixels, imlib_img->is_data_alloc);
        break;
    default:
        printf("image is not info\n");
        break;
    }
}


#ifdef ENABLE_MAIX_IMAGE_CONSIVE

#include "libmaix_image.h"


void* imlib_image2maix_image(void* img)
{
    libmaix_image_t *maix_img = NULL;
    image_t *imlib_img = (image_t*)img;
    switch (imlib_img->pixfmt)
    {
    case PIXFORMAT_GRAYSCALE:
        maix_img = libmaix_image_create(imlib_img->w, imlib_img->h, LIBMAIX_IMAGE_MODE_GRAY, LIBMAIX_IMAGE_LAYOUT_HWC, imlib_img->data, false);
        return maix_img;
        break;
    case PIXFORMAT_RGB565:
        maix_img = libmaix_image_create(imlib_img->w, imlib_img->h, LIBMAIX_IMAGE_MODE_RGB565, LIBMAIX_IMAGE_LAYOUT_HWC, imlib_img->data, false);
        return maix_img;
        break;
    case PIXFORMAT_RGB888:
        maix_img = libmaix_image_create(imlib_img->w, imlib_img->h, LIBMAIX_IMAGE_MODE_RGB888, LIBMAIX_IMAGE_LAYOUT_HWC, imlib_img->data, false);
        return maix_img;
        break;
    default:
        return maix_img;
        break;
    }
}
void* maix_image2imlib_image(void* img)
{
    libmaix_image_t *maix_img = (libmaix_image_t*)img;
    image_t *imlib_img = NULL;
    switch (maix_img->mode)
    {
    case LIBMAIX_IMAGE_MODE_GRAY:
        imlib_img = imlib_image_create(maix_img->width, maix_img->height, PIXFORMAT_GRAYSCALE, maix_img->width * maix_img->height, maix_img->data, false);
        break;
    case LIBMAIX_IMAGE_MODE_RGB565:
        imlib_img = imlib_image_create(maix_img->width, maix_img->height, PIXFORMAT_RGB565, maix_img->width * maix_img->height * 2, maix_img->data, false);
        break;
    case LIBMAIX_IMAGE_MODE_RGB888:
        imlib_img = imlib_image_create(maix_img->width, maix_img->height, PIXFORMAT_RGB888, maix_img->width * maix_img->height * 3, maix_img->data, false);
        break;
    default:
        break;
    }
    return imlib_img;
}
#endif
