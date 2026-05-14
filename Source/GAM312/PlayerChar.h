// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

//Added ub character camera component 
#include "Camera/CameraComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Stamina = 100.0f;

	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION()
		void DecreaseStats();

};
