#ifndef CLIPMODEL_H
#define CLIPMODEL_H

#include <QObject>
#include <QString>
#include <QColor>

class ClipModel : public QObject {
    Q_OBJECT

public:
    explicit ClipModel(QObject *parent = nullptr);

    QString label;
    int startTick = 0;
    int duration = 480; // duração padrão de 1 compasso em PPQ 480
    QColor color = QColor("#3F72AF");

signals:
    void updated();
};

#endif // CLIPMODEL_H
