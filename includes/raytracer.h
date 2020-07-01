#ifndef RAYTRACER_H
# define RAYTRACER_H

#include <ft_color.h>
#include <stdbool.h>
#include <../minilibX/mlx.h>

#include <stdio.h>

#define NB_PTHREADS         8
#define REBOUNDS_MIRROR		10

#define SAVE                1
#define RT_AMB              2
#define RT_RES              4
#define RT_AA               8
#define RT_FILTER           16

#define DAMIER              1
#define RAINBOW             2
#define UVMAPPING           4
#define MIRROR              8
#define NORMAL_DIST         16

#define RED                 10
#define GREEN               11
#define BLUE                12
#define BLACK_AND_WHITE     13
#define SEPIA               14 

typedef struct              s_light
{
    void                    *next;
    void                    *start;
    t_vec3                  pos;
    double                  intensity;
    t_color_precision       color;
}                           t_light;

typedef struct              s_cam
{
    void                    *next;
    void                    *back;
    void                    *start;
    t_vec3                  pos;
    t_vec3                  dir;
    double                  fov;
}                           t_cam;

typedef struct              s_uvmap
{
    void                    *addr;
    t_color                 *img;
    int                     x;
    int                     y;
}                           t_uvmap;

typedef struct              s_obj
{
    char                    type;
    void                    *target;
    void                    *start;
    bool				    (*collision)(t_ray r, void *obj, double *t);
	t_vec3			        (*get_normal)(void *s, t_ray r);
    void                    *next;
    void                    *back;
    t_color_precision       color;
    t_color_precision       color_damier;
    t_color_precision       texture;
    void                    *mlx_ptr;
    double                  dist;
    char                    effect;
    double                  rainbow;
    int                     rb;
    int                     ch;
    t_uvmap                 *uvmap;
}                           t_obj;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
    void                    *img;
    t_color                 *end_buff;
	int						max_h;
	int						max_w;
    t_color_precision       *buff;
}							t_mlx;

typedef struct              s_scene
{
    t_cam                   *cams;
    t_obj                   *objs;
    t_light                 *lights;
    t_color_precision       amb_color;
    double                  amb_intensity;
    char                    *filename;
    t_mlx                   *image;
    unsigned                index;
    t_vec3                  p;
    t_vec3                  n;
    double                  aa;
	int						threads;
    int                     mouse;
    int                     aarainbow;
    char                    filter;
    char                    flags;
}                           t_scene;


bool                        parser(int ac, char **argv, t_scene *s);
int                        	load_image(void *s);
void                        *engine(void *fill);
void                        *engine_hooks(void *fill);
bool                        check_obj_collision(t_scene *s, t_obj **near, t_ray ray);
bool                        check_light_collision(t_scene *s, double *min, t_ray ray);
void                        export_bmp(t_scene *s);
bool                        calc_image_hooks(t_scene *s);
int 		                calc_image(t_scene *s);
t_scene      				*copy_structure(t_scene *s);

t_color                     filter(t_scene *s, t_color c);
void                        effect(t_scene *s, t_obj *obj);
void                        damier(t_scene *s, t_obj *obj);
void                        rainbow(t_scene *s, t_obj *obj);
t_color_precision           uvmapping(t_scene *s, t_obj *obj);

t_color                     precision_to_rgb(t_scene *s, t_color_precision c);
void                        copy_buff(t_scene *s);

#endif
