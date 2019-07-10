#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    combat = false;
    ui->setupUi(this);
    temp = new ZorkUL();
    ui->textEdit->append(QString::fromStdString(temp->printWelcome()));
    ui->textEditCharacter->setText(QString::fromStdString(temp->player->longDescription()));
    ui->lineEdit->setFocus();

    connect(temp->player, SIGNAL(change()), this, SLOT(on_change()));
    connect(temp->player, SIGNAL(win()), this, SLOT(on_win()));
    connect(temp->player, SIGNAL(lose()), this, SLOT(on_lose()));
    connect(temp->player, SIGNAL(pickedMap()), this, SLOT(on_map()));
    connect(temp->player, SIGNAL(pickedCrown()), this, SLOT(on_crown()));
    connect(temp->player, SIGNAL(pickedSoD()), this, SLOT(on_SoD()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_westButton_clicked()
{
    if(!combat)
        ui->textEdit->append(QString::fromStdString(temp->go("west")));
}

void MainWindow::on_northButton_clicked()
{
    if(!combat)
        ui->textEdit->append(QString::fromStdString(temp->go("north")));
}

void MainWindow::on_southButton_clicked()
{
    if(!combat)
        ui->textEdit->append(QString::fromStdString(temp->go("south")));
}

void MainWindow::on_eastButton_clicked()
{
    if(!combat)
        ui->textEdit->append(QString::fromStdString(temp->go("east")));
}

void MainWindow::on_teleportButton_clicked()
{
    if(!combat)
        ui->textEdit->append(QString::fromStdString(temp->teleport()));
}

void MainWindow::on_takeButton_clicked()
{
    if(!combat)
    {
        string input = (ui->lineEdit->text()).toStdString();
        ui->textEdit->append(QString::fromStdString(temp->takeItem(input)));
        ui->lineEdit->setText("");
    }
}

// Update text box if character stats have changed
void MainWindow::on_change()
{
    ui->textEditCharacter->setText(QString::fromStdString(temp->player->longDescription()));
}

void MainWindow::on_win()
{
    ui->textEdit->setText("You won!\nCongratulations, you have collected divine king's artefacts, nobody can stand in your way now.\nYou may continue to explore the rest of the map, but watch out for traps and bats!.");
}

void MainWindow::on_lose()
{
    ui->textEdit->setText("You lost!\nWindow will close in 10 seconds.\n");

    // Prevent any more actions after player lost
    combat = true;

    // Close window after 10s
    QTimer timer;
    QTimer::singleShot(10000, this, SLOT(close()));
}

void MainWindow::on_map()
{
    ui->mapImage->setStyleSheet("border-image: url(:/images/resFiles/map.png) 0 0 0 0 stretch stretch");
}

void MainWindow::on_crown()
{
    ui->textEdit->append("You leveled up!\n");
    ui->crownWidget->setStyleSheet("border-image: url(:/images/resFiles/crown.png) 0 0 0 0 stretch stretch");
}

void MainWindow::on_SoD()
{
    ui->textEdit->append("You leveled up!\n");
    ui->swordWidget->setStyleSheet("border-image: url(:/images/resFiles/sod.png) 0 0 0 0 stretch stretch");
}

void MainWindow::on_lineEdit_returnPressed()
{
    if(!combat)
    {
        string input = (ui->lineEdit->text()).toStdString();
        ui->textEdit->append(QString::fromStdString(temp->takeItem(input)));
        ui->lineEdit->setText("");
    }
}
