#pragma once

#include <QObject>
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>

#include "core/tracks/TrackModel.h"

class SessionController : public QObject
{
    Q_OBJECT

public:
    explicit SessionController(QObject *parent = nullptr);

    // Acesso à lista de faixas
    const QList<TrackModel*>& getTracks() const;

    // Volume
    float getVolume(TrackModel* track) const;
    void setVolume(TrackModel* track, float value);

    // BPM
    int bpm() const;
    void setBpm(int bpmValue);

    // Posição de reprodução
    int playheadPosition() const;
    void setPlayheadPosition(int pos);

    // Arquivos importados
    QStringList importedFiles() const;
    void addImportedFile(const QString &path);

public slots:
    void addTrack();

signals:
    void trackAdded(TrackModel* track);
    void volumeChanged(TrackModel* track, float volume);
    void bpmChanged(int bpm);
    void fileImported(const QString &path);

private:
    QList<TrackModel*> trackList;
    QMap<TrackModel*, float> trackVolumes;
    int m_bpm = 120;
    int m_playhead = 0;
    QStringList importedFilePaths;
};

