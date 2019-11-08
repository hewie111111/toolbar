#include "DhSeekBar.h"
#include<QPainter>
DhSeekBar::DhSeekBar(QWidget *parent)
	: QWidget(parent)
{
	setMouseTracking(true);
	isFocus = false;
	isPressed = false;
	m_range = 10000;
	m_progress = 0;
}

DhSeekBar::~DhSeekBar()
{
	
}
void DhSeekBar::enterEvent(QEvent *e) {
	this->isFocus = true;
	update();
	QWidget::enterEvent(e);
}
void DhSeekBar::leaveEvent(QEvent *e) {
	this->isFocus = false;
	update();
	QWidget::leaveEvent(e);
}
void DhSeekBar::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	int width = this->width() - 20;
	int height = this->height();
	QPen pen(QColor(0, 0, 255));
	if (!isFocus) {
		pen.setWidth(1);
		painter.setPen(pen);
		painter.drawLine(QPoint(10,height/2), QPoint(10 + width, height / 2));
		int x = ProgressToXvalue(m_progress);
		painter.setBrush(QColor(0, 0, 255));
		painter.drawEllipse(QPoint(x, height / 2), 2, 2);
	}
	else{
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawLine(QPoint(10, height / 2), QPoint(10 + width, height / 2));
		painter.setPen(Qt::PenStyle::NoPen);
		painter.setBrush(QColor(255, 0, 0));
		int x = ProgressToXvalue(m_progress);
		painter.drawEllipse(QPoint(x, height / 2), 3, 3);
	}

}
void DhSeekBar::mouseMoveEvent(QMouseEvent *event) {
	int x = event->x();
	if(isPressed)
	    m_progress = XvalueToProgress(x);
	update();
	QPoint globalPos = event->globalPos();
	int tmpProgress = XvalueToProgress(x);
	emit Moving(globalPos, tmpProgress);
	QWidget::mouseMoveEvent(event);
}
void DhSeekBar::mousePressEvent(QMouseEvent *event) {
	isPressed = true;
	int x = event->x();
	m_progress = XvalueToProgress(x);
	update();
}
void DhSeekBar::mouseReleaseEvent(QMouseEvent *event) {
	isPressed = false;
}

int DhSeekBar::ProgressToXvalue(int progress) {
	int width = this->width();
	int xValue = 0;
	xValue = ((double)progress / (double)m_range)*(width - 20) + 10;
	return xValue;
}
int DhSeekBar::XvalueToProgress(int xValue) {
	int progress = 0;
	int width = this->width();
	if (xValue <= 10) progress = 0;
	else if(xValue>=width-10) progress = 10000;
	else
	    progress = m_range*((double)(xValue-10 )/(double)(width-20));
	return progress;
}