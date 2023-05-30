#include "dommodel.h"

DomModel::DomModel(const QDomDocument& document, QObject *parent)
    : QAbstractItemModel{parent},
      domDocument(document),
      rootItem(new DomItem(domDocument, 0))
{}

DomModel::~DomModel()
{
    delete rootItem;
}

int DomModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 3;
}

Qt::ItemFlags DomModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant DomModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
        case 0:
            return tr("Name");
        case 1:
            return tr("Atributes");
        case 2:
            return tr("Value");
        default:
            break;
        }
    }

    return QVariant();
}

QModelIndex DomModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    DomItem* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<DomItem*>(parent.internalPointer());

    DomItem* childItem = parentItem->child(row);

    if (childItem)
        return createIndex(row, column, childItem);

    return QModelIndex();
}

int DomModel::rowCount(const QModelIndex& parent) const
{
    if (parent.column() > 0)
        return 0;

    DomItem* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<DomItem*>(parent.internalPointer());

    return parentItem->node().childNodes().count();
}

QModelIndex DomModel::parent(const QModelIndex& child) const
{
    if (!child.isValid())
        return QModelIndex();

    DomItem* childItem = static_cast<DomItem*>(child.internalPointer());
    DomItem* parentItem = childItem->parent();

    if (!parentItem || parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

QVariant DomModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    const DomItem* item = static_cast<DomItem*>(index.internalPointer());
    const QDomNode node = item->node();

    switch (index.column())
    {
    case 0:
        return node.nodeName();
    case 1:
    {
        const QDomNamedNodeMap attributeMap = node.attributes();
        QStringList attributes;
        for (int i = 0; i < attributeMap.count(); ++i)
        {
            QDomNode attribute = attributeMap.item(i);
            attributes << attribute.nodeName() + "=\"" + attribute.nodeValue() + "\"";
        }
        return attributes.join(' ');
    }
    case 2:
        return node.nodeValue().split('\n').join(' ');
    default:
        break;
    }

    return QVariant();
}
