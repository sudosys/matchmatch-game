#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include <fstream>
#include <sstream>

StatisticsWindow::StatisticsWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StatisticsWindow) {
    ui->setupUi(this);
    ui->statistics_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
