﻿//
// MainPage.xaml.cpp
// Implementacja klasy MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "SelectionPage.xaml.h"


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

//Szablon elementu Pusta strona jest udokumentowany na stronie https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x415



Tipplify::MainPage::MainPage()
{
    InitializeComponent();
}

void Tipplify::MainPage::ChangeContent(Platform::String^ newDescription, Platform::String^ newTitle, Platform::String^ newIngredients, Platform::String^ newPath)
{
    // Zmiana treści w MainPage
    Image^ image = DImage;
    Windows::UI::Xaml::Media::Imaging::BitmapImage^ bitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage();
    String^ path = "ms-appx:///" + newPath;
    Uri^ uri = ref new Uri(path);
    bitmapImage->UriSource = uri;
    image->Source = bitmapImage;
   
    
    Description->Text = newDescription;
    Title->Text = newTitle;
    Ingredients->Text = newIngredients;
}

void Tipplify::MainPage::NavToMain(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    //Przeniesienie użytkownika na stronę selekcji 
    SelectionPage^ selectionpage = ref new SelectionPage();
    Windows::UI::Xaml::Window::Current->Content = selectionpage;
}
