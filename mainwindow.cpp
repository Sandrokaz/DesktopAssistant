#include "mainwindow.h"
#include "taskmanager.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->taskManagerButton,&QPushButton::clicked,this, &MainWindow::openTaskManager);
}

void MainWindow::openTaskManager() {
    // Check if an instance already exists
    static TaskManager* taskManager = nullptr;
    if (!taskManager || taskManager->isHidden()) {
        delete taskManager;  // Delete previous instance if closed
        taskManager = new TaskManager(this);
        taskManager->setAttribute(Qt::WA_DeleteOnClose); // Ensure it's deleted once closed
    }
    taskManager->show();  // Show the TaskManager window
    taskManager->raise(); // Bring the window to the front
    taskManager->activateWindow(); // Focus the window
}
