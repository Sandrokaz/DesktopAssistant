#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include <QTimeEdit>
#include <QListWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    //QTime *currentTime;
    QTimeEdit *timeSetter;  // Or QSpinBox
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
