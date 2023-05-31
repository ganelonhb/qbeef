#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDomDocument>
#include "detailedreportdockwidget.h"

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
    void on_toolButtonExecutableOpen_clicked();

    void on_toolButtonExecutableClear_clicked();

    void on_toolButtonArgsClear_clicked();

    void on_toolButtonInputOpen_clicked();

    void on_checkBoxAllLeaks_clicked(bool checked);

    void on_checkBoxAllHeuristics_clicked(bool checked);

    void on_radioButtonIgnoreRangeNo_toggled(bool checked);

    void on_radioButtonIgnoreRangeYes_toggled(bool checked);

    void on_radioButtonIgnoreRangeGCC_toggled(bool checked);

    void on_pushButtonDetailedReport_clicked();

private:
    Ui::MainWindow *ui;

    QDomDocument doc;
    DetailedReportDockWidget* report;

};
#endif // MAINWINDOW_H
