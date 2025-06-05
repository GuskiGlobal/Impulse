#include "core/tracks/TrackModel.h"

TrackModel::TrackModel(QObject *parent)
    : QObject(parent)
{
}

TrackModel::TrackModel(int id, QObject *parent)
    : QObject(parent), track_id(id)
{
}

TrackModel::TrackModel(const QString &name, int id, QObject *parent)
    : QObject(parent), track_id(id), track_name(name)
{
}

TrackModel::TrackModel(const QString &name, int id, int volume, QObject *parent)
    : QObject(parent), track_id(id), track_volume(volume), track_name(name)
{
}

int TrackModel::volume() const
{
    return track_volume;
}

void TrackModel::setVolume(int value)
{
    if (track_volume != value) {
        track_volume = value;
        emit volumeChanged(value);
    }
}

QString TrackModel::name() const
{
    return track_name;
}

void TrackModel::setName(const QString &newName)
{
    if (track_name != newName) {
        track_name = newName;
        emit nameChanged(newName);
    }
}

//int TrackModel::id() const
//{
//    return track_id;
//}

