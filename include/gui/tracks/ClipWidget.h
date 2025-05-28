#ifndef CLIPWIDGET_H
#define CLIPWIDGET_H

#include <QWidget>
#include <QColor>

#include "core/tracks/ClipModel.h"

class ClipWidget : public QWidget {
    Q_OBJECT

public:
    explicit ClipWidget(ClipModel *model, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ClipModel *clipModel;
};

#endif // CLIPWIDGET_H
