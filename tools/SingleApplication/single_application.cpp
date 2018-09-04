/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "single_application.h"

#include <QCoreApplication>
#include <QFile>
#include <QLocalSocket>

SingleApplication::SingleApplication(int argc, char **argv)
        : QApplication(argc, argv),
          server_name_(QCoreApplication::applicationName()) {
    if (ServerExist()) {
        std::exit(0);
    } else {
        CreateServer();
    }
}

bool SingleApplication::ServerExist() {
    QLocalSocket socket;
    socket.connectToServer(server_name_);
    if (socket.waitForConnected(500)) {
        // 连接成功，表示已有一个实例在运行
        running_ = true;
    }
    return running_;
}

void SingleApplication::CreateServer() {
    instance_server_.reset(new QLocalServer(this));
    // 无法连接服务，表示目前没有正在运行的实例
    instance_server_->setSocketOptions(QLocalServer::WorldAccessOption);
    connect(instance_server_.get(), &QLocalServer::newConnection, this,
            &SingleApplication::OnNewConnection);

    if (instance_server_->listen(server_name_)) {
        return;
    }

    // 地址已被使用导致无法创建连接，表示前一个程序已崩溃，移除该server
    if (instance_server_->serverError() == QAbstractSocket::AddressInUseError) {
        QLocalServer::removeServer(server_name_);
        instance_server_->listen(server_name_);
    }
}

void SingleApplication::OnNewConnection() {
    delete instance_server_->nextPendingConnection();
    emit ShowWindow();
}
