#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class StatisticsWindow; }
QT_END_NAMESPACE

class StatisticsWindow : public QDialog {
    Q_OBJECT

    public:
        StatisticsWindow(QWidget *parent = nullptr);
        ~StatisticsWindow();
        Ui::StatisticsWindow* ui;
        void fill_table();

    private slots:

    private:

};

#endif // STATISTICSWINDOW_H
