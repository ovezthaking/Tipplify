﻿//
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

#include <Windows.Security.Cryptography.h>
#include <Windows.Storage.Streams.h>
using namespace Platform::Collections;




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
    LoadRecipes(); // Wczytaj przepisy przy tworzeniu strony
}



// LAST SAVE
void Tipplify::SelectionPage::LoadRecipes()
{
    StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
    Platform::String^ recipesFolderPath = "Assets\\recipes";

    // Uzyskaj dostęp do folderu z przepisami
    create_task(localFolder->GetFolderAsync(recipesFolderPath))
        .then([this](StorageFolder^ recipesFolder)
            {
                // Pobierz wszystkie pliki .json w folderze
                return create_task(recipesFolder->GetFilesAsync())
                    .then([this](IVectorView<StorageFile^>^ files)
                        {
                            // Przeszukaj każdy plik .json i wczytaj przepis
                            for (StorageFile^ file : files)
                            {
                                create_task(FileIO::ReadTextAsync(file))
                                    .then([this, file](String^ content)
                                        {
                                            // Wczytaj przepis z pliku .json (tu trzeba dostosować do Twoich potrzeb)
                                            ParseAndHandleRecipe(content);
                                        });
                            }
                        });
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
                    OutputDebugStringW(L"Error during recipe loading: ");
                    OutputDebugStringW(ex->Message->Data());
                    // Obsługa błędów podczas wczytywania przepisów
                }
            });
}

void Tipplify::SelectionPage::ParseAndHandleRecipe(String^ jsonContent)
{
    try
    {
        JsonObject^ jsonObject = JsonObject::Parse(jsonContent);

        if (jsonObject->HasKey("name") && jsonObject->HasKey("description") &&
            jsonObject->HasKey("photoPath") && jsonObject->HasKey("ingredients"))
        {
            // Pobierz dane z obiektu JSON
            String^ name = jsonObject->GetNamedString("name");
            String^ description = jsonObject->GetNamedString("description");
            String^ photoPath = jsonObject->GetNamedString("photoPath");
            JsonArray^ ingredientsJsonArray = jsonObject->GetNamedArray("ingredients");

            // Przetwórz składniki z tablicy JSON
            Vector<String^>^ ingredientsVector = ref new Vector<String^>();
            for (IJsonValue^ ingredientJsonValue : ingredientsJsonArray)
            {
                if (ingredientJsonValue->ValueType == JsonValueType::String)
                {
                    String^ ingredient = ingredientJsonValue->GetString();
                    ingredientsVector->Append(ingredient);
                }
            }

            // Tutaj możesz użyć danych przepisu do własnej logiki biznesowej
            // Na przykład, utwórz obiekt przepisu, dodaj go do listy przepisów itp.

            // Przykład wypisywania danych na konsolę

           

            // Tworzenie przycisku
            Button^ recipeButton = ref new Button();
            recipeButton->Content = name; // Ustaw nazwę przycisku na nazwę przepisu
            recipeButton->Click += ref new RoutedEventHandler(this, &Tipplify::SelectionPage::ChangeRecipe);


            // Dodaj przycisk do kontenera na przyciski (na przykład, Grid lub StackPanel)
            RecipeList->Children->Append(recipeButton);


            OutputDebugStringW(L"Recipe Name: ");
            OutputDebugStringW(name->Data());
            OutputDebugStringW(L"\n");

            OutputDebugStringW(L"Description: ");
            OutputDebugStringW(description->Data());
            OutputDebugStringW(L"\n");

            OutputDebugStringW(L"Photo Path: ");
            OutputDebugStringW(photoPath->Data());
            OutputDebugStringW(L"\n");

            OutputDebugStringW(L"Ingredients:\n");
            for (String^ ingredient : ingredientsVector)
            {
                OutputDebugStringW(L" - ");
                OutputDebugStringW(ingredient->Data());
                OutputDebugStringW(L"\n");
            }

            // Tutaj możesz dodać własną logikę obsługi przepisu


        }
        else
        {
            // Obsługa błędów braku wymaganych kluczy w JSON
            OutputDebugStringW(L"Error: Invalid JSON structure - missing required keys.\n");
        }
    }
    catch (Exception^ ex)
    {
        // Obsługa błędów parsowania JSON
        OutputDebugStringW(L"Error during JSON parsing: ");
        OutputDebugStringW(ex->Message->Data());
        OutputDebugStringW(L"\n");
    }
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


void Tipplify::SelectionPage::ExpandRecipe_click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    if (RecipeAdditionPanel->Visibility == Windows::UI::Xaml::Visibility::Collapsed)
    {
        // Panel jest obecnie zwinięty, więc rozwijamy go
        RecipeAdditionPanel->Visibility = Windows::UI::Xaml::Visibility::Visible;
        ToggleRecipeAddition->Content = "Schowaj";
    }
    else
    {
        // Panel jest obecnie rozwinięty, więc zwijamy go
        RecipeAdditionPanel->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
        ToggleRecipeAddition->Content = "Dodaj drink";
    }
}

void Tipplify::SelectionPage::AddRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    // Pobierz dane 
    Platform::String^ name = NameTextBox->Text;
    Platform::String^ description = DescriptionTextBox->Text;
    Platform::String^ photoPath = PhotoPathTextBox->Text;
    Platform::String^ ingredientsText = IngredientsTextBox->Text;

    Vector<Platform::String^>^ ingredientsVector = ref new Vector<Platform::String^>();

    // Dzielenie tekstu na składniki

    std::wstring ingredientsWStr = ingredientsText->Data();
    std::wstringstream wss(ingredientsWStr);
    std::wstring ingredient;
    while (std::getline(wss, ingredient, L','))
    {
        ingredientsVector->Append(ref new Platform::String(ingredient.c_str()));
    }




    // Utwórz nowy obiekt JSON
    JsonObject^ jsonObject = ref new JsonObject();

    
    jsonObject->Insert("name", JsonValue::CreateStringValue(name));
    jsonObject->Insert("description", JsonValue::CreateStringValue(description));
    jsonObject->Insert("photoPath", JsonValue::CreateStringValue(photoPath));
    

    // Utwórz tablicę JSON z wektora składników
    JsonArray^ ingredientsJsonArray = ref new JsonArray();
    for (Platform::String^ ingredient : ingredientsVector)
    {
        ingredientsJsonArray->Append(JsonValue::CreateStringValue(ingredient));
    }

    jsonObject->Insert("ingredients", ingredientsJsonArray);

    

    String^ jsonString = jsonObject->Stringify();

    StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
    

    String^ filePath ="Assets" + "\\" + "recipes" + "\\" + name + ".json";
   
    
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



    

 

 

    // Wyczyszczenie TextBoxów po dodaniu przepisu
    NameTextBox->Text = "";
    DescriptionTextBox->Text = localFolder->Path + filePath; //TEMPORARY: SCEIZKA STWORZONEGO PLIKU W NAMETEXTBOXIE
    PhotoPathTextBox->Text = "";
    IngredientsTextBox->Text = "";

    // Tworzenie przycisku
    Button^ recipeButton = ref new Button();
    recipeButton->Content = name; // Ustaw nazwę przycisku na nazwę przepisu
    recipeButton->Click += ref new RoutedEventHandler(this, &Tipplify::SelectionPage::ChangeRecipe);

    // Dodaj przycisk do kontenera na przyciski (na przykład, Grid lub StackPanel)
    RecipeList->Children->Append(recipeButton);
    
}




