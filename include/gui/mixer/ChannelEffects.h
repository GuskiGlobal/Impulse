#ifndef CHANNELEFFECTS_H
#define CHANNELEFFECTS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

class ChannelEffects : public QWidget
{
    Q_OBJECT
public:
    explicit ChannelEffects(QWidget *parent = nullptr);

    void addEffect(const QString &effectName);
    void removeEffect(const QString &effectName);
    void clearEffects();
    QStringList getEffects() const;

signals:
    void effectSelected(const QString &effectName);

private:
    QVBoxLayout *effectsLayout;
    QListWidget *effectsList;

    // Reservado para UI futura
    QPushButton *effectButton;
    QPushButton *addEffectButton;
    QComboBox *effectSelector;
    QLabel *effectsLabel;
};

#endif // CHANNELEFFECTS_H
