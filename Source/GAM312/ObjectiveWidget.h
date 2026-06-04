// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAM312_API UObjectiveWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//To be able to call upon the blueprint
	UFUNCTION(BlueprintImplementableEvent)
		void UpdatematOBJ(float matsCollected);

	//For the widget to get updated often
	UFUNCTION(BlueprintImplementableEvent)
		void UpdatebuildObj(float objectsBuilt);
	
};
