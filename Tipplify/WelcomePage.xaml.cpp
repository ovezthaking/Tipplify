//
// WelcomePage.xaml.cpp
// Implementacja klasy WelcomePage
// Strona powitalna
//

#include "pch.h"
#include "WelcomePage.xaml.h"
#include "SelectionPage.xaml.h"

#include <stdlib.h>
#include <iostream>
//#include <mysql_driver.h>
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
//#include "../../../../../Program Files/MySQL/Connector ODBC 8.2/include/jdbc/cppconn/driver.h"
//#include "../../../../../Program Files/MySQL/Connector ODBC 8.2/include/jdbc/cppconn/exception.h"
//#include "../../../../../Program Files/MySQL/Connector ODBC 8.2/include/jdbc/cppconn/prepared_statement.h"
//#include "../../../../../Program Files/MySQL/Connector ODBC 8.2/include/jdbc/mysql_connection.h"
//#include "../../../../../Program Files/MySQL/Connector ODBC 8.2/include/jdbc/mysql_driver.h"

using namespace Tipplify;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

//Szablon elementu Pusta strona jest udokumentowany na stronie https://go.microsoft.com/fwlink/?LinkId=234238

WelcomePage::WelcomePage()
{
	InitializeComponent();
}

inline static void ConnectToDatabase()
{
	/*
	
	//BAZA DANYCH?
	
	sql::mysql::MySQL_Driver* driver = nullptr;
	sql::Connection* con = nullptr;

	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "username", "password");



	delete con;
	*/
}


void Tipplify::WelcomePage::NavToMain(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Definicja przycisku przekierowującego użytkownika na stronę selekcji
	SelectionPage^ selectionpage = ref new SelectionPage();
	Windows::UI::Xaml::Window::Current->Content = selectionpage;
	
	//Zwrócenie funkcji podłączenia do bazy danych
	//return ConnectToDatabase();
}
