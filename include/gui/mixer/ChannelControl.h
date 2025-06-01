#ifndef CHANNELCONTROL_H
#define CHANNELCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>

class ChannelControl : public QWidget
{
    Q_OBJECT
public:
    explicit ChannelControl(QWidget *parent = nullptr);
private:
    QVBoxLayout *controlLayout;
    QVBoxLayout *buttonsLayout;
    QHBoxLayout *soundButtonsLayout;
    QHBoxLayout *extraButtonsLayout;
    QPushButton *muteButton;
    QPushButton *soloButton;
    QPushButton *recordButton;
    QPushButton *monitorButton;
    QSlider *panSlider;
};

#endif // CHANNELCONTROL_H