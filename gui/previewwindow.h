#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class PreviewWindow; }
QT_END_NAMESPACE

class PreviewWindow : public QDialog {
    Q_OBJECT

    public:
        PreviewWindow(QWidget *parent = nullptr);
        ~PreviewWindow();
        Ui::PreviewWindow* ui;
};

#endif // PREVIEWWINDOW_H
