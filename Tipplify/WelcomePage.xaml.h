//
// WelcomePage.xaml.h
// Deklaracja klasy WelcomePage
//

#pragma once

#include "WelcomePage.g.h"

namespace Tipplify
{
	/// <summary>
	/// Pusta strona, która może być używana samodzielnie lub do której można nawigować wewnątrz ramki.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class WelcomePage sealed
	{
	public:
		WelcomePage();
	private:
		void TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
