/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:23:06 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 17:22:33 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H

void	player_angle_key(int keycode, t_data *data);
void	player_movement(int keycode, t_data *data);
void	switch_mouse_state(t_data *data, int state);

#endif
