#ifndef VIDEOOPENCV_H
#define VIDEOOPENCV_H
#include<opencv2/opencv.hpp>
#include<iostream>
#define print(a) std::cout<<#a<<" = "<<a<<std::endl;

using namespace cv;

class VideoOpencv
{
public:
    VideoOpencv();

    Mat Movement(Mat img1,Mat img2, int& count,int k);

    bool filters(Mat imag1,Mat imag2,int& count,int k);


};

#endif // VIDEOOPENCV_H
