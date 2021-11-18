//Contours are the curve joining all the continuous points along the boundary, having same color or intensity
//For better accuracy, use binary images. So before finding contours, apply threshold or canny edge detection.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
int dil = 1;
RNG rng(12345);
void dil_callback(int, void*);

const int max_dil = 20;

int main( )
{
    // window
    const char* source_window = "Source";
    namedWindow (source_window );
    
    Mat src = imread("Dog.jpg");
    cvtColor(src, img, COLOR_BGR2GRAY );
    blur(img, img, Size(3,3));
    imshow(source_window, src );
    Canny(img, img, 50, 150 );
    // Callback is called everytime trackbar moves
    createTrackbar("Canny thresh:", source_window, &dil, max_dil, dil_callback );
    dil_callback(0,0);
    waitKey();
    return 0;
}
void dil_callback(int, void* )
{
    Mat dil_output;
    if (dil==0){dil=1;}
    Mat kernel = getStructuringElement(MORPH_RECT, Size(dil,dil));
    Mat drawing = Mat::zeros(img.size(), CV_8UC3 );
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    // Dilate image depending on Kernel
    dilate(img, dil_output, kernel);
    // get the countours
    findContours(dil_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE ); // RETR_EXTERNAL_
    // cout << contours.size() << endl;
    for( size_t i = 0; i< contours.size(); i++ )
    {
        // Draw colors on each "idividual" contour
        Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        drawContours(drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0 );
    }
    imshow("Colored Contours", drawing);
}
