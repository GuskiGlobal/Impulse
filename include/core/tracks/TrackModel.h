#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QObject>
#include <QString>
#include <QList>

#include "core/tracks/ClipModel.h"

class TrackModel : public QObject {
    Q_OBJECT

public:
    explicit TrackModel(QObject *parent = nullptr);

    QString name;
    bool muted = false;
    bool solo = false;
    bool recording = false;

    QList<ClipModel*> clips;

    int volume() const;
    void setVolume(int value);

signals:
    void clipAdded(ClipModel* clip);
    void volumeChanged(int value);

private:
    int m_volume = 80;
};

#endif // TRACKMODEL_H

