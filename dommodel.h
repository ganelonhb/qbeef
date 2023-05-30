#ifndef DOMMODEL_H
#define DOMMODEL_H

#include <QAbstractItemModel>
#include <QObject>

class DomModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DomModel(QObject *parent = nullptr);
};

#endif // DOMMODEL_H
