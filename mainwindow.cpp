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
    // compute da and dy
    Mat dx, dy;
    Sobel(image, dx, CV_32F, 1, 0);
    Sobel(image, dy, CV_32F, 0, 1);

    // compute gradient
    Mat mag;
    magnitude(dx, dy, mag);
    Scalar meanVal = cv::mean(mag);

    return float(meanVal.val[0]);
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
