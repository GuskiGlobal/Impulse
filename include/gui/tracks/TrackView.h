#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QWidget>

class QVBoxLayout;
class QScrollArea;

class TrackView : public QWidget {
    Q_OBJECT

public:
    explicit TrackView(QWidget *parent = nullptr);
    void addTrackWidget(QWidget *widget);

signals:
    void addTrackRequested();

private slots:

private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *trackLayout;
    QScrollArea *scrollArea;
    QWidget *trackContainer;
};

#endif // TRACKVIEW_H

