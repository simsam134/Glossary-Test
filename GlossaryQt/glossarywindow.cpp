#include "glossarywindow.h"

GlossaryWindow::GlossaryWindow(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant GlossaryWindow::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex GlossaryWindow::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex GlossaryWindow::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int GlossaryWindow::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int GlossaryWindow::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant GlossaryWindow::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
