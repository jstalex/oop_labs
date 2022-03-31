#ifndef CUSTOMBROWSER_H
#define CUSTOMBROWSER_H
#include <QTextBrowser>

namespace Ui { class MainWindow; }

class customBrowser : public QTextBrowser{
public:
    customBrowser(QWidget* parent);
    void GreenText(QString text);
    void RedText(QString text);
};

#endif // CUSTOMBROWSER_H
