/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:29:18 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/05 20:16:59 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

/* Initialize the 'pool' list. */
t_tetra		*init_pool(void)
{
	return (head);
}

/* Creates + allocate a new 'tetra' node and add it to the current 'pool' list. */
t_tetra		*add_tetra(t_tetra *head)
{
	t_tetra	*node;
	t_tetra *roam;
	int		i;

	if (!(node = malloc(sizeof(node))))
		return (NULL);
	node->coords = malloc(sizeof(node->coords) * 5);
	node->coords[4] = NULL;
	i = 0;
	while (i < 4)
	{
		node->coords[i] = malloc(sizeof(*(node->coords)) * 3);
		node->coords[i][2] = '\0';
	}
	roam = head;
	while (roam->next != NULL)
		roam = roam->next;
	roam->next = node;
	return (head);
}

t_tetra		*read_input(int fd, t_tetra *head)
{
	int		i;
	char	*line;
	t_tetra	*ptr;

	i = 0;
	ptr = head;
	while (get_next_line(fd, &line) > 0)
	{
		if (i && (i + 1) % 5 == 0)
		{
			//Seulement un \n, sinon erreur!
			head = add_tetra(head);
			ptr = ptr->next;
			
		}
		//VERIFIE LA VALIDITE DU DERNIER TETRA CHAQUE FOIS QUE NECESSAIRE.
		i++;
	}
	return (head);
}

/* main parsing function ("dispatch") */
t_tetra		*parse(char *input)
{
	int		fd;
	t_tetra *pool;

	pool = NULL;
	if ((fd = open(input, O_RDONLY)) < 0)
	{
		ft_putstr("error: failed to open the input file.\n");
		return (NULL);
	}
	pool = read_input(fd, pool);
	close(fd);
	return (pool);
}

int			main(int argc, char **argv)
{
	t_tetra *pool;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <input_file>\n");
		return (1);
	}
	if ((pool = parse(argv[1])) == NULL)
	{
		return (1);
	}
	return (0);
}
