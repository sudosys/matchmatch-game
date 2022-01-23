#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>

StatisticsWindow::StatisticsWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StatisticsWindow) {
    ui->setupUi(this);

    ui->statistics_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    std::ifstream statistics_file;

    statistics_file.open("player_statistics.txt");

    if (is_file_empty(statistics_file)) { ui->delete_records_button->setEnabled(false); }
}

StatisticsWindow::~StatisticsWindow() {
    delete ui;
}

void StatisticsWindow::fill_table() {

    std::string row, column;
    int row_count = 0, column_count = 0;
    std::ifstream stat_file("player_statistics.txt");
    QTableWidgetItem* table_item;

    while (getline(stat_file, row)) {
        row_count = ui->statistics_table->rowCount();
        ui->statistics_table->insertRow(row_count);
        std::istringstream split(row);
        while (getline(split, column, ',')) {
            table_item = new QTableWidgetItem(QString::fromStdString(column));
            table_item->setFlags(table_item->flags() ^ Qt::ItemIsEditable);
            ui->statistics_table->setItem(row_count,column_count, table_item);
            column_count++;
        }
        column_count = 0;
    }

}

void StatisticsWindow::clear_statistics_file() {

    std::ofstream statistics_file;

    statistics_file.open("player_statistics.txt");

    statistics_file.close();
}

bool StatisticsWindow::is_file_empty(std::ifstream& file) {

    return file.peek() == std::ifstream::traits_type::eof();

}

void StatisticsWindow::on_delete_records_button_clicked() {

    QMessageBox::StandardButton delete_prompt = QMessageBox::question(this, "Delete All Statistics",
                                              "Are you sure you want to delete all the statistics?", QMessageBox::Yes|QMessageBox::No);

    if (delete_prompt == QMessageBox::Yes) {
        clear_statistics_file();
        close();
        QMessageBox::information(this, "Information", "All statistics have been deleted successfully!", QMessageBox::Ok);
    }
    else if (delete_prompt == QMessageBox::No) { return; }

}

