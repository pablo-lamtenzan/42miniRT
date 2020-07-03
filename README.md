# MiniRT
### A raytracer engine in C language coded from scracth using minilibX (42Paris's lib) as graphic lib.

> This index sucks

## Index
### I. Use
  #### a. [Specifications]
  #### b. [Run]
### II. Engine
  #### a) Shapes
  #### b) Lights
  #### c) Effects
  #### d) Multithread
### III. Interactions
  #### a) Mouse
  #### b) Keyboard
### IV. Input
  #### a) Shapes
  #### b) Unique parameters
  #### c) Extras

> Put Here an pretty image

## I. Use
### a) Specifications
This program works in MacOS and Linux, however the graphic lib (minilibX) doesn't work in all the linux architectures. I hardly recommend to run it into Ubunti/Xubuntu OS. The Linux minibibX doesn't work on Manjaro arch. If you want to run this program in a Darwin arch (MacOs) you need to use version of the graph lib for MacOS (avalaible in minilibX_MacOS dir) and change the value of the variable "LIBX" in the Makefile to "minilibX_MacOS".
### b) Run
For run the program you need to clone this git repository `git clone https://github/pablo-lamtenzan/42miniRT`.
Then if you did correctly the specifications part use the command `make` , this will compile the project sources converting them to relecatable objects files (*.o) and then, link this objects making an image as an executable file named "miniRT".
When you have your executable file you need a *.rt file as argument, this file contains the scene you want to raytrace `./miniRT <filename.rt>` (see later in Input part).
The result of the raytracing will be printed in a window that the program will open, but if you want to save the result as an image (*.bmp) you just have to add as second argument `--save`, so the long command will be `./miniRT <filename.rt> --save`. The name of the *.bmp file will be the same than the filename.

## II. Engine
**a) Shapes**
- Planes (1st degree)
- Squares (1st degree)
- Triangles (1st degree)
- Spheres (1st degree)
- Cylinders (1st degree) with disk in the sides (1 st degree)
- Cones (2nd degree)
- Cubes (1st degree and composed)
- Pyramids (1st degree and composed)

**b) Lights**
- Multispots
- Shadows
- Ambient light
- Colored ligth spots

**c) Effects**
- Mirror effect avalaible in all shapes
- Textures avalaible in spheres
- Color filters (r/g/b and sepia)
- Checkerboard color distruption
- Rainbow color distruption
- Antialisaing (1 to 6)
- Normal perturbation using the sin

**d) Multihreading**
- Uses 8 phreads to calculate the image reducing considerately the time for calculate a scene.

## III. Interactions
## a) Navigation
The imposed graph lib doesn't use the GPU so the execution time is a little bit long for able a smooth navigation. For solve that problem, during the navigation, the size and the quality of the image must be reduce. This process will start only if a you call the navigation mode. For exit the navigation mode use espace `esp`.

When you execute an acccion a charge bar will apear in the terminal (stdout). The next accion can't start until the current process haven't end so i strongly recommend to wait the end of all the charges bars.

### b) Mouse
You can modify the position of your current camera using `scroll whell`, `scroll whell up` will zoom in, vice versa `scroll well down` will zoom out.
For change the camera direction you have to able the the camera direction movement pushing into the scroll whell `scroll well push`, then clicking on `mouse left button` you will increase the change of the direction or `mouse mouse button` for decraese. For exit the camera direction mode push `scroll whell` again. The camera dirrection mode will change the camera dirrection to where the mouse is pointing.

### c) Keysboard
If you have more than 1 camera you can switch infinitely between them using `+` for go the right or `ivert pontuation:`\` for go to the left.
You can swicth into the shapes in the scene using `p` for going to the next and `o` for going back. The id of the shape will apear on the terminal (stdout) when you switch.
When you have a shape sellected (swicthed), you can effectuate a translation of the shape using `the directional arrows` and `n m` or a rotation using `w a s d z x`.

### Input 
> to do 



