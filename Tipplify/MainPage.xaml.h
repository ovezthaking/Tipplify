//
// MainPage.xaml.h
// Deklaracja klasy MainPage.
//

#pragma once

#include "MainPage.g.h"
#include "WelcomePage.g.h"

namespace Tipplify
{
	/// <summary>
	/// Pusta strona, która może być używana samodzielnie lub do której można nawigować wewnątrz ramki.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

		void ChangeContent(Platform::String^ newDescription, Platform::String^ newTitle);

	private:
		void ChangeContent(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NavToMain(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		
	};
}

