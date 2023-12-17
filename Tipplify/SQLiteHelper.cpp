#include "pch.h"
#include "SQLiteHelper.h"

#include "Lib/sqlite3.h"

// SQLiteHelper.cpp
#include "SQLiteHelper.h"

SQLiteHelper::SQLiteHelper() : database(nullptr) {}

SQLiteHelper::~SQLiteHelper() {
    if (database) {
        sqlite3_close(database);
    }
}

bool SQLiteHelper::OpenDatabase(const std::wstring& databasePath) {
    return sqlite3_open16(databasePath.c_str(), &database) == SQLITE_OK;
}

bool SQLiteHelper::CreateTable(const std::wstring& tableName, const std::wstring& columns) {
    std::wstring query = L"CREATE TABLE IF NOT EXISTS " + tableName + L" (" + columns + L");";
    return ExecuteQuery(query);
}

bool SQLiteHelper::ExecuteQuery(const std::wstring& query) {
    char* errorMessage = nullptr;
    int result = sqlite3_exec(database, utf16_to_utf8(query).c_str(), nullptr, nullptr, &errorMessage);

    if (result != SQLITE_OK) {
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

// Funkcja pomocnicza do konwersji std::wstring na std::string
std::string utf16_to_utf8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(wstr);
}
