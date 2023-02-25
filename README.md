# picfilters

picfilters.cpp is this project's main file. It takes a .ppm image file and can transform it into a new .ppm image file. Transformations include color inversion, horizontal/vertical flipping, etc.

picfilters calls helper functions from ppmio, which can read from and write to .ppm files. 

picfilters calls helper functions from image, which is where the code for each transformation lives. 

The test_data folder contains sample .ppm files and what their transformations look like.

testFilters is a bash script for testing whether my program's output matches what the expected transformations should look like.
