/***************************************************************************
 *   Copyright (C) 2005-07 by the Quassel IRC Team                         *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CHATSCENE_H_
#define _CHATSCENE_H_

#include <QGraphicsScene>

class AbstractUiMsg;
class Buffer;
class ChatLine;
class QGraphicsSceneMouseEvent;

class ChatScene : public QGraphicsScene {
  Q_OBJECT

  public:
    ChatScene(Buffer *buffer, QObject *parent);
    virtual ~ChatScene();

    Buffer *buffer() const;

  public slots:

  protected slots:
    void appendMsg(AbstractUiMsg *msg);
    void prependMsg(AbstractUiMsg *msg);

    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

  private:
    Buffer *_buffer;
    QList<ChatLine*> _lines;

};

#endif
