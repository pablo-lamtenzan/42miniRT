# MiniRT
### A raytracer engine in C language coded from scracth using minilibX (42Paris's lib) as graphic lib.

[42 Subject of the project](https://cdn.intra.42.fr/pdf/pdf/10458/en.subject.pdf)

## Index
### I. Use
- #### a. Specifications
- #### b. Run
### II. Engine
- #### a) Shapes
- #### b) Lights
- #### c) Effects
- #### d) Multithread
### III. Interactions
- #### a) Mouse
- #### b) Keyboard
### IV. Input
- #### a) Shapes
- #### b) Unique parameters
- #### c) Extras

![sc5](https://github.com/pablo-lamtenzan/42miniRT/blob/master/test.png)

## I. Use
### a) Specifications
This program works in MacOS and Linux, however the graphic lib (minilibX) doesn't work in all the linux architectures. I hardly recommend to run it into Ubunti/Xubuntu OS. The Linux minibibX doesn't work on Manjaro arch. If you want to run this program in a Darwin arch (MacOs) you need to use version of the graph lib for MacOS (avalaible in minilibX_MacOS dir) and change the value of the variable "LIBX" in the Makefile to "minilibX_MacOS".
[Oficial repository minilibX-Linux](https://github.com/42Paris/minilibx-linux)
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
For change the camera direction you have to able the the camera direction movement pushing into the scroll whell `scroll well push`, then clicking on `mouse left button` you will increase the change of the direction or `mouse mouse button` for decrease. For exit the camera direction mode push `scroll whell` again. The camera dirrection mode will change the camera dirrection to where the mouse is pointing.

### c) Keysboard
If you have more than 1 camera you can switch infinitely between them using `+` for go the right or `ivert pontuation:`\` for go to the left.
You can swicth into the shapes in the scene using `p` for going to the next and `o` for going back. The id of the shape will apear on the terminal (stdout) when you switch.
When you have a shape sellected (swicthed), you can effectuate a translation of the shape using `the directional arrows` and `n m` or a rotation using `w a s d z x`.

## IV. Input 
The program is only able to read with the rt extension (*.rt), this files should follow an specific sintax, this sintax will be explained in this part. All errors is the sintax are correctly handled so the program will just return an error mesage.
### Shapes
For define a shape you must know at least the `position` and the `color`, both parameters are global for all the shapes.
Other shapes will need the `direction`, the `height` or the `diameter` too. The sintax of this properties depend of the type of the value `,` separator will be used for separete the `values` and `.` will be used to define a float.
The `espace` will be used for separate the parameters as `position` `esp` `direction` for example.

***The sintax is:***
- position: `float, float, float` (x, y, z)
- direction: `float, float, float` between -1 and 1 (x, y, z)
- color: `int, int, int` from 0 to 255 (r/g/b)
- height: `float` only positive values
- diameter: `float` only positive values
- base height: `float` only positive values
- curvature: `float` only positive values

For define a camera or a light the same `position`, `direction`, `color` format must be used. However for define lights or cameras we need the `intensitespacey` and the `field of view`.

***The sintax is:***
- intensity: `float` between 0 and 1
- field of view (fov): `int` between 0 and 180

Each shape, camera or light has an identifier this id will be the first element of the line. One parameter per line is handled only.

***Camera and lights***
- Camera: `c position direction fov`
- Light: `l position intensity color`

***Shapes***
- Sphere: `sp position diameter color`
- Plane: `pl position direction color`
- Square: `sq position direction height color`
- Triangle: `postion` `position` `position` (position of the 3 corners)
- Cylinder: `position direction diameter height color`
- Cone: `position direction curvature height color`
- Cube: `position direction base_height color`
- Pyramid: `position direction base_height height color`

### Unique parameters
This parameters define properties about the scene. They can only be denifed one time each one per input file.

***Defined as:***
- Resolution: `R int int` (weight and height, the size of the output window)
- Ambient light: `A intensity color`
- Antialisaing: `aa int` (1 to 6)
- Filter: `f value` (value coulb be r/g/b/s, red, green, blue, sepia)

### Extras
At the end of the definition of a shape you can add extra values, this extra values will modify the shape color.

***Defined as***
- Mirror: `m` works in all the shapes and put effect mirror in the current shape
- Rainbow: `r intensity` replace color by a degraded
- Checkerboard: `d color height` create squares using the color value and the given color, the height is the side of the squares
- Textures: `tx path` only work in spheres with xmp extension textures files
- Normal perturbation: `Uppercasse alphabetical char`

Example: `sp 0,0,0 50 255,0,255 m` will define a mirror in the sphere,
          `sp 0,0,0 50 255,0,255 M` will define a mirror in the sphere + normal perturbation,
          `sp 0,0,0 50 255,0,255 H` will define a sphere with normal perturbation.




