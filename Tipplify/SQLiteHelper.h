// SQLiteHelper.h
#pragma once

#include "Lib/sqlite3.h"
#include <string>


class SQLiteHelper {
public:
    SQLiteHelper();
    ~SQLiteHelper();

    bool OpenDatabase(const std::wstring& databasePath);
    bool CreateTable(const std::wstring& tableName, const std::wstring& columns);
    bool ExecuteQuery(const std::wstring& query);

private:
    sqlite3* database;
};
