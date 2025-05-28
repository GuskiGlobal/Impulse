#ifndef EMPTYTRACK_H
#define EMPTYTRACK_H

#include "gui/tracks/TrackControl.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QString>

class EmptyTrack : public QWidget
{
    Q_OBJECT

public:
    explicit EmptyTrack(QWidget *parent = nullptr);
    void setTrackId(const QString &id);
    QString getTrackId() const;


private:
    QString trackId;
    QLabel *trackArea;
    TrackControl *trackControl;
    QHBoxLayout *trackLayout;
    QLabel *trackLabel;
    QLabel *dragBar;
};

#endif // EMPTYTRACK_H

