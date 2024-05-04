/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:28:29 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/01 23:09:37 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_maps
{
	char	**con;
	int		len;
	int		width;
	void	*img[10];
	void	*mlx;
	void	*mlx_win;
	int		pos_ex;
	int		pos_ey;
	int		pl_x;
	int		pl_y;
	int		count_c;
	int		index;
	int		enmy_x;
	int		enmy_y;
	int		index_enmy;
	int		i;
	int		count_enmy;
	int		count_move;
}	t_maps;

typedef struct s_var_rf
{
	int		fd;
	char	*s;
	char	*str;
	int		n;
	int		c_e;
	int		c_p;
	int		c_coll;
	int		c_o;
	int		c_c;
}	t_var_rf;

typedef struct s_vflood
{
	int		j;
	int		i;
	char	**str;
}	t_vflood;

#endif