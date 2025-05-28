#ifndef FILEBROWSERWIDGET_H
#define FILEBROWSERWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QModelIndex>

class FileBrowserWidget : public QWidget {
    Q_OBJECT

public:
    explicit FileBrowserWidget(QWidget *parent = nullptr);

private slots:
    void onFileClicked(const QModelIndex &index);

private:
    QTreeView *treeView;
    QFileSystemModel *fileModel;
};

#endif // FILEBROWSERWIDGET_H
