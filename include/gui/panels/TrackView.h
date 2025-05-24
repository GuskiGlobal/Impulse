#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class TrackView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit TrackView(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    void createDummyTracks();
};

#endif // TRACKVIEW_H

