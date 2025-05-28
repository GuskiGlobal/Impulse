#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QObject>
#include <QString>
#include <QList>

class ClipModel;

class TrackModel : public QObject {
    Q_OBJECT

public:
    explicit TrackModel(QObject *parent = nullptr);

    QString name;
    bool muted = false;
    bool solo = false;
    bool recording = false;

    QList<ClipModel*> clips;

signals:
    void clipAdded(ClipModel* clip);
};

#endif // TRACKMODEL_H

