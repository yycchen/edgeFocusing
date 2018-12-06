#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <stdlib.h>

#include <QMainWindow>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>

#include "opencv2/opencv.hpp"

using namespace cv;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();

private:
    Ui::MainWindow *ui;
    float calculateMeanEdgeStrength(Mat image);
};

#endif // MAINWINDOW_H
