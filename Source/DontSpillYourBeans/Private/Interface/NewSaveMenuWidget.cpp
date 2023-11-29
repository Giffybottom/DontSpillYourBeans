// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/NewSaveMenuWidget.h"

//UI Widgets coded
#include "Interface/ButtonwWithTextWidget.h"
//UI BP includes
#include "Components/EditableTextBox.h" 
#include "Components/Button.h"

UNewSaveMenuWidget::UNewSaveMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TSubclassOf<UUserWidget>WidgetType = UNewSaveMenuWidget::StaticClass();

}
void  UNewSaveMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

