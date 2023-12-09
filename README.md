<div align="center">
 
 ![fdfm](https://github.com/facetint/FdF/assets/99668549/ba22aa6a-a221-4d98-927f-88cecb64b583)

 </div>

# FdF
In this project, the Minilibx library is used. The program takes a map as a parameter and creates a 3D representation of it.

🔹 This project is one of the projects that are going to prepare you for the next curriculum graphics project which is Cub3d or Minirt.


<img width="1276" alt="Ekran Resmi 2023-12-10 00 12 10" src="https://github.com/facetint/FdF/assets/99668549/feb7d55e-29c7-4c9b-b837-461353f394bd">



## MiniLibX

  # DESCRIPTION
  
  MiniLibX is an easy way to create graphical software, without any X-Window/Cocoa programming knowledge. It provides simple window creation, a drawing tool, image and basic events 
  management.

  -> mlx.h should be included for a correct use of the MiniLibX API. It only contains function prototypes, no structure is needed.

  # LIBRARY FUNCTIONS
 
First of all, you need to initialize the connection between your software and the display.The mlx_init() function will create this connection. No parameters are needed, and it will return a void* identifier, used for further calls to the library routines.

If mlx_init() fails to set up the connection to the graphical system, it will return NULL, otherwise a non-null pointer is returned as a connection identifier.

 # LINKING MINILIBX ON MACOSX

♦️ To use MiniLibX functions, you’ll need to link your software with the MiniLibX library, and several system frameworks:


<img width="429" alt="Ekran Resmi 2023-11-26 02 09 30" src="https://github.com/facetint/FdF/assets/99668549/b778098e-9893-4711-b08d-8b82cb7fe77c">


You may also need to specify the path to the MiniLibX library, using the -L flag.

# FUNCTIONS

🔲 **mlx_init()** : Used to start MiniLibX.

🔲 **mlx_new_window** : Creates a window and specifies the starting position of this window. Returns a pointer to the created window, which is then used to perform graphical operations on the window.We can give the window height, width and a title.

🔲**mlx_loop** : Used to start the interaction loop. This function is used to listen to window events, track user interaction and run a specific graphics application continuously.


<img width="646" alt="Ekran Resmi 2023-11-26 02 30 03" src="https://github.com/facetint/FdF/assets/99668549/2e34e52b-ddbd-4456-a9cf-a49f2db8022e">

🔲 **mlx_put_pixel** : paints the pixel at the specified coordinates in the specified window with the specified color.

🔲 **mlx_new_image** : This function creates a structure for storing and manipulating image data. This structure is used to create, modify and display graphical content.

🔲 **mlx_get_data_addr** : Used to retrieve the data address of an image and related information.

🔲**mlx_hook** : Hooking into events is one of the most powerful tools that MiniLibX provides. It allows you to register to any of the aforementioned events with the call of a simple hook registration function.

🔲**mlx_string_put** : Used to draw text on a window. This function is used to draw a string at specified coordinates and in a specific color.


<img width="946" alt="Ekran Resmi 2023-11-26 04 23 49" src="https://github.com/facetint/FdF/assets/99668549/63c0819e-7aa5-4af4-a738-ca4d72ad3b32">


## LINE DRAWING ALGORITHMS

   ## 1) DDA LINE ALGORITHM

   DDA (Digital Differential Analyzer) is a line drawing algorithm used in computer graphics to create a line segment between two specified endpoints. It is a simple and efficient algorithm that works by using the incremental difference between the x coordinates and y coordinates of the two endpoints to draw the line.
     
 🟥 The steps involved in DDA line generation algorithm are:

✣ Input the two endpoints of the line segment, (x1,y1) and (x2,y2).

✣ Calculate the difference between the x-coordinates and y-coordinates of the endpoints as dx and dy respectively.

✣ Calculate the slope of the line as m = dy/dx.

✣ Set the initial point of the line as (x1,y1).

✣ Loop through the x-coordinates of the line, incrementing by one each time, and calculate the corresponding y-coordinate using the equation y = y1 + m(x – x1).

✣ Plot the pixel at the calculated (x,y) coordinate.

✣ Repeat steps 5 and 6 until the endpoint (x2,y2) is reached.

DDA algorithm is relatively easy to implement and is computationally efficient, making it suitable for real-time applications. However, it has some limitations, such as the inability to handle vertical lines and the need for floating-point arithmetic, which can be slow on some systems.


   ## 2) BRESENHAM'S LINE ALGORITHM

   <img width="685" alt="Ekran Resmi 2023-11-19 21 09 09" src="https://github.com/facetint/FdF/assets/99668549/4220419b-e74d-4b1b-8bd0-12191363e8e0">


   Bresenham's line algorithm is a line drawing algorithm that determines the points of an n-dimensional raster that should be selected in order to form a close approximation to a 
 straight line between two points. It is commonly used to draw line primitives in a bitmap image (e.g. on a computer screen), as it uses only integer addition, subtraction, and bit 
 shifting.

 ▶︎ Bresenham’s algorithm only uses integer values, integer comparisons, and additions. This makes Bresenham’s algorithm more efficient, fast, and easier to calculate than the DDA algorithm.

 ▶︎ In this method, next pixel selected is that one who has the least distance from true line.

 ▶︎ The method works as follows:

   Assume a pixel P1'(x1',y1'),then select subsequent pixels as we work our may to the night, one pixel position at a time in the horizontal direction toward P2'(x2',y2').
   Once a pixel in choose at any step , The next pixel is :

   1- Either the one to its right (lower-bound for the line)
   2 - One top its right and up (upper-bound for the line)
    ▶︎ The line is best approximated by those pixels that fall the least distance from the path between P1',P2'.

 ▶︎ Once we choose a pixel, we have two possible pixels to select as the next pixel.
 
  1- Right side pixel (East — E)

  2- Upper right pixel (North East — NE)

 ![image](https://github.com/facetint/FdF/assets/99668549/c7b296df-3abd-4fad-9245-3364f58a73d8)
  
✣ Assume current pixel coordinates are (x, y)

✣ Select E as next pixel — increment only X value by 1 - (x + 1, y)

✣ Select NE as next pixel — increment both X and Y values by 1 - (x + 1, y + 1)

✣ To select the next pixel, we are using a decision parameter based on the slope error. If the slope error is greater than 0.5, the actual line is near the NE. The line is closer to E when the slope error is less than 0.5.

✣ At each step, we need to calculate the decision variable incrementally by adding △E or △NE depending on the choice of the pixel.

 🟥 The steps involved in Bresenham line generation algorithm are:

✣ Declare variable x1, x2, y1, y2, d, E, NE, dx, dy

✣ Enter value of x1,y1,x2,y2  ->>  (Where x1,y1are coordinates of starting point, And x2,y2 are coordinates of Ending point)

✣ First, we need to calculate dx and dy
         dx = x2-x1
         dy = y2-y1
        
✣ We use dx and dy values to calculate the initial decision variable (d). value of the decision variable is changed on each step.
         d = 2 * (dy - dx)

✣ Similarly, we need to calculate △E and △NE values. After the first initiation, these values are not changed.
        E = 2 * dy
        NE = 2 * (dy - dx)
        
✣ Now we have to decide what is the best pixel to choose next, NE or E. We are using the sign of decision parameter to take that decision.
         
   ♦️ Case 1: d ≤ 0

   We are going to select pixel E if the decision variable is negative or zero. In this scenario, we only increment the x value by 1 and calculate the new decision variable using △E.     Remember to keep y value as it is.
  
   d = d + E
   x = x + 1
 
✣ Case 2: d > 0

   When the decision variable is positive, select NE as the next pixel. In addition to calculating the new decision variable and increment the x value, need to increment the y value by 1.

   d = d + NE
   y = y + 1
   x = x + 1

Continue until x = x2

Up to now we only talked about the general scenario of this algorithm, where x1 < x2 and 0 < slope < 1. There are three other scenarios we need to consider.

▶︎ Case 1: x1 > x2

   In this case, we should draw the line from left to right. Take (X2, Y2) as the starting point and (X1, Y1) as the endpoint, then continue the Bresenham’s algorithm.

▶︎ Case 2: slope < 0

   In the case of a negative slope, we can get the line with a positive slope by reflecting the original line around the X-axis. We perform Bresenham’s algorithm to the line with a    
   positive slope and reflect back around the X-axis to get the pixels.

 🟥 EXAMPLE

 Draw a line from (x1, y1) to (x2, y2). In this scenario, we assume that the slope is negative.
 Now, instead of using Bresenham from (x1, y1) to (x2, y2), use the algorithm on (x1, -y1) to (x2, -y2). After calculating all the pixels from (x1, -y1) to (x2, -y2), we change the sign of the y values of all the pixels to get the pixels for the original line.

▶︎ Case 3: slope > 1

  In the case of the slope is greater than 1, we can use Bresenham’s algorithm by exchanging the x and y values. after the calculations, exchange the x and y values back to get the 
  pixels to display on the line.


## ROTATION MATRIX

![image](https://github.com/facetint/FdF/assets/99668549/4fd8aff4-5bce-417f-a97e-5f13a506f745)   

▶︎  In linear algebra, a rotation matrix is a transformation matrix that is used to perform a rotation in Euclidean space.Geometry provides us with four types of transformations, namely, rotation, reflection, translation, and resizing. Furthermore, a transformation matrix uses the process of matrix multiplication to transform one vector to another. When we want to alter the cartesian coordinates of a vector and map them to new coordinates, we take the help of the different transformation matrices.

## 3D Rotation

![image](https://github.com/facetint/FdF/assets/99668549/8e04f711-a3f7-4a3e-939f-0fa7a585adc5)


▶︎ In 3D space, rotation can occur about the x, y, or z-axis.

▶︎ Our goal is to construct three 3x3 matrices, one for each rotation about one of the axes.

## 3D Rotation Around the Z-Axis

<img width="252" alt="Ekran Resmi 2023-11-19 19 43 51" src="https://github.com/facetint/FdF/assets/99668549/5f5841d5-33f4-43a4-999c-123bb07fbe5a">

▶︎ We know that we don't want to affect the z-components of the other basis vectors as they rotate around the z-axis, so we put 0's in the z-components.

▶︎ We're using a left-handed coordinate system here, meaning that the x-axis points to the right, the y-axis up, and the z-axis into the screen.S


## 3D Rotation Around the X-Axis

<img width="254" alt="Ekran Resmi 2023-11-19 19 44 11" src="https://github.com/facetint/FdF/assets/99668549/434b620b-0f9e-49ca-ae81-c22d5063be8d">

Now we are interested in the y components and the z components. The x components of the basis vectors are fixed in place because we are rotating around the x axis.


## 3D Rotation Around the Y-Axis

<img width="254" alt="Ekran Resmi 2023-11-19 19 44 21" src="https://github.com/facetint/FdF/assets/99668549/a765ecf5-f202-4dde-b770-655de85e616a">


Now we are interested in the x components and z components. The x components of the basis vectors are fixed in place because we are rotating around the y axis.


