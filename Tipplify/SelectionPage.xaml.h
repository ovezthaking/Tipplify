//
// SelectionPage.xaml.h
// Deklaracja klasy SelectionPage
//

#pragma once

#include "SelectionPage.g.h"

namespace Tipplify
{
	/// <summary>
	/// Pusta strona, która może być używana samodzielnie lub do której można nawigować wewnątrz ramki.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
		public ref class Recipe sealed
	{
	public:

		property Platform::String^ Name;
		property Platform::String^ Description;
		property Platform::String^ Instructions;
	};
		public ref class SelectionPage sealed
	{
	public:
		SelectionPage();
	private:
		void ChangeRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);


		void LoadRecipes();
		void AddRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ExpandRecipe_click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ParseAndHandleRecipe(Platform::String^ jsonContent);
		
		
	};

}
