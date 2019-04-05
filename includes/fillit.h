/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:57:08 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/05 18:57:37 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_tetra
{
	char			**coords;
	int				type;
	struct s_tetra	*next;
}				t_tetra;				

t_tetra			*init_pool(void);
t_tetra			*add_tetra(t_tetra *head);
t_tetra			*read_input(int fd, t_tetra *head);
t_tetra			*parse(char *input);

#endif
