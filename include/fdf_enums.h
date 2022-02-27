/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 02:30:58 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 02:30:58 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ENUNS_H
#define FDF_ENUNS_H

typedef enum 
{
	MLX_EVENT_KEYDOWN = 2,
	MLX_EVENT_KEYUP = 3,
	MLX_EVENT_DESTROY = 17,
} MLX_EVENT;

typedef enum 
{
	KEY_ESCAPE = 65307,
} KEYS;

typedef enum 
{
	EXIT_CODE_NORMAL = 0,
	EXIT_CODE_MALLOC_FAIL = 1,
} EXIT_CODE;

#endif