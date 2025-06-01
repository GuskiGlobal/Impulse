#include "gui/mixer/ChannelEffects.h"

ChannelEffects::ChannelEffects(QWidget *parent)
    : QWidget(parent)
    {
        effectsList = new QListWidget(this);
        effectsList->addItems({"Reverb", "Delay", "Chorus", "Flanger", "Distortion"});
        effectsLayout = new QVBoxLayout(this);
        effectsLayout->addWidget(effectsList);
        effectsLayout->setContentsMargins(0, 0, 0, 0);
        
        setLayout(effectsLayout);

        connect(effectsList, &QListWidget::itemClicked, this, [=](QListWidgetItem *item) {
        emit effectSelected(item->text());
        });
    }