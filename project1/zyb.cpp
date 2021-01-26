//============================================================================
// Name        : zyb.cpp
// Author      : 邹博诚
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

void dump(const std::vector<std::vector<int>> &data) {
	for (std::vector<int> row : data) {
		for (int x : row) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
}

std::string formatImagePath(int id) {
	const char path[] = "./images/";
	const char suffix[] = ".png";
	std::stringstream ss;
	ss << path;
	ss << id;
	ss << suffix;
	return ss.str();
}

void show(const std::vector<std::vector<int>> &data) {
	if (data.size() == 0 || data[0].size() == 0) {
		std::cerr << "Empty data" << std::endl;
		return;
	}
	//获取参数
	cv::Mat tmp = cv::imread(formatImagePath(data[0][0]));
	if (tmp.data == nullptr) {
		std::cerr << "Failed to read file:" << formatImagePath(data[0][0])
				<< std::endl;
		return;
	}
	int width = tmp.cols;
	int heigh = tmp.rows;
	cv::Mat result = cv::Mat::zeros(heigh * data.size(), width * data[0].size(),
	CV_8UC3);
	for (unsigned long i = 0; i < data.size(); i++) {
		for (unsigned long j = 0; j < data[i].size(); j++) {
			cv::Mat tmp = cv::imread(formatImagePath(data[i][j]));
			if (tmp.data == nullptr) {
				std::cerr << "Failed to read file:"
						<< formatImagePath(data[0][0]) << std::endl;
				return;
			}
			cv::Mat imageROI = result(
					cv::Rect(j * width, i * heigh, width, heigh));
			tmp.copyTo(imageROI, tmp);
		}
	}
	cv::imshow("test", result);
	cv::waitKey(0);
}

//Just for test
int main() {
	int m, n;
	std::cin >> m >> n;
	std::vector<std::vector<int>> data;
	for (int i = 0; i < m; i++) {
		std::vector<int> row;
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;
			row.push_back(x);
		}
		data.push_back(row);
	}
	dump(data);
	show(data);
	std::cout << "" << std::endl;
	return 0;
}
