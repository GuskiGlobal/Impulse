#include "gui/panels/TrackView.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>
#include <QColor>

TrackView::TrackView(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    setDragMode(QGraphicsView::ScrollHandDrag);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // Fundo da timeline (em tema global ou manualmente se preferir)
    scene->setBackgroundBrush(QColor("#222831"));  // ou use Theme::Background

    createDummyTracks();
}

void TrackView::createDummyTracks()
{
    const int trackHeight = 60;
    const int trackSpacing = 10;
    const int trackWidth = 800;

    for (int i = 0; i < 5; ++i) {
        int y = i * (trackHeight + trackSpacing);

        // Linha de faixa
        QGraphicsRectItem *trackLine = scene->addRect(0, y, trackWidth, trackHeight,
                                                      QPen(Qt::gray),
                                                      QBrush(QColor("#393E46")));

        // Nome da faixa
        QGraphicsTextItem *label = scene->addText(QString("Track %1").arg(i + 1));
        label->setDefaultTextColor(QColor("#EEEEEE"));
        label->setPos(5, y + 5);

        // Clip de exemplo
        QGraphicsRectItem *clip = scene->addRect(120, y + 10, 200, 40,
                                                 QPen(Qt::NoPen),
                                                 QBrush(QColor("#FD7014")));
    }

    scene->setSceneRect(0, 0, trackWidth + 200, 400);
}

