//
// App.xaml.cpp
// Implementacja klasy aplikacji.
//

#include "pch.h"
#include "WelcomePage.xaml.h"

using namespace Tipplify;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

/// <summary>
/// Inicjuje pojedynczy obiekt aplikacji. Jest to pierwszy wiersz napisanego kodu
/// wykonywanego i jest logicznym odpowiednikiem metod main() lub WinMain().
/// </summary>
App::App()
{
    InitializeComponent();
    Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Wywoływane, gdy aplikacja jest uruchamiana normalnie przez użytkownika końcowego. Inne punkty wejścia
/// będą używane, kiedy aplikacja zostanie uruchomiona w celu otworzenia określonego pliku.
/// </summary>
/// <param name="e">Szczegóły dotyczące żądania uruchomienia i procesu.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e)
{
    auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

    // Nie powtarzaj inicjowania aplikacji, gdy w oknie znajduje się już zawartość,
    // upewnij się tylko, że okno jest aktywne
    if (rootFrame == nullptr)
    {
        // Utwórz ramkę, która będzie pełnić funkcję kontekstu nawigacji, i skojarz ją z
        // kluczem SuspensionManager
        rootFrame = ref new Frame();

        rootFrame->NavigationFailed += ref new Windows::UI::Xaml::Navigation::NavigationFailedEventHandler(this, &App::OnNavigationFailed);

        if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
        {
            // TODO: Przywracaj zapisany stan sesji tylko wtedy, gdy jest to potrzebne, planując
            // ostateczne kroki uruchamiania po ukończeniu przywracania

        }

        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                // Kiedy stos nawigacji nie jest przywrócony, przejdź do pierwszej strony,
                // konfigurując nową stronę przez przekazanie wymaganych informacji jako
                // parametr nawigacji
                rootFrame->Navigate(TypeName(WelcomePage::typeid), e->Arguments);
            }
            // Umieść ramkę w bieżącym oknie
            Window::Current->Content = rootFrame;
            // Upewnij się, ze bieżące okno jest aktywne
            Window::Current->Activate();
        }
    }
    else
    {
        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                // Kiedy stos nawigacji nie jest przywrócony, przejdź do pierwszej strony,
                // konfigurując nową stronę przez przekazanie wymaganych informacji jako
                // parametr
                rootFrame->Navigate(TypeName(WelcomePage::typeid), e->Arguments);
            }
            // Upewnij się, ze bieżące okno jest aktywne
            Window::Current->Activate();
        }
    }
}

/// <summary>
/// Wywoływane, gdy wykonanie aplikacji jest wstrzymywane. Stan aplikacji jest zapisywany
/// bez wiedzy o tym, czy aplikacja zostanie zakończona, czy wznowiona z niezmienioną zawartością
/// pamięci.
/// </summary>
/// <param name="sender">Źródło żądania wstrzymania.</param>
/// <param name="e">Szczegóły żądania wstrzymania.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
    (void) sender;  // Nieużywany parametr
    (void) e;   // Nieużywany parametr

    //TODO: Zapisz stan aplikacji i zatrzymaj wszelkie aktywności w tle
}

/// <summary>
/// Wywoływane, gdy nawigacja do konkretnej strony nie powiedzie się
/// </summary>
/// <param name="sender">Ramka, do której nawigacja nie powiodła się</param>
/// <param name="e">Szczegóły dotyczące niepowodzenia nawigacji</param>
void App::OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e)
{
    throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}
