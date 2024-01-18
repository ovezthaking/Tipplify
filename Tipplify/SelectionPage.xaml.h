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
		property Platform::String^ Ingredients;
		property Platform::String^ PhotoPath;
	};

		public ref class SelectionPage sealed
	{
	public:
		SelectionPage();
	private:
		void ChangeRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Platform::Collections::Vector<Recipe^>^ parsedRecipes;
		Platform::Collections::Vector<Recipe^>^ parsedRecipesFiltered;
		void LoadRecipes();
		void FilterRecipes();
		void AddRecipe(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DisplayAllRecipes();
		void DisplayFilteredRecipes();
		void ExpandRecipe_click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ParseAndHandleRecipe(Platform::String^ jsonContent);
		
		void SearchRecipes(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void ScrollViewer_ViewChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs^ e);
		};

}
