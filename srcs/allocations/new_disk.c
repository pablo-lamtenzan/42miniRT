/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:23:39 by plamtenz          #+#    #+#             */
/*   Updated: 2020/07/04 14:24:51 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <allocations.h>
#include <stdlib.h>
#include <aux.h>

t_disk			*rt_new_disk(t_cyl cyl, bool side)
{
	t_disk		*new;

	if (!(new = malloc(sizeof(t_disk))))
		return (NULL);
	new->dir = cyl.dir;
	new->d = cyl.d;
	new->pos = vec_scale(cyl.dir, cyl.height / 2);
	if (side)
		new->pos = vec_sub(cyl.pos, new->pos);
	else
		new->pos = vec_add(cyl.pos, new->pos);
	new->color = cyl.color;
	return (new);
}

void			rt_disk_obj(t_obj *obj, t_disk *d)
{
	obj->type = DISK;
	obj->collision = collisions_disk;
	obj->get_normal = normal_disk;
	obj->target = d;
	obj->color = d->color;
}

bool			create_disks(t_scene *s, t_cyl cyl, t_obj *obj)
{
	t_obj		*disk1;
	t_obj		*disk2;

	if ((disk1 = rt_new_obj(DISK)) &&
			(disk2 = rt_new_obj(DISK)))
	{
		*disk1 = *obj;
		*disk2 = *obj;
		ft_objadd_back(&s->objs, disk1);
		rt_disk_obj(disk1, rt_new_disk(cyl, false));
		ft_objadd_back(&s->objs, disk2);
		rt_disk_obj(disk2, rt_new_disk(cyl, true));
		return (true);
	}
	return (false);
}
