/* Copyright (©) 2017 zgzf1001@gmail.com */

#ifndef SRC_UTILS_SINGLE_APPLICATION_SINGLE_APPLICATION_H_
#define SRC_UTILS_SINGLE_APPLICATION_SINGLE_APPLICATION_H_

#include <QApplication>
#include <QLocalServer>
#include <QObject>

#include <memory>

class SingleApplication : public QApplication {
    Q_OBJECT

public:
    SingleApplication(int argc, char **argv);

signals:
    void ShowWindow();

private:
    bool ServerExist();
    void CreateServer();

private slots:
    void OnNewConnection();

private:
    std::unique_ptr<QLocalServer> instance_server_;
    bool running_ = false;
    QString server_name_;
};

#endif  // SRC_UTILS_SINGLE_APPLICATION_SINGLE_APPLICATION_H_
