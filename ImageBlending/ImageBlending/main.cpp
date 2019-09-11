//
//  main.cpp
//  ImageBlending
//
//  Created by 陈江林 on 2019/9/10.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string fileName = "/Users/chenjianglin/Documents/C++/ImageBlending/ImageBlending/ImageBlending/one.jpg";
    string fileName2 = "/Users/chenjianglin/Documents/C++/ImageBlending/ImageBlending/ImageBlending/two.jpg";
    
    Mat image = imread(fileName);
    
    Mat image2 = imread(fileName2);
    
    if (image.empty()) {
        return -1;
    }
    if (image2.empty()) {
        return -1;
    }
    
    Mat dst;
    double alpha = 0.5;
    if (image.rows == image2.rows && image.cols == image2.cols && image.channels() == image2.channels()) {
        //图片混合 gamma 值 是一个校验值
        addWeighted(image, alpha, image2, 1 - alpha, 0, dst);
    }
    // 对应的 I(y) = a * I(fx1) + (1 - a) * I(fx2) + gamma
    if (dst.empty()) {
        return -1;
    }
    string outWindow = "out window";
    namedWindow(outWindow);
    imshow(outWindow, dst);
    
    waitKey(0);
    
    return 0;
}
