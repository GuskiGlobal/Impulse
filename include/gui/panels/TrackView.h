#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include "gui/tracks/EmptyTrack.h"

class QVBoxLayout;
class EmptyTrack;

class TrackView : public QWidget
{
    Q_OBJECT

public:
    explicit TrackView(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
};

#endif // TRACKVIEW_H

