//
// WelcomePage.xaml.cpp
// Implementacja klasy WelcomePage
//

#include "pch.h"
#include "WelcomePage.xaml.h"
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

//Szablon elementu Pusta strona jest udokumentowany na stronie https://go.microsoft.com/fwlink/?LinkId=234238

WelcomePage::WelcomePage()
{
	InitializeComponent();
}



void Tipplify::WelcomePage::NavToMain(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	SelectionPage^ selectionpage = ref new SelectionPage();
	Windows::UI::Xaml::Window::Current->Content = selectionpage;
}
