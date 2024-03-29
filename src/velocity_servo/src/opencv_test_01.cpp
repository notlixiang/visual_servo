// opencv_test_01.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include "opencv2/calib3d/calib3d.hpp"


using namespace std;
using namespace cv;
using namespace xfeatures2d;
 

//int MAX_KERNEL_LENGTH = 5;
//
//int main()
//{
//	// 读入一张图片（游戏原画）  
//	Mat src = imread("111.png");
//	Mat dst = src.clone();
//	Mat padded;                            //将输入图像延扩到最佳的尺寸
//
//	int i = 5;
//	//for (i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
//	//{
//		
//		GaussianBlur(src, dst, Size(i, i), 0, 0);
//		//blur(src, dst, Size(i, i), Point(-1, -1));
//		//medianBlur(src, dst, i);
//
//
//	//}
//
//	imshow("Input Image", src);    // Show the result
//	imshow("Output Image", dst);    // Show the result
//	waitKey();
//
//
//
//	//// 创建一个名为 "游戏原画"窗口  
//	//namedWindow("游戏原画");
//	//// 在窗口中显示游戏原画  
//	//imshow("游戏原画", I);
//	//// 等待6000 ms后窗口自动关闭  
//	//waitKey(6000);
//}




//Mat src, erosion_dst, dilation_dst;
//
//int erosion_elem = 0;
//int erosion_size = 0;
//int dilation_elem = 0;
//int dilation_size = 0;
//int const max_elem = 2;
//int const max_kernel_size = 21;
//
///** Function Headers */
//void Erosion(int, void*);
//void Dilation(int, void*);
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// Load 图像
//	src = imread("111.png");
//
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	/// 创建显示窗口
//	namedWindow("Erosion Demo", CV_WINDOW_AUTOSIZE);
//	namedWindow("Dilation Demo", CV_WINDOW_AUTOSIZE);
//	cvMoveWindow("Dilation Demo", src.cols, 0);
//
//	/// 创建腐蚀 Trackbar
//	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
//		&erosion_elem, max_elem,
//		Erosion);
//
//	createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
//		&erosion_size, max_kernel_size,
//		Erosion);
//
//	/// 创建膨胀 Trackbar
//	createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
//		&dilation_elem, max_elem,
//		Dilation);
//
//	createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
//		&dilation_size, max_kernel_size,
//		Dilation);
//
//	/// Default start
//	Erosion(0, 0);
//	Dilation(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
///**  @function Erosion  */
//void Erosion(int, void*)
//{
//	int erosion_type;
//	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
//	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
//	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
//
//	Mat element = getStructuringElement(erosion_type,
//		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
//		Point(erosion_size, erosion_size));
//
//	/// 腐蚀操作
//	erode(src, erosion_dst, element);
//	imshow("Erosion Demo", erosion_dst);
//}
//
///** @function Dilation */
//void Dilation(int, void*)
//{
//	int dilation_type;
//	if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
//	else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
//	else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
//
//	Mat element = getStructuringElement(dilation_type,
//		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
//		Point(dilation_size, dilation_size));
//	///膨胀操作
//	dilate(src, dilation_dst, element);
//	imshow("Dilation Demo", dilation_dst);
//}

///// 全局变量
//Mat src, dst;
//
//int morph_elem = 0;
//int morph_size = 0;
//int morph_operator = 0;
//int const max_operator = 4;
//int const max_elem = 2;
//int const max_kernel_size = 21;
//
//char* window_name = "Morphology Transformations Demo";
//
///** 回调函数申明 */
//void Morphology_Operations(int, void*);
//
///** @函数 main */
//int main(int argc, char** argv)
//{
//	/// 装载图像
//	src = imread(argv[1]);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 创建选择具体操作的 trackbar
//	createTrackbar("Operator:\n 0: Opening - 1: Closing \n 2: Gradient - 3: Top Hat \n 4: Black Hat", window_name, &morph_operator, max_operator, Morphology_Operations);
//
//	/// 创建选择内核形状的 trackbar
//	createTrackbar("Element:\n 0: Rect - 1: Cross - 2: Ellipse", window_name,
//		&morph_elem, max_elem,
//		Morphology_Operations);
//
//	/// 创建选择内核大小的 trackbar
//	createTrackbar("Kernel size:\n 2n +1", window_name,
//		&morph_size, max_kernel_size,
//		Morphology_Operations);
//
//	/// 启动使用默认值
//	Morphology_Operations(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
///**
//* @函数 Morphology_Operations
//*/
//void Morphology_Operations(int, void*)
//{
//	// 由于 MORPH_X的取值范围是: 2,3,4,5 和 6
//	int operation = morph_operator + 2;
//
//	Mat element = getStructuringElement(morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
//
//	/// 运行指定形态学操作
//	morphologyEx(src, dst, operation, element);
//	imshow(window_name, dst);
//}


//Mat src, dst, tmp;
//char* window_name = "Pyramids Demo";
//
//
///**
//* @函数 main
//*/
//int main(int argc, char** argv)
//{
//	/// 指示说明
//	printf("\n Zoom In-Out demo  \n ");
//	printf("------------------ \n");
//	printf(" * [u] -> Zoom in  \n");
//	printf(" * [d] -> Zoom out \n");
//	printf(" * [ESC] -> Close program \n \n");
//
//	/// 测试图像 - 尺寸必须能被 2^{n} 整除
//	src = imread(argv[1]);
//	if (!src.data)
//	{
//		printf(" No data! -- Exiting the program \n");
//		return -1;
//	}
//
//	tmp = src;
//	dst = tmp;
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//	imshow(window_name, dst);
//
//	
//	pyrUp(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2));
//		
//		imshow(window_name, dst);
//		tmp = dst;
//		waitKey(0);
//	return 0;
//}



//int threshold_value = 0;
//int threshold_type = 3;;
//int const max_value = 255;
//int const max_type = 4;
//int const max_BINARY_value = 255;
//
//Mat src, src_gray, dst;
//char* window_name = "Threshold Demo";
//
//char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
//char* trackbar_value = "Value";
//
///// 自定义函数声明
//void Threshold_Demo(int, void*);
//
///**
//* @主函数
//*/
//int main(int argc, char** argv)
//{
//	/// 读取一副图片，不改变图片本身的颜色类型（该读取方式为DOS运行模式）
//	src = imread(argv[1], 1);
//
//	/// 将图片转换成灰度图片
//	cvtColor(src, src_gray, CV_RGB2GRAY);
//
//	/// 创建一个窗口显示图片
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 创建滑动条来控制阈值
//	createTrackbar(trackbar_type,
//		window_name, &threshold_type,
//		max_type, Threshold_Demo);
//
//	createTrackbar(trackbar_value,
//		window_name, &threshold_value,
//		max_value, Threshold_Demo);
//
//	/// 初始化自定义的阈值函数
//	Threshold_Demo(0, 0);
//
//	/// 等待用户按键。如果是ESC健则退出等待过程。
//	while (true)
//	{
//		int c;
//		c = waitKey(20);
//		if ((char)c == 27)
//		{
//			break;
//		}
//	}
//
//}
//
//
///**
//* @自定义的阈值函数
//*/
//void Threshold_Demo(int, void*)
//{
//	/* 0: 二进制阈值
//	1: 反二进制阈值
//	2: 截断阈值
//	3: 0阈值
//	4: 反0阈值
//	*/
//
//	threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
//
//	imshow(window_name, dst);
//}





//using namespace cv;
//
///** @函数main */
//int main(int argc, char** argv)
//{
//	/// 声明变量
//	Mat src, dst;
//
//	Mat kernel;
//	Point anchor;
//	double delta;
//	int ddepth;
//	int kernel_size;
//	char* window_name = "filter2D Demo";
//
//	int c;
//
//	/// 载入图像
//	src = imread(argv[1],1);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	/// 创建窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 初始化滤波器参数
//	anchor = Point(-1, -1);
//	delta = 0;
//	ddepth = -1;
//
//	/// 循环 - 每隔0.5秒，用一个不同的核来对图像进行滤波
//	int ind = 0;
//	while (true)
//	{
//		c = waitKey(500);
//		/// 按'ESC'可退出程序
//		if ((char)c == 27)
//		{
//			break;
//		}
//
//		/// 更新归一化块滤波器的核大小
//		kernel_size = 3 + 2 * (ind % 5);
//		kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
//
//		/// 使用滤波器
//		filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
//		imshow(window_name, dst);
//		ind++;
//	}
//	/*cout << src << endl;*/
//	waitKey(0);
//	return 0;
//}




//Mat src, dst;
//int top, bottom;
//int myleft, myright;
//int borderType;
//Scalar value;
//char* window_name = "copyMakeBorder Demo";
//RNG rng(12345);
//
//void border(int, void*);
///** @函数 main  */
//int main(int argc, char** argv)
//{
//
//	int c;
//
//	/// 装载图像
//	src = imread(argv[1]);
//
//	if (!src.data)
//	{
//		return -1;
//		printf(" No data entered, please enter the path to an image file \n");
//	}
//
//	/// 使用说明
//	printf("\n \t copyMakeBorder Demo: \n");
//	printf("\t -------------------- \n");
//	printf(" ** Press 'c' to set the border to a random constant value \n");
//	printf(" ** Press 'r' to set the border to be replicated \n");
//	printf(" ** Press 'ESC' to exit the program \n");
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 初始化输入参数
//	top = (int)(0.05*src.rows); bottom = (int)(0.05*src.rows);
//	myleft = (int)(0.05*src.cols); myright = (int)(0.05*src.cols);
//	dst = src;
//
//	imshow(window_name, dst);
//
//	createTrackbar("121",
//				window_name, &borderType,
//				4, border);
//
//	waitKey(0);
//	return 0;
//}
//void border(int, void*)
//{
//
//	value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//	copyMakeBorder(src, dst, top, bottom, myleft, myright, borderType, value);
//
//	imshow(window_name, dst);
//}




///** @function main */
//int main(int argc, char** argv)
//{
//
//	Mat src, src_gray;
//	Mat grad;
//	char* window_name = "Sobel Demo - Simple Edge Detector";
//	char* src_window_name = "Src";
//	int scale = 1;
//	int delta = 0;
//	int ddepth = CV_16S;
//
//	int c;
//
//	/// 装载图像
//	src = imread(argv[1]);
//	imshow(src_window_name, src);
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
//	src_gray = src;
//	/// 转换为灰度图
//	cvtColor(src, src_gray, CV_RGB2GRAY);
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 创建 grad_x 和 grad_y 矩阵
//	Mat grad_x, grad_y;
//	Mat abs_grad_x, abs_grad_y;
//
//	/// 求 X方向梯度
//	//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
//	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
//	convertScaleAbs(grad_x, abs_grad_x);
//
//	/// 求Y方向梯度
//	//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
//	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
//	convertScaleAbs(grad_y, abs_grad_y);
//
//	/// 合并梯度(近似)
//	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
//
//	imshow(window_name, grad);
//	
//	waitKey(0);
//
//	return 0;
//}



///** @函数 main */
//int main(int argc, char** argv)
//{
//	Mat src, src_gray, dst;
//	int kernel_size = 3;
//	int scale = 1;
//	int delta = 0;
//	int ddepth = CV_16S;
//	char* window_name = "Laplace Demo";
//	char* src_window_name = "Src";
//
//	int c;
//
//	/// 装载图像
//	src = imread(argv[1]);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//	imshow(src_window_name, src);
//	/// 使用高斯滤波消除噪声
//	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
//
//	/// 转换为灰度图
//	cvtColor(src, src_gray, CV_RGB2GRAY);
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 使用Laplace函数
//	Mat abs_dst;
//
//	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
//	convertScaleAbs(dst, abs_dst);
//
//	/// 显示结果
//	imshow(window_name, abs_dst);
//
//	waitKey(0);
//
//	return 0;
//}




///// 全局变量
//
//Mat src, src_gray;
//Mat dst, detected_edges;
//
//int edgeThresh = 1;
//int lowThreshold;
//int const max_lowThreshold = 150;
//int ratio = 2;
//int kernel_size = 3;
//char* window_name = "Edge Map";
//char* src_window_name = "Src";
//
///**
//* @函数 CannyThreshold
//* @简介： trackbar 交互回调 - Canny阈值输入比例1:3
//*/
//void CannyThreshold(int, void*)
//{
//	/// 使用 3x3内核降噪
//	blur(src_gray, detected_edges, Size(3, 3));
//
//	/// 运行Canny算子
//	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
//
//	/// 使用 Canny算子输出边缘作为掩码显示原图像
//	dst = Scalar::all(0);
//
//	src.copyTo(dst, detected_edges);
//	imshow(window_name, dst);
//}
//
//
///** @函数 main */
//int main(int argc, char** argv)
//{
//	/// 装载图像
//	src = imread(argv[1]);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//	imshow(src_window_name, src);
//	/// 创建与src同类型和大小的矩阵(dst)
//	dst.create(src.size(), src.type());
//
//	/// 原图像转换为灰度图像
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//
//	/// 创建显示窗口
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//
//	/// 创建trackbar
//	createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
//
//	/// 显示图像
//	CannyThreshold(0, 0);
//
//	/// 等待用户反应
//	waitKey(0);
//
//	return 0;
//}




//void help()
//{
//	cout << "\nThis program demonstrates line finding with the Hough transform.\n"
//		"Usage:\n"
//		"./houghlines <image_name>, Default is pic1.jpg\n" << endl;
//}
//
//int main(int argc, char** argv)
//{
//	const char* filename = argc >= 2 ? argv[1] : "pic1.jpg";
//
//	Mat src = imread(filename, 0);
//	if (src.empty())
//	{
//		help();
//		cout << "can not open " << filename << endl;
//		return -1;
//	}
//
//	Mat dst, cdst;
//	Canny(src, dst, 50, 200, 3);
//	cvtColor(dst, cdst, CV_GRAY2BGR);
//
//#if 0
//	vector<Vec2f> lines;
//	HoughLines(dst, lines, 1, CV_PI / 180, 100, 0, 0);
//
//	for (size_t i = 0; i < lines.size(); i++)
//	{
//		float rho = lines[i][0], theta = lines[i][1];
//		Point pt1, pt2;
//		double a = cos(theta), b = sin(theta);
//		double x0 = a * rho, y0 = b * rho;
//		pt1.x = cvRound(x0 + 1000 * (-b));
//		pt1.y = cvRound(y0 + 1000 * (a));
//		pt2.x = cvRound(x0 - 1000 * (-b));
//		pt2.y = cvRound(y0 - 1000 * (a));
//		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
//	}
//#else
//	vector<Vec4i> lines;
//	HoughLinesP(dst, lines, 1, CV_PI / 180, 100, 100, 5);
//	for (size_t i = 0; i < lines.size(); i++)
//	{
//		Vec4i l = lines[i];
//		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
//	}
//#endif
//	imshow("source", src);
//	imshow("detected lines", cdst);
//
//	waitKey();
//
//	return 0;
//}





///** @function main */
//int main(int argc, char** argv)
//{
//	Mat src, src_gray;
//
//	/// Read the image
//	src = imread(argv[1], 1);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	/// Convert it to gray
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//
//	/// Reduce the noise so we avoid false circle detection
//	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
//
//	vector<Vec3f> circles;
//
//	/// Apply the Hough Transform to find the circles
//	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows / 8, 200, 100, 0, 0);
//
//	/// Draw the circles detected
//	for (size_t i = 0; i < circles.size(); i++)
//	{
//		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//		int radius = cvRound(circles[i][2]);
//		// circle center
//		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
//		// circle outline
//		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
//	}
//
//	/// Show your results
//	namedWindow("Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE);
//	imshow("Hough Circle Transform Demo", src);
//
//	waitKey(0);
//	return 0;
//}




///// Global variables
//Mat src, dst;
//Mat map_x, map_y;
//char* remap_window = "Remap demo";
//int ind = 0;
//
///// Function Headers
//void update_map(void);
//
///**
//* @function main
//*/
//int main(int argc, char** argv)
//{
//	/// Load the image
//	src = imread(argv[1], 1);
//
//	/// Create dst, map_x and map_y with the same size as src:
//	dst.create(src.size(), src.type());
//	map_x.create(src.size(), CV_32FC1);
//	map_y.create(src.size(), CV_32FC1);
//	///imshow("map_x", map_x);
//	/// Create window
//	namedWindow(remap_window, CV_WINDOW_AUTOSIZE);
//
//	/// Loop
//	while (true)
//	{
//		/// Each 1 sec. Press ESC to exit the program
//		int c = waitKey(1000);
//
//		if ((char)c == 27)
//		{
//			break;
//		}
//
//		/// Update map_x & map_y. Then apply remap
//		update_map();
//		remap(src, dst, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//		/// Display results
//		imshow(remap_window, dst);
//	}
//	return 0;
//}
//
///**
//* @function update_map
//* @brief Fill the map_x and map_y matrices with 4 types of mappings
//*/
//void update_map(void)
//{
//	ind = ind % 4;
//
//	for (int j = 0; j < src.rows; j++)
//	{
//		for (int i = 0; i < src.cols; i++)
//		{
//			switch (ind)
//			{
//			case 0:
//				if (i > src.cols*0.25 && i < src.cols*0.75 && j > src.rows*0.25 && j < src.rows*0.75)
//				{
//					map_x.at<float>(j, i) = 2 * (i - src.cols*0.25) + 0.5;
//					map_y.at<float>(j, i) = 2 * (j - src.rows*0.25) + 0.5;
//				}
//				else
//				{
//					map_x.at<float>(j, i) = 0;
//					map_y.at<float>(j, i) = 0;
//				}
//				break;
//			case 1:
//				map_x.at<float>(j, i) = i;
//				map_y.at<float>(j, i) = src.rows - j;
//				break;
//			case 2:
//				map_x.at<float>(j, i) = src.cols - i;
//				map_y.at<float>(j, i) = j;
//				break;
//			case 3:
//				map_x.at<float>(j, i) = src.cols - i;
//				map_y.at<float>(j, i) = src.rows - j;
//				break;
//			} // end of switch
//		}
//	}
//	ind++;
//}





///// 全局变量
//char* source_window = "Source image";
//char* warp_window = "Warp";
//char* warp_rotate_window = "Warp + Rotate";
//
///** @function main */
//int main(int argc, char** argv)
//{
//	Point2f srcTri[3];
//	Point2f dstTri[3];
//
//	Mat rot_mat(2, 3, CV_32FC1);
//	Mat warp_mat(2, 3, CV_32FC1);
//	Mat src, warp_dst, warp_rotate_dst;
//
//	/// 加载源图像
//	src = imread(argv[1], 1);
//
//	/// 设置目标图像的大小和类型与源图像一致
//	warp_dst = Mat::zeros(src.rows, src.cols, src.type());
//
//	/// 设置源图像和目标图像上的三组点以计算仿射变换
//	srcTri[0] = Point2f(0, 0);
//	srcTri[1] = Point2f(src.cols - 1, 0);
//	srcTri[2] = Point2f(0, src.rows - 1);
//
//	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
//	dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
//	dstTri[2] = Point2f(src.cols*0.15, src.rows*0.7);
//
//	/// 求得仿射变换
//	warp_mat = getAffineTransform(srcTri, dstTri);
//
//	/// 对源图像应用上面求得的仿射变换
//	warpAffine(src, warp_dst, warp_mat, warp_dst.size());
//
//	/** 对图像扭曲后再旋转 */
//
//	/// 计算绕图像中点顺时针旋转50度缩放因子为0.6的旋转矩阵
//	Point center = Point(warp_dst.cols / 2, warp_dst.rows / 2);
//	double angle = -50.0;
//	double scale = 0.6;
//
//	/// 通过上面的旋转细节信息求得旋转矩阵
//	rot_mat = getRotationMatrix2D(center, angle, scale);
//
//	/// 旋转已扭曲图像
//	warpAffine(warp_dst, warp_rotate_dst, rot_mat, warp_dst.size());
//
//	/// 显示结果
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, src);
//
//	namedWindow(warp_window, CV_WINDOW_AUTOSIZE);
//	imshow(warp_window, warp_dst);
//
//	namedWindow(warp_rotate_window, CV_WINDOW_AUTOSIZE);
//	imshow(warp_rotate_window, warp_rotate_dst);
//
//	/// 等待用户按任意按键退出程序
//	waitKey(0);
//
//	return 0;
//}



///**  @function main */
//int main(int argc, char** argv)
//{
//	Mat src, dst;
//
//	char* source_window = "Source image";
//	char* equalized_window = "Equalized Image";
//
//	/// 加载源图像
//	src = imread(argv[1], 1);
//
//	if (!src.data)
//	{
//		cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
//		return -1;
//	}
//
//	/// 转为灰度图
//	cvtColor(src, src, CV_BGR2GRAY);
//
//	/// 应用直方图均衡化
//	equalizeHist(src, dst);
//
//	/// 显示结果
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);
//
//	imshow(source_window, src);
//	imshow(equalized_window, dst);
//
//	/// 等待用户按键退出程序
//	waitKey(0);
//
//	return 0;
//}





///** @函数 main */
//int main(int argc, char** argv)
//{
//	Mat src, dst,mixed;
//
//	/// 装载图像
//	src = imread(argv[1], 1);
//
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	/// 分割成3个单通道图像 ( R, G 和 B )
//	vector<Mat> rgb_planes;
//	split(src, rgb_planes);
//
//	/// 设定bin数目
//	int histSize = 255;
//
//	/// 设定取值范围 ( R,G,B) )
//	float range[] = { 0, 255 };
//	const float* histRange = { range };
//
//	bool uniform = true; bool accumulate = false;
//
//	Mat r_hist, g_hist, b_hist;
//
//	/// 计算直方图:
//	calcHist(&rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
//	calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
//	calcHist(&rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
//
//	// 创建直方图画布
//	int hist_w = 400; int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / histSize);
//
//	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0,0, 0));
//
//	/// 将直方图归一化到范围 [ 0, histImage.rows ]
//	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//
//	/// 在直方图画布上画出直方图
//	for (int i = 1; i < histSize; i++)
//	{
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
//			Scalar(0, 0, 255), 2, 8, 0);
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
//			Scalar(0, 255, 0), 2, 8, 0);
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
//			Scalar(255, 0, 0), 2, 8, 0);
//	}
//
//	/// 显示直方图
//	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
//	imshow("calcHist Demo", histImage);
//
//
//	//mixChannels(rgb_planes, mixed);
//	waitKey(0);
//
//	return 0;
//
//}




///// 全局变量
//Mat src; Mat hsv; Mat hue;
//int bins = 25;
//
///// 函数申明
//void Hist_and_Backproj(int, void* );
//
///** @函数 main */
//int main( int argc, char** argv )
//{
//  /// 读取图像
//  src = imread( argv[1], 1 );
//  /// 转换到 HSV 空间
//  cvtColor( src, hsv, CV_BGR2HSV );
//
//  /// 分离 Hue 通道
//  hue.create( hsv.size(), hsv.depth() );
//  int ch[] = { 0, 0 };
//  mixChannels( &hsv, 1, &hue, 1, ch, 1 );
//
//  /// 创建 Trackbar 来输入bin的数目
//  char* window_image = "Source image";
//  namedWindow( window_image, CV_WINDOW_AUTOSIZE );
//  createTrackbar("* Hue  bins: ", window_image, &bins, 180, Hist_and_Backproj );
//  Hist_and_Backproj(0, 0);
//
//  /// 现实图像
//  imshow( window_image, src );
//
//  /// 等待用户反应
//  waitKey(0);
//  return 0;
//}
//
//
///**
// * @函数 Hist_and_Backproj
// * @简介：Trackbar事件的回调函数
// */
//void Hist_and_Backproj(int, void* )
//{
//  MatND hist;
//  int histSize = MAX( bins, 2 );
//  float hue_range[] = { 0, 180 };
//  const float* ranges = { hue_range };
//
//  /// 计算直方图并归一化
//  calcHist( &hue, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false );
//  normalize( hist, hist, 0, 255, NORM_MINMAX, -1, Mat() );
//
//  /// 计算反向投影
//  MatND backproj;
//  calcBackProject( &hue, 1, 0, hist, backproj, &ranges, 1, true );
//
//  /// 显示反向投影
//  imshow( "BackProj", backproj );
//
//  /// 显示直方图
//  int w = 400; int h = 400;
//  int bin_w = cvRound( (double) w / histSize );
//  Mat histImg = Mat::zeros( w, h, CV_8UC3 );
//
//  for( int i = 0; i < bins; i ++ )
//     { rectangle( histImg, Point( i*bin_w, h ), Point( (i+1)*bin_w, h - cvRound( hist.at<float>(i)*h/255.0 ) ), Scalar( 0, 0, 255 ), -1 ); }
//
//  imshow( "Histogram", histImg );
//}
//




///// 全局变量
//Mat img; Mat templ; Mat result;
//char* image_window = "Source Image";
//char* result_window = "Result window";
//
//int match_method=0;
//int max_Trackbar = 5;
//
///// 函数声明
//void MatchingMethod(int, void*);
//
///** @主函数 */
//int main(int argc, char** argv)
//{
//	/// 载入原图像和模板块
//	img = imread(argv[1], 1);
//	templ = imread(argv[2], 1);
//
//	/// 创建窗口
//	namedWindow(image_window, CV_WINDOW_AUTOSIZE);
//	namedWindow(result_window, CV_WINDOW_AUTOSIZE);
//
//	/// 创建滑动条
//	char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
//	createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod);
//
//	MatchingMethod(0, 0);
//
//
//	imshow("tpl", templ);
//	waitKey(0);
//	return 0;
//}
//
///**
//* @函数 MatchingMethod
//* @简单的滑动条回调函数
//*/
//void MatchingMethod(int, void*)
//{
//	/// 将被显示的原图像
//	Mat img_display;
//	img.copyTo(img_display);
//
//	/// 创建输出结果的矩阵
//	int result_cols = img.cols - templ.cols + 1;
//	int result_rows = img.rows - templ.rows + 1;
//
//	result.create(result_cols, result_rows, CV_32FC1);
//
//	/// 进行匹配和标准化
//	matchTemplate(img, templ, result, match_method);
//	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
//
//	/// 通过函数 minMaxLoc 定位最匹配的位置
//	double minVal; double maxVal; Point minLoc; Point maxLoc;
//	Point matchLoc;
//
//	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
//
//	/// 对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值代表更高的匹配结果. 而对于其他方法, 数值越大匹配越好
//	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
//	{
//		matchLoc = minLoc;
//	}
//	else
//	{
//		matchLoc = maxLoc;
//	}
//
//	/// 让我看看您的最终结果
//	rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
//	rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
//
//	imshow(image_window, img_display);
//	imshow(result_window, result);
//
//	return;
//}




//Mat src; Mat src_gray;
//int thresh = 95;
//int max_thresh = 255;
//RNG rng(12345);
//
///// Function header
//void thresh_callback(int, void*);
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// 加载源图像
//	src = imread(argv[1], 1);
//
//	/// 转成灰度并模糊化降噪
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//	blur(src_gray, src_gray, Size(3, 3));
//
//	/// 创建窗体
//	char* source_window = "Source";
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, src);
//
//	createTrackbar(" Canny thresh:", "Source", &thresh, max_thresh, thresh_callback);
//	thresh_callback(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///** @function thresh_callback */
//void thresh_callback(int, void*)
//{
//	Mat canny_output;
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//
//	/// 用Canny算子检测边缘
//	Canny(src_gray, canny_output, thresh, thresh * 2, 3);
//	/// 寻找轮廓
//	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	/// 绘出轮廓
//	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
//	for (int i = 0; i< contours.size(); i++)
//	{
//		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
//	}
//
//	/// 在窗体中显示结果
//	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
//	imshow("Contours", drawing);
//}






//Mat src; Mat src_gray;
//int thresh = 100;
//int max_thresh = 255;
//RNG rng(12345);
//
///// Function header
//void thresh_callback(int, void*);
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// 加载源图像
//	src = imread(argv[1], 1);
//
//	/// 转成灰度图并进行模糊降噪
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//	blur(src_gray, src_gray, Size(3, 3));
//
//	/// 创建窗体
//	char* source_window = "Source";
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, src);
//
//	createTrackbar(" Threshold:", "Source", &thresh, max_thresh, thresh_callback);
//	thresh_callback(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///** @function thresh_callback */
//void thresh_callback(int, void*)
//{
//	Mat src_copy = src.clone();
//	Mat threshold_output;
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//
//	/// 对图像进行二值化
//	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);
//
//	/// 寻找轮廓
//	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	/// 对每个轮廓计算其凸包
//	vector<vector<Point> >hull(contours.size());
//	for (int i = 0; i < contours.size(); i++)
//	{
//		convexHull(Mat(contours[i]), hull[i], false);
//	}
//
//	/// 绘出轮廓及其凸包
//	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
//	for (int i = 0; i< contours.size(); i++)
//	{
//		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
//		drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
//	}
//
//	/// 把结果显示在窗体
//	namedWindow("Hull demo", CV_WINDOW_AUTOSIZE);
//	imshow("Hull demo", drawing);
//}






//Mat src; Mat src_gray;
//int thresh = 100;
//int max_thresh = 255;
//RNG rng(12345);
//
///// 函数声明
//void thresh_callback(int, void*);
//
///** @主函数 */
//int main(int argc, char** argv)
//{
//	/// 载入原图像, 返回3通道图像
//	src = imread(argv[1], 1);
//
//	/// 转化成灰度图像并进行平滑
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//	blur(src_gray, src_gray, Size(3, 3));
//
//	/// 创建窗口
//	char* source_window = "Source";
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, src);
//
//	createTrackbar(" Threshold:", "Source", &thresh, max_thresh, thresh_callback);
//	thresh_callback(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///** @thresh_callback 函数 */
//void thresh_callback(int, void*)
//{
//	Mat threshold_output;
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//
//	/// 使用Threshold检测边缘
//	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);
//	/// 找到轮廓
//	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	/// 多边形逼近轮廓 + 获取矩形和圆形边界框
//	vector<vector<Point> > contours_poly(contours.size());
//	vector<Rect> boundRect(contours.size());
//	vector<Point2f>center(contours.size());
//	vector<float>radius(contours.size());
//
//	for (int i = 0; i < contours.size(); i++)
//	{
//		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
//		boundRect[i] = boundingRect(Mat(contours_poly[i]));
//		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
//	}
//
//
//	/// 画多边形轮廓 + 包围的矩形框 + 圆形框
//	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
//	for (int i = 0; i< contours.size(); i++)
//	{
//		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
//		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
//		circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
//	}
//
//	/// 显示在一个窗口
//	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
//	imshow("Contours", drawing);
//}




Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// 函数声明
void thresh_callback(int, void*);

/** @主函数 */
int main(int argc, char** argv)
{
	/// 读入原图像, 返回3通道图像数据
	src = imread(argv[1], 1);

	/// 把原图像转化成灰度图像并进行平滑
	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));

	/// 创建新窗口
	char* source_window = "Source";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);

	createTrackbar(" Canny thresh:", "Source", &thresh, max_thresh, thresh_callback);
	thresh_callback(0, 0);

	waitKey(0);
	return(0);
}

/** @thresh_callback 函数 */
void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// 使用Canndy检测边缘
	Canny(src_gray, canny_output, thresh, thresh * 2, 3);
	/// 找到轮廓
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 计算矩
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	///  计算中心矩:
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}

	/// 绘制轮廓
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 8, 0);
	}

	/// 显示到窗口中
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);

	/// 通过m00计算轮廓面积并且和OpenCV函数比较
	printf("\t Info: Area and Contour Length \n");
	for (int i = 0; i< contours.size(); i++)
	{
		printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n", i, mu[i].m00, contourArea(contours[i]), arcLength(contours[i], true));
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 8, 0);
	}
}







///// Global variables
//Mat src, src_gray;
//int thresh = 200;
//int max_thresh = 255;
//
//char* source_window = "Source image";
//char* corners_window = "Corners detected";
//
///// Function header
//void cornerHarris_demo(int, void*);
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// Load source image and convert it to gray
//	src = imread(argv[1], 1);
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//
//	/// Create a window and a trackbar
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	createTrackbar("Threshold: ", source_window, &thresh, max_thresh, cornerHarris_demo);
//	imshow(source_window, src);
//
//	cornerHarris_demo(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///** @function cornerHarris_demo */
//void cornerHarris_demo(int, void*)
//{
//
//	Mat dst, dst_norm, dst_norm_scaled;
//	dst = Mat::zeros(src.size(), CV_32FC1);
//
//	/// Detector parameters
//	int blockSize = 2;
//	int apertureSize = 3;
//	double k = 0.04;
//
//	/// Detecting corners
//	cornerHarris(src_gray, dst, blockSize, apertureSize, k, BORDER_DEFAULT);
//
//	/// Normalizing
//	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
//	convertScaleAbs(dst_norm, dst_norm_scaled);
//
//	/// Drawing a circle around corners
//	for (int j = 0; j < dst_norm.rows; j++)
//	{
//		for (int i = 0; i < dst_norm.cols; i++)
//		{
//			if ((int)dst_norm.at<float>(j, i) > thresh)
//			{
//				circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
//			}
//		}
//	}
//	/// Showing the result
//	namedWindow(corners_window, CV_WINDOW_AUTOSIZE);
//	imshow(corners_window, dst_norm_scaled);
//}





///// Global variables
//Mat src, src_gray;
//
//int maxCorners = 23;
//int maxTrackbar = 100;
//
//RNG rng(12345);
//char* source_window = "Image";
//
///// Function header
//void goodFeaturesToTrack_Demo(int, void*);
//
///**
//* @function main
//*/
//int main(int argc, char** argv)
//{
//	/// Load source image and convert it to gray
//	src = imread(argv[1], 1);
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//
//	/// Create Window
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//
//	/// Create Trackbar to set the number of corners
//	createTrackbar("Max  corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo);
//
//	imshow(source_window, src);
//
//	goodFeaturesToTrack_Demo(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///**
//* @function goodFeaturesToTrack_Demo.cpp
//* @brief Apply Shi-Tomasi corner detector
//*/
//void goodFeaturesToTrack_Demo(int, void*)
//{
//	if (maxCorners < 1) { maxCorners = 1; }
//
//	/// Parameters for Shi-Tomasi algorithm
//	vector<Point2f> corners;
//	double qualityLevel = 0.01;
//	double minDistance = 10;
//	int blockSize = 3;
//	bool useHarrisDetector = false;
//	double k = 0.04;
//
//	/// Copy the source image
//	Mat copy;
//	copy = src.clone();
//
//	/// Apply corner detection
//	goodFeaturesToTrack(src_gray,
//		corners,
//		maxCorners,
//		qualityLevel,
//		minDistance,
//		Mat(),
//		blockSize,
//		useHarrisDetector,
//		k);
//
//
//	/// Draw corners detected
//	cout << "** Number of corners detected: " << corners.size() << endl;
//	int r = 4;
//	for (int i = 0; i < corners.size(); i++)
//	{
//		circle(copy, corners[i], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
//			rng.uniform(0, 255)), -1, 8, 0);
//	}
//
//	/// Show what you got
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, copy);
//}






///// Global variables
//Mat src, src_gray;
//
//int maxCorners = 10;
//int maxTrackbar = 25;
//
//RNG rng(12345);
//char* source_window = "Image";
//
///// Function header
//void goodFeaturesToTrack_Demo(int, void*);
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// Load source image and convert it to gray
//	src = imread(argv[1], 1);
//	cvtColor(src, src_gray, CV_BGR2GRAY);
//
//	/// Create Window
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//
//	/// Create Trackbar to set the number of corners
//	createTrackbar("Max  corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo);
//
//	imshow(source_window, src);
//
//	goodFeaturesToTrack_Demo(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
///**
//* @function goodFeaturesToTrack_Demo.cpp
//* @brief Apply Shi-Tomasi corner detector
//*/
//void goodFeaturesToTrack_Demo(int, void*)
//{
//	if (maxCorners < 1) { maxCorners = 1; }
//
//	/// Parameters for Shi-Tomasi algorithm
//	vector<Point2f> corners;
//	double qualityLevel = 0.01;
//	double minDistance = 10;
//	int blockSize = 3;
//	bool useHarrisDetector = false;
//	double k = 0.04;
//
//	/// Copy the source image
//	Mat copy;
//	copy = src.clone();
//
//	/// Apply corner detection
//	goodFeaturesToTrack(src_gray,
//		corners,
//		maxCorners,
//		qualityLevel,
//		minDistance,
//		Mat(),
//		blockSize,
//		useHarrisDetector,
//		k);
//
//
//	/// Draw corners detected
//	cout << "** Number of corners detected: " << corners.size() << endl;
//	int r = 4;
//	for (int i = 0; i < corners.size(); i++)
//	{
//		circle(copy, corners[i], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
//			rng.uniform(0, 255)), -1, 8, 0);
//	}
//
//	/// Show what you got
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	imshow(source_window, copy);
//
//	/// Set the neeed parameters to find the refined corners
//	Size winSize = Size(5, 5);
//	Size zeroZone = Size(-1, -1);
//	TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 40, 0.001);
//
//	/// Calculate the refined corner locations
//	cornerSubPix(src_gray, corners, winSize, zeroZone, criteria);
//
//	/// Write them down
//	for (int i = 0; i < corners.size(); i++)
//	{
//		cout << " -- Refined Corner [" << i << "]  (" << corners[i].x << "," << corners[i].y << ")" << endl;
//	}
//}






//void readme();
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/*if (argc != 3)
//	{
//		readme(); return -1;
//	}*/
//
//	Mat img_1 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
//	Mat img_2 = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
//
//	if (!img_1.data || !img_2.data)
//	{
//		std::cout << " --(!) Error reading images " << std::endl; return -1;
//	}
//
//	//-- Step 1: Detect the keypoints using SURF Detector
//	int minHessian = 400;
//
//	vector<KeyPoint> keypoints1, keypoints2;
//	keypoints1.resize(100);
//	keypoints2.resize(100);
//
//	Ptr<SURF> detector = SURF::create(minHessian);
//	detector->detect(img_1, keypoints1);//检测img1中的SIFT特征点，存储到keypoints1中  
//	detector->detect(img_2, keypoints2);
//
//	//SurfFeatureDetector detector(minHessian);
//
//	std::vector<KeyPoint> keypoints_1, keypoints_2;
//
//	detector->detect(img_1, keypoints_1);
//	detector->detect(img_2, keypoints_2);
//
//	//-- Draw keypoints
//	Mat img_keypoints_1; Mat img_keypoints_2;
//
//	drawKeypoints(img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
//	drawKeypoints(img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
//
//	//-- Show detected (drawn) keypoints
//	imshow("Keypoints 1", img_keypoints_1);
//	imshow("Keypoints 2", img_keypoints_2);
//
//	waitKey(0);
//
//	return 0;
//}
//
///** @function readme */
//void readme()
//{
//	std::cout << " Usage: ./SURF_detector <img1> <img2>" << std::endl;
//}




//void readme();
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/*if (argc != 3)
//	{
//		return -1;
//	}*/
//
//	Mat img_1 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
//	Mat img_2 = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
//
//	if (!img_1.data || !img_2.data)
//	{
//		return -1;
//	}
//
//	//-- Step 1: Detect the keypoints using SURF Detector
//	int minHessian = 400;
//
//	//SurfFeatureDetector detector(minHessian);
//	Ptr<SURF> detector = SURF::create(minHessian);
//
//
//	std::vector<KeyPoint> keypoints_1, keypoints_2;
//
//	detector->detect(img_1, keypoints_1);
//	detector->detect(img_2, keypoints_2);
//
//	//-- Step 2: Calculate descriptors (feature vectors)
//	//SurfDescriptorExtractor extractor;
//	Ptr<SURF> extractor = SURF::create();
//
//	Mat descriptors_1, descriptors_2;
//
//	extractor->compute(img_1, keypoints_1, descriptors_1);
//	extractor->compute(img_2, keypoints_2, descriptors_2);
//
//	//-- Step 3: Matching descriptor vectors with a brute force matcher
//	//BruteForceMatcher< L2<float> > matcher;
//
//	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
//	std::vector< DMatch > matches;
//	matcher->match(descriptors_1, descriptors_2, matches);
//
//	//-- Draw matches
//	Mat img_matches;
//	drawMatches(img_1, keypoints_1, img_2, keypoints_2, matches, img_matches);
//
//	//-- Show detected matches
//	imshow("Matches", img_matches);
//
//	waitKey(0);
//
//	return 0;
//}
//
///** @function readme */
//void readme()
//{
//	std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl;
//}



//void readme();
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/*if (argc != 3)
//	{
//		readme(); return -1;
//	}*/
//
//	Mat img_1 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
//	Mat img_2 = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
//
//	if (!img_1.data || !img_2.data)
//	{
//		std::cout << " --(!) Error reading images " << std::endl; return -1;
//	}
//
//	//-- Step 1: Detect the keypoints using SURF Detector
//	int minHessian = 400;
//
//	//SurfFeatureDetector detector(minHessian);
//	Ptr<SURF> detector = SURF::create(minHessian);
//
//	std::vector<KeyPoint> keypoints_1, keypoints_2;
//
//	detector->detect(img_1, keypoints_1);
//	detector->detect(img_2, keypoints_2);
//
//	//-- Step 2: Calculate descriptors (feature vectors)
//	//SurfDescriptorExtractor extractor;
//	Ptr<SURF> extractor = SURF::create();
//
//	Mat descriptors_1, descriptors_2;
//
//	extractor->compute(img_1, keypoints_1, descriptors_1);
//	extractor->compute(img_2, keypoints_2, descriptors_2);
//
//	//-- Step 3: Matching descriptor vectors using FLANN matcher
//	FlannBasedMatcher matcher;
//	std::vector< DMatch > matches;
//	matcher.match(descriptors_1, descriptors_2, matches);
//
//	double max_dist = 0; double min_dist = 100;
//
//	//-- Quick calculation of max and min distances between keypoints
//	for (int i = 0; i < descriptors_1.rows; i++)
//	{
//		double dist = matches[i].distance;
//		if (dist < min_dist) min_dist = dist;
//		if (dist > max_dist) max_dist = dist;
//	}
//
//	printf("-- Max dist : %f \n", max_dist);
//	printf("-- Min dist : %f \n", min_dist);
//
//	//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist )
//	//-- PS.- radiusMatch can also be used here.
//	std::vector< DMatch > good_matches;
//
//	for (int i = 0; i < descriptors_1.rows; i++)
//	{
//		if (matches[i].distance < 2 * min_dist)
//		{
//			good_matches.push_back(matches[i]);
//		}
//	}
//
//	//-- Draw only "good" matches
//	Mat img_matches;
//	drawMatches(img_1, keypoints_1, img_2, keypoints_2,
//		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
//		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//
//	//-- Show detected matches
//	imshow("Good Matches", img_matches);
//
//	for (int i = 0; i < good_matches.size(); i++)
//	{
//		printf("-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx);
//	}
//
//	waitKey(0);
//
//	return 0;
//}
//
///** @function readme */
//void readme()
//{
//	std::cout << " Usage: ./SURF_FlannMatcher <img1> <img2>" << std::endl;
//}




//void readme();
//
///** @function main */
//int main(int argc, char** argv)
//{
//	//if (argc != 3)
//	//{
//	//	readme(); return -1;
//	//}
//
//	Mat img_object = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
//	Mat img_scene = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
//
//	if (!img_object.data || !img_scene.data)
//	{
//		std::cout << " --(!) Error reading images " << std::endl; return -1;
//	}
//
//	//-- Step 1: Detect the keypoints using SURF Detector
//	int minHessian = 400;
//
//	//SurfFeatureDetector detector(minHessian);
//	Ptr<SURF> detector = SURF::create(minHessian);
//
//	std::vector<KeyPoint> keypoints_object, keypoints_scene;
//
//	detector->detect(img_object, keypoints_object);
//	detector->detect(img_scene, keypoints_scene);
//
//	//-- Step 2: Calculate descriptors (feature vectors)
//	//SurfDescriptorExtractor extractor;
//	Ptr<SURF> extractor = SURF::create();
//
//	Mat descriptors_object, descriptors_scene;
//
//	extractor->compute(img_object, keypoints_object, descriptors_object);
//	extractor->compute(img_scene, keypoints_scene, descriptors_scene);
//
//	//-- Step 3: Matching descriptor vectors using FLANN matcher
//	FlannBasedMatcher matcher;
//	std::vector< DMatch > matches;
//	matcher.match(descriptors_object, descriptors_scene, matches);
//
//	double max_dist = 0; double min_dist = 100;
//
//	//-- Quick calculation of max and min distances between keypoints
//	for (int i = 0; i < descriptors_object.rows; i++)
//	{
//		double dist = matches[i].distance;
//		if (dist < min_dist) min_dist = dist;
//		if (dist > max_dist) max_dist = dist;
//	}
//
//	printf("-- Max dist : %f \n", max_dist);
//	printf("-- Min dist : %f \n", min_dist);
//
//	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
//	std::vector< DMatch > good_matches;
//
//	for (int i = 0; i < descriptors_object.rows; i++)
//	{
//		if (matches[i].distance < 3 * min_dist)
//		{
//			good_matches.push_back(matches[i]);
//		}
//	}
//
//	Mat img_matches;
//	drawMatches(img_object, keypoints_object, img_scene, keypoints_scene,
//		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
//		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//
//	//-- Localize the object
//	std::vector<Point2f> obj;
//	std::vector<Point2f> scene;
//
//	for (int i = 0; i < good_matches.size(); i++)
//	{
//		//-- Get the keypoints from the good matches
//		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
//		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
//	}
//
//	Mat H = findHomography(obj, scene, CV_RANSAC);
//
//	//-- Get the corners from the image_1 ( the object to be "detected" )
//	std::vector<Point2f> obj_corners(4);
//	obj_corners[0] = cvPoint(0, 0); 
//	obj_corners[1] = cvPoint(img_object.cols, 0);
//	obj_corners[2] = cvPoint(img_object.cols, img_object.rows); 
//	obj_corners[3] = cvPoint(0, img_object.rows);
//	std::vector<Point2f> scene_corners(4);
//
//	perspectiveTransform(obj_corners, scene_corners, H);
//
//	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
//	line(img_matches, scene_corners[0] + Point2f(img_object.cols, 0), scene_corners[1] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[1] + Point2f(img_object.cols, 0), scene_corners[2] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[2] + Point2f(img_object.cols, 0), scene_corners[3] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[3] + Point2f(img_object.cols, 0), scene_corners[0] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//
//	//-- Show detected matches
//	imshow("Good Matches & Object detection", img_matches);
//
//	waitKey(0);
//	return 0;
//}
//
///** @function readme */
//void readme()
//{
//	std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl;
//}








