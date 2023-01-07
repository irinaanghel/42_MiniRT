#include "../../inc/minirt.h"


void	ft_exit_check(char **row, t_minirt *minirt, char *message)
{
	if (row)
		ft_free_matrix(row);
	if (minirt)
	{
		free(minirt->ambient);
		free(minirt->camera);
		free(minirt->light);
		ft_free_pl(minirt->planes);
		ft_free_sp(minirt->spheres);
		ft_free_cy(minirt->cylinders);
		if (minirt->data)
			ft_free_matrix(minirt->data);
		free(minirt);
	}
	if (message)
		printf("%s", message);
	exit(0);
}