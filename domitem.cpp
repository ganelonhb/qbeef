#include "domitem.h"

DomItem::DomItem(const QDomNode& node, int row, DomItem* parent)
    : domNode(node),
      parentItem(parent),
      rowNumber(row)
{}
DomItem::~DomItem()
{
    qDeleteAll(this->childItems);
}

DomItem* DomItem::parent()
{
    return this->parentItem;
}

int DomItem::row() const
{
    return this->rowNumber;
}

QDomNode DomItem::node() const
{
    return this->domNode;
}

DomItem* DomItem::child(int i)
{
    DomItem* childItem = childItems.value(i);

    if (childItem)
        return childItem;

    // If the child does not yet exist, create it.
    if (i >= 0 && i < domNode.childNodes().count())
    {
        QDomNode childNode = domNode.childNodes().item(i);
        childItem = new DomItem(childNode, i, this);
        childItems[i] = childItem;
    }

    return childItem;
}
