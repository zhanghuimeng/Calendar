#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化stackwidget相关
    ui->stackedWidget->setCurrentIndex(0);
    switchButtons[0] = ui->dayButton;
    switchButtons[1] = ui->weekButton;
    switchButtons[2] = ui->monthButton;
    switchButtons[3] = ui->fourDaysButton;
    switchButtons[4] = ui->scheduleButton;

    // 设置切换按钮和stackwidget的关联
    connect(ui->dayButton, SIGNAL(toggled(bool)), this, SLOT(activateDay(bool)));
    connect(ui->weekButton, SIGNAL(toggled(bool)), this, SLOT(activateWeek(bool)));
    connect(ui->monthButton, SIGNAL(toggled(bool)), this, SLOT(activateMonth(bool)));
    connect(ui->fourDaysButton, SIGNAL(toggled(bool)), this, SLOT(activateFourDays(bool)));
    connect(ui->scheduleButton, SIGNAL(toggled(bool)), this, SLOT(activateSchedule(bool)));
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)),
            this, SLOT(changeCurrentButtonToggleState(int)));
    changeCurrentButtonToggleState(0);

    // 初始化timelabels
    for (int i = 0; i < 24; i++)
    {
        timeLabelsForTable.append(QString::number(i) + ":00");
        timeLabelsForTable.append("");
    }

    // 初始化day日历
    ui->dayTableWidget->setColumnCount(1);
    ui->dayTableWidget->setRowCount(48);
    ui->dayTableWidget->setVerticalHeaderLabels(timeLabelsForTable);
    ui->dayTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dayTableWidget->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->dayTableWidget->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::changeCurrentButtonToggleState(int index)
{
    for (int i = 0; i < 5; i++)
        switchButtons[i]->setChecked(false);
    switchButtons[index]->setChecked(true);
}

void MainWindow::activateDay(bool toggled)
{
    qDebug() << "active day" << toggled;
    if (toggled)
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::activateWeek(bool toggled)
{
    if (toggled)
        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::activateMonth(bool toggled)
{
    if (toggled)
        ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::activateFourDays(bool toggled)
{
    if (toggled)
        ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::activateSchedule(bool toggled)
{
    if (toggled)
        ui->stackedWidget->setCurrentIndex(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}
