/*
 * maze.h
 *
 *  Created on: May 13, 2012
 *      Author: chiraag
 */

#ifndef MAZE_H_
#define MAZE_H_

#include <QGraphicsItem>

class maze : public QGraphicsItem
{
public:
 maze();
 ~maze();

 QRectF boundingRect() const;
 QPainterPath shape() const;
 void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

private:
 QColor color;
};

#endif /* MAZE_H_ */
