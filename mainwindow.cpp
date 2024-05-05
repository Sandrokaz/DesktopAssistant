#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    timer(new QTimer(this)), currentTime(new QTime(0,0,0))
{
    ui->setupUi(this);
    ui->lcdTimer->display(currentTime->toString("hh:mm:ss"));
    setupConnections();
    lcdTimer = ui->lcdTimer;  // Assuming you named it lcdTimer in Qt Designer
    timeSetter = ui->timeSetter;  // Assuming you named it timeSetter in Qt Designer

}


void MainWindow::setupConnections() {
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->tasksList, &QListWidget::itemChanged, this, &MainWindow::updateProgress);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimerDisplay);
}


void MainWindow::addTask() {
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

void MainWindow::customizeLCD(){
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


void MainWindow::updateProgress() {
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


void MainWindow::startTimer() {
    timer->start(1000); // Start the timer with a 1-second interval
}

void MainWindow::updateTimerDisplay() {
    *currentTime = currentTime->addSecs(1);
    ui->lcdTimer->display(currentTime->toString("hh:mm:ss"));
}

void MainWindow::stopTimer() {
    timer->stop();
}

void MainWindow::resetTimer() {
    timer->stop();
    lcdTimer->display(0);  // Or reset to the initial value
}





MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete currentTime;
}
