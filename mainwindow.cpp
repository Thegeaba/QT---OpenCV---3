#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Incarca imaginea de fundal
void MainWindow::on_btn_loadImage_clicked()
{
    path = QFileDialog::getOpenFileName(this, "Selectați o imagine", QDir::homePath(), "Imagini (*.png *.jpg *.jpeg)");

    if (!path.isEmpty()) {
        background = imread(path.toStdString());
        cv::resize(background, background, Size(backgroundWidth, backgroundHeight));

        QString tempImagePath = "background.jpg";
        imwrite(tempImagePath.toStdString(), background);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
    }
}

// Scrie textul pe imaginea de fundal
void MainWindow::on_btn_textWrite_clicked()
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        QString labelPosX = "X: " + QString::number(posX);
        QString labelPosY = "Y: " + QString::number(posY);
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        ui->label_coordX->setText(labelPosX);
        ui->label_coordY->setText(labelPosY);
    }
}

// posX
void MainWindow::on_horizontalSlider_textPoz_valueChanged(int value)
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        posX = value;
        QString labelPosX = "X: " + QString::number(posX);
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        ui->label_coordX->setText(labelPosX);
    }
}

// posY
void MainWindow::on_verticalSlider_textPoz_valueChanged(int value)
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        posY = value;
        QString labelPosY = "Y: " + QString::number(posY);
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        ui->label_coordY->setText(labelPosY);
    }
}


// Size
void MainWindow::on_verticalSlider_textSize_valueChanged(int value)
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        fontSize = value;
        QString labelFontSize = "Size: " + QString::number(fontSize);
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        ui->label_size->setText(labelFontSize);
    }
}

// Bold
void MainWindow::on_verticalSlider_textBold_valueChanged(int value)
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        textBold = value;
        QString labelFontBold = "Bold: " + QString::number(textBold);
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        ui->label_bold->setText(labelFontBold);
    }
}

// Alege culoarea
void MainWindow::on_btn_textColor_clicked()
{
    if(!path.isEmpty()){
        text = ui->inputText->toPlainText();
        const String textConst = text.toStdString();
        Mat modifiedBackground = background.clone();

        QColor newColor = QColorDialog::getColor(QColor(textColor[0], textColor[1], textColor[2]), this);

        if (newColor.isValid()) {
            textColor = Scalar(newColor.blue(), newColor.green(), newColor.red());

            putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);
        }

        QString tempImagePath = "modified_background.jpg";
        imwrite(tempImagePath.toStdString(), modifiedBackground);

        ui->frame_background->setStyleSheet("background-image: url(" + tempImagePath + ");");
        QString cssColor = QString("background-color: rgb(%1, %2, %3);").arg(textColor[2]).arg(textColor[1]).arg(textColor[0]);
        ui->frame_color->setStyleSheet(cssColor);
    }
}

// Salvare
void MainWindow::on_btn_save_clicked()
{
    if(!path.isEmpty()){
        Mat modifiedBackground = background.clone();
        const String textConst = text.toStdString();
        putText(modifiedBackground, textConst, Point(posX, posY), FONT_HERSHEY_SIMPLEX, fontSize, textColor, textBold);

        QString fileSaveDirectory = "C:/Users/Cristi/Desktop/OpenCV   C++/imagini/destinatie/";
        QString imageName = QString("%1POZA_%2.jpg").arg(fileSaveDirectory).arg(sequence, 4, 10, QChar('0'));
        imwrite(imageName.toStdString(), modifiedBackground);
        sequence += 1;
    }
}

