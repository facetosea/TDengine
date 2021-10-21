/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef TDENGINE_QUERYINFOUTIL_H
#define TDENGINE_QUERYINFOUTIL_H

#ifdef __cplusplus
extern "C" {
#endif
#include "parserInt.h"

SSchema* getTbnameColumnSchema();

int32_t  getNumOfColumns(const STableMeta* pTableMeta);
int32_t  getNumOfTags(const STableMeta* pTableMeta);
SSchema *getTableColumnSchema(const STableMeta *pTableMeta);
SSchema *getTableTagSchema(const STableMeta* pTableMeta);
SSchema *getOneColumnSchema(const STableMeta* pTableMeta, int32_t colIndex);

size_t     getNumOfExprs(SQueryStmtInfo* pQueryInfo);
SExprInfo* createExprInfo(STableMetaInfo* pTableMetaInfo, int16_t functionId, SColumnIndex* pColIndex, int16_t type,
                          int16_t size, int16_t resColId, int16_t interSize, int32_t colType);
void       addExprInfo(SQueryStmtInfo* pQueryInfo, int32_t index, SExprInfo* pExprInfo);
void       updateExprInfo(SExprInfo* pExprInfo, int16_t functionId, int32_t colId, int16_t srcColumnIndex, int16_t resType, int16_t resSize);
void       assignExprInfo(SExprInfo* dst, const SExprInfo* src);

SExprInfo* getExprInfo(SQueryStmtInfo* pQueryInfo, int32_t index);
int32_t    copyAllExprInfo(SArray* dst, const SArray* src, bool deepcopy);

void       cleanupFieldInfo(SFieldInfo* pFieldInfo);

STableComInfo getTableInfo(const STableMeta* pTableMeta);

#ifdef __cplusplus
}
#endif

#endif  // TDENGINE_QUERYINFOUTIL_H
