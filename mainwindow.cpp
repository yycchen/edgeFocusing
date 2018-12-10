#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui -> setupUi(this);
    connect(ui -> exitBtn, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    delete ui;
}

float MainWindow::calculateMeanEdgeStrength(Mat image) {
    int subWidth = image.cols / 3;
    int subHeight = image.rows / 3;
    float meanEdgeStrength = 0;
    Mat subImage;
    std::vector<Mat> subImages;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            Rect roi(i*subWidth, j*subHeight, subWidth, subHeight);
            subImage = image(roi);
            subImages.push_back(subImage);
        }
    }

    for (int i = 0; i < subImages.size(); i++) {
        subImage = subImages[i];
        // compute dx and dy
        Mat dx, dy;
        Sobel(subImage, dx, CV_32F, 1, 0);
        Sobel(subImage, dy, CV_32F, 0, 1);

        // compute gradient
        Mat mag;
        magnitude(dx, dy, mag);
        Scalar meanVal = cv::mean(mag);
        meanEdgeStrength += meanVal.val[0];
    }
    meanEdgeStrength /= subImages.size();

    return meanEdgeStrength;
}

void MainWindow::on_browseButton_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), tr("D:/"), tr("Images (*.png *.jpg *.bmp)"));
    ui -> inputFilename -> setText(filename);

    QPixmap pm(filename);
    ui -> imageLabel -> setPixmap(pm);
    ui -> imageLabel -> setScaledContents(true);

    String fname = ui -> inputFilename -> text().toStdString();
    Mat image = imread(fname, 0);
    float mean = calculateMeanEdgeStrength(image);

    char str[30];
    sprintf(str, "Mean Edge Strength = %.3f", mean);
    QString qstr = QString(QLatin1String(str));
    ui -> meanEdgeStrength -> setText(qstr);
}
