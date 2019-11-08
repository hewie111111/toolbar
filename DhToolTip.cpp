#include "DhToolTip.h"
#include<QPainter>
#include<QString>
DhToolTip::DhToolTip(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::ToolTip);
	setFixedSize(30, 10);
	//setAttribute(Qt::WA_TranslucentBackground);
	setStyleSheet("background-color: rgb(255,207, 251,255)");
	m_Text = 0;
}

DhToolTip::~DhToolTip()
{
}
void DhToolTip::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	int width = this->width();
	int height = this->height();
	painter.setPen(QColor(0xFF, 0, 0));
	QFont font("Times", 5, QFont::Normal, true);
	painter.setFont(font);
	char buf[5] = { 0 };
	sprintf(buf, "%d", m_Text);
	QString str = QString::fromLocal8Bit(buf);
	painter.drawText(0, 0, width, height,   // 指定位置
		Qt::AlignHCenter | Qt::AlignVCenter, // 指定对齐等属性
		str);
}
void DhToolTip::SetText(int text) {
	m_Text = text;
	update();
}
