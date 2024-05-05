#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTimeEdit>
#include <QListWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class TaskManager;
}
QT_END_NAMESPACE

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(QWidget *parent = nullptr);
    ~TaskManager();

private slots:
    void setupConnections();
    void addTask();
    void updateProgress();
    void updateTimerDisplay();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void customizeLCD();

private:
    QLCDNumber *lcdTimer;
    QTimer *timer;
    QTime *currentTime;
    QTimeEdit *timeSetter;  // Or QSpinBox
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    Ui::TaskManager *ui;
};

#endif // TASKMANAGER_H
