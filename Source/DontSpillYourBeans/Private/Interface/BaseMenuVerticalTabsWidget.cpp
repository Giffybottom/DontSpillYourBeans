// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/BaseMenuVerticalTabsWidget.h"
//UI Widgets coded
#include "Interface/ButtonwWithTextWidget.h"
#include "Interface/TextButtonWithIntWidget.h"


//UI BP includes
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
//UI BP includes specic to this menu 
#include "Components/VerticalBox.h"
//: Super(ObjectInitializer) need for derived classes
UBaseMenuVerticalTabsWidget::UBaseMenuVerticalTabsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

	TSubclassOf<UUserWidget>WidgetType = UBaseMenuVerticalTabsWidget::StaticClass();
}

void UBaseMenuVerticalTabsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	hasDefaultMenu = true;
}

void UBaseMenuVerticalTabsWidget::BindButtons()
{
	Super::BindButtons();
	// Binding tab buttons
	//get number of menus 
	int menusCount = MenuSwitcher->GetChildrenCount();
	//set to start of sub menus 
	int menuBindStartNumber = 0;
	//check for default menu
	if (hasDefaultMenu)
	{
		//subtract default screen aka screen 0
		menusCount--;
		// 1 to exclude the default
		menuBindStartNumber = 1;
	}
	//if has an end range number
	if (buttonRangeEndIndex == -1)
	{//careful to not have spacers in the box
		buttonRangeEndIndex = tabButtons->GetChildrenCount();
	}
   //To check buttons and menus line up in count
	int numBtnCount = tabButtons->GetChildrenCount();
	//check the amount of menus match match btn count  
	if (menusCount == buttonRangeEndIndex)
	{
		//loop buttons and hook them to their respective screens

			int btnIndex = buttonRangeStartIndex;
			//Dont shift start since buttons dont have a default
			for (size_t i = 0; i < menusCount; i++)
			{
				UTextButtonWithIntWidget* btn = Cast<UTextButtonWithIntWidget>(tabButtons->GetChildAt(btnIndex));
				if (btn != nullptr)
				{
					int menuIndex = i;
					if (hasDefaultMenu)
					{
						//index of the menu + 1 since zero is the default screen
						menuIndex += 1;
					}
					btn->number = menuIndex;
					btn->OnPassNumber.AddDynamic(this, &UBaseMenuWidget::SwitchMenu);
					btnIndex++;
				}
			}
			

		}

		BindBackButtons(menuBindStartNumber, menusCount);

	

}

void UBaseMenuVerticalTabsWidget::NextMenu()
{
	Super::NextMenu();
	tabButtons->GetChildAt(CurrTabIndex)->SetFocus();

}

void UBaseMenuVerticalTabsWidget::PrevMenu()
{
	Super::PrevMenu();

}

void UBaseMenuVerticalTabsWidget::CloseMenu()
{
	Super::CloseMenu();
	tabButtons->GetChildAt(0)->SetFocus();
}

