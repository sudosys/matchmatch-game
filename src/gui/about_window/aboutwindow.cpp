#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AboutWindow) {
    ui->setupUi(this);

    bool experimental_version = false;

    std::string date(__DATE__);
    std::string time(__TIME__);
    std::string build_date_time = "Built on " + date + " " + time;

    std::string game_name = "Match Match Game";
    std::string game_version = "v1.20";

    ui->game_name->setText(QString::fromStdString(game_name + " " + game_version));
    ui->build_date_time->setText(QString::fromStdString(build_date_time));

    if (experimental_version) {
        ui->experimental->setText("EXPERIMENTAL");
        ui->experimental->setStyleSheet("color: red; font-weight: bold; font-size: 15px;");
    }
}

AboutWindow::~AboutWindow() {
    delete ui;
}
