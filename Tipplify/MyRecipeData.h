// MyRecipeData.h
#pragma once

#include <collection.h>

namespace Tipplify
{
    // Struktura reprezentująca dane przepisu
    public value struct MyRecipeData
    {
        Platform::String^ Name;
        Platform::String^ Description;
        Platform::String^ PhotoPath;
        Windows::Foundation::Collections::IVector<Platform::String^>^ Ingredients;
    };
}
