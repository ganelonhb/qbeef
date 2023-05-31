#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditExecutable->setFocus();

    this->report = new DetailedReportDockWidget(this);
    report->setVisible(false);

    //report->setXML("<?xml version=\"1.0\"?>\n\n<valgrindoutput>\n\n<protocolversion>4</protocolversion>\n<protocoltool>memcheck</protocoltool>\n\n<preamble>\n  <line>Memcheck, a memory error detector</line>\n  <line>Copyright (C) 2002-2022, and GNU GPL\'d, by Julian Seward et al.</line>\n  <line>Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info</line>\n  <line>Command: ./a.out</line>\n</preamble>\n\n<pid>59875</pid>\n<ppid>59609</ppid>\n<tool>memcheck</tool>\n\n<args>\n  <vargv>\n    <exe>/usr/bin/valgrind</exe>\n    <arg>--xml=yes</arg>\n    <arg>--xml-file=TEST.txt</arg>\n  </vargv>\n  <argv>\n    <exe>./a.out</exe>\n  </argv>\n</args>\n\n<status>\n  <state>RUNNING</state>\n  <time>00:00:00:00.349 </time>\n</status>\n\n\n<status>\n  <state>FINISHED</state>\n  <time>00:00:00:01.950 </time>\n</status>\n\n<error>\n  <unique>0x0</unique>\n  <tid>1</tid>\n  <kind>Leak_DefinitelyLost</kind>\n  <xwhat>\n    <text>256 bytes in 16 blocks are definitely lost in loss record 1 of 1</text>\n    <leakedbytes>256</leakedbytes>\n    <leakedblocks>16</leakedblocks>\n  </xwhat>\n  <stack>\n    <frame>\n      <ip>0x4843223</ip>\n      <obj>/usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so</obj>\n      <fn>operator new[](unsigned long)</fn>\n      <dir>/usr/src/debug/valgrind/valgrind-3.21.0/coregrind/m_replacemalloc</dir>\n      <file>vg_replace_malloc.c</file>\n      <line>714</line>\n    </frame>\n    <frame>\n      <ip>0x109153</ip>\n      <obj>/home/donquixote/Repos/cpp/purposeful memleak/a.out</obj>\n      <fn>main</fn>\n    </frame>\n  </stack>\n</error>\n\n<errorcounts>\n</errorcounts>\n\n<suppcounts>\n</suppcounts>\n\n</valgrindoutput>\n\n");
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


void MainWindow::on_pushButtonDetailedReport_clicked()
{
    if (!report->isVisible())
            report->setVisible(true);

    return;
}

