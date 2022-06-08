#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MyVector<char> vector(4);
    vector[0] = 'A';
    vector[1] = 'B';
    vector[2] = 'C';
    vector[3] = 'D';

    ui->textEdit->clear();
    for (auto it = vector.begin(); it != vector.end(); it++)
        ui->textEdit->append(QString(*it));
}

void MainWindow::on_pushButton_2_clicked()
{
    MyVector<char> vector;
    for (auto c : {'A', 'B', 'C', 'D'})
        vector.pushBack(c);
    ui->textEdit->clear();
    for (int i = vector.size() - 1; i >= 0; --i)
        ui->textEdit->append(QString(vector[i]));
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open list from txt"), "", tr("Text files (*.txt)"));
    ui->textEdit_2->clear();
    if (!filename.isEmpty()) {
        std::ifstream stream(filename.toStdString());
        std::string input;
        while (getline(stream, input)) {
            fruits.pushBack(input);
            ui->textEdit_2->append(QString::fromStdString(input));
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    std::sort(fruits.beginPtr(), fruits.endPtr());
    ui->textEdit_2->clear();
    for (const auto& item : fruits) {
        ui->textEdit_2->append(QString::fromStdString(item));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit_2->clear();
    for (const auto& item : fruits) {
        if (item[0] == 'A')
            ui->textEdit_2->append(QString::fromStdString(item));
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit_2->clear();
    for (const auto& item : fruits) {
        if (!(item == "Orange" || item == "Lime"))
            ui->textEdit_2->append(QString::fromStdString(item));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open list from txt"), "", tr("Text files (*.txt)"));
    ui->textEdit_3->clear();
    if (!filename.isEmpty()) {
        std::ifstream stream(filename.toStdString());
        std::string input;

        while (getline(stream, input)) {
            QDateTime dateTime = QDateTime::fromString(QString::fromStdString(input), QString::fromStdString(("dd/MM/yyyy")));
            dates.pushBack(dateTime);
            ui->textEdit_3->append(QString::fromStdString(input));
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    std::sort(dates.beginPtr(), dates.endPtr());
    ui->textEdit_3->clear();
    for (const auto& item : dates) {
        ui->textEdit_3->append(item.toString("dd/MM/yyyy"));
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    MyList<int> list;
    list.pushBack(1234);
    list.pushBack(5678);

    list.pushFront(9101112);
    list.pushFront(13141516);

    ui->textEdit_4->append(QString::fromStdString("FULL LIST"));

    for (const auto& item : list)
        ui->textEdit_4->append(QString::number(item));

    ui->textEdit_4->append(QString::fromStdString("2th element : ") + QString::number(list[2]));
}

void MainWindow::on_pushButton_10_clicked() {
    for (int i = 0; i < 100; ++i)
        numbers.pushBack((i + 1) * (i + 1));
    ui->textEdit_5->clear();
    for (const auto& item : numbers)
        ui->textEdit_5->append(QString::number(item));
}

void MainWindow::on_pushButton_11_clicked() {
    ui->textEdit_5->clear();
    std::for_each(numbers.begin(), numbers.end(), [this](int a) {
        ui->textEdit_5->append(QString::number(std::sqrt(a)));
        return;
    });
}
