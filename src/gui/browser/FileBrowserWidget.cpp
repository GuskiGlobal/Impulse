#include "gui/browser/FileBrowserWidget.h"

#include <QDir>
#include <QFileInfo>
#include <QDebug>

FileBrowserWidget::FileBrowserWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(QDir::homePath());
    fileModel->setNameFilters({ "*.wav", "*.mp3", "*.ogg" });
    fileModel->setNameFilterDisables(false);

    treeView = new QTreeView(this);
    treeView->setModel(fileModel);
    treeView->setRootIndex(fileModel->index(QDir::homePath()));
    treeView->setHeaderHidden(true);

    layout->addWidget(treeView);
    setLayout(layout);

    connect(treeView, &QTreeView::clicked,
            this, &FileBrowserWidget::onFileClicked);
}

void FileBrowserWidget::onFileClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileModel->fileInfo(index);
    if (fileInfo.isFile()) {
        qDebug() << "Arquivo selecionado:" << fileInfo.absoluteFilePath();
        // Futuramente: emitir sinal ou carregar preview
    }
}
