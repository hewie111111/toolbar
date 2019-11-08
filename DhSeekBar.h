#pragma once

#include <QWidget>
#include <QEnterEvent> 
#include<QEvent>
#include<QMouseEvent>
#include<QPaintEvent>
class DhSeekBar : public QWidget
{
	Q_OBJECT

public:
	DhSeekBar(QWidget *parent);
	~DhSeekBar();
	
signals:
	void Moving(QPoint pos,int progress);
protected:
	virtual void enterEvent(QEvent *e);
	virtual void leaveEvent(QEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
private:
	int ProgressToXvalue(int progress);
	int XvalueToProgress(int xValue);
protected:
	int m_range;
	int m_progress;
	bool isPressed;
	bool isFocus;
};
