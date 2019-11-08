#pragma once

#include <QWidget>
#include<QPaintEvent>
class DhToolTip : public QWidget
{
	Q_OBJECT

public:
	DhToolTip(QWidget *parent);
	~DhToolTip();
	void SetText(int text);
private:
	virtual void paintEvent(QPaintEvent *event);
private:
	int m_Text;
};
