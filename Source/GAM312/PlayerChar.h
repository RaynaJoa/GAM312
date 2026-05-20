// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Resource_M.h"
#include "BuildingPart.h"

//Added ub character camera component 
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM312_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Establishing character movement 
	UFUNCTION()
		void MoveForward(float axisValue);

	//Establishing character movement
	UFUNCTION()
		void MoveRight(float axisValue);

	//Establishing character jump
	UFUNCTION()
		void StartJump();

	//Establishing stoping character jump
	UFUNCTION()
		void StopJump();

	//Establishing character object interaction (will be added later)
	UFUNCTION()
		void FindObject();

	//Establishing being able to get the camera in the code
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;

	//To set up the player with 100 health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health = 100.0f;

	//To set up the player with 100 hunger
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	//Set up the player with 100 stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Stamina = 100.0f;

	//To indicate wood as a collectable item
	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	//To indicate stone as a collectable item
	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;

	//To indicate berry as a collectable item 
	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	//To set up the array for resources
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	//To set up the array for making resources
	UPROPERTY(EditAnywhere, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	//To set up the hit marker for collecting
	UPROPERTY(EditAnywhere, Category = "HitMarker")
		UMaterialInterface* hitDecal;

	//To set up Building Supplies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
		TArray<int> BuildingArray;

	//Set up bool for building items
	UPROPERTY()
		bool isBuilding;

	//Setting up editing building
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<ABuildingPart> BuildPartClass;

	//Spawning building parts
	UPROPERTY()
		ABuildingPart* spawnedPart;

	//To set up health
	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	//TO set up hunger 
	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	//To set up stamina 
	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	//To decrease the overall stats of everything
	UFUNCTION()
		void DecreaseStats();
	
	//To collect resources
	UFUNCTION()
		void GiveResource(float amount, FString resourceType);

	//To update resources on hand
	UFUNCTION(BlueprintCallable)
		void UpdateResources(float woodAmount, float stoneAmount, FString buildObject);

	//To spawn buildings
	UFUNCTION(BlueprintCallable)
		void SpawnBuilding(int buildingID, bool& isSuccess);

	//To rotate the building items
	UFUNCTION()
		void RotateBuilding();


};
