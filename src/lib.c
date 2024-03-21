/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:44:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/22 01:07:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_colorizer_basic.h"
#include "mb_colorizer_basic_types.h"

typedef struct s_local
{
	const t_mb_colorizer_basic_node	*next_node;
	const t_mb_colorizer_basic_node	*current_node;
	size_t							offset;
}	t_local;

static t_local	find_node_and_offset(
	const t_mb_colorizer_basic *self,
	size_t offset
)
{
	size_t	i;
	size_t	sum;

	sum = 0;
	i = (size_t)-1;
	while (++i < self->count)
	{
		sum += self->nodes[i].offset;
		if (sum >= offset)
		{
			return ((t_local){
				&self->nodes[i],
				&self->nodes[(i + 1) % self->count],
				offset - (sum - self->nodes[i].offset)
			});
		}
	}
	return ((t_local){
		&self->nodes[0],
		&self->nodes[1 % self->count],
		0
	});
}

t_mb_colorizer_basic_color	mb_colorizer_basic(
	const t_mb_colorizer_basic *self,
	size_t iteration_count
)
{
	const t_local	l
		= find_node_and_offset(self, iteration_count % self->length);
	const float		ratio = (float)l.offset / (float)l.current_node->offset;

	return ((t_mb_colorizer_basic_color){
		l.current_node->color.r * (1.0f - ratio) + l.next_node->color.r * ratio,
		l.current_node->color.g * (1.0f - ratio) + l.next_node->color.g * ratio,
		l.current_node->color.b * (1.0f - ratio) + l.next_node->color.b * ratio,
		l.current_node->color.a * (1.0f - ratio) + l.next_node->color.a * ratio,
	});
}
