//
// SelectionPage.xaml.cpp
// Implementacja klasy SelectionPage
//

#include "pch.h"
#include "SelectionPage.xaml.h"
#include "MainPage.xaml.h"
#include "WelcomePage.xaml.h"
#include <string>
#include <fstream>

#include <stdlib.h>
#include <iostream>


#include <ppltasks.h>
#include <collection.h>
#include <sstream>
#include <fstream>
#include <ppl.h>




using namespace Windows::Data::Json;
using namespace concurrency;


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
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;

//Szablon elementu Pusta strona jest udokumentowany na stronie https://go.microsoft.com/fwlink/?LinkId=234238




Tipplify::SelectionPage::SelectionPage()
{
    InitializeComponent();
    
}



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


void Tipplify::SelectionPage::AddRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    // Pobierz dane 
    Platform::String^ name = NameTextBox->Text;
    Platform::String^ description = DescriptionTextBox->Text;
    Platform::String^ photoPath = PhotoPathTextBox->Text;
    Platform::String^ ingredients = IngredientsTextBox->Text;

    // Utwórz nowy obiekt JSON
    JsonObject^ jsonObject = ref new JsonObject();

    
    jsonObject->Insert("name", JsonValue::CreateStringValue(name));
    jsonObject->Insert("description", JsonValue::CreateStringValue(description));
    jsonObject->Insert("photoPath", JsonValue::CreateStringValue(photoPath));
    jsonObject->Insert("ingredients", JsonValue::CreateStringValue(ingredients));
    

    String^ jsonString = jsonObject->Stringify();

    StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
    

    String^ filePath ="Lib" + "\\" + name + ".json";
   
    
    // utwórz plij
    create_task(localFolder->CreateFileAsync(filePath, CreationCollisionOption::GenerateUniqueName))
        .then([jsonString](StorageFile^ file)
            {
                // Zapisywanie ciągu znaków JSON do istniejącego pliku (nadpisywanie)
                return FileIO::WriteTextAsync(file, jsonString);
            })
        .then([](task<void> previousTask)
            {
                try
                {
                    // Obsługa błędów, jeśli wystąpiły
                    previousTask.get();
                    
                    
                }
                catch (Exception^ ex)
                {
                    OutputDebugStringW(L"Error during file writing: ");
                    OutputDebugStringW(ex->Message->Data());
                    // Obsługa błędów podczas zapisu
                    
                }
            });



    

 

 

    // Wyczyszczenie TextBox-ów po dodaniu przepisu
    NameTextBox->Text = filePath;
    DescriptionTextBox->Text = "";
    PhotoPathTextBox->Text = "";
    IngredientsTextBox->Text = "";
}

