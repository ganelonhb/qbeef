#ifndef DETAILEDREPORTDOCKWIDGET_H
#define DETAILEDREPORTDOCKWIDGET_H

#include <QDockWidget>
#include <QString>
#include <QByteArray>
#include <QDomDocument>
#include <QHeaderView>

#include "dommodel.h"

namespace Ui {
class DetailedReportDockWidget;
}

class DetailedReportDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit DetailedReportDockWidget(QWidget *parent = nullptr);
    ~DetailedReportDockWidget();

    void setXML(const QString& str);

private slots:
    void on_toolButtonExpandAll_clicked();

    void on_toolButtonCollapseAll_clicked();

    void on_pushButtonHideSelf_clicked();

private:
    Ui::DetailedReportDockWidget *ui;

};

#endif // DETAILEDREPORTDOCKWIDGET_H
