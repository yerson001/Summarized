#include "videoopencv.h"

VideoOpencv::VideoOpencv()
{

}

Mat VideoOpencv::Movement(Mat img1, Mat img2, int &count, int k)
{
    cv::Mat image01,image02,image02bw,d;
    img1.convertTo(image01, CV_8UC1);
    img2.convertTo(image02, CV_8UC1);
    //      imshow("image01", RI(image01,0.5));
    //      imshow("image02", RI(image02,0.5));
    rectangle(image01, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
    rectangle(image02, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
    //imshow("image01", RI(image01,0.5));
    cvtColor(image01, image01, COLOR_RGB2GRAY, 1);
    cvtColor(image02, image02bw, COLOR_RGB2GRAY, 1);
    absdiff(image01, image02bw, d);
    //imshow("d", RI(d,0.5));
    GaussianBlur(d, d, Size(k, k), 5, 3);
    Canny(d, d, 45, 80);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(d, d, kernel);

    int nonZero = countNonZero(d);
    //print(nonZero);

    if (nonZero > 500) {
        //std::cout << "movement:"<< count_movi<<std::endl;
    }


    return d;
}


bool VideoOpencv::filters(Mat img1, Mat img2, int &count, int k)
{
    cv::Mat image01,image02,image02bw,d;
    img1.convertTo(image01, CV_8UC1);
    img2.convertTo(image02, CV_8UC1);
    //      imshow("image01", RI(image01,0.5));
    //      imshow("image02", RI(image02,0.5));
    rectangle(image01, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
    rectangle(image02, Point2d(50,50),Point2d(800,120), (127,0,0),-1, LINE_8);
    //imshow("image01", RI(image01,0.5));
    cvtColor(image01, image01, COLOR_RGB2GRAY, 1);
    cvtColor(image02, image02bw, COLOR_RGB2GRAY, 1);
    absdiff(image01, image02bw, d);
    //imshow("d", RI(d,0.5));
    GaussianBlur(d, d, Size(k, k), 5, 3);
    Canny(d, d, 45, 80);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(d, d, kernel);


    //imshow("dd", RI(d,0.5));
    int nonZero = countNonZero(d);
    print(nonZero);
    //cout<<"No zero: "<<nonZero<<endl;
    //video.write(img2);

    if (nonZero > 500) {
        //cout << "movement:" <<count<< endl;
        //videoOnlyMovement.write(img2);
        count ++;
        return 1;
      }
    //std::cout << " Area: " << contourArea(contours[i]) << std::endl;

    //imshow("Image", RI(img2,0.5));
    return 0;
}
