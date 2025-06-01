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

    // Atributos de estado
    bool muted = false;
    bool solo = false;
    bool recording = false;

    // Clips da faixa
    QList<ClipModel*> clips;

    // Volume
    int volume() const;
    void setVolume(int value);

    // Nome
    QString name() const;
    void setName(const QString &newName);

signals:
    void clipAdded(ClipModel* clip);
    void volumeChanged(int value);
    void nameChanged(const QString &newName);

private:
    int m_volume = 80;
    QString m_name = "Untitled";
};

#endif // TRACKMODEL_H
