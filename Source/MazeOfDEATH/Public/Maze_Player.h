// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Maze_Player.generated.h"

UENUM(BlueprintType)
enum class EFearLevel : uint8
{
	Low UMETA(DisplayName = "Low"),
	Medium UMETA(DisplayName = "Medium"),
	High UMETA(DisplayName = "High")
};



UCLASS()
class MAZEOFDEATH_API AMaze_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMaze_Player();

	UPROPERTY(EditAnywhere, Category = "Collision")
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, Category = "Collision")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Controller")
	class AMaze_PlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFearLevel Fear = EFearLevel::Low;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void TurnAround(float Ratio);

};
