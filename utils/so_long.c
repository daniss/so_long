#include "../includes/so_long.h"

/*int main(int argc, char **argv)
{
	check(argc, argv);
    mlx_clear_window();
}*/

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    // Initialisation de MinilibX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return 1;

    // Création d'une fenêtre de 800x600 pixels
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ma première fenêtre MinilibX");
    if (!win_ptr)
        return 1;

    // Boucle de gestion des événements (pour garder la fenêtre ouverte)
    mlx_loop(mlx_ptr);

    return 0;
}