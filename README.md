<div align="center">
 
 ![fdfm](https://github.com/facetint/FdF/assets/99668549/ba22aa6a-a221-4d98-927f-88cecb64b583)

 </div>

# FdF
In this project, the Minilibx library is used. The program takes a map as a parameter and creates a 3D representation of it.

🔹 This project is one of the projects that are going to prepare you for the next curriculum graphics project which is Cub3d or Minirt.

## LINE DRAWING ALGORITHMS

   ## 1) DDA LINE ALGORITHM

   DDA (Digital Differential Analyzer) is a line drawing algorithm used in computer graphics to create a line segment between two specified endpoints. It is a simple and efficient algorithm that works by using the incremental difference between the x coordinates and y coordinates of the two endpoints to draw the line.
     
The steps involved in DDA line generation algorithm are:

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
  
Assume current pixel coordinates are (x, y)

Select E as next pixel — increment only X value by 1 - (x+1, y)

Select NE as next pixel — increment both X and Y values by 1 - (x+1, y+1)

To select the next pixel, we are using a decision parameter based on the slope error. If the slope error is greater than 0.5, the actual line is near the NE. The line is closer to E when the slope error is less than 0.5.

At each step, we need to calculate the decision variable incrementally by adding △E or △NE depending on the choice of the pixel.
 
## ROTATION MATRIX

![image](https://github.com/facetint/FdF/assets/99668549/4fd8aff4-5bce-417f-a97e-5f13a506f745)   

▶︎  In linear algebra, a rotation matrix is a transformation matrix that is used to perform a rotation in Euclidean space.Geometry provides us with four types of transformations, namely, rotation, reflection, translation, and resizing. Furthermore, a transformation matrix uses the process of matrix multiplication to transform one vector to another. When we want to alter the cartesian coordinates of a vector and map them to new coordinates, we take the help of the different transformation matrices.

## 3D Rotation

![image](https://github.com/facetint/FdF/assets/99668549/8e04f711-a3f7-4a3e-939f-0fa7a585adc5)


▶︎ In 3D space, rotation can occur about the x, y, or z-axis.

▶︎ Our goal is to construct three 3x3 matrices, one for each rotation about one of the axes.

## 3D Rotation Around the Z-Axis

<img width="252" alt="Ekran Resmi 2023-11-19 19 43 51" src="https://github.com/facetint/FdF/assets/99668549/5f5841d5-33f4-43a4-999c-123bb07fbe5a">


▶︎ We're using a left-handed coordinate system here, meaning that the x-axis points to the right, the y-axis up, and the z-axis into the screen.




## 3D Rotation Around the X-Axis

<img width="254" alt="Ekran Resmi 2023-11-19 19 44 11" src="https://github.com/facetint/FdF/assets/99668549/434b620b-0f9e-49ca-ae81-c22d5063be8d">


## 3D Rotation Around the Y-Axis

<img width="254" alt="Ekran Resmi 2023-11-19 19 44 21" src="https://github.com/facetint/FdF/assets/99668549/a765ecf5-f202-4dde-b770-655de85e616a">



