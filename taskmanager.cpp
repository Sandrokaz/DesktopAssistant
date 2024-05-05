#include "taskmanager.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(QWidget *parent)
    : QWidget(parent), ui(new Ui::TaskManager),
    timer(new QTimer(this)), currentTime(new QTime(0,0,0))
{
    ui->setupUi(this);
    ui->lcdTimer->display(currentTime->toString("hh:mm:ss"));
    setupConnections();
    lcdTimer = ui->lcdTimer;  // Assuming you named it lcdTimer in Qt Designer
    timeSetter = ui->timeSetter;  // Assuming you named it timeSetter in Qt Designer

}


void TaskManager::setupConnections() {
    connect(ui->addButton, &QPushButton::clicked, this, &TaskManager::addTask);
    connect(ui->tasksList, &QListWidget::itemChanged, this, &TaskManager::updateProgress);
    connect(ui->startButton, &QPushButton::clicked, this, &TaskManager::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &TaskManager::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &TaskManager::resetTimer);
    connect(timer, &QTimer::timeout, this, &TaskManager::updateTimerDisplay);
}


void TaskManager::addTask() {
    QStringList tasks = ui->taskInput->toPlainText().split("\n", Qt::SkipEmptyParts);
    ui->tasksList->blockSignals(true); // Prevent itemChanged signal during setup
    foreach (const QString &taskName, tasks) {
        if (!taskName.trimmed().isEmpty()) {
            QListWidgetItem *item = new QListWidgetItem(taskName.trimmed());
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(Qt::Unchecked);
            ui->tasksList->addItem(item);
        }
    }
    ui->tasksList->blockSignals(false); // Re-enable itemChanged signal
    ui->taskInput->clear();
}

void TaskManager::customizeLCD(){
    QLCDNumber* lcd = ui->lcdTimer;  // Access the LCD number

    // Modify the palette
    QPalette lcdPalette = lcd->palette();

    // Set the foreground and background colors
    lcdPalette.setColor(QPalette::WindowText, QColor(Qt::red));  // Red digits
    lcdPalette.setColor(QPalette::Window, QColor(Qt::white));    // Black background

    // Apply the new palette
    lcd->setPalette(lcdPalette);

    // Set the segment style
    lcd->setSegmentStyle(QLCDNumber::Filled);

    // Ensure the background color fills the entire background
    lcd->setAutoFillBackground(true);

}


void TaskManager::updateProgress() {
    int totalCount = ui->tasksList->count();
    int completedCount = 0;
    for (int i = 0; i < totalCount; ++i) {
        if (ui->tasksList->item(i)->checkState() == Qt::Checked) {
            completedCount++;
        }
    }
    int progress = (totalCount > 0) ? (100 * completedCount / totalCount) : 0;
    ui->progressBar->setValue(progress);
}


void TaskManager::startTimer() {
    timer->start(1000); // Start the timer with a 1-second interval
}

void TaskManager::updateTimerDisplay() {
    *currentTime = currentTime->addSecs(1);
    ui->lcdTimer->display(currentTime->toString("hh:mm:ss"));
}

void TaskManager::stopTimer() {
    timer->stop();
}

void TaskManager::resetTimer() {
    timer->stop();
    lcdTimer->display(0);  // Or reset to the initial value
}





TaskManager::~TaskManager()
{
    delete ui;
    delete timer;
    delete currentTime;
}
