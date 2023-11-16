#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QtGui>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <QColorDialog>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_loadImage_clicked();

    void on_btn_textWrite_clicked();

    void on_horizontalSlider_textPoz_valueChanged(int value);

    void on_verticalSlider_textPoz_valueChanged(int value);

    void on_verticalSlider_textSize_valueChanged(int value);

    void on_verticalSlider_textBold_valueChanged(int value);

    void on_btn_textColor_clicked();

    void on_btn_save_clicked();

private:
    Ui::MainWindow *ui;

    Mat background;
    QString path;
    QString text;
    int posX = 256;
    int posY = 256;
    int fontSize = 1;
    int textBold = 1;

    Scalar textColor = Scalar(0, 0, 0);
    int backgroundWidth = 512;
    int backgroundHeight = 512;
    int sequence = 1;


};
#endif // MAINWINDOW_H
