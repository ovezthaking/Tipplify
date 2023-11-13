//
// WelcomePage.xaml.cpp
// Implementacja klasy WelcomePage
//

#include "pch.h"
#include "WelcomePage.xaml.h"
#include <MainPage.xaml.cpp>
#include <MainPage.xaml.h>

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


void Tipplify::WelcomePage::TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void Tipplify::WelcomePage::NavToMain(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MainPage^ mainpage = ref new MainPage();
	Windows::UI::Xaml::Window::Current->Content = mainpage;
}
