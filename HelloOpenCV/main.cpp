#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::namedWindow("raw", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("canny", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture cap;
    cap.open(0);

    if (!cap.isOpened()) {
        std::cerr << "Couldn't open camera" << std::endl;
        return -1;
    }

    cv::UMat frame, gray, canny;

    for (;;) {
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("raw", frame);

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::imshow("gray", gray);

        cv::Canny(gray, canny, 10, 100, 3, true);
        cv::imshow("canny", canny);

        char c = cv::waitKey(10);
        if (c == 27) break;
    }

    cap.release();
    return 0;
}
