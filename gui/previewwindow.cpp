#include "previewwindow.h"
#include "ui_previewwindow.h"

PreviewWindow::PreviewWindow(QWidget *parent) : QDialog(parent), ui(new Ui::PreviewWindow) {
    ui->setupUi(this);
}

PreviewWindow::~PreviewWindow() {
    delete ui;
}


void PreviewWindow::on_close_button_clicked() {
    close();
}

