/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WINQ/WINQ.h>

namespace WCDB {

CTETableName::CTETableName(const std::string &tableName)
{
    lang::CTETableName &lang = getMutableLang();
    lang.tableName.assign(tableName);
}

CTETableName &CTETableName::byAddingColumn(const Column &column)
{
    lang::CTETableName &lang = getMutableLang();
    lang.columns.append(column.getLang());
    return *this;
}

CTETableName &CTETableName::byAddingColumns(const std::list<Column> &columns)
{
    lang::CTETableName &lang = getMutableLang();
    for (const Column &column : columns) {
        lang.columns.append(column.getLang());
    }
    return *this;
}

} // namespace WCDB
