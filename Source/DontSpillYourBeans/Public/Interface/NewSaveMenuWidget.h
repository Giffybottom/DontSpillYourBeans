// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/BaseScreenWidget.h"
#include "NewSaveMenuWidget.generated.h"

/**
 * 
 */

UCLASS()
class DONTSPILLYOURBEANS_API UNewSaveMenuWidget : public UBaseScreenWidget
{
	GENERATED_BODY()
	
public:

	UNewSaveMenuWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	//buttons 


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class	UEditableTextBox* EditableTextBoxInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "UI|Input")
		class 	UButtonwWithTextWidget* buttonConfirm;

	// vars 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Input")
		FString inputTxt;
	//functions 

};