#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main(int argc, char **argv)
{
    Mat eye = Mat::eye(3, 3, CV_32F);
    cout << "Mat::eye: \n" << eye << endl;

    Mat zeros = Mat::zeros(3, 3, CV_8U);
    cout << "Mat::zero: \n" << zeros << endl;

    Mat ones = Mat::ones(3, 3, CV_32F);
    cout << "Mat::one: \n" << ones << endl;
    cout << "ones + eye: \n" << ones + eye << endl;
    cout << "ones * 4 : \n" << ones * 4 << endl;
    cout << "ones.inverse: \n" << ones.inv() << endl;

    cv::Vec3b vec = cv::Vec3b(2, 0, 0);
    cout << "vec: \n" << vec << endl;

    // Mat m = (cv::Mat_<Type>(height,width) << 0,-1,0,-1,5,-1,0,-1,0)
    //这种初始化方式，类型的地方用CV_32F这种是不行的，必须用基本类型
    /**
     * If matrix is of type CV_8U then use Mat.at<uchar>(y,x).
     * If matrix is of type CV_8S then use Mat.at<schar>(y,x).
     * If matrix is of type CV_16U then use Mat.at<ushort>(y,x).
     * If matrix is of type CV_16S then use Mat.at<short>(y,x).
     * If matrix is of type CV_32S then use Mat.at<int>(y,x).
     * If matrix is of type CV_32F then use Mat.at<float>(y,x).
     * If matrix is of type CV_64F then use Mat.at<double>(y,x).
     **/
    Mat floatMat = (Mat_<float>(3,3) << 2.00f, 2.10f, 2.20f, 2.30f, 2.40f, 2.50f, 2.60f, 2.70f, 2.80f);
    cout << "floatMat: \n" << floatMat << endl;
    cout << "floatMat.inv: \n" << floatMat.inv() << endl;


    Mat homogra(3,3,CV_64FC1);
    homogra.at<float>(0,0)=1.1688;
    homogra.at<float>(0,1)=0.23;
    homogra.at<float>(0,2)=(-62.20);
    homogra.at<float>(1,0)=(-0.013);
    homogra.at<float>(1,1)=1.225;
    homogra.at<float>(1,2)=-6.29;
    homogra.at<float>(2,0)=0;
    homogra.at<float>(2,1)=0;
    homogra.at<float>(2,2)=1;

    Mat inverse = homogra.inv();
    cout << "homogra: \n" << homogra << "\n"; 
    cout << "homogra inverse: \n"<< inverse << "\n"; 

    cout << "homogra setTo(0): \n" << homogra.setTo(0) << "\n"; 
    cout << "homogra setTo(0, homogra < 1.0): \n" << homogra.setTo(1, homogra < 1) << "\n"; 

    Mat emptyMat;
    cout << (emptyMat.empty() ? "mat is empty!\n" : "mat is not empty \n");

    vector<int> points;
    int a = 8, b = 5, c = 7, d = 3;
    points.emplace_back(a);
    points.emplace_back(b);
    points.emplace_back(c);
    points.emplace_back(d);
    std::sort(points.begin(), points.end());
    cout << "sorted point: \n";
    for(auto point : points) {
        cout << point << " ";
    }
    cout << endl;


    // cv::bitwise_and(idxMapMask, maskGrays[i], intersect);
    // cv::bitwise_or(allmask, maskGrays[i], allmask);

}
