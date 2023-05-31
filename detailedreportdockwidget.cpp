#include "detailedreportdockwidget.h"
#include "ui_detailedreportdockwidget.h"

DetailedReportDockWidget::DetailedReportDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DetailedReportDockWidget)
{
    ui->setupUi(this);
}

DetailedReportDockWidget::~DetailedReportDockWidget()
{
    delete ui;
}

void DetailedReportDockWidget::setXML(const QString& str)
{
    QDomDocument d;
    d.setContent(str);

    ui->treeViewReport->setModel(new DomModel(d, this));
    ui->treeViewReport->expandAll();

    ui->treeViewReport->header()->setStretchLastSection(false);
    ui->treeViewReport->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    return;
}

void DetailedReportDockWidget::on_toolButtonExpandAll_clicked()
{
    return ui->treeViewReport->expandAll();
}


void DetailedReportDockWidget::on_toolButtonCollapseAll_clicked()
{
    return ui->treeViewReport->collapseAll();
}


void DetailedReportDockWidget::on_pushButtonHideSelf_clicked()
{
    return this->hide();
}

