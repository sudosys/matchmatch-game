#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AboutWindow) {
    ui->setupUi(this);

    std::string date(__DATE__);
    std::string time(__TIME__);
    std::string build_date_time = "Built on " + date + " " + time;

    ui->build_date_time->setText(QString::fromStdString(build_date_time));
}

AboutWindow::~AboutWindow() {
    delete ui;
}
