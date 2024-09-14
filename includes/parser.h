/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:09:26 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/14 18:10:03 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef parser_h
# define parser_h

int	open_file(char *argv, int *fd);
int	file_is_ocult(char *argv);
int	check_file(char *argv);

#endif
