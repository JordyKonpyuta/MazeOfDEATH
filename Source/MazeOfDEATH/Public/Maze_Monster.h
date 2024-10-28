// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Maze_Monster.generated.h"

class AMaze_Player;

UCLASS()
class MAZEOFDEATH_API AMaze_Monster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMaze_Monster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	AMaze_Player* PlayerRef;

};
