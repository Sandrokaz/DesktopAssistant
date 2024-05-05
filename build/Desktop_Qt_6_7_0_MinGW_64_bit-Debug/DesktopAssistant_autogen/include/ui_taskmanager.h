/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QTextEdit *taskInput;
    QPushButton *addButton;
    QListWidget *tasksList;
    QLCDNumber *lcdTimer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QTimeEdit *timeSetter;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QWidget *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName("TaskManager");
        TaskManager->resize(1309, 999);
        centralwidget = new QWidget(TaskManager);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1321, 933));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 230, 1281, 23));
        progressBar->setValue(0);
        taskInput = new QTextEdit(centralwidget);
        taskInput->setObjectName("taskInput");
        taskInput->setGeometry(QRect(30, 260, 541, 671));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(590, 480, 111, 41));
        tasksList = new QListWidget(centralwidget);
        tasksList->setObjectName("tasksList");
        tasksList->setGeometry(QRect(720, 260, 571, 671));
        lcdTimer = new QLCDNumber(centralwidget);
        lcdTimer->setObjectName("lcdTimer");
        lcdTimer->setGeometry(QRect(570, 20, 201, 61));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(580, 140, 51, 24));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(720, 140, 61, 24));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(630, 140, 80, 24));
        timeSetter = new QTimeEdit(centralwidget);
        timeSetter->setObjectName("timeSetter");
        timeSetter->setGeometry(QRect(580, 80, 171, 41));
        menubar = new QMenuBar(TaskManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1309, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        statusbar = new QStatusBar(TaskManager);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        menubar->addAction(menuFile->menuAction());
        menuFile->addSeparator();

        retranslateUi(TaskManager);

        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QWidget *TaskManager)
    {
        TaskManager->setWindowTitle(QCoreApplication::translate("TaskManager", "TaskManager", nullptr));
        taskInput->setPlaceholderText(QCoreApplication::translate("TaskManager", "Enter tasks, one per line", nullptr));
        addButton->setText(QCoreApplication::translate("TaskManager", "Add Task", nullptr));
        startButton->setText(QCoreApplication::translate("TaskManager", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("TaskManager", "Stop", nullptr));
        resetButton->setText(QCoreApplication::translate("TaskManager", "Reset", nullptr));
        menuFile->setTitle(QCoreApplication::translate("TaskManager", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
