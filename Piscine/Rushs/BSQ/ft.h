/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:16:15 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:05 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_filedata
{
	int		file_length;
	char	*file_name;
	char	*file_content;
}	t_filedata;

typedef struct s_treat_arr
{
	int		start_pos;
	char	*untouch_a;
	char	*treated_arr;
}	t_treat_arr;

typedef struct s_resolv
{
	char	**parsed_arr;
	char	**resolv_arr;
	int		x;
	int		y;
	int		x1;
	int		y1;
}	t_resolv;

void affichage(char **str);

int			length_file(char *file_name);
t_filedata	*init_file_struct(char *file_name);
t_filedata	*get_file_data(t_filedata *file_s);
t_treat_arr	*init_resol_arr_struct(t_filedata *file_d);
t_treat_arr	*fix_array(t_treat_arr *array);
t_resolv	*init_resolv_struct(t_treat_arr *array);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
t_resolv	*parsed_str(t_treat_arr *array, t_resolv *resolv_s);
int			check_error(t_treat_arr *array);
t_resolv 	*resolv_enigma(t_resolv *resolv_s);
t_resolv    *check_square(t_resolv *resolv_s, int j, int i);
t_resolv    *check_bottom(t_resolv *resolv_s, int j, int i);
t_resolv    *check_backward(t_resolv *resolv_s, int j, int i);
t_resolv    *check_upward(t_resolv *resolv_s, int j, int i);
t_resolv    *check_center(t_resolv *resolv_s, int j, int i);
char		**ft_split(char *str, char *charset);
void		ft_putstr(char *str);
int			ft_strlen(char *str);

#endif
