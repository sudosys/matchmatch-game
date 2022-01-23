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
        void clear_statistics_file();
        bool is_file_empty(std::ifstream& file);

    private slots:
        void on_delete_records_button_clicked();

private:

};

#endif // STATISTICSWINDOW_H
