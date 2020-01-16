//
//  recdetect.h
//  recdetect
//
//  Created by fujikoli(李鑫) on 2017/9/15.
//  Copyright © 2017年 fujikoli(李鑫). All rights reserved.
//
//  远程身份认证iOS端SDK
//  v1.4.0
//

#ifndef recdetect_h
#define recdetect_h

//#include <opencv2/imgproc.hpp>
//#include <opencv2/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

/**
 * 清晰度检测
 * @param imgSrc            输入图像
 * @return                  返回清晰度程度，值越大图像越清晰
 */
    double blurDetect(cv::Mat& imgSrc);

/**
 * 身份证边缘检测
 * @param imgSrc            输入图像
 * @param corners           检测出的身份证的四个顶点，顺时针排序，未检出size为0
 * @param roiRect           ROI区域
 * @param threshold1        身份证长宽比低阈值
 * @param threshold2        身份证长宽比高阈值
 */
    void IDCardDetect(cv::Mat& imgSrc, std::vector<cv::Point>& corners, cv::Rect& roiRect, double threshold1, double threshold2);

/**
 * 银行卡边缘检测
 * @param imgSrc            输入图像
 * @param corners           检测出的银行卡的四个顶点，顺时针排序，未检出size为0
 * @param roiRect           ROI区域
 * @param threshold1        长边与短边的比的低阈值，低于该阈值的矩形在内部逻辑中被过滤
 * @param threshold2        长边与短边的比的高阈值，高于该阈值的矩形在内部逻辑中被过滤
 */
    void BankCardDetect(cv::Mat& imgSrc, std::vector<cv::Point>& corners, cv::Rect& roiRect, double threshold1, double threshold2);

/**
 * 角度检测
 * @param corners           输入检测出的四个顶点
 * @return                  返回四个点连线形成的不规则四边形面积与包围四个点的最小外接矩形的比值
 */
    double distortionDetect(std::vector<cv::Point> corners);

/**
 * 版本
 * @return                  版本号
 */
    std::string Version();

#endif /* recdetect_h */
