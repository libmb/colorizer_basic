/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:44:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/23 00:18:07 by Juyeong Maing    ###   ########.fr       */
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
	size_t							i;
	const t_mb_colorizer_basic_node	*current_node;

	i = (size_t)-1;
	while (++i < self->count)
	{
		if (self->nodes[i].offset >= offset)
		{
			current_node = &self->nodes[(i + self->count - 1) % self->count];
			return ((t_local){
				&self->nodes[i],
				current_node,
				offset - current_node->offset
				+ (offset < current_node->offset) * self->length,
			});
		}
	}
	current_node = &self->nodes[self->count - 1];
	return ((t_local){
		&self->nodes[0],
		current_node,
		offset - current_node->offset,
	});
}

t_mb_colorizer_basic_color	mb_colorizer_basic(
	const t_mb_colorizer_basic *self,
	size_t iteration_count
)
{
	const t_local	l
		= find_node_and_offset(self, iteration_count % self->length);
	const float		ratio = (float)l.offset
		/ (float)(l.next_node->offset + self->length * (l.current_node->offset
				> l.next_node->offset) - l.current_node->offset);

	return ((t_mb_colorizer_basic_color){
		l.current_node->color.r * (1.0f - ratio) + l.next_node->color.r * ratio,
		l.current_node->color.g * (1.0f - ratio) + l.next_node->color.g * ratio,
		l.current_node->color.b * (1.0f - ratio) + l.next_node->color.b * ratio,
		l.current_node->color.a * (1.0f - ratio) + l.next_node->color.a * ratio,
	});
}
