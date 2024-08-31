#include <iostream>
#include <cmath>
#include <cstdlib>
#include<cstdio>
typedef float Point[3];


void perProject(float p_x, float p_y, float p_z, float& x_proj, float& y_proj) {
    
    // Distance from viewer to projection plane
    float d = 1.0f;


    // Perspective Projection Formula
    x_proj = d * (p_x / p_z);
    y_proj = d * (p_y / p_z);
}




int main()
{

    // Other Method

    // Define the coordinates
   /* float x = 2.0f;
    float y = 3.0f;
    float z = 5.0f;*/ // Depth

    // to stores projected co-ordinates 
    /*float x_proj, y_proj;*/


    //perProject(x , y ,z , x_proj , y_proj);

    /*std::cout << "Original Point (c) : (" << x << ", " << y << ", " << z << ")" << '\n';
    std::cout << "Projected Point (c') : (" << x_proj << ", " << y_proj <<  ")" << '\n';*/
    
    Point corners[8] = {
       { 1, -1, -5},
       { 1, -1, -3},
       { 1,  1, -5},
       { 1,  1, -3},
       {-1, -1, -5},
       {-1, -1, -3},
       {-1,  1, -5},
       {-1,  1, -3}
    };

    const unsigned int image_width = 512, image_height = 512;

    for (int i = 0; i < 8; ++i) {
        // Divide the x and y coordinates by the z coordinate to 
        //oject the point onto the  prcanvas
        float x_proj = corners[i][0] / -corners[i][2];
        float y_proj = corners[i][1] / -corners[i][2];
        float x_proj_remap = (1 + x_proj) / 2;
        float y_proj_remap = (1 + y_proj) / 2;
        float x_proj_pix = x_proj_remap * image_width;
        float y_proj_pix = y_proj_remap * image_height;
        printf("Corner: %d x:%f y:%f\n", i, x_proj_pix, y_proj_pix);
    }

    return 0;
}
