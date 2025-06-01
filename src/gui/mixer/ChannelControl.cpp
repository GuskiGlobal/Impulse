#include "gui/mixer/ChannelControl.h"

ChannelControl::ChannelControl(QWidget *parent)
    :QWidget(parent)
{
    controlLayout = new QVBoxLayout(this);
    buttonsLayout = new QVBoxLayout();
    soundButtonsLayout = new QHBoxLayout();
    extraButtonsLayout = new QHBoxLayout();

    panSlider = new QSlider(Qt::Horizontal, this);
    panSlider->setRange(-100, 100);
    panSlider->setValue(0);
    panSlider->setMinimumWidth(60);
    panSlider->setMaximumWidth(60);
    panSlider->setTickPosition(QSlider::TicksAbove);
    panSlider->setTickInterval(50);
    panSlider->setSingleStep(25);
    panSlider->setPageStep(10);
    panSlider->setToolTip("Pan Control");
    panSlider->setToolTipDuration(2000);

    muteButton = new QPushButton("M", this);
    soloButton = new QPushButton("S", this);
    recordButton = new QPushButton("R", this);
    monitorButton = new QPushButton("M", this);

    soundButtonsLayout->addWidget(muteButton);
    soundButtonsLayout->addWidget(soloButton);
    soundButtonsLayout->setContentsMargins(0, 0, 0, 0);
    extraButtonsLayout->addWidget(recordButton);
    extraButtonsLayout->addWidget(monitorButton);
    extraButtonsLayout->setContentsMargins(0, 0, 0, 0);

    buttonsLayout->addLayout(soundButtonsLayout);
    buttonsLayout->addLayout(extraButtonsLayout);
    buttonsLayout->setContentsMargins(0, 0, 0, 0);
    buttonsLayout->setAlignment(Qt::AlignCenter);
    buttonsLayout->setSpacing(2);

    controlLayout->addWidget(panSlider);
    controlLayout->addLayout(buttonsLayout);
    controlLayout->setContentsMargins(0, 0, 0, 0);
    controlLayout->setSpacing(4);
    controlLayout->setAlignment(Qt::AlignCenter);
    setLayout(controlLayout);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    setMinimumWidth(60);
    setMaximumWidth(60);
}