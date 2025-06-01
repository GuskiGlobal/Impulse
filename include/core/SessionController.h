#ifndef SESSIONCONTROLLER_H
#define SESSIONCONTROLLER_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QStringList>

#include "core/tracks/TrackModel.h"

class SessionController : public QObject
{
    Q_OBJECT

public:
    explicit SessionController(QObject *parent = nullptr);

    const QList<TrackModel*>& getTracks() const;
    void addTrack();

    float getVolume(TrackModel *track) const;
    void setVolume(TrackModel *track, float value);

    int bpm() const;
    void setBpm(int bpmValue);

    int playheadPosition() const;
    void setPlayheadPosition(int pos);

    QStringList importedFiles() const;
    void addImportedFile(const QString &path);

signals:
    void trackAdded(TrackModel *track);
    void volumeChanged(TrackModel *track, float value);
    void bpmChanged(int bpm);
    void fileImported(const QString &path);

private:
    QList<TrackModel*> trackList;
    QMap<TrackModel*, float> trackVolumes;
    QStringList importedFilePaths;

    int m_bpm = 120;
    int m_playhead = 0;
};

#endif // SESSIONCONTROLLER_H
