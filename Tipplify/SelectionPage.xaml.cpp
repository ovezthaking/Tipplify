//
// SelectionPage.xaml.cpp
// Implementacja klasy SelectionPage
//

#include "pch.h"
#include "SelectionPage.xaml.h"
#include "MainPage.xaml.h"
#include "WelcomePage.xaml.h"


#include <stdlib.h>
#include <iostream>
//#include <mysql_driver.h>
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
#include "Lib/mysql/cppconn/driver.h"
#include "Lib/mysql/cppconn/exception.h"
#include "Lib/mysql/cppconn/prepared_statement.h"
#include "Lib/mysql/mysql_connection.h"
#include <mysql_driver.h>



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




Tipplify::SelectionPage::SelectionPage()
{
    InitializeComponent();
    /*
    //BAZA DANYCH 
    sql::Driver* driver = nullptr;
    sql::Connection* con = nullptr;
    const std::string server = "tcp://127.0.0.1:3306";
    const std::string username = "ovez";
    const std::string password = "oliwer1234";

   
    
      
    try {
        driver = sql::mysql::get_mysql_driver_instance(); //Przez tą linijkę ukazuje się błąd
       // con = driver->connect(server, username, password);

    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
       
    }


    //BAZA DANYCH 
    sql::Driver* driver = nullptr;
    sql::Connection* con = nullptr;
    const std::string server = "tcp://127.0.0.1:3306";
    const std::string username = "ovez";
    const std::string password = "oliwer1234";

try{
        //driver = sql::mysql::get_mysql_driver_instance(); //Przez tą linijkę ukazuje się błąd
       // con = driver->connect(server, username, password);

}
catch (sql::SQLException e)
{
    std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
    system("pause");
    exit(1);
}
*/
        
}

/*
* 
//* BAZA DANYCH MYSQL
* 
inline static void ConnectToDatabase()
{
    sql::mysql::MySQL_Driver* driver = nullptr;
    sql::Connection* con = nullptr;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password");

    

    delete con;
}
*/

void Tipplify::SelectionPage::ChangeRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    
    Button^ clickedButton = dynamic_cast<Button^>(sender);
    if (clickedButton != nullptr)
    {
        MainPage^ mainpage = ref new MainPage();

        // Jeżeli pierwszy przycisk został kliknięty
        if (clickedButton->Content->ToString() == "Champagne Cocktail")
        {
            mainpage->ChangeContent("Kostkę cukru nasączamy angosturą i umieszczamy w kieliszku. Wlewamy na nią koniak, następnie powoli dodajemy szampan. Champagne cocktail  możemy ozdobić plastrem pomarańczy i wisienką koktajlową.", "Champagne Cocktail");
            
        }
        // Jeżeli drugi przycisk został kliknięty
        else if (clickedButton->Content->ToString() == "Mojito")
        {
            mainpage->ChangeContent("Skruszyć lód, limonkę wyszorować, pokroić na ćwiartki i wrzucić do szklanki typu highball/long drink Zasypać cukrem i dokładnie ugnieść. Następnie dodać listki mięty i znowu ugnieść. Do połowy wysokości szklanki dodać kruszony lód, a następnie rum i znów lód (kruszony). Zamieszać. Na wierzch dodać wodę gazowaną i delikatnie zmieszać. Szklankę udekorować limonką i listkami mięty.", "Mojito");
        }





        // Przeniesienie użytkownika na stronę główną
        Windows::UI::Xaml::Window::Current->Content = mainpage;
    }
}
