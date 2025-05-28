#ifndef TRACKCONTROL_H
#define TRACKCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QComboBox>
#include <QLineEdit>

class TrackControl : public QWidget
{
    Q_OBJECT

public:
    explicit TrackControl(QWidget *parent = nullptr);

private:
    QVBoxLayout *controlLayout;
    QHBoxLayout *buttonsLayout;
    QPushButton *muteButton;
    QPushButton *soloButton;
    QPushButton *recordButton;
    QSlider *slider;
    QComboBox *channelSelect;
    QLineEdit *trackName;
};

#endif // TRACKCONTROL_H

