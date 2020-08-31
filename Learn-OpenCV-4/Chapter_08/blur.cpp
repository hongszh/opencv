// EROSION 

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

// main function
int main(int argc, char** argv)
{
    Mat inputImage, outputImage;

    if(argc < 3)
    {
        cerr << "Insufficient input args. The format is:\n$ ./main image.jpg 5" << endl;
        return -1;
    }
    
    // Read the input image
    inputImage = imread(argv[1]);
    
    // Read the input value for the amount of erosion
    int erosionSize;
    istringstream iss(argv[2]);
    iss >> erosionSize;
    
    // Check the validity of the input image
    if(!inputImage.data)
    {
        cout << "Invalid input image. Exiting!" << endl;
        return -1;
    }
    
    int erosionElement = 2;


    // Create windows to display the input and output images
    namedWindow("Input image", WINDOW_AUTOSIZE);
    namedWindow("Output image after erosion", WINDOW_AUTOSIZE);
    
    // blur the image
    blur(inputImage, outputImage, Size(2*erosionSize+1, 2*erosionSize+1), Point(0,0));

    //在图像的指定位置添加 星标记
    drawMarker(inputImage, Point(50, 50), Scalar(0, 0, 255), MARKER_STAR, 20, 3);
    //在图像的指定位置添加 棱形标记
    drawMarker(inputImage, Point(50, 450), Scalar(255, 0, 255), MARKER_DIAMOND, 20, 3);
    //在图像的指定位置添加 十字标记
    drawMarker(inputImage, Point(450, 450), Scalar(0, 255, 255), MARKER_CROSS, 20, 3);
    //在图像的指定位置添加 X标记
    drawMarker(inputImage, Point(450, 50), Scalar(255, 0, 0), MARKER_TILTED_CROSS, 20, 3);
    
    // Display the output image
    imshow("Input image", inputImage);
    imshow("Output image after erosion", outputImage);
    
    // Wait until the user hits a key on the keyboard
    waitKey(0);
    
    return 0;
}

