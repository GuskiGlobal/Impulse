#include "gui/tracks/ClipWidget.h"

#include <QPainter>

ClipWidget::ClipWidget(ClipModel *model, QWidget *parent)
    : QWidget(parent), clipModel(model)
{
    setMinimumSize(60, 40);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void ClipWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(clipModel->color);
    painter.setPen(Qt::black);
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
    painter.drawText(rect(), Qt::AlignCenter, clipModel->label);
}
