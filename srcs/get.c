#include "../includes/minirt.h"

//function that takes the values for the light ratio
//and transforms them with atof and inserts 
//them in the corresponding elements of the struct obj
void	ft_get_l_r(char *l_r, t_main *m, int i)
{
	float	f_l_r;

	if (ft_valid_char_fl(l_r))
		exit_error_free("L_R : Invalid input\n", m->scn.obj);
	f_l_r = ft_atof(l_r);
	if (f_l_r < 0 || f_l_r > 1)
		exit_error_free("L_R : Input not in range\n", m->scn.obj);
	m->scn.obj[i].light_r = f_l_r;
}

//function that takes the values for the rgb 
//and transforms them with atof and inserts 
//them in the corresponding elements of the struct obj
void	ft_get_rgb(char *rgb, t_main *m, int i)
{
	char	**split;
	int		j;
	int		tmp;

	j = 0;
	if (ft_valid_char_rgb(rgb))
		exit_error_free("RGB : Invalid input : char\n", m->scn.obj);
	split = ft_split(rgb, ',');
	if (ft_check_size_tab(split, 3))
	{
		ft_tab_free((void **)split);
		exit_error_free("RGB : Invalid input : nb\n", m->scn.obj);
	}
	while (split[j])
	{
		tmp = ft_atoi(split[j]);
		if (tmp < 0 || tmp > 255)
			free_split_exit(split, m->scn.obj, "RGB : Invalid input : range\n");
		j++;
	}
	m->scn.obj[i].rgb.x = ft_atof(split[0]) / 255;
	m->scn.obj[i].rgb.y = ft_atof(split[1]) / 255;
	m->scn.obj[i].rgb.z = ft_atof(split[2]) / 255;
	ft_tab_free((void **)split);
}

//function that takes the values for the coordinates
//and transforms them with atof and inserts 
//them in the corresponding elements of the struct obj
void	ft_get_pos(char *coord, t_main *m, int i)
{
	char	**split;
	int		j;

	j = 0;
	split = ft_split(coord, ',');
	while (j < 3)
		if (ft_valid_char(split[j++]))
			free_split_exit(split, m->scn.obj, "COORD:Invalid input:char\n");
	if (ft_check_size_tab(split, 3))
		free_split_exit(split, m->scn.obj, "COORD : Invalid input : nb\n");
	m->scn.obj[i].pos.x = ft_atof(split[0]);
	m->scn.obj[i].pos.y = ft_atof(split[1]);
	m->scn.obj[i].pos.z = ft_atof(split[2]);
	ft_tab_free((void **)split);
}

//function that takes the values for the vectors
//and transforms them with atof and inserts 
//them in the corresponding elements of the struct obj
void	ft_get_vec(char *coord, t_main *m, int i)
{
	char	**split;
	int		j;
	float	p;

	j = -1;
	split = ft_split(coord, ',');
	if (ft_check_size_tab(split, 3))
		free_split_exit(split, m->scn.obj, "V3d : Invalid input nb arg\n");
	while (split[++j])
	{
		if (ft_valid_char(split[j]))
			free_split_exit(split, m->scn.obj, "V3d: Invalid char\n");
		p = ft_atoi(split[j]);
		if (p < -1 || p > 1)
			free_split_exit(split, m->scn.obj, "V3d : Invalid input : range\n");
	}
	m->scn.obj[i].vec.x = ft_atof(split[0]);
	m->scn.obj[i].vec.y = ft_atof(split[1]);
	m->scn.obj[i].vec.z = ft_atof(split[2]);
	ft_tab_free((void **)split);
}

/* function that takes the values for the FOV
* and transforms them with atof and inserts 
* them in the corresponding elements of the struct obj
* check if the char respects the formatting for FOV 
* -> range 0-180
*/
void	ft_get_fov(char *fov, t_main *m, int i)
{
	int	fov_i;
	int	j;

	j = -1;
	while (fov[++j])
	{
		if (!isdigit(fov[j]))
			exit_error_free("FOV : Invalid input\n", m->scn.obj);
	}
	fov_i = ft_atoi(fov);
	if (fov_i > 180)
		exit_error_free("FOV : Invalid input\n", m->scn.obj);
	m->scn.obj[i].fov = fov_i;
}
