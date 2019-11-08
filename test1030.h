#pragma once

#include <QtWidgets/QWidget>
#include "ui_test1030.h"
#include "DhToolTip.h"
class test1030 : public QWidget
{
	Q_OBJECT

public:
	test1030(QWidget *parent = Q_NULLPTR);
private:
	DhToolTip *myTip;
private slots:
    void OnMoving(QPoint pos,int progress);
private:
	Ui::test1030Class ui;
};
