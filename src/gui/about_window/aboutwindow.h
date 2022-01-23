#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AboutWindow; }
QT_END_NAMESPACE

class AboutWindow : public QDialog {
    Q_OBJECT

    public:
        AboutWindow(QWidget *parent = nullptr);
        ~AboutWindow();

    private slots:

    private:
        Ui::AboutWindow* ui;
};

#endif // ABOUTWINDOW_H
