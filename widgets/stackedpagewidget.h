/*
 * Cantata
 *
 * Copyright (c) 2011-2015 Craig Drummond <craig.p.drummond@gmail.com>
 *
 * ----
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef STACKED_PAGE_WIDGET_H
#define STACKED_PAGE_WIDGET_H

#include <QStackedWidget>
#include <QMap>
#include "mpd-interface/song.h"
#include "gui/page.h"

class Icon;
class SelectorButton;
class SizeWidget;
class QLabel;

class StackedPageWidget : public QStackedWidget, public Page
{
    Q_OBJECT

public:
    StackedPageWidget(QWidget *p);
    virtual ~StackedPageWidget();

    void setView(int v);
    void focusSearch();
    QStringList selectedFiles(bool allowPlaylists) const;
    QList<Song> selectedSongs(bool allowPlaylists) const;
    void addSelectionToPlaylist(const QString &name, bool replace, quint8 priorty);
    void removeItems();
    void showEvent(QShowEvent *e);

Q_SIGNALS:
    void close();

private:
    bool shown;
};

#endif
