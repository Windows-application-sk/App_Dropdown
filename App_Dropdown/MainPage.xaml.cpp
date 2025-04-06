//
// MainPage.xaml.cpp
// MainPage クラスの実装。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace App_Dropdown;

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

// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x411 を参照してください

MainPage::MainPage()
{
    InitializeComponent();

    // 共通リスト項目
    auto items = ref new Platform::Collections::Vector<Platform::String^>();
    items->Append("リスト1");
    items->Append("リスト2");
    items->Append("リスト3");

    // ドロップダウンを配列にまとめる
    dropdowns = { Dropdown1, Dropdown2, Dropdown3 };

    for (auto comboBox : dropdowns)
        comboBox->ItemsSource = items;
}

void MainPage::OnDropdownSelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
{
    ComboBox^ comboBox = dynamic_cast<ComboBox^>(sender);
    if (!comboBox || comboBox->SelectedIndex < 0)
        return;

    int dropdownIndex = 0;

    if (comboBox == Dropdown1)
        dropdownIndex = 1;
    else if (comboBox == Dropdown2)
        dropdownIndex = 2;
    else if (comboBox == Dropdown3)
        dropdownIndex = 3;

    int listIndex = comboBox->SelectedIndex + 1; // 1-based index

    OutputDebugStringW(
        (L"ドロップダウン" + dropdownIndex.ToString() +
            L"にリスト" + listIndex.ToString() +
            L"が選択されました。\n")->Data());
}
