#ifndef DOMMODEL_H
#define DOMMODEL_H

// Uses implementation defined here:
//  https://doc.qt.io/qt-5/qtwidgets-itemviews-simpledommodel-example.html

#include <QAbstractItemModel>
#include <QObject>
#include <QDomDocument>
#include <QDomNamedNodeMap>
#include <QVariant>
#include <QModelIndex>
#include <QStringList>

#include "domitem.h"

class DomModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DomModel(const QDomDocument& document, QObject *parent = nullptr);
    ~DomModel();

    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(    int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& child) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

private:
    QDomDocument domDocument;
    DomItem* rootItem;
};

#endif // DOMMODEL_H
