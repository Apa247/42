int	main(int argc, char **argv)
{
	void    *mlx;
    void    *mlx_w;

    mlx = mlx_init();
    mlx_w =  mlx_new_window(mlx, 9 * 47, \
		9 * 47, "So_lon");
	printf("%s\n", "OK");
    mlx_loop(mlx);
	return (0);
}