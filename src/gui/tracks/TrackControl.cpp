#include "gui/tracks/TrackControl.h"

TrackControl::TrackControl(QWidget *parent)
    : QWidget(parent)
{
    controlLayout = new QVBoxLayout();

    trackName = new QLineEdit(this);
    trackName->setText("New Track");
    trackName->setObjectName("trackNameEdit");

    buttonsLayout = new QHBoxLayout();

    muteButton = new QPushButton("M", this);
    muteButton->setCheckable(true);
    muteButton->setObjectName("muteButton");

    soloButton = new QPushButton("S", this);
    soloButton->setCheckable(true);
    soloButton->setObjectName("soloButton");

    recordButton = new QPushButton("R", this);
    recordButton->setCheckable(true);
    recordButton->setObjectName("recordButton");

    slider = new QSlider(Qt::Horizontal, this);
    channelSelect = new QComboBox(this);

    buttonsLayout->addWidget(muteButton);
    buttonsLayout->addWidget(soloButton);
    buttonsLayout->addWidget(recordButton);

    controlLayout->addWidget(trackName);
    controlLayout->addLayout(buttonsLayout);
    controlLayout->addWidget(slider);
    controlLayout->addWidget(channelSelect);

    controlLayout->setSpacing(6);
    controlLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(controlLayout);
    setFixedWidth(150); // Mantém a mesma largura fixa que o GroupBox tinha
}

