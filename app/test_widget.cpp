#include "test_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <opencv2/opencv.hpp>
#include <cstdlib> // Include the header for getenv
#include <iostream>

test_widget::test_widget(QWidget *parent)
    : QMainWindow(parent)
{
    const char* varName = "MY_VARIABLE"; // Replace with the name of the environment variable you want to retrieve
    char* envValue = std::getenv(varName);
    if (envValue != nullptr) {
        std::cout << "Value of " << varName << " is: " << envValue << std::endl;
    } else {
        std::cout << "Environment variable " << varName << " is not set." << std::endl;
    }


    // Create a central widget (e.g., a QWidget) to contain your content
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create a layout for the central widget
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create a QLabel to display the image
    QLabel *imageLabel = new QLabel(centralWidget);
    layout->addWidget(imageLabel);

    // Load an image using OpenCV
    cv::Mat image = cv::imread("./../kisspng-python.jpg"); // Replace with the actual image path

    if (!image.empty()) {
        // Convert the OpenCV image to a QImage for display
        QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

        // Display the image in the QLabel
        imageLabel->setPixmap(QPixmap::fromImage(qImage));
    } else {
        // If image loading fails, display a placeholder message
        imageLabel->setText("Image not found");
    }

    // Create a QPushButton for toggling the color
    QPushButton *toggleButton = new QPushButton("Toggle Color", centralWidget);
    layout->addWidget(toggleButton);

    // Connect the button's clicked signal to a slot
    connect(toggleButton, &QPushButton::clicked, this, &test_widget::toggleColor);

    // Initialize the color flag
    colorFlag = false;
}

test_widget::~test_widget()
{
}

void test_widget::toggleColor(void)
{
    if (colorFlag) {
        // Set the background color to a different color (e.g., red)
        centralWidget()->setStyleSheet("background-color: red;");
    } else {
        // Set the background color to the original color (e.g., white)
        centralWidget()->setStyleSheet("background-color: white;");
    }


    // Toggle the color flag
    colorFlag = !colorFlag;
    std::cout << "Color flag set to: " << colorFlag << std::endl;
}
