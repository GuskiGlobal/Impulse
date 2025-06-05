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

    explicit TrackModel(int id, QObject *parent = nullptr);
    explicit TrackModel(const QString &name, int id, QObject *parent = nullptr);
    explicit TrackModel(const QString &name, int id, int volume, QObject *parent = nullptr);

    // track ID
    int id() const{ return track_id; }

    // Track properties
    bool muted = false;
    bool solo = false;
    bool recording = false;


    QList<ClipModel*> clips;

    // Volume
    int volume() const;
    void setVolume(int value);

    // Name
    QString name() const;
    void setName(const QString &newName);

signals:
    void clipAdded(ClipModel* clip);
    void volumeChanged(int value);
    void nameChanged(const QString &newName);

private:
    int track_id;
    int track_volume = 80;
    QString track_name = "Untitled";
};

#endif // TRACKMODEL_H
