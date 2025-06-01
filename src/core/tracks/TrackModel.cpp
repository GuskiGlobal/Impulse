#include "core/tracks/TrackModel.h"

TrackModel::TrackModel(QObject *parent)
    : QObject(parent)
{
}

int TrackModel::volume() const
{
    return m_volume;
}

void TrackModel::setVolume(int value)
{
    if (m_volume != value) {
        m_volume = value;
        emit volumeChanged(value);
    }
}

QString TrackModel::name() const
{
    return m_name;
}

void TrackModel::setName(const QString &newName)
{
    if (m_name != newName) {
        m_name = newName;
        emit nameChanged(newName);
    }
}
