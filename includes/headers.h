/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:26:43 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 00:39:32 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <mlx.h>
# include <stdbool.h> 
# include "structs.h"
# include "get_next_line.h"

void	search_place_for_enmy(t_maps *map);
void	hook_mlx(t_maps *map);
int		move(int key, t_maps *map);
int		count(t_maps *map);
int		_imags_(t_maps *map);
void	ft_free(t_maps *maps);
t_maps	*c_list(void);
size_t	ft_strlen(const char *s);
void	*f_free_split(char **arr, int n);
char	**ft_split(const char *s, char c, int *count_world);
int		cal_len(char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *s, int c);
bool	check_name(char *str);
bool	is_valide(t_var_rf *var);
bool	valide(t_maps *maps, t_var_rf *var, char *str);
bool	isone(char *str);
bool	read_file(char *str, t_var_rf *var, t_maps *maps, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**allocatematrix(int *rows, int *cols);
bool	valide_flood_fill(t_maps *maps, t_vflood v);
char	*g_n_l(int fd);
void	mlx(t_maps *map);
void	draw_window(t_maps *map);
int		ft_exit(t_maps *map);
void	initialization(t_maps *map, t_var_rf *var);
char	*ft_itoa(int n);
void	moves_enemy(t_maps *map);
void	hook_mlx(t_maps *map);
int		affiche_enmy(t_maps *map);
#endif