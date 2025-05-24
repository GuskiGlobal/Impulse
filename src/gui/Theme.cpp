#include "gui/Theme.h"
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

bool Theme::applyTheme(const QString &filePath) {
    QString fullPath = QCoreApplication::applicationDirPath() + "/" + filePath;

    QFile file(fullPath);
    if (!file.exists()) {
        qWarning() << "[Theme] Arquivo não encontrado:" << fullPath;
        return false;
    }

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "[Theme] Falha ao abrir o arquivo:" << fullPath;
        return false;
    }

    QTextStream in(&file);
    QString styleSheet = in.readAll();
    qApp->setStyleSheet(styleSheet);

    qDebug() << "[Theme] Tema aplicado com sucesso:" << fullPath;
    return true;
}

