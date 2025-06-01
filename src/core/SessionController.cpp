#include "core/SessionController.h"

SessionController::SessionController(QObject *parent)
    : QObject(parent)
{
}

const QList<TrackModel*>& SessionController::getTracks() const {
    return trackList;
}

void SessionController::addTrack() {
    auto *track = new TrackModel(this);
    track->setName(QString("Track %1").arg(trackList.size() + 1));
    trackList.append(track);
    trackVolumes[track] = 1.0f; 
    emit trackAdded(track); // <- usado pelo MixerView
}

float SessionController::getVolume(TrackModel *track) const {
    return trackVolumes.value(track, 1.0f);
}

void SessionController::setVolume(TrackModel *track, float value) {
    if (trackVolumes.contains(track)) {
        trackVolumes[track] = value;
        emit volumeChanged(track, value); // <- pode ser usado para mover slider
    }
}

int SessionController::bpm() const {
    return m_bpm;
}

void SessionController::setBpm(int bpmValue) {
    if (m_bpm != bpmValue) {
        m_bpm = bpmValue;
        emit bpmChanged(bpmValue);
    }
}

int SessionController::playheadPosition() const {
    return m_playhead;
}

void SessionController::setPlayheadPosition(int pos) {
    m_playhead = pos;
}

QStringList SessionController::importedFiles() const {
    return importedFilePaths;
}

void SessionController::addImportedFile(const QString &path) {
    if (!importedFilePaths.contains(path)) {
        importedFilePaths.append(path);
        emit fileImported(path);
    }
}
