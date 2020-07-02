# MiniRT
### A raytracer engine in C language coded from scracth using minilibX (42Paris's lib) as graphic lib.

## Index
### I. Use
### II. Engine
### III. Interactions
### IV. Input

## I. Use
### Specifications
This program works in MacOS and Linux, however the graphic lib (minilibX) doesn't work in all the linux architectures. I hardly recommend to run it into Ubunti/Xubuntu OS. Its doesn't work on Manjaro arch. If you want to run this program in a Darwin arch (MacOs) you need to use version of the graph lib for MacOS (avalaible in minilibX_MacOS dir) and change the value of the variable "LIBX" in the Makefile to minilibX_MacOS.
### Run
For run the program you need to clone this git repository `git clone https://github/pablo-lamtenzan/42miniRT`.
Then if you did correctly the specifications part use the command `make` , this will compile the project sources into relecatable objects files (*.o) and then link this objects making an image of that as an executable file named "miniRT".
When you have your executale file you need a *.rt file as argument, this file contains the scene you want to raytrace `./miniRT <filename.rt>` (see later in Input part).
The result of the raytracing will be printed in a window that the program will open, but if you want to save the result as an image (*.bmp) you just have to add as second argument `--safe`, so the long command will be `./miniRT <filename.rt> --save`. The name of the *.bmp file will be the same than the filename.

## II. Engine
**Shapes**
- Planes (1st degree)
- Squares (1st degree)
- Triangles (1st degree)
- Spheres (1st degree)
- Cylinders (1st degree) with disk in the sides (1 st degree)
- Cones (2nd degree)
- Cubes (1st degree and composed)
- Pyramids (1st degree and composed)

**Lights**
- Multispots
- Shadows
- Ambient light
- Colored ligth spots

**Effects**
- Mirror effect avalaible in all shapes
- Textures avalaible in spheres
- Color filters (r/g/b and sepia)
- Checkerboard color distruption
- Rainbow color distruption
- Antialisaing (1 to 6)
- Normal perturbation using the sin

**Multiphreading**
Uses 8 phreads to calculate the image reducing considerately the time for calculate a scene.





