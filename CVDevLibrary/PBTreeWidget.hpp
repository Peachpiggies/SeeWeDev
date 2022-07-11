//Copyright © 2022, NECTEC, all rights reserved

//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

#ifndef PBTREEWIDGET_H
#define PBTREEWIDGET_H

#pragma once

#include "CVDevLibrary.hpp"

#include "nodes/internal/Export.hpp"
#include <QTreeWidget>

class CVDEVSHAREDLIB_EXPORT PBTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit PBTreeWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
};

#endif // PBTREEWIDGET_H
