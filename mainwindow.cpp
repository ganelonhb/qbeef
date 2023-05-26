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


void MainWindow::on_toolButtonExecutableOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Executable"), QDir::homePath());

    return ui->lineEditExecutable->setText(fileName);
}


void MainWindow::on_toolButtonExecutableClear_clicked()
{
    return ui->lineEditExecutable->clear();
}


void MainWindow::on_toolButtonArgsClear_clicked()
{
    return ui->lineEditArgs->clear();
}


void MainWindow::on_toolButtonInputOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath());

    return ui->lineEditInput->setText(fileName);
}

