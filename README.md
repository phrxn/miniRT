# miniRT

<p align="center">
  <img src="https://raw.githubusercontent.com/phrxn/phrxn/master/42/badges/minirte.png" />
</p>


## About

miniRT is a simple ray tracer. Using a file containing information about a "scene", it renders an image.

This scene file contains:

- A camera that points to a place in 3D space
- An ambient light source for the entire space
- One or more lights (spots) anywhere in the space, each light has its own color and intensity
- Zero or more objects (planes, cylinders and/or spheres) that contain their own characteristics, such as: color, coordinate, size and direction.

Based on the information provided by the scene file, miniRT uses the raytracing technique to create an image.

The miniRT is capable of:

Manage the light:
- Spot brightness
- Hard shadows
- Ambiance lighting
- Diffuse and specular lightning (phong effect)
- Multiple lights colors and intensity

Manage objects:
- Color
- Size
- intersection
- Direction

## Scene file object properties

#### Camera syntax

| Identity |  coordenates(X,Y,Z)  |  direction vector(X,Y,Z)  |      FOV     |
|----------|----------------------|---------------------------|--------------|
|    C     |        5,5,-5        |        -1, 1, 10          |      90      |

#### Ambient Light

| Identity |       intensity      |   Color (RGB)  |
|----------|----------------------|----------------|
|    A     |        0.4           |  0, 127, 255   |


#### Lighting (spot)

| Identity |  coordenates(X,Y,Z)  |  brightness ratio (0 - 1.0)   |  Color (RGB)  |
|----------|----------------------|-------------------------------|---------------|
|    L     |        0,10,-10      |              0.6              | 255, 255, 255 |

#### Sphere

| Identity |  coordenates(X,Y,Z)  |  diameter (float or int value)  |  Color (RGB)  |
|----------|----------------------|---------------------------------|---------------|
|    sp    |      0,1,-1          |            0.6  or   3          | 255, 255, 255 |

#### Plane

| Identity |  coordenates(X,Y,Z)  |  normalized normal vector |  Color (RGB)  |
|----------|----------------------|---------------------------|---------------|
|    pl    |      -2,1,3          |         1,0.5,0.5         | 255, 255, 255 |

#### Cylinder

| Identity |  coordenates(X,Y,Z)  |  normalized normal vector| diameter | height |  Color (RGB)  |
|----------|----------------------|--------------------------|----------|--------|---------------|
|    cy    |      -2,1,3          |      1,0.5,0.5           |   3.4    |    3   | 255, 255, 255 |

## Compile & Run

### Prerequisites

Before compiling the program, make sure you have installed on your computer:
- [ ] <code>make</code>
- [ ] <code>g++</code> (GNU Compiler Collection) or <code>clang</code>
- [ ] the following libraries: <code>xorg</code> <code>libxext-dev</code> <code>zlib1g-dev</code> <code>libbsd-dev</code>

If you are on Debian or derivatives, you can install these libraries as the command <code>apt</code>:<br>
``sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev``

### Compile

1. Download this repository: ``git clone https://github.com/phrxn/miniRT.git``

2. After downloading, enter the project folder ``cd miniRT``

3. Run ``make`` to compile the project

4. After running make, an executables will be created: <code>miniRT</code>

### Run

After the project compiles, the miniRT executable will be created. It expects a scene file (.rt) as a parameter, inside the <code>scenes</code> directory you can find several scenes to run.

5. Run: ``./miniRT file.rt``

:bangbang: The raytracing process is time-consuming, so the image may take a while to process since this project does NOT use GPU, but CPU to perform image calculations!

## Some Images

<p align="center">
  <img src="https://raw.githubusercontent.com/phrxn/miniRT/refs/heads/master/images/atom.png" />
  <br>
  <img src="https://raw.githubusercontent.com/phrxn/miniRT/refs/heads/master/images/complex2.png" />
  <br>
  <img src="https://raw.githubusercontent.com/phrxn/miniRT/refs/heads/master/images/composition.png" />
</p>

## Future Ideas

- [ ] Implement a "loading" to display how much of the image has been processed
- [ ] Use GPU instead of CPU to do the calculations