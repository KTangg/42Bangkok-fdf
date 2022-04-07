# FDF - Fil De Fer (Wireframe model)

This project is about creating a "**simple**"(may be not) wireframe model representation of 3D landscape by projected various points (x, y, z) into orthographic projection
and display on screen.

## For 42-Student
***Do not just copy and paste*** this code for your own project. Make sure that you really understand the objective of 42-Project and learn what it's necessary.

## MinilibX (helper library from 42)
[MinilibX](https://github.com/42Paris/minilibx-linux), a simple X-Window (X11R6) programming API in C, designed for students, suitable for X-beginners.

## Program Input
FDF take *file.fdf* as input which will conntained (x, y) coordinate as (column, row) and the value represent (z, [optional RGB values])
```COMMANDLINE
$>cat 42.fdf
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
  0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
  0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
  0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
  0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
  0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
  0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
For more maps: [Map for FDF](https://github.com/KTangg/42Bangkok-fdf/files/8411040/maps.1.zip) 

## Projection Concept
FDF file which contain which is 3D coordinate (x, y, z) but computer display only got 2D coordinate (x, y). \
The 3D-Projection is a design technique used to display a n-dimensional object on a n − 1 dimensional surface.

Projection equation in my FDF project for Θ Rotate angle.
|***Project Coordinate***|***Equations***|
|-------------------|------------------------|
|x<sub>*proj*</sub>| *cos(Θ)* x<sub>*3d*</sub> - *sin(Θ)* y<sub>*3d*</sub> - (*cos(Θ)* - *sin(Θ)*)z<sub>*3d*</sub>|
|y<sub>*proj*</sub>| (*sin(Θ)* x<sub>*3d*</sub> + *cos(Θ)* y<sub>*3d*</sub> - (*sin(Θ)* + *cos(Θ)*)z<sub>*3d*</sub>) \* 0.707|

\* 0.707(sin(30) / sin(45)) is for isometric projection in y axis.

[More about Projection](https://en.wikipedia.org/wiki/3D_projection)

## World Map from my FDF
<img width="2560" alt="world_map_fdf" src="https://user-images.githubusercontent.com/77738298/161595861-10e37db0-b724-4369-9357-fdab59f5b119.png">

This map is generate from [42MapGenerator](https://github.com/jgigault/42MapGenerator)

## How to use

Compile fdf file
```SHELL
fdf$  make
```

Render fdf map
```SHELL
fdf$  ./fdf [file.fdf]
```

Feel that display window too small?? \
Edit these values in *includes/fdf.h*
```C
// Resolution of window
#define RESO_X 1200 // Edit 1200 to your choice for window width
#define RESO_Y 900 // Edit 900 to your choice for window height
```

### Key bindings
|***Key***|***Action***|
|---------|------------|
|Q|Rotate left|
|E|Rotate right|
|Left|Translate left|
|Right|Translate right|
|Up|Translate up|
|Down|Translate down|
|I|Isometric view|
|P|Parallel view|
|+|Increase extrude level|
|-|Decreasecrease extrude level|
|Mouse scroll up|Zoom in|
|Mouse scroll down|Zoom out|
|Esc|Exit program|

