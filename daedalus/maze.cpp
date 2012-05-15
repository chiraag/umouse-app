/*
 * maze.cpp
 *
 *  Created on: May 13, 2012
 *      Author: chiraag
 */

#include "maze.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

#define XP 200
#define YP 200

maze::maze() : color(0, 0, 0)
{

}

maze::~maze()
{
}

QRectF maze::boundingRect() const
{
	qreal adjust = 0.5;
	return QRectF(-XP-adjust, -YP-adjust, 2*(XP+adjust), 2*(YP+adjust));
}

QPainterPath maze::shape() const
{
	QPainterPath path;
	path.addRect(-XP, -YP, 2*XP, 2*YP);
	return path;
}

void maze::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	// Body
	painter->setPen(QPen(color, 1));
	painter->drawRect(-XP, -YP, 2*XP, 2*YP);
}

