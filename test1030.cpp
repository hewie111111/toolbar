#include "test1030.h"

test1030::test1030(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	myTip = new DhToolTip(nullptr);
	connect(ui.widget, SIGNAL(Moving(QPoint,int)), this, SLOT(OnMoving(QPoint,int)));
	
}

void test1030::OnMoving(QPoint pos,int progress) {
	myTip->move(pos.x()-15,pos.y()-12);
	myTip->SetText(progress);
	myTip->show();
}
