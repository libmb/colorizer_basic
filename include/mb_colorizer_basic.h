/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_colorizer_basic.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/20 01:05:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_COLORIZER_BASIC_H
# define MB_COLORIZER_BASIC_H

# include "mb_colorizer_basic_types.h"

t_mb_colorizer_basic_color	mb_colorizer_basic(
								const t_mb_colorizer_basic *self,
								size_t iteration_count);

#endif
