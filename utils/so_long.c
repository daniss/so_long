#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    check(argc, argv);
}

/*int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *image_ptr;
    void *image2_ptr;
    int width, height;
    int i = 0;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 650, 250, "Affichage d'une image");

    image_ptr = mlx_xpm_file_to_image(mlx_ptr, "imagesxpm/grasstree.xpm", &width, &height);
    image2_ptr = mlx_xpm_file_to_image(mlx_ptr, "imagesxpm/carrots.xpm", &width, &height);

    if (image_ptr == NULL) {
        // Gestion de l'erreur de chargement de l'image
        printf("Erreur lors du chargement de l'image.\n");
        return 1;
    }
    while(i != 650)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, i, 0);
        i += 50;
    }
    i = 0;
    while(i != 250)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, i);
        i += 50;
    }
    i = 0;
    while(i != 650)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, i, 200);
        i += 50;
    }
    i = 0;
    while(i != 250)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 600, i);
        i += 50;
    }
    //mlx_put_image_to_window(mlx_ptr, win_ptr, image2_ptr, 0, 0);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_xpm_file_to_image(mlx_ptr, "imagesxpm/carrots.xpm", &width, &height), 750, 100);

    mlx_loop(mlx_ptr);

    mlx_destroy_image(mlx_ptr, image_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);

    return 0;
}*/
