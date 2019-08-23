#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include "inputHandler.hpp"

std::vector<cv::Mat> panorama(const InputHandler &inputHandler);
