/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_colorizer_basic_types.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:38:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/20 01:06:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_COLORIZER_BASIC_TYPES_H
# define MB_COLORIZER_BASIC_TYPES_H

# include <stddef.h>

typedef struct s_mb_colorizer_basic_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_mb_colorizer_basic_color;

typedef struct s_mb_colorizer_basic_node
{
	size_t						offset;
	t_mb_colorizer_basic_color	color;
}	t_mb_colorizer_basic_node;

typedef struct s_mb_colorizer_basic
{
	size_t						length;
	size_t						count;
	t_mb_colorizer_basic_node	*nodes;
}	t_mb_colorizer_basic;

#endif
