 // g++ m.cpp -o app `pkg-config --cflags --libs opencv`
 #include <opencv4/opencv2/imgcodecs.hpp>

 #include <opencv2/highgui.hpp>

 #include <opencv2/imgproc.hpp>

 #include <iostream>

 // Namespace
 using namespace cv;
 using namespace std;

 // Constants
 enum EDGES {
     ERODE = 0, DILATE = 1
 };

 /*  ----- Basic Functions ------  */
 
 // Webcam
 void Webcam() {
     VideoCapture cap(0);
     Mat img;

     while (true) {
         cap.read(img);
         imshow("Image", img);
         waitKey(1);
     }
 }

 // load image
 Mat Load_Image() {
     string path = "./image.jpg";
     Mat img = imread(path);
     imshow("Loaded image", img);
     return img;
 }
 
 // convert to gray image
 void Convert_Gray(Mat & img) {
     cvtColor(img, img, COLOR_BGR2GRAY);
     imshow("gray", img);
 }
 
 // Gaussian Blur
 void Gaussian_Blur(Mat & img) {
     GaussianBlur(img, img, Size(3, 3), 0);
     imshow("GBlur", img);
 }
 
 // Canny
 void Edge_Detection(Mat & img) {
     Canny(img, img, 20, 100);
     imshow("Canny", img);
 }
 
 // Dilate - Erode
 void Dilate_Erode(Mat & img, bool dil) {
     Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
     auto text = "not processed";
     if (dil) {
         dilate(img, img, kernel);
         text = "Dilate";
     } else {
         erode(img, img, kernel);
         text = "Erode";
     }
     imshow(text, img);
 }
 
 // Rescale
 void Rescale(Mat & img) {
     resize(img, img, Size(), 0.5, 0.5);
     imshow("Half size", img);
 }

// Cropping image
void Crop(Mat const img) {
     Rect roi(155,240,80,80);
     Mat cropped_img = img(roi);
     imshow("cropped", cropped_img);
 }


 /* ----------------------------------- */
 int main() {
     Mat img = Load_Image();
     Convert_Gray(img);
     Gaussian_Blur(img);
     Edge_Detection(img);
     Dilate_Erode(img, DILATE);
     Crop(img);
     Rescale(img);
     waitKey(0);
     return 0;
 }
