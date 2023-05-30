#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditExecutable->setFocus();
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


void MainWindow::on_checkBoxAllLeaks_clicked(bool checked)
{
    ui->checkBoxIndirect->setEnabled(!checked);
    ui->checkBoxReachable->setEnabled(!checked);
    ui->checkBoxPossible->setEnabled(!checked);
    ui->checkBoxDefinite->setEnabled(!checked);

    if (checked)
    {
        ui->checkBoxIndirect->setChecked(true);
        ui->checkBoxReachable->setChecked(true);
        ui->checkBoxPossible->setChecked(true);
        ui->checkBoxDefinite->setChecked(true);
    }

    return;
}


void MainWindow::on_checkBoxAllHeuristics_clicked(bool checked)
{
    ui->checkBoxHstdstring->setEnabled(!checked);
    ui->checkBoxHlength64->setEnabled(!checked);
    ui->checkBoxHnewarray->setEnabled(!checked);
    ui->checkBoxHmultipleinheritance->setEnabled(!checked);

    if (checked)
    {
        ui->checkBoxHstdstring->setChecked(true);
        ui->checkBoxHlength64->setChecked(true);
        ui->checkBoxHnewarray->setChecked(true);
        ui->checkBoxHmultipleinheritance->setChecked(true);
    }

    return;
}


void MainWindow::on_radioButtonIgnoreRangeNo_toggled(bool checked)
{
    if (checked)
    {
        ui->spinBoxIgnoreRangeBelowSPLower->setEnabled(false);
        ui->labelTo->setEnabled(false);
        ui->spinBoxIgnoreRangeBelowSPUpper->setEnabled(false);
    }

    return;
}


void MainWindow::on_radioButtonIgnoreRangeYes_toggled(bool checked)
{
    if (checked)
    {
        ui->spinBoxIgnoreRangeBelowSPLower->setEnabled(true);
        ui->labelTo->setEnabled(true);
        ui->spinBoxIgnoreRangeBelowSPUpper->setEnabled(true);
    }

    return;
}


void MainWindow::on_radioButtonIgnoreRangeGCC_toggled(bool checked)
{
    if (checked)
    {
        ui->spinBoxIgnoreRangeBelowSPLower->setEnabled(false);
        ui->labelTo->setEnabled(true);
        ui->spinBoxIgnoreRangeBelowSPUpper->setEnabled(false);

        ui->spinBoxIgnoreRangeBelowSPLower->setValue(1024);
        ui->spinBoxIgnoreRangeBelowSPUpper->setValue(1);
    }

    return;
}

